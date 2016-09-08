#include "apue.h"
#include <errno.h>


/* 
 * #include <signal.h>
 * int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
 *
 * sigprocmask() is used to fetch and/or change the signal mask of the calling thread.
 * The signal mask is the set of signals whose delivery is currently blocked for the caller.
 * The behavior of the call is dependent on the value of how, as follows.
 *
 * SIG_BLOCK: The set of blocked signals is the union of the current set and the set argument.
 *
 * SIG_UNBLOCK: The signals in set are removed from the current set of blocked signals. It is permissible to attempt to unblock a signal which is not blocked.
 *
 * SIG_SETMASK: The set of blocked signals is set to the argument set.
 *
 *
 * int sigismember(const sigset_t *set, int signum);
 *
 * sigismember(0 tests whether signum is a member of set)
 */
void
pr_mask(const char *str)
{
    int errno_save;
    sigset_t sigset;

    errno_save = errno;    /* we can be called by signal handlers */
    if (sigprocmask(0, NULL, &sigset) < 0) {
        err_ret("sigprocmask error");
    } else {
        printf("%s", str);
        if (sigismember(&sigset, SIGINT)) {
            printf(" SIGINT");
        }
        if (sigismember(&sigset, SIGQUIT)) {
            printf(" SIGQUIT");
        }
        if (sigismember(&sigset, SIGUSR1)) {
            printf(" SIGUSR1");
        }
        if (sigismember(&sigset, SIGALRM)) {
            printf(" SIGALRM");
        }
        
        /* remaining signals can go here */
        printf("\n");
    }
    errno = errno_save;     /* restore errno */
}
