#include "apue.h"
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
	int n;
	int i = 1;
	int fd;
	char buf[BUFSIZE];

	if (argc != 2) 
		err_quit("mycat filename");

	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		err_quit("open file failed.");

	while ((n = read(fd, buf, BUFSIZE)) > 0) {
		printf("read at %d time\n", i++);
		if ((write(STDOUT_FILENO, buf, n)) != n) 
			err_quit("write error"); 
	}

	if (n < 0)
		err_quit("read error");

	exit(0);
}
