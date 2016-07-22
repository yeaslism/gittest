#include <stdio.h>

int main()
{
	int num[] = {3,6,5,5,7};
	int *pNum = num;

	int sum = 0;

	int max = -99999;
	int min = 99999;


	printf("%d , %d \r\n",*(pNum+1),num[1]);

	for(int i=0;i<sizeof(num)/sizeof(int);i++)
	{
		printf("%d , ",*(pNum+i));

		sum += *(pNum+i);

		if (max < *(pNum+i)){
			max = *(pNum+i);
		}
		if (min > *(pNum+i)){
			min = *(pNum+i);
		}



	}

	printf("\r\n 총 합: %d \r\n",sum);

	printf("최대값 : %d \r\n", max);

	printf("최소값 : %d \r\n", min);





	return 0;

}
