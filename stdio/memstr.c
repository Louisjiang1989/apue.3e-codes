#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BSZ 48

int main()
{
	FILE *fp;
	char buf[BSZ];
	
	memset(buf, 'a', BSZ-2);
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';

	printf("before fmemopen buf: %s\n", buf);
	printf("BSZ: %d\n", BSZ);

	if ((fp = fmemopen(buf, BSZ, "w+")) == NULL) {
		printf("fmemopen error %s\n", strerror(errno));
		exit(-1);
	}
	
	printf("fp: %p\n", fp);
	fprintf(fp, "hello world");
	
	fclose(fp);
	
	printf("after fmemopen buf(%p): %s, strlen: %d\n", buf, buf, strlen(buf));

	return (0);
}

