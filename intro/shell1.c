#include "apue.h"
#include <sys/wait.h>

int main()
{
	char buf[MAXLINE];
	pid_t pid;
	int status;
	
	printf("%% ");
	while (fgets(buf,  MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf)-1] == '\n') 
			buf[strlen(buf)-1] = 0;

		pid = fork();
		if (pid < 0)
			err_quit("fork error");
		else if (pid == 0) /*child*/ {
			execlp(buf, buf, NULL);
			printf("execlp error\n");
			exit(-1);
		}

		if ((pid = waitpid(pid, &status, 0) < 0)) 
			err_quit("waitpid error");
		printf("%% ");
	} 
	exit(0);
}
