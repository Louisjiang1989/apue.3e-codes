#include "apue.h"
#include <setjmp.h>

static void f1(int, int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;
static int     globval;

int
main(void)
{
    int autoval;
    register int regival;
    volatile int volaval;
    static int statval;

    globval = 1; autoval = 2; regival = 3; volaval = 4; statval = 5;
    
    /*
     * setjmp, sigsetjmp -- save stack context for nonlocal goto
     * setjmp and longjmp are useful for dealing with errors and interrupts encountered in a low-level
     * subroutine of a program. setjmp() saves the stack context/environment in env for later use by
     * longjmp(3). The stack context will be invalidated if the function which called setjmp() returns.
     *
     * sigsetjmp() is similar to setjmp(). If, and only if, savesigs is nonzero, the process's current signal
     * mask is saved in env and will be restored if a siglongjmp(3) is later performed with this env.
     */
    if (setjmp(jmpbuffer) != 0) {
        printf("after longjmp:\n");
        printf("globval = %d, autoval = %d, regival = %d," " volaval = %d, statval = %d\n",
                globval, autoval, regival, volaval, statval);
        exit(0);
    }

    /*
     * Change variables after setjmp, but before longjmp.
     */
    globval = 95; autoval = 96; regival = 97; volaval = 98;
    statval = 99;

    f1(autoval, regival, volaval, statval); /* never returns */
    exit(0);
}

static void
f1(int i, int j, int k, int l)
{
    printf("int f1(): \n");
    printf("globval = %s, autoval = %d, regival = %d,"
            " volaval = %d, statval = %d\n", globval, i, j, k, l);
    f2();
}

static void
f2(void)
{
    /* 
     * longjmp, siglongjmp --- nonlocal jump to a saved stack context.
     * longjmp() and setjmp(3) are useful for dealing with errors and interrupts encountered in a low-level 
     * subroutine of a program. longjmp() restores the environment saved by the last call of setjmp(3) with
     * the corresponding env argument. After longjmp() is completed, program execution continues as if the corresponding
     * call of setjmp(3) had just return the value val. longjmp() cannot cause 0 to be returned. If longjmp() is invoked with a 
     * second argument of 0, 1 will be returned instead.
     *
     * siglongjmp() is similar to longjmp() except for the type of its env argument. If, and only if, the sigsetjmp(3)
     * call that set this env used a nonzero savesigs flag, siglongjmp() also restores the signal mask that was saved
     * by sigsetjmp(3).
     */
    longjmp(jmpbuffer, 1);
}
