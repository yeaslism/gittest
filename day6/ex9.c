#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//add 10,20
	//sub 5,2
	//mul 4,3
	//div 8,2

	char strCmd[128];

	
	gets(strCmd);
	//scanf("%s",strCmd);


	char *ptrTemp;
	char *pCmd;
	int a,b;

	ptrTemp = strtok(strCmd," ");

	pCmd = strdup(ptrTemp);

	a = atoi( strtok(NULL,",") );
	b = atoi( strtok(NULL,",") );

	if(strcmp(pCmd,"add") == 0) {	
		printf("%d + %d = %d \r\n",a,b,a+b);
	}
	else if(strcmp(pCmd,"sub") == 0) {
		printf("%d - %d = %d \r\n",a,b,a-b);
	}
	else if(strcmp(pCmd,"mul") == 0) {
		printf("%d * %d = %d \r\n",a,b,a*b);
	}
	else if(strcmp(pCmd,"div") == 0) {
		printf("%d / %d = %d \r\n",a,b,a/b);
	}





	return 0;
}
