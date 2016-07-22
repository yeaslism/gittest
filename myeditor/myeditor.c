#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myeditor.h"

typedef struct {
	char *m_szToken;
	void (*m_fp)();
} _S_PROC_OBJECT;

static char *pTemp;
static _S_STR_LINE *pHeader = NULL;

void _me_push();
void me_push();
void me_pop();
void me_delete();
void me_insert();
void me_rm();
void me_set();
void me_dump();
void me_readfile();
void me_writefile();

_S_PROC_OBJECT proc_objects[] = {
	{"push",me_push},
	{"pop",me_pop},
	{"del",me_delete},
	{"dump",me_dump},
	{"read",me_readfile},
	{"write",me_writefile}
};

void apply(char *szToken)
{
	for(int i=0;i< sizeof(proc_objects)/sizeof(_S_PROC_OBJECT);i++) {
		if( strcmp(proc_objects[i].m_szToken,szToken) == 0)
		{
			proc_objects[i].m_fp();
			break;
		}
	}
}

void me_writefile()
{
	char *szFileName = strtok(NULL,"");
	printf("write : %s \r\n",szFileName);	

	FILE *pfile = fopen(szFileName,"w");

	_S_STR_LINE *pLine = pHeader;

	while(pLine != NULL) {
		fputs(pLine->m_szStr,pfile);
		pLine = pLine->m_pNext;
	}

	fclose(pfile);
}

void me_readfile()
{
	char *szFileName = strtok(NULL,"");
	printf("read : %s \r\n",szFileName);	

	FILE *pfile = fopen(szFileName,"r");
	char szBuf[512];
	while(1) {
		if(fgets(szBuf,512,pfile) == NULL) break;
		//printf("%s",szBuf);
		_me_push(szBuf);
	}

	fclose(pfile);

}

void _me_push(char *szText)
{
	char *pstr = (char *)malloc(strlen(szText)+1);
	strcpy(pstr,szText);
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

void me_push()
{
	pTemp = strtok(NULL," ");
	_me_push(pTemp);	
}


void me_pop() //마지막줄 지우기
{
	_S_STR_LINE *pLine = pHeader;

	while(pLine != NULL) {
		/*if( ((_S_STR_LINE*)(pLine->m_pNext))->m_pNext == NULL) {
		  pLine->m_pNext = NULL;
		  }*/
		pLine = pLine->m_pNext;
		if(pLine != NULL) {
			_S_STR_LINE *pNextNext = pLine->m_pNext;
			if(pNextNext == NULL) {
				pHeader->m_pNext = NULL;
				pLine = NULL;
				//pLine->m_pNext = NULL;
			}
			else {
				if(pNextNext->m_pNext == NULL) {
					pLine->m_pNext = NULL;
				}
			}
		}
	}
}
void me_delete() //첫째줄 지우기
{
	_S_STR_LINE *_pGarbage = pHeader;
	pHeader = pHeader->m_pNext;

	free(_pGarbage->m_szStr);
	free(_pGarbage);
}

void me_insert()
{
	int nIndex = atoi(strtok(NULL," "));
	pTemp = strtok(NULL,"");
	printf("%d 째줄에  %s  추가 \r\n",nIndex+1,pTemp);	
	
}

void me_rm()
{

}

void me_set() //set 1 new string
{

}

void me_dump()
{
	puts("------------------------");
	_S_STR_LINE *pLine = pHeader;

	while(pLine != NULL) {
		puts(pLine->m_szStr);
		pLine = pLine->m_pNext;
	}

	puts("------------------------");

}

