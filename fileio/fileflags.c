#include "apue.h"
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int
main(int argc, char *argv[])
{
    int val;

    if (argc != 2)
        err_quit("usage: a.out <descriptor#>");

    if(chdir("/home/louis/apue/apue.3e-codes/fileio") != 0) {
    	err_quit("chdir error %s\n", strerror(errno));
    }    

    int fd = open("./file", O_RDWR | O_APPEND);

    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fcntl error for fd %d", fd);

    switch (val & O_ACCMODE) {
        case O_RDONLY:
            printf("read only");
            break;

        case O_WRONLY:
            printf("write only");
            break;

        case O_RDWR:
            printf("read write");
            break;

        default:
            err_dump("unknown access mode");
    }
    if (val & O_APPEND)
        printf(", append");
    if (val & O_NONBLOCK)
        printf(", nonblocking");
    if (val & O_SYNC)
        printf(", synchronous writes");

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC)
        printf(", synchronous writes");
#endif

    putchar('\n');
    exit(0);
}


