#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"

void drawMyBox(int xpos,int ypos,int color)
{	
	int ix,iy;
	ix=1;
	iy=1;

	setColor(30,color);
	while(ix <= 6) {
		iy=1;
		while(iy <= 2){
			
			gotoxy(ix+xpos,iy+ypos);
			printf(" ");
			iy++;
		
		}
		ix++;


	}
	setColor(0,0);

}


int main()
{
	system("clear");


	drawMyBox(1,2,42);
	
	drawMyBox(5,3,41);

	setColor(30,44);
	gotoxy(0,20);
	printf("                                       ");
	setColor(0,0);


	return 0;
}
