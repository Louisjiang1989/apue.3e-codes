#include "apue.h"

/* Reliable version of signal(), using POSIX sigaction(). */
Sigfunc *
signal(int signo, Sigfunc *func) 
{
    struct sigaction act, oact;

    act.sa_handler = func;             /* the signal hander */
    sigemptyset(&act.sa_mask);         /* clear the mask signal set */
    act.sa_flags = 0;                  /* sa_flags = 0 --> default action;  SA_NODEFER / SA_RESETHAND */
    if (signo == SIGALRM) {
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;
#endif
    } else {
        act.sa_flags |= SA_RESTART;
    }

    /*
     * sigaction, rt_sigaction - examine and change a signal action
     * #include <signal.h>
     * int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
     *
     * The sigaction() system call is used to change the action taken by a process on receipt of a specific signal.
     * signum specifies the signal and can be any valid signal except SIGKILL and SIGSTOP.
     * If act is non-NULL, the new action for signal signum is installed from act. If oldact is non-NULL, the previous action is saved in oldact.
     */
    if (sigaction(signo, &act, &oact) <0) {
        return (SIG_ERR);
    }
    return (oact.sa_handler);
}
