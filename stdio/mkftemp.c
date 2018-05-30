#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

#define LEN 50

int louismkstemp(char *);

char template1[] = "/home/louis/apue/apue.3e-codes/stdio/template1XXXXXX";
char *template2 = "/home/louis/apue/apue.3e-codes/stdio/template2XXXXXX";

int main()
{
	int err;
	
	err = louismkstemp(template1);
	if (0 != err) {
		printf("louistmkstemp %s error %s\n", template1, strerror(errno));
		exit(-1);
	}

	err = louismkstemp(template2);
	if (0 != err) {
		printf("louismkstemp %s error %s\n", template2, strerror(errno));
		exit(-1);
	}

	return 0;
}

int louismkstemp(char *template)
{
	struct stat st;	

	int fd = mkstemp(template);
	if (fd == -1) {
		printf("mkstemp %s error %s\n", template, strerror(errno));
		return -1;
	}

	int err = fstat(fd, &st);
	if (err != 0) {
		if (errno == ENOENT) {	
			printf("%s is not exited.\n", template);
			return -1;
		}
	}

	return 0;
}
