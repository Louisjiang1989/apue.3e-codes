#include "../include/apue.h"
#include <setjmp.h>

int main()
{
	int v1, v2, v3, v4 = 1;
	
	int set_value;
	jmp_buf buf;
	if(set_value = setjmp(buf) != 0){
		printf("louistestjmp value: %d\n", set_value);
		printf("main1 v1(%d) v2(%d) v3(%d) v4(%d)\n", v1, v2, v3, v4); 
		exit(0);
	}

	v1 = 2;
	v2 = 3;
	v3 = 4;
	v4 = 5;
	printf("main2 v1(%d) v2(%d) v3(%d) v4(%d)\n", v1, v2, v3, v4);

	longjmp(buf, 1);
	
	return 0;
}

