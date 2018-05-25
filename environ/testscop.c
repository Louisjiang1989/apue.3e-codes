#include <stdio.h>

int f1(int val, int val2)
{
	printf("global &val: %p\n", &val);
	printf("global &val2: %p\n", &val2);	

	int num = 0;

	printf("global &num: %p\n", &num);
	
	int *ptr = &num;

	if(val < 0) {
		printf("input val: %d\n", val);
		
		int val;
		val = 5;
		printf("temp &val: %p\n", &val);
		ptr = &val;
		printf("tmp ptr: %p\n", ptr);
		printf("temp &ptr: %p\n", &ptr);
	}

	printf("global &ptr: %p\n", &ptr);

	return (*ptr + 1);
}

int main()
{
	int val = f1(-1, 1);
	printf("man val: %d\n", val);
	return 0;
}
