#include <stdio.h>

int main()
{
	
	double a=1.3;
	double b=1.7;
	double temp;

	double *pa,*pb;

	printf("바꾸기 전의 a,b의 값 : %f,%f \r\n",a,b);

	pa=&a;
	pb=&b;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
	

	/*temp = a;
	a = b;
	b = temp;*/

	printf("바꾼 후의 a,b의 값 : %f,%f \r\n",a,b);



	return 0;
}
