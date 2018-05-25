#include "apue.h"

int 
main(void)
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
	err_sys("cannot seek");
    else 
        printf("seek OK\n");
    exit(0);
}
