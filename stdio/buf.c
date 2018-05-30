#include "apue.h"

/* http://blog.chinaunix.net/uid-26833883-id-3198114.html */

int pr_stdio(const char *, FILE *);
int is_unbuffered(FILE *);
int is_linebuffered(FILE *);
int buff_size(FILE *);

int main()
{
	char buf[MAXLINE];

	fgets(buf, MAXLINE, stdin);
	fputs(buf, stdout);
	fputs("bbbbbbbbbbbb\n", stderr);
	
	pr_stdio("stdin", stdin);
	pr_stdio("stdout", stdout);
	pr_stdio("stderr", stderr);

	FILE *fp = fopen("/etc/passwd", "r");
	getc(fp);
	pr_stdio("/etc/passwd", fp);
	
	return 0;
}

int pr_stdio(const char *name, FILE *fp)
{
	printf("%s", name);
	if (is_unbuffered(fp)) {
		printf(" is unbuffered.");
	} else if (is_linebuffered(fp)) {
		printf(" is line buffered.");
	} else {
		printf(" fully buffered.");
	}

	printf(", buffer size: %d\n", buff_size(fp));
	return 0;
}

int is_unbuffered(FILE *fp)
{
	return (fp->_flags & _IO_UNBUFFERED);
}

int is_linebuffered(FILE *fp)
{
	return (fp->_flags & _IO_LINE_BUF);
}

int buff_size(FILE* fp)
{
	return (fp->_IO_buf_end - fp->_IO_buf_base);
}

