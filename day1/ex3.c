
#include <stdio.h>

int main()
{
	printf("hello \r\n");
	
	printf("\x1b[31m");
	printf("hello \r\n");
	
	printf("\x1b[1;31m");
	printf("hello\r\n");
	
	printf("\x1b[0m");

	printf("\x1b[33m");
	printf("hello\r\n");

	printf("\x1b[32m");
	printf("hello\r\n");

	printf("\x1b[36m");
	printf("hello\r\n");

	printf("\x1b[34m");
	printf("hello\r\n");

	printf("\x1b[35m");
	printf("hello\r\n");
	
	

	return 0;

}

