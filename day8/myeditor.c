#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myeditor.h"

int main()
{
	puts("MyEditor Version 1.0");

	_S_STR_LINE *pHeader = NULL;

	int bLoop = 1;
	while(bLoop)
	{
		char *pTemp;
		char strCmd[128];
		gets(strCmd);

		pTemp = strtok(strCmd," ");
		
		if(!strcmp(pTemp,"exit")) {
			bLoop = 0;
		}
		else if(!strcmp(pTemp,"push")) {
			pTemp = strtok(NULL," ");
			char *pstr = (char *)malloc(strlen(pTemp)+1);
			strcpy(pstr,pTemp);
			_S_STR_LINE *pLine = (_S_STR_LINE *)malloc(sizeof(_S_STR_LINE));
			pLine->m_szStr = pstr;
			pLine->m_pNext = NULL;
			if(pHeader ==NULL) {
				pHeader = pLine;
			}
			else {
			//끝까지 찾아 들어가기
				_S_STR_LINE *pNext = (_S_STR_LINE *)pHeader;
				
				while(pNext != NULL) {
					//마지막이라면-
					if(pNext->m_pNext == NULL){
						pNext->m_pNext = pLine;
						pNext = NULL;
					}
					else {	//더 있다면-
						pNext = pNext->m_pNext;
					}
				}
			}
		}
		else if(!strcmp(pTemp,"pop")) { //마지막줄 지우기
		}
		else if(!strcmp(pTemp,"del")) { //첫째줄 지우기

			_S_STR_LINE *_pGarbage = pHeader;
			pHeader = pHeader->m_pNext;

			free(_pGarbage->m_szStr);
			free(_pGarbage);
			
		}
		else if(!strcmp(pTemp,"ins")) {
			int nIndex = atoi(strtok(NULL," "));
			pTemp = strtok(NULL,"");
			printf("%d 째줄에  %s  추가 \r\n",nIndex+1,pTemp);	
		}
		else if(!strcmp(pTemp,"rm")) {
			int nIndex = atoi(strtok(NULL," "));
		}
		else if(!strcmp(pTemp,"set")) {
		
			int nIndex = atoi(strtok(NULL," "));
		}
		else if(!strcmp(pTemp,"dump")) {
			puts("------------------------");
			_S_STR_LINE *pLine = pHeader;

			while(pLine != NULL) {
				puts(pLine->m_szStr);
				pLine = pLine->m_pNext;
			}
		
			
			puts("------------------------");
		}

	}

	return 0;
}
