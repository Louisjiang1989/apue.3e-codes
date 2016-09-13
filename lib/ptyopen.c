#include "apue.h"
#include <errno.h>
#include <fcntl.h>
#if defined(SOLARIS)
#include <stropts.h>
#endif

/* 
 * posix_openpt: open a pseudoterminal device
 *
 * #include <stdlib.h>
 * #include <fcntl.h>
 * int posix_openpt(int flags);
 *
 * posix_openpt() function opens an unused pseudoterminal master device, returning a file
 * descriptor that can be used to refer to that device. The flags argument is a bit mask
 * that ORs together zero or more of the following flags:
 * O_RDWR: Open the device for both reading and writing, It is usual to specify this flag.
 * O_NOCTTY: Do not make this device the controlling terminal for the process.
 *
 * grantpt: grant access to the slave pseudoterminal
 *
 * #define _XOPEN_SOURCE
 * #include <stdlib.h>
 * int grantpt(int fd);
 *
 * The grantpt() function changes the mode and owner of the slave pseudoterminal device
 * corresponding to the master pseudoterminal referred to by fd. The user ID of the slave
 * is set to the real UID of the calling process. The group ID is set to an unspecified value (e.g. tty).
 * The mode of the slave is set 0620(crw--w----).
 *
 *
 * The behavior of grantpt() is unspecified if a signal handler is installed to catch SIGCHID signals.
 *
 * unlockpt: unlock a pseudoterminal master/slave pair
 *
 */


int
ptym_open(char *pts_name, int pts_namesz)
{
    char *ptr;
    int fdm, err;

    if ((fdm = posix_openpt(O_RDWR)) < 0) {
        return -1;
    }
    if (grantpt(fdm) < 0) {  /* grant access to slave */
        goto errout;
    }
    if (unlockpt(fdm) < 0) {  /* clear slave's lock flag */
        goto errout;
    }
    if ((ptr = ptsname(fdm)) == NULL) {   /* get slave's name */
        goto errout;
    }

    /* Return name of slave. Null terminate to handle case where strlen(ptr) > pts_namesz. */
    strncpy(pts_name, ptr, pts_namesz);
    pts_name[pts_namesz - 1] = '\0';
    return fdm;             /* return fd of master */
errout:
    err = errno;
    close(fdm);
    errno = err;
    return -1;
}

int 
ptys_open(char *pts_name)
{
    int fds;
#if defined(SOLARIS)
    int err, setup;
#endif

    if ((fds = open(pts_name, O_RDWR)) < 0) {
        return -1;
    }

#if defined(SOLARIS)
    /*
     *Check if stream is already set up by autopush facility
     */
    if ((setup = ioctl(fds, I_FIND, "ldterm")) <0) {
        goto errout;
    }
    if (setup == 0) {
        if (ioctl(fds, I_PUSH, "ptem") < 0) {
            goto errout;
        }
        if (ioctl(fds, I_PUSH, "ldterm") < 0) {
            goto errout;
        }
        if (ioctl(fds, I_PUSH, "ttcompat") < 0) {
errout:
            err = errno;
            close(fds);
            errno = err;
            return -1;
        }
    }
#endif
    return fds;
}



