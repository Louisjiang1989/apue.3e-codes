#include "apue.h"
#include <ctype.h>

int main()
{
	char c;
	while ((c = getchar()) != EOF) {
		if (isupper(c))
			c = tolower(c);

		putchar(c);

		if (c == '\n')
			fflush(stdout);
	} 

	exit(0);
}
