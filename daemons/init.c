#include "apue.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>

/*
 * exec the cmd as daemon 
 */
void
daemonize(const char *cmd)
{
    int i, fd0, fd1, fd2;
    pid_t pid;
    struct rlimit rl;
    struct sigaction sa;

    /* 
     * Clear file creation mask.
     */
    umask(0);

    /* 
     * Get maxium number of file descriptors.
     */
    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
        err_quit("%s: can't get file limit", cmd);
    }

    /* Become a session leader to lose controlling TTY.
     */
    if ((pid = fork()) < 0) {
        err_quit("%s: can't fork", cmd);
    } else if (pid != 0){  /* parent */
	printf("the parent process\n");
        exit(0);
    }

    printf("the child process\n");

    setsid();

    /*
     * Ensure future opens won't allocate controlling TTYs
     */
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGHUP, &sa, NULL) < 0) {
        err_quit("%s: can't ignore SIGHUP", cmd);
    }
    if ((pid = fork()) < 0) {
        err_quit("%s: can't fork", cmd);
    } else if (pid != 0) {   /* parent */
	printf("child parent process\n");
        exit(0);
    }

    printf("child child process\n");

    /* 
     * Change the current working directory to the root so we won't
     * prevent file systems from being unmounted.
     */
    if (chdir("/") < 0) {
        err_quit("%s: can't change directory to /", cmd);
    }

    /* 
     * Close all open file descriptions.
     */
    if (rl.rlim_max == RLIM_INFINITY) {
        rl.rlim_max = 1024;
    }
    for (i = 0; i < rl.rlim_max; i++) {
        close(i);
    }

    /* Attach file descriptions 0, 1, and 2 to /dev/null.
     */
    fd0 = open("/dev/null", O_RDWR);
    fd1 = dup(0);
    fd2 = dup(0);

    /*
     * Initialize the log file 
     */
    openlog(cmd, LOG_CONS, LOG_DAEMON);
    if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
	printf("child child process exit\n");
        syslog(LOG_ERR, "unexpected file descriptors %d %d %d", fd0, fd1, fd2);
        exit(1);
    }
    return;
}
