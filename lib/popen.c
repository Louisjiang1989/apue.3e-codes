#include "apue.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

/* 
 * Pointer to array allocated at run-time.
 */
static pid_t *childpid = NULL;

/* 
 * From our open_max()
 *
 * The popen() function opens a process by creating a pipe, forking, and invoking(调用) the shell. 
 * Since a pipe is by definition unidirectional, the "type" argument may specify only reading or
 * writing, not both; the resulting stream is correspondingly read-only or write-only.
 *
 * The command argument is a pointer to a null-terminated string containing a shell command line.
 * This command is passed to /bin/sh using the -c flag; interpretation, if any, is performed by 
 * the shell.
 *
 * The type argument is a pointer to a null-terminated string which must contain either the letter 'r'
 * for reading or the letter 'w' for writing. Since glibc 2.9, this argument can additionally include
 * the letter 'e', which causes the close-on-exec flag (FD_CLOEXEC) to be set on the underlying file
 * descriptor; see the description of the O_CLOEXEC flag in open(2) for reasons why this may be usefil.
 *
 * The return value from popen() is a normal standard I/O stream in all respects save that it must be 
 * closed with pclose() rather than fclose(3). Writing to such a stream writes to the standard input of
 * the command;the command's standart output is the same as that of process that called popen(), unless 
 * this is altered by the command itself. Conversely, reading from the stream reads the command's 
 * standard output, and the command's standard input is the same as that of the process that called popen().
 *
 * Note that output popen(0 streams are block buffered by default.
 *
 * The pclose() function waits for the associated process to terminate and returns the exit status of the 
 * command as returned by wait4(2).
 *
 * RETURN VALUE
 * the popen() function returns NULL if the fork(2) or pipe(2) calls fail, or if it cannot allocate memory.
 * the pclose(0 function returns -1 if wait4(2) returns as error, or some other error is detected. In the 
 * event of an error, these function set errno to indicate the cause of the error.
 */

FILE* 
popen(const char *cmdstring, const char *type)
{
    
    int pfd[2];
    pid_t pid;
    /* only allow "r" or "w" */
    if ((type[0] != 'r' && type[0] != 'w') || type[1] != 0) {
        errno = EINVAL;
        return NULL;
    }

    if (childpid == NULL) {  /* first time through */
        /* allocate zeroed out array for child pids */
        maxfd = open_max();
        if ((childpid = calloc(maxfd, sizeof(pid_t))) == NULL) {
            return NULL;
        }
    }

    if (pipe(pfd) < 0) {
        return NULL;    /* errno set by pipe() */
    }
    if (pfd[0] >= maxfd || pfd[1] >= maxfd) {
        close(pfd[0]);
        close(pfd[1]);
        errno = EMFILE;
        return NULL;
    }

    if ((pid = fork()) < 0) {
        return NULL;  /* errno set by fork() */
    } else if (pid == 0) {   /* child */
        if (*type == 'r') {
            close(pfd[0]);
            if (pfd[1] != STDOUT_FILENO) {
                dup2(pfd[1], STDOUT_FILENO);     /* duplicate the STDOUT_FILENO to pfd[1] */
                close(pfd[1]);
            }
        } else {  /* 'w' */
            close(pfd[1]);
            if (pfd[0] != STDIN_FILENO) {
                dup2(pfd[0], STDIN_FILENO);
                close(pfd[0]);
            }
        }
        
        /* close all descriptors in childpid[] */
        for (i = 0; i < maxfd; i++) {
            if (childpid[i] > 0) {
                close(i);
            }
        }
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127);
    }

    /* parent continues... */
    if (*type == 'r') {
        close(pfd[1]);
        /* fdopen function associates a stream with the existing file descriptor, fd.
         * The mode of the stream (one of the values "r", "r+", "w", "w+", "a", "a+") 
         * must be compatiable with the mode of the file descriptor. The file position
         * indicator of the new stream is set to that belong to fd, and the error and 
         * end-of-file indicators are cleared. Modes "w" or "w+" do not cause truncation 
         * of the file. the file descriptor is not dup'ed, and will be closed when the stream
         * created by fdopen() is closed. The result of applying fdopen() to a shared memory
         * object is undefined.
         */
        if ((fp = fdopen(pfd[0], type)) == NULL) {
            return NULL;
        } 
    } else {
            close(pfd[0]);
            if ((fp = fdopen(pfd[1], type)) == NULL) {
                return NULL;
            }
    }

    childpid[fileno(fp)] = pid; /* remember child pid for this fd */
    return fp;
}

int 
pclose(FILE *fp) 
{
    int fd, stat;
    pid_t pid;
    if (childpid == NULL) {
        errno = EINVAL;
        return -1;           /* popen() has never been called */
    }

    /*
     *the function fileno() examins to argument stream and returns its integer descriptor.
     */
    fd = fileno(fp);
    if (fd >= maxfd) {
        errno = EINVAL;
        return -1;           /* invalid file descriptor */
    }

    if ((pid = childpid[fd]) == 0) {
        errno = EINVAL;
        return -1;      /* fp wasn't opened by popen() */
    }

    childpid[fd] = 0;
    /* fclose function flushes the stream pointed to by stream(writing any buffered output data using fflush(3))
     * and closes the underlying file descriptor.
     */
    if (fclose(fp) == EOF) {
        return -1;
    }
    
    /*
     * the waitpid() system call suspends execution of the calling process until a child specified by 
     * pid argument has changed state. By default, waitpid() waits only for terminated children, but
     * this behavior is modifiable via the options argument, as described below.
     *
     * The value of pid can be :
     * < -1 meaning wait for any child process whose process group ID is equal to the absolute value of pid.
     * -1   meaning wait for any child process.
     *  0   meaning wait for any child process whose process group ID is equal to that of calling process.
     *  > 0 meaning wait for the child whose process ID is equal to the value of pid.
     */
    while (waitpid(pid, &stat, 0) < 0) {
        if (errno != EINTR) {
            return -1;          /* error other than EINTR from waitpid() */
        }
    }

    return stat;  /* return child's termination status */
}
