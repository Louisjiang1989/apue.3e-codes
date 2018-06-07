#include "apue.h"
#include <sys/wait.h>

#define DEF_BIN "/bin/more" 

int main(int argc, char **argv)
{
	int fd[2], n;
	pid_t pid;
	FILE *fp;
	char line[MAXLINE];
	char *argv0;

	if (argc != 2)
		err_quit("a.out filename");

	if (pipe(fd) < 0)
		err_quit("pipe error");

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		err_quit("open error");

	pid = fork();
	if (pid < 0)
		err_quit("fork error");
	else if (pid > 0) {
		/* parent */
		close(fd[0]);
		
		while (fgets(line, MAXLINE, fp)) {
			n = strlen(line);

			if (write(STDIN_FILENO, line, n) != n)
				err_quit("write error");
		}

		int status;

		if (waitpid(pid, &status, 0) < 0)
			err_quit("waitpid error");
		
		exit(0);
	} else {
		close(fd[1]);

		if (fd[0] != STDIN_FILENO) {
			if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO) {
				err_quit("dup2 STDIN_FILENO error");
			}
		}

		argv0 = strrchr(DEF_BIN, '/');
		execl(DEF_BIN, argv0, (char *)0);
		err_quit("execlp error");
	}

	exit(0);
}
