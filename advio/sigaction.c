#include "apue.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

void sig_handler(int signum)
{
	printf("receive signal %d\n", signum);
}

int main()
{
	/*struct sigaction act, oldact;*/
	sigset_t act, oldact;
	sigset_t zeromask;

	/*act.sa_handler = sig_handler;
	act.sa_flags = 0;

	if(sigaction(SIGUSR1, &act, &oldact) < 0) {
		printf("sigaction error %s\n", strerror(errno));
		exit(-1);
	}*/

	printf("signal call before\n");

	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);

	printf("signal call over\n");

	sigemptyset(&act);
	sigemptyset(&oldact);
	sigemptyset(&zeromask);

	/*sigaddset(&zeromask, SIGUSR2);*/
	sigsuspend(&zeromask); /*这里收到一个非阻塞的信号之后就向下执行，否则就在这挂起，等待接受信号。*/

	printf("signal sigsuspend over1\n");

	sigsuspend(&zeromask);

	printf("signal sigsuspend over2\n");

	sleep(200); 

	return 0;
}
