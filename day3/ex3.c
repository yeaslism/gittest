#include <stdio.h>
int main()
{
	int i=0;

	while(i <= 100){
		printf("count = %d \r\n",i);
		i++; //i+=1
	}

	int d=10;

	while(d >= 0){
		printf("%d \r\n",d);
		d--;
	}


	
	return 0;
}
