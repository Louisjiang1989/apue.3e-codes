#include "apue.h"

int main()
{
	char line[MAXLINE];
	int n;
	int int1, int2;

	printf("%% ");
	fflush(stdout);
	
	while ((n = read(STDIN_FILENO, line, MAXLINE)) > 0) {
		if (sscanf(line, "%d%d", &int1, &int2) == 2) {
			if (printf("%d\n", int1 + int2) == EOF) 
				err_quit("printf error");

		} else {
			if (printf("invalid args\n") == EOF)
				err_quit("printf error");
		}
		printf("%% ");
		fflush(stdout);
	}

	exit(0);
}
