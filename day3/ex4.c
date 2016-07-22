#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"

int main()
{
	system("clear");

	int i=0;
	int x=20;
	

	while(i<20) {
		gotoxy(10,i);	
		printf("+");
		i++;

		gotoxy(i,10);
		printf("+");
		i++;

		gotoxy(i+20,i);
		printf("x");
		
		gotoxy(x+20,i);
		printf("x");	
		x-=2;
	}

	gotoxy(0,20);
	printf("====================");
	return 0;
}
