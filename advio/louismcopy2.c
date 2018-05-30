#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define G 1024*1024*1024
#define MAXCOPYSIZE 1*G

int main(int argc, char **argv)
{
	int fin, fout;
	void *src, *dst;
	size_t csize;
	struct stat st;
	off_t fsz = 0;
	
	fin = open(argv[1], O_RDONLY);
	if(fin < 0) {
		printf("open %s error %s\n", argv[1], strerror(errno));
		exit(-1);
	}

	if(fstat(fin, &st) < 0) {
		printf("fstat %s error %s\n", argv[1], strerror(errno));
		exit(-1);
	}

	fout = open(argv[2], O_CREAT | O_RDWR | O_TRUNC);	
	if(fout < 0) {
		printf("open %s error %s\n", argv[2], strerror(errno));
		exit(-1);
	}

	if(ftruncate(fout, st.st_size) < 0) {
		printf("ftruncate %s error %s\n", argv[2], strerror(errno));
		exit(-1);
	}

	printf("st.st_size: %d, fsz: %d\n", st.st_size, fsz); 	

	while(fsz < st.st_size) {
		printf("st.st_size: %d, fsz: %d, MAXCOPYSIZE: %d\n", st.st_size, fsz, MAXCOPYSIZE);
		if(st.st_size - fsz > MAXCOPYSIZE) {
			csize = MAXCOPYSIZE;
		} else {
			printf("st.st_size %d, fsz: %d\n", st.st_size, fsz);
			csize = st.st_size - fsz;
		}

		src = mmap(0, csize, PROT_READ, MAP_SHARED, fin, fsz);
		if(src == NULL) {
			printf("mmap %s error %s\n", argv[1], strerror(errno));
			exit(-1);
		}

		
		dst = mmap(0, csize, PROT_READ | PROT_WRITE, MAP_SHARED, fout, fsz);
		if(dst == NULL) {
			printf("mmap %s error %s\n", argv[2], strerror(errno));
			exit(-1);
		}

		memcpy(dst, src, csize);
		munmap(src, csize);
		munmap(dst, csize);

		fsz = fsz + csize;
	}
	
	return 0;
}
