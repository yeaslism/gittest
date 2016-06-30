#include <stdio.h>

int main()
{
	int a,b;

	a=2;
	b=1;

	while(b <= 9) {

		printf(" %d * %d = %d \r\n",a,b,a*b);
		b += 2; //b++; 1씩 증가,
	 			//b += 2; 2씩 증가
	
	}

	int c;

	c=1;

	while(c<=100){
		printf("%d \r\n",c);
		c++;
	}

}
