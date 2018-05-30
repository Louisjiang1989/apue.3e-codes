#include "apue.h"
#include <errno.h>
#include <string.h>

int main()
{
	char buf[MAXLINE];
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		printf("|||\n");
		if (fputs(buf, stdout) == EOF) {
			printf("fputs error %s\n", strerror(errno));
			exit(-1);
		}
		printf("\n||||\n");
	}

	return 0;
}
