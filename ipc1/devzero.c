#include "apue.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <stdarg.h>

#define LOOP 1024

#define SIZE sizeof(long)

static void
err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
    char buf[MAXLINE];

    vsnprintf(buf, MAXLINE-1, fmt, ap);
    if (errnoflag)
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1, ": %s", strerror(error));

    strcat(buf, "\n");
    fflush(stdout);     /* in case stdout and stderr are the same */
    fputs(buf, stderr);
    fflush(NULL);       /* flushes all stdio output streams */
}

void
err_quit(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    err_doit(0, 0, fmt, ap);
    va_end(ap);
    exit(1);
}


static int update(long *ptr)
{
	return ((*ptr)++);
}

int main()
{
	int fd, i, count;
	pid_t pid;
	void *area;

	fd = open("/dev/zero", O_RDWR);
	if (fd < 0)
		err_quit("open /dev/zero error");

	if ((area = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
		err_quit("mmap failed");

	close(fd);

	TELL_WAIT();

	if ((pid = fork()) < 0)
		err_quit("fork error");
	else if (pid > 0) {
		for (i=0; i<LOOP; i+=2) {
			if ((count = update((long*)area)) != i) 
				err_quit("parent process expect %d got %d\n", i, count);
	
			TELL_CHILD(pid);
			WAIT_CHILD();
		}
		
	} else {
		for (i=1; i<LOOP+1; i+=2) {
			WAIT_PARENT();
			if ((count = update((long*)area)) != i) 
				err_quit("child process expect %d got %d\n", i, count);
			
			TELL_PARENT(getppid());
		}
		
	}

	exit(0);
}
