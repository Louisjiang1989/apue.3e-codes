#include "apue.h"

static void signal_quit();

int main()
{
	int c;

	if (signal(SIGQUIT, signal_quit) == SIG_ERR) 
		err_quit("signal error");

	while ((c = fgetc(stdin)) != EOF) {
		if (fputc(c, stdout) == EOF) 
			err_quit("fputc error");
	}

	if (ferror(stdin)) 
		err_quit("fgetc error");

	exit(0);
}

void signal_quit()
{
	err_quit("receive signal SIGQUIT");
}
