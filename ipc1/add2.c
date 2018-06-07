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
			line[n] = 0;
			sprintf(line, "%d\n", int1 + int2);
			fprintf(stdout, "%s\n", line); 

		} else {
			err_quit("invalid args");
		}
		printf("%% ");
		fflush(stdout);
	}

	exit(0);
}
