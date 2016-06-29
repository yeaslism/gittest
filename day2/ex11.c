#include <stdio.h>

int main()
{
	
	char a = 0xff;
	unsigned char b = 0xff;
	printf("%d , %d \r\n",a,0x7f);
	a = 0x80;
	printf("%d , %d \r\n",a,0x80);
	a = 0xff;
	printf("%d , %d \r\n",a,0xff);

	printf("%d \r\n",b);

	return 0;
}

