#include "apue.h"

static volatile sig_atomic_t sigflag; /* set nonzero by sig handler */
static sigset_t newmask, oldmask, zeromask;

static void
sig_usr(int signo)  /* one signal handler for SIGUSR1 and SIGUSR2 */
{
    int pid = getpid();
    printf("sig_usr calling pid(%d)\n", pid);
    sigflag = 1;
}

void
TELL_WAIT(void) 
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        err_sys("signal(SIGUSR1) error");
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        err_sys("signal(SIGUSR2) error");
    }
    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGUSR1);
    sigaddset(&newmask, SIGUSR2);

    /* Block SIGUSR1 and SIGUSR2 and save current signal mask */
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
        err_sys("SIG_BLOCK error");
    }
}

void
TELL_PARENT(pid_t pid)
{
    /*
     * kill - send a signal to a process
     */
    printf("TELL_PARENT kill pid(%d)\n", pid);
    kill(pid, SIGUSR2);  /* tell parent we are done */
}

void
WAIT_PARENT(void)
{
    while (sigflag == 0) {
	printf("WAIT_PARENT sigsuspend\n");
        sigsuspend(&zeromask);  /* and wait for parent */
    }

    printf("WAIT_PARENT sigsuspend over\n");

    sigflag = 0;

    /* Reset signal mask to original value */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        err_sys("SIG_SETMASK error");
    }
}

void 
TELL_CHILD(pid_t pid)
{
    printf("TELL_CHILD kill pid(%d)\n", pid);
    kill(pid, SIGUSR1);  /* tell child we are done */
}

void
WAIT_CHILD(void)
{
    while (sigflag == 0) {
	printf("WAIT_CHILD sigsuspend\n");
        sigsuspend(&zeromask);  /* and wait for child */
    }

    printf("WAIT_CHILD sigsuspend over\n");

    sigflag = 0;

    /* Reset signal mask to original value */
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        err_sys("SIG_SETMASK error");
    }
}



