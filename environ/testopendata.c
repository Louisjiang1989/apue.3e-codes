#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
	char buf[BUFSIZ];

	FILE *fp = fopen("datafile", "r");
	if(fp == NULL) {
		printf("fopen datafile error %s\n", strerror(errno));
		exit(-1);
	}

	setbuf(fp, buf);
	if(errno != 0) {
		printf("setbuf error: %s\n", strerror(errno));
		exit(-1);
	}

	setvbuf(fp, buf, _IOLBF, BUFSIZ);

	return 0;
}	
