#include <stdio.h>
#include <math.h>

int main()
{
	printf("%f \r\n",sqrt(2.0));

	double vx,vy;
	vx = 1.0;
	vy = 1.0;

	double vlength = sqrt((vx*vx)+(vy*vy));

	printf("벡터의 길이(1,1) : %f \r\n",vlength);

	vx / = vlength;
	vy / = vlength;

	printf("단위 벡터 : %f,%f \r\n",vx,vy);

	vlength = sqrt(vx*vx + vy*vy);

	printf("벡터의 길이 : %f \r\n",vlength);

	return 0;
}
