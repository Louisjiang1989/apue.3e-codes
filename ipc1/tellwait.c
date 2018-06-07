#include "apue.h"

static int pfd1[2], pfd2[2];

void TELL_WAIT()
{
	if (pipe(pfd1) < 0 || pipe(pfd2)) 
		err_quit("pipe error");
}

void TELL_CHILD(pid_t pid)
{
	if (write(pfd1[1], "c", 1) != 1) 
		err_quit("write pfd1[1] error");
}

void TELL_PARENT(pid_t pid)
{
	if (write(pfd2[1], "p", 1) != 1)
		err_quit("write pfd2[1] error");
}

void WAIT_CHILD()
{
	char c;
	if (read(pfd1[0], &c, 1) != 1) 
		err_quit("read pfd1[0] failed"); 

	if (c != 'c')
		err_quit("read pfd1[0] error");
}

void WAIT_PARENT()
{
	char c;
	if (read(pfd2[0], &c, 1) != 1)
		err_quit("read pfd2[0] failed");

	if (c != 'p')
		err_quit("read pfd2[0] error");
}

