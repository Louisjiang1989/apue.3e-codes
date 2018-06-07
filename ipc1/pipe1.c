#include "apue.h"

int main()
{
	int fd[2];
	long i = 0;
	long j = 0;
	pid_t pid;

	if (pipe(fd) < 0) {
		err_quit("pipe error");
	}

	pid = fork();
	if (pid < 0)
		err_quit("fork error");
	else if (pid > 0) {
		close(fd[0]);

		while(1) {
			if (write(fd[1], "p", 1) != 1) 
				err_quit("parent process write error");
			
			printf("parent process write p i: %d\n", i++);
		}
	} else {
		close(fd[1]);
		char c;

		while(1) {
			if (read(fd[0], &c, 1) != 1)
				err_quit("child process read failed.");

			if (c != 'p')
				err_quit("child process read error %c", c);
	
			sleep(0.5);			
			printf("child process read %c j: %d\n", c, j++); 
		}
	
	}

	exit(0);
}
