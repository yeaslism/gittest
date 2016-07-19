#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <math.h>

#include "../engine/engine2d.h"
#include "../mapEditor/map.h"

#include "plane.h"
#include "bullet.h"
#include "alien.h"

struct timespec work_timer;
double acc_tick, last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuf[2];

_S_MAP_OBJECT gPlayerModel;
_S_MAP_OBJECT gBulletModel;
_S_MAP_OBJECT gPlayerBulletModel;
_S_MAP_OBJECT gAlienModel;

_S_Plane gPlayerObject;
_S_BULLET_OBJECT gBulletObject[32];
_S_BULLET_OBJECT gPlayerBulletObject[32];
_S_ALIEN_OBJECT gAlienObject[8];

double getDist(_S_BULLET_OBJECT *pBullet,_S_Plane *pPlane)
{
	double bullet_pos_x = pBullet->m_fXpos;
	double bullet_pos_y = pBullet->m_fYpos;

	double target_pos_x = pPlane->m_fXpos;
	double target_pos_y = pPlane->m_fYpos;

	double vx = target_pos_x - bullet_pos_x;
	double vy = target_pos_y - bullet_pos_y;
	double dist = sqrt(vx*vx+vy*vy);

	return dist;
}

int main()
{

	for(int i=0;i<3;i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],35,32);
	}

	map_init(&gPlayerModel);
	map_load(&gPlayerModel,"plane1.dat");

	map_init(&gPlayerBulletModel);
	map_load(&gPlayerBulletModel,"bullet1.dat");

	map_init(&gBulletModel);
	map_load(&gBulletModel,"plasma.dat");

	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");

	//double TablePosition[] = {0,6.0,12};
	double TablePosition_x[] = {0,25,12};
	double TablePosition_y[] = {2,7,15};

	Plane_init(&gPlayerObject,&gPlayerModel,17,30);
	gPlayerObject.m_nFSM = 1;

	for (int i=0;i<3;i++)
	{
		_S_BULLET_OBJECT *pObj = &gBulletObject[i];
		bullet_init(pObj,0,0,0,&gBulletModel);
		pObj->m_nFSM = 1;
	}

	for (int i=0;i<sizeof(gPlayerBulletObject)/sizeof(_S_BULLET_OBJECT);i++)
	{
		bullet_init(&gPlayerBulletObject[i],0,0,0,&gPlayerBulletModel);
	}

	for (int i=0;i<3;i++)
	{
		_S_ALIEN_OBJECT *pObj = &gAlienObject[i];
		alien_init(pObj,&gAlienModel);
		//pObj->m_fXpos = TablePosition[i];
		//pObj->m_fYpos = 2;
		pObj->m_fXpos = TablePosition_x[i];
		pObj->m_fYpos = TablePosition_y[i];
		pObj->m_nFSM = 1;

		gAlienObject[i].m_pBullet = &gBulletObject[i];
	}

	system("clear");

	set_conio_terminal_mode();
	acc_tick=last_tick=0;

	while(bLoop) {
		//타이밍처리
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec +
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		//실시간 입력
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("Bye~ \r");
			}
			else if(ch == 'j') {
				for (int i=0;i<sizeof(gPlayerBulletObject)/sizeof(_S_BULLET_OBJECT);i++) {
					_S_BULLET_OBJECT *pObj = &gPlayerBulletObject[i];
					if(pObj->m_nFSM == 0) {
						pObj->pfFire(pObj,0,0,10,0,0,5.0);
						break;
					}
				}
	
			}


			gPlayerObject.pfApply(&gPlayerObject,delta_tick,ch);
		}

		for (int i=0;i<3;i++) 
		{
			_S_ALIEN_OBJECT *pObj = &gAlienObject[i];
			pObj->pfApply(pObj,delta_tick);
		}

		for (int i=0;i<3;i++)
		{
			_S_BULLET_OBJECT *pObj = &gBulletObject[i];
			pObj->pfApply(pObj,delta_tick);
		}

		for(int i=0;i<3;i++)
		{
			_S_BULLET_OBJECT *pObj = &gBulletObject[i];
			if(pObj->m_nFSM != 0) {
				double dist = getDist(pObj,&gPlayerObject);

				if(dist < 0.25) {  //비행기랑 충돌하면 총알 sleep상태
					pObj->m_nFSM = 0;
					gPlayerObject.m_nFSM = 0;
					printf("\r\n - Gave Over - \r\n");
					bLoop = 0;
				}

			}
		}

		//타이밍 계산
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);
			gPlayerObject.pfDraw(&gPlayerObject,&gScreenBuf[1]);

			for(int i=0;i<3;i++) 
			{
				_S_ALIEN_OBJECT *pObj = &gAlienObject[i];
				pObj->pfDraw(pObj,&gScreenBuf[1]);
			}

			for(int i=0;i<3;i++) 
			{
				_S_BULLET_OBJECT *pObj = &gBulletObject[i];
				pObj->pfDraw(pObj,&gScreenBuf[1]);
			}


			map_dump(&gScreenBuf[1],Default_TilePalette);
			acc_tick = 0;
		}

	}

	return 0;

}
