#include "apue.h"
#include <fcntl.h>

/*
 * we know, each file descriptor has a close-on-exec flag, and the last bit of this flag is set to '0' by default.
 * the function of this flag is that it will close the fd before called exec() functions by other process.
 */
int 
set_cloexec(int fd)
{
    int val;

    if ((val = fcntl(fd, F_GETFD, 0)) <0) {
        return (-1);
    }
    val |= FD_CLOEXEC;   /* enable close-on-exec */

    return (fcntl(fd, F_SETFD, val));
}
