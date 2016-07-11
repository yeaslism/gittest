#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char *m_szName;
	void *node[8];
} _S_AREA;

int main()
{
	_S_AREA town = {
		"town",
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
	};
	_S_AREA dungeon_1 = {
		"dungeon1",
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
	};
	_S_AREA dungeon_2 = {
		"dungeon2",
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
	};
	_S_AREA dungeon_3 = {
		"dungeon3",
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
	};


	town.node[0] = &dungeon_1;
	dungeon_1.node[0] = &town;
	dungeon_1.node[1] = &dungeon_2;
	dungeon_2.node[0] = &dungeon_1;
	dungeon_2.node[1] = &dungeon_3;
	dungeon_3.node[0] = &dungeon_2;

	
	_S_AREA *pCurrentArea = &town;

	int bLoop = 1;

	void setColor(int fore_color,int backg_color)
	{
		printf("%c[%d;%dm",0x1b,fore_color,backg_color);
	}

	system("clear");
	setColor(33,40);
	printf("***************************************\r\n");
	printf("  타운에 오신 것을 환영합니다.\r\n\r\n\r\n");
	printf("  현재 위치 확인하기 [Type 'look'] \r\n\r\n");
	printf("  이동하기 [Type ''move 이동장소'] \r\n");
	setColor(37,40);	
	printf("  town , dungeon1 , dungeon2, dungeon3 \r\n\r\n");
	setColor(33,40);
	printf("  끝내기 [Type 'exit'] \r\n");	
	printf("***************************************\r\n");
	setColor(0,0);


	while(bLoop) {
		char szCmd[32];
		gets(szCmd);
		char *pTemp = strtok(szCmd," ");

		if(!strcmp(pTemp,"look")) {
			setColor(33,40);
			printf("  - 당신은 %s 에 서있습니다. -\r\n",pCurrentArea->m_szName);
			setColor(0,0);
		}
		else if(!strcmp(pTemp,"move")) {
			char *pszArea = strtok(NULL,"");
			setColor(33,40);
			printf("  - 당신은 %s 으로 이동합니다. -\r\n",pszArea);
			setColor(0,0);
			for(int i=0;i<8;i++) {
				_S_AREA *pNode = pCurrentArea->node[i];
				if(pNode == NULL) break;
				//puts(pNode->m_szName);
				if(!strcmp(pNode->m_szName,pszArea)) {
					setColor(33,40);
					printf("  .......이동 성공! \r\n");
					setColor(0,0);
					pCurrentArea = pNode;
				}
			}
		}
		else if(!strcmp(pTemp,"exit")) {
			bLoop = 0;
		}

	}


}
