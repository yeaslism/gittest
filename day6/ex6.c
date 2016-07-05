#include <stdio.h>
#include <string.h>

int main()
{
	char *pStrCmd = "move position 123,56";

	char *ptr = strstr(pStrCmd,"position"); //"position"이 시작되는 곳부터 출력

	printf("%s \r\n",ptr);

	char pStrTemp[128];

	strncpy(pStrTemp,pStrCmd,4); //4번째까지 카피

	printf("%s \r\n",pStrTemp);

	char *pStrClone;

	pStrClone = strdup(pStrCmd);

	pStrClone[0]='a';
	/*pStrClone = pStrCmd;

	pStrCmd[1] = 'n';*/

	printf("%s \r\n",pStrClone);
	printf("%s \r\n",pStrCmd);


	return 0;
}
