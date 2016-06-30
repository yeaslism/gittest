#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"

int main()
{
	int bLoop = 1;
	char cmd;
	int xpos,ypos;
	xpos=1;ypos=1;	

	while(bLoop) {	
		scanf("%c", &cmd);
		switch(cmd) {
			
			case 'l':
			xpos-=1;
			break;

			case 'r':
			xpos+=1;
			break;
			
			case 'u':
			ypos -=1;
			break;

			case 'd':
			ypos+=1;
			break;

			case 'q':
			bLoop = 0;
			break;
		
		}

		system("clear");
		drawMyBox(xpos,ypos,41,2);
		gotoxy(0,20);
		printf("------------------");

	printf("%d,%d \r"),xpos,ypos;


	}



	//drawMyBox(2,2,41);

	return 0;
}
