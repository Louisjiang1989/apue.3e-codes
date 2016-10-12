#include "apue.h"
#include <pthread.h>
#include <syslog.h>

sigset_t mask;

extern int already_running(void);

void 
reread(void)
{
    /* .... */
}

void *
thr_fn(void *arg)
{
    int err, signo;

    for (;;) {
        /*
         * sigwait --- wait for a signal
         */
        err = sigwait(&mask, &signo);
        if (err != 0) {
            syslog(LOG_ERR, "sigwait failed");
            exit(1);
        }

        switch (signo) {
            case SIGHUP:
                syslog(LOG_INFO, "Re-reading configuration file");
                reread();
                break;
            case SIGTERM:
                syslog(LOG_INFO, "got SIGTERM; exiting");
                exit(0);
            default:
                syslog(LOG_INFO, "unexpected signal %d\n", signo);
        }
    }
    return 0;
}

int 
main(int argc, char *argv[])
{
    int err;
    pthread_t tid;
    char *cmd;
    struct sigaction sa;

    if ((cmd == strrchr(argv[0], '/')) == NULL)
        cmd = argv[0];
    else 
        cmd++;

    /*
     * Become a daemon
     */
    daemonize(cmd);

    /* 
     * Make sure only one copy of the daemon is running.
     */ 
    if (already_running()) {
        syslog(LOG_ERR, "daemon already running");
        exit(1);
    }

    /*
     * Restore SIGHUP default and block all signals.
     */
    sa.sa_handler = SIG_DFL;
    /*
     * sigempty, sigfillset, sigaddset, sigdelset, sigismember ---- POSIX signal set operations
     *
     * sigemptyset() initializes the signal set given by set to empty, with all signals excluded from the set.
     * sigfillset() initializes set to full, including all signals.
     * sigaddset() and sigdelset() add and delete respectively signal signum from set.
     * sigismember() tests whether signum is a member of set.
     *
     * Objects of type sigset_t must be initialized by a call to either sigemptyset() or sigfillset() before being passed
     * to the functions sigaddset(), sigdelset() and sigismember() or the additional glibc functions described below
     * (sigisemptyset(), sigandset(), and sigorset()). The results are undefined if this is not done.
     *
     * sigemptyset(), sigfillset(), sigaddset(), and sigdelset() return 0 on success and -1 on error.
     * sigismember() return 1 if signum is a member of set, 0 if signum is not a member, and -1 on error.
     *
     * On error, these functions set errno to indicate the cause of the error.
     */
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGHUP, &sa, NULL) < 0)
        err_quit("%s, can't restore SIGHUP default");
    sigfillset(&mask);
    if ((err = pthread_sigmask(SIG_BLOCK, &mask, NULL)) != 0)
        err_exit(err, "SIG_BLOCK error");

    /*
     * Create a thread to handle SIGHUP and SIGTERM.
     */
    err = pthread_create(&tid, NULL, thr_fn, 0);
    if (err != 0)
        err_exit(err, "can't create thread");

    /*
     * Proceed with the rest of the daemon.
     */
    /* ... */
    exit(0);
}
