#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
	char ch;
	while ((ch = getc(stdin)) != EOF) {
		printf("aaa ch: %d\n", ch);
		if (putc(ch, stdout) == EOF) {
			printf("putc error %s\n", strerror(errno));
			exit(-1);
		}
		printf("\n");
	}	

	if (ferror(stdin)) {
		printf("ferror error %s is set.\n", strerror(errno));
		exit(-1);
	}

	return 0;
}
