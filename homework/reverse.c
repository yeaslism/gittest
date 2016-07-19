#include <stdio.h>
#include <string.h>

void reverse(char array[])
{
	int i;
	for(i=strlen(array)-2;i>=0;i--) {
		printf("%d ",array[i]);
	}
}

int main()
{
	char array[] = {1,2,3,4,5};

	int size = strlen(array);
		for(int i=0;i<size;i++) {
		printf("%d ",array[i]);
	}

	printf("\r\n");

	reverse(array);

	return 0;
}
