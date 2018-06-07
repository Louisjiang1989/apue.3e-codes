#include "apue.h"

int main()
{
	printf("the pid of the process: %ld\n", (long)getpid());
	sleep(10);
	exit(0);
}
