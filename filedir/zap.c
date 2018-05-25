#include "apue.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    int i, fd;
    struct stat statbuf;
    struct timespec times[2];

    for (i = 1; i < argc; i++) {
        if (stat(argv[i], &statbuf) < 0) {
            /* fetch current times */
            err_ret("%s: stat error", argv[i]);
            continue;
        }
        if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0) {
            /* truncate */
            err_ret("%s: open error", argv[i]);
            continue;
        }
        /*times[0] = statbuf.st_atim;
        times[1] = statbuf.st_mtim;*/
	struct timespec newtime1 = {0, 0};
	struct timespec newtime2 = {1527230498, 0};
	times[0] = newtime1;
	times[1] = newtime2;
        /*
         * futimes, lutimes ---- change file timestamps
         */ 
        if (futimens(fd, times) < 0)  /* reset times */
            err_ret("%s: futimens error", argv[i]);
        close(fd);
    }
    exit(0);
}
