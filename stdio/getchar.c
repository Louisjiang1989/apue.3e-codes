#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	while ((c = getchar()) != EOF) {
		printf("\n|||\n");
		putchar(c);
		printf("\n|||\n");
	}
	
	return 0;
}
