#include "apue.h"
#include <fcntl.h>

int
main(void)
{
    if (open("tempfile-hard", O_RDWR) < 0)
        err_sys("open error");
    /*
     * unlink, unlinkat ---- delete a name and possibly the file it refers to 
     */ 
    if (unlink("tempfile-hard") < 0)
        err_sys("unlink error");
    printf("file unlinked\n");
    sleep(15);   /*  seconds */
    printf("done\n");
    exit(0);
}
