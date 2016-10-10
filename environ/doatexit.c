#include "apue.h"

static void my_exit1(void);
static void mu_exit2(void);

int
main(void)
{
    /*
     * atexit -- register a function to be called at normal process termination 
     * the atexit() function registers the given function to be called at normal process termination, either via exit(3)
     * or via return from the program's main(). Function so registered are called in the reverse order of their registration
     * no arguments are passed.
     * The same function may be registerd multiple times; it is called once for each registration.
     * the atexit() function return 0 if successful; otherwise it returns a nonzero value.
     */
    if (atexit(my_exit2) != 0)
        err_sys("can't register my_exit2");

    if (atexit(my_exit1) != 0)
        err_sys("can't register my_exit1");

    printf("main is done\n");
    return 0;
}

static void
my_exit1(void)
{
    printf("first exit handler\n");
}

static void 
my_exit2(void)
{
    printf("second exit handler\n");
}
