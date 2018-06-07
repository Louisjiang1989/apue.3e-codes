#include "apue.h"
#include <dirent.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		err_quit("usage: a.out dirname");
	}

	struct dirent *dr;
	DIR *dp = opendir(argv[1]);
	if (!dp) {
		err_quit("opendir error");
	}

	while ((dr = readdir(dp)) != NULL) {
		printf("dir: %s\n", dr->d_name);
	}

	exit(0);
}
