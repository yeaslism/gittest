#include <stdio.h>
#include <stdlib.h>

void setColor(int fore_color,int backg_color)
{
	printf("%c[%d;%dm",0x1b,fore_color,backg_color);
}

void gotoxy(int x, int y)
{
	printf("%c[%d;%df",0x1b,y,x);

}

int main()
{
	int fore_color;
	fore_color = 31;
	system("clear");

	gotoxy(28,3);

	setColor(33,44);
	printf("hello");

	gotoxy(28,5);

	setColor(30,43);
	printf("world");

	setColor(0,0);

	gotoxy(20,1);
	printf("*");

	gotoxy(20,2);
	printf("*");

	gotoxy(20,3);
	printf("*");
	
	gotoxy(20,4);
	printf("*");

	gotoxy(20,5);
	printf("*");

	gotoxy(20,6);
	printf("*");

	gotoxy(20,7);
	printf("*");

	gotoxy(20,7);
	printf("*");

	gotoxy(20,8);
	printf("*");

	gotoxy(20,9);
	printf("*");

	gotoxy(20,10);
	printf("*");

	gotoxy(20,11);
	printf("*");

	gotoxy(20,12);
	printf("*");




	gotoxy(40,1);
	printf("*");

	gotoxy(40,2);
	printf("*");

	gotoxy(40,3);
	printf("*");

	gotoxy(40,4);
	printf("*");

	gotoxy(40,5);
	printf("*");

	gotoxy(40,6);
	printf("*");

	gotoxy(40,7);
	printf("*");

	gotoxy(40,8);
	printf("*");

	gotoxy(40,9);
	printf("*");

	gotoxy(40,10);
	printf("*");

	gotoxy(40,11);
	printf("*");

	gotoxy(40,12);
	printf("*");


	setColor(32,40);

	gotoxy(25,6);
	printf("((");

	gotoxy(26,7);
	printf("))");

	gotoxy(25,8);
	printf("((");

	gotoxy(26,9);
	printf("))");
	
	gotoxy(25,10);
	printf("((");

	gotoxy(26,11);
	printf("))");

	setColor(36,40);
	
	gotoxy(31,8);
	printf("<'))))<");

	setColor(0,0);

	gotoxy(21,12);
	printf("-------------------");
	return 0;
}
