#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <aio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define BSZ 4096
#define NBUF 8

enum rwop {
	UNUSED = 0,
	READ_PENDING = 1,
	WRITE_PENDING = 2
};

struct buf {
	enum rwop op;
	int last;
	struct aiocb aiocb;
	unsigned char data[BSZ];
};


struct buf bufs[NBUF];

void translate(unsigned char *data) 
{
	return;
}

int main(int argc, char **argv)
{
	int ifd, ofd, i, n, err;
	unsigned char databuf[BSZ] = {0};
	struct stat st;
	off_t offset = 0;
	ssize_t sz = 0;
	int numop = 0;
	const struct aiocb* aiocblist[NBUF];

	if(argc != 3) {
		printf("usage: a.out src-file dst-file\n");
		exit(-1);
	}

	ifd = open(argv[1], O_RDONLY);
	if(ifd < 0) {
		printf("open %s error %s\n", argv[1], strerror(errno));
		exit(-1);
	}

	if (fstat(ifd, &st) < 0) {
		printf("fstat %s error %s\n", argv[1], strerror(errno));
		exit(-1);
	}
	
	ofd = open(argv[2], O_CREAT | O_RDWR);
	if(ofd < 0) {
		printf("open %s error %s\n", argv[2], strerror(errno));
		exit(-1);
	}

	for (i=0; i<NBUF; i++) {
		bufs[i].op = UNUSED;
		bufs[i].last = 0;
		bufs[i].aiocb.aio_buf = bufs[i].data;
		bufs[i].aiocb.aio_sigevent.sigev_notify = SIGEV_NONE;
		aiocblist[i] = NULL;
	}	

	for (;;) {
		for (i=0; i<NBUF; i++) {
			switch(bufs[i].op) {
			case UNUSED:
				printf("UNUSED case\n");
				if (offset < st.st_size) {
					bufs[i].op = READ_PENDING;
					bufs[i].aiocb.aio_fildes = ifd;
					bufs[i].aiocb.aio_offset = offset;
					bufs[i].aiocb.aio_buf = bufs[i].data;
					offset += BSZ;
					bufs[i].aiocb.aio_nbytes = BSZ;
					
					if (offset > st.st_size) {
						bufs[i].last = 1;
					}				

					if(aio_read(&bufs[i].aiocb) < 0) {
						printf("aio_read error %s\n", strerror(errno));
						exit(-1);
					}
						
					aiocblist[i] = &bufs[i].aiocb;	
					printf("numop ++ start\n");
					numop++;
					printf("numop -- over\n");
				}
				break;
			case READ_PENDING:
				printf("READ_PENDING case\n");
				err = aio_error(&bufs[i].aiocb);
				if (err == EINPROGRESS) {
					printf("aio read request has not been completed.\n");
					continue;
				} else if (err != 0) {
					printf("aio read request failed %s\n", strerror(errno));
					exit(-1);
				}
				
				sz = aio_return(&bufs[i].aiocb);
				if (sz < 0) {
					printf("aio return error %s\n", strerror(errno));
					exit(-1);
				}

				if (sz != BSZ && !bufs[i].last) {
					printf("short read return error %s\n", strerror(errno));
					exit(-1);
				}
				
				translate(bufs[i].data);
				
				bufs[i].aiocb.aio_fildes = ofd;
				bufs[i].aiocb.aio_nbytes = sz;			

				err = aio_write(&bufs[i].aiocb);
				if (err != 0) {		
					printf("aio write request error %s\n", strerror(errno));
					exit(-1);
				}

				bufs[i].op = WRITE_PENDING;
				break;
			case WRITE_PENDING:
				printf("WRITE_PENDING case\n");
				err = aio_error(&bufs[i].aiocb);
				if (err == EINPROGRESS) {		
					printf("aio write error %s\n", strerror(errno));
					continue;
				} else if (err != 0) {
					printf("aio write error %s\n", strerror(errno));
					exit(-1);
				}

				ssize_t wsz = aio_return(&bufs[i].aiocb);
				if (wsz < 0) {
					printf("aio write return error %s\n", strerror(errno));
					exit(-1);
				}

				if (wsz != sz) {
					printf("short write %d %d\n", sz, wsz);
					exit(-1); 
				}
					
				bufs[i].op = UNUSED;
				aiocblist[i] = NULL;
				printf("numop -- start\n");
				numop--;
				printf("numop -- over\n");
				break;
			}		
		}

		printf("out of NBUF\n");
		if (numop == 0) {
			printf("numop == 0\n");
			if (offset >= st.st_size) {
				printf("offset: %d, st.st_size: %d\n", offset, st.st_size);
				break;
			}
		} else {
			printf("numop: %d\n", numop);
			err = aio_suspend(aiocblist, NBUF, NULL);
			if (err != 0) {
				printf("aio suspend error %s\n", strerror(errno));
				exit(-1);
			}
		}
	}

	bufs[0].aiocb.aio_fildes = ofd;
	err = aio_fsync(O_SYNC, &bufs[0].aiocb);
	if (err != 0) {
		printf("fsync %s error %s\n", argv[2], strerror(errno));
		exit(-1);
	}

	return 0;
}
