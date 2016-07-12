#include <stdio.h>
#include <stdlib.h>
#include "../mapEditor/map.h"


void map_drawTile_trn(_S_MAP_OBJECT *pObj,int posx,int posy,_S_MAP_OBJECT *pTarget)
{
	for(int iy=0;iy < pObj->m_header.m_nHeight;iy++) {
		for(int ix=0;ix < pObj->m_header.m_nWidth;ix++) {
			map_PutTile(pTarget,ix + posx,iy + posy,pObj->m_pBuf[iy * pObj->m_header.m_nWidth + ix]);
		}
	}

}


int main()
{
	_S_MAP_OBJECT screenBuf;
	map_init(&screenBuf);
	map_new(&screenBuf,16,16);

	
	map_PutTile(&screenBuf,6,5,4);
	map_PutTile(&screenBuf,5,5,4);
	map_PutTile(&screenBuf,4,5,4);
	map_PutTile(&screenBuf,6,5,4);
	map_PutTile(&screenBuf,5,6,4);
	map_PutTile(&screenBuf,4,6,4);
	map_PutTile(&screenBuf,6,7,4);
	map_PutTile(&screenBuf,5,7,4);
	map_PutTile(&screenBuf,4,7,4);

	_S_MAP_OBJECT humanObj;map_init(&humanObj);map_load(&humanObj,"human.dat");
	puts("\r\n--------------------\r\n");
	//map_drawTile(&humanObj,5,5,&screenBuf);
	//map_drawTile_mirror_h(&humanObj,5,5,&screenBuf);
	//map_drawTile_mirror_v(&humanObj,5,5,&screenBuf);

	map_dump(&screenBuf,Default_TilePalette);


	return 0;
}
