#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 500000

char buf[BUFSIZE] = {0};

int main()
{
	ssize_t rsize = 0;
	ssize_t tmpwsize = 0;
	
	rsize = read(STDIN_FILENO, buf, sizeof(buf));
	fprintf(stderr, "%d bytes read\n", rsize);

	while(rsize > 0) {
		tmpwsize = write(STDOUT_FILENO, buf, rsize);

		if(tmpwsize > 0) {
			rsize -= tmpwsize;
		}

		fprintf(stderr, "%d bytes write\n", tmpwsize);
	}

	return 0;
}
