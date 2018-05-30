#include "apue.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFSIZE 100000

ssize_t louisreadn(int fd, void *ptr, size_t n)
{
	printf("fd: %d\n", fd);
	size_t nleft = n;
	ssize_t nread = 0;

	/*lseek(fd, 0, SEEK_SET);*/	

	while(nleft > 0) {
		printf("nleft: %d\n", nleft);
		if((nread = read(fd, ptr, nleft)) < 0) {
			if(nleft == n) {
				printf("read error at first time: %s\n", strerror(errno));
				exit(-1);
			} else {
				printf("nleft != n: %d\n", nread);
				break;
			}
		} else if (nread == 0) {
			printf("nread == 0\n");
			break; /* EOF */
		}

		printf("nread: %d\n", nread);
		
		nleft -= nread;
		ptr += nread;
	}

	return (n - nleft);
}

int main(int argc, char **argv)
{
	int fin;
	char buf[BUFSIZE] = {0};

	fin = open(argv[1], O_RDWR);
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

	ssize_t nread = louisreadn(fin, buf, sizeof(buf));
	if (nread < 0) {
		printf("read error\n");
		exit(-1);
	}

	printf("read %d bytes success.\n", nread);

	offset = ftell(fp);
	printf("offset: %ld\n", offset);
	
	while(1){
	}

	return 0;
}
