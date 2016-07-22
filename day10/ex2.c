#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "../engine/engine2d.h"


char pstr[] = {
	0,0,0,1,0,0,0,0,
	0,0,0,1,0,0,0,0,
	0,0,0,1,0,0,0,0,
	0,0,0,1,0,0,0,0,
	0,0,1,0,0,0,0,0,
	0,0,1,0,0,0,0,0,
	0,0,1,0,0,0,0,0,
	0,1,0,0,0,0,1,0,
	0,1,0,0,0,1,1,0,
	0,1,0,0,1,1,1,0
};

/*int main()
{
	int ix,iy;
	for(iy=0;iy<11;iy++) {
		for(ix=0;ix<8;ix++) {
			if(pstr[ (iy*8)+ix ] == 0) {
				putchar('.');
			}
			else {
				putchar('@');
			}
		}
		puts("");
	}*/


void putTile(int sy,int ey,int sx,int ex,int width,char *ptrBuf)
{
	int ix,iy;
	for(iy=sy;iy<ey;iy++) {
		for(ix=sx;ix<ex;ix++) {
			if(pstr[ (iy*width)+ix ] == 0) {
				putchar('.');
			}
			else {
				putchar('@');
			}
		}
		printf("\r\n"); //puts("");
	}
}

struct timespec work_timer;
double acc_tick,last_tick;
int nCount = 0;
int main()
{
	set_conio_terminal_mode();
	acc_tick = 0;
	last_tick = 0;
	//putTile(2,6,0,4,pstr);
	int bLoop = 1;
	while(bLoop) {
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
			}
		}

		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec +
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		acc_tick += delta_tick;
		if(acc_tick > 1.0) {
			acc_tick = 0;
			nCount++;
			putTile(nCount,nCount+4,0,8,8,pstr);
			//printf("%d \r\n",nCount);

		}

	}
}




