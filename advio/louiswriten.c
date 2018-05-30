#include "apue.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFSIZE 100000

ssize_t louiswriten(int fd, void *ptr, size_t n)
{
	printf("fd: %d\n", fd);
	size_t nleft = n;
	ssize_t nwrite = 0;

	/*lseek(fd, 0, SEEK_SET);*/	

	while(nleft > 0) {
		printf("nleft: %d\n", nleft);
		if((nwrite = write(fd, ptr, nleft)) < 0) {
			if(nleft == n) {
				printf("write error at first time: %s\n", strerror(errno));
				exit(-1);
			} else {
				printf("nleft != n: %d\n", nwrite);
				break;
			}
		} else if (nwrite == 0) {
			printf("nwrite == 0\n");
			break; /* EOF */
		}

		printf("nwrite: %d\n", nwrite);
		
		nleft -= nwrite;
		ptr += nwrite;
	}

	return (n - nleft);
}

int main(int argc, char **argv)
{
	int fin;
	char buf[BUFSIZE] = {0};

	fin = open(argv[1], O_CREAT | O_RDWR);
	if (fin < 0) {
		printf("open %s error %s\n", argv[1], strerror(errno));
		exit(-1);
	}

	
	FILE *fp = fdopen(fin, "w+");
	if(fp == NULL) {
		printf("fdopen error %s\n", strerror(errno));
		exit(-1);
	}

	long offset = ftell(fp);

	
	printf("offset: %ld\n", offset);

	strcpy(buf, "hello world\n");

	ssize_t nwrite = louiswriten(fin, buf, sizeof(buf));
	if (nwrite < 0) {
		printf("write error\n");
		exit(-1);
	}

	printf("write %d bytes success.\n", nwrite);

	offset = ftell(fp);
	printf("offset: %ld\n", offset);
	
	while(1){
	}

	return 0;
}
