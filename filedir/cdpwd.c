#include "apue.h"

int 
main(void)
{
    char *ptr;
    size_t size;

    if (chdir("/usr/spool/uucppublic") < 0)
        err_sys("chdir failed");

    ptr = path_alloc(&size);  /* our own function */
    /*
     * getcwd, getwd, get_current_dir_name - get current working directory 
     *
     * #include <unistd.h>
     * int *getcwd(char *buf, size_t size);
     */
    if (getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");

    printf("cwd = %s\n", ptr);
    exit(0);
}
