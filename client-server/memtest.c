#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	void *p = malloc(3*(ssize_t)1024*(ssize_t)1024*(ssize_t)1024);
	
	if(p == NULL){
		printf("malloc error: %s %d\n", strerror(errno), errno);
		exit(-1);
	}
	return 0;
}
