#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include "../engine/engine2d.h"

typedef struct
{
	int m_nSkima;
	int m_nWidth;
	int m_nHeight;
}_S_MAP_HEADER;


typedef struct
{
	_S_MAP_HEADER m_header;
	char *m_pBuf;
}_S_MAP_OBJECT;

_S_MAP_OBJECT MapObject;
int main()
{
	int bLoop = 1;

	MapObject.m_header.m_nSkima = 1;
	MapObject.m_pBuf = NULL;
	char TilePalette[] = {'.','#','@','%'};

	while(bLoop)
	{
		char szCmd[32];
		gets(szCmd);
		char *pTemp = strtok(szCmd," ");
		if(!strcmp(pTemp,"exit")) {
			bLoop = 0;
			if ( MapObject.m_pBuf ) {
				free(MapObject.m_pBuf);
			}
		}

		else if(!strcmp(pTemp,"dump")) {
			putTile(
			0,MapObject.m_header.m_nHeight,
			0,MapObject.m_header.m_nWidth,
			MapObject.m_header.m_nWidth,
			MapObject.m_pBuf,
			TilePalette	
			);
		}
		else if(!strcmp(pTemp,"new")) {
			// new 8 4
			if(MapObject.m_pBuf !=NULL) {free(MapObject.m_pBuf);}
			MapObject.m_header.m_nWidth = atoi(strtok(NULL," "));
			MapObject.m_header.m_nHeight = atoi(strtok(NULL," "));
			MapObject.m_pBuf = malloc(
			MapObject.m_header.m_nHeight * MapObject.m_header.m_nWidth );

			for(int i=0;i <	MapObject.m_header.m_nHeight * MapObject.m_header.m_nWidth;i++) {
				MapObject.m_pBuf[i] = 0;
			}
		}
		else if(!strcmp(pTemp,"put")) {
			//put 1 2 1 (x y tile_index)
			int x,y,tile_index;

			MapObject.m_pBuf[] = tile_index;


		}




	}

	return 0;
}
