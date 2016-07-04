#include <stdio.h>
int main()
{

	int num[] = {3,7,15,6,8,2};

	printf("배열의 개수 : %d \r\n",sizeof(num)/sizeof(int));

	int sum = 0;
	int max = -99999;
	int min = 99999;

	for(int i=0;i < sizeof(num)/sizeof(int);i++){
		//sum = sum + num[i];
		sum += num[i];
		if(max < num[i]){
			max = num[i];
		}
		if(min > num[i]){
			min = num[i];
		}
	}



	printf("총 합 : %d \r\n",sum);

	printf("최대값 : %d \r\n",max);

	printf("최소값 : %d \r\n",min);

	return 0;
}
