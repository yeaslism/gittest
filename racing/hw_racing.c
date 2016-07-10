#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "engine/engine2d.h"
#include "r_game.h"

char screen_buffer[8*8];

struct timespec work_timer;
double acc_tick,last_tick;

double rock_acc_tick;
double bomb_acc_tick;
int rock_xpos,rock_ypos;
int bomb_xpos,bomb_ypos;
int rock_pos_table[8] ={ 3,5,7,0,2,1,4,6 };
int bomb_pos_table[8] ={ 6,4,2,1,0,3,5,2 };
int rock_cur_table_index = 0;
int bomb_cur_table_index = 0;

int bLoop = 1;

int car_xpos,car_ypos;

static int nFSM = 0;
static int nStep = 0;

void rg_PlayGame(double delta_tick)
{
	switch(nStep)
	{
		case 0:
			nStep++;
			system("clear");
			break;
		case 1:
			//사용자 입력처리
			if(kbhit() != 0) {
				char ch = getch();
				if(ch == 'q') {
					bLoop = 0;
				}
				else if(ch == 'a'){
					car_xpos -= 1;
				}
				else if(ch == 'd'){
					car_xpos += 1;
				}
				else if(ch == 'w'){
					car_ypos -= 1;
				}
				else if(ch == 's'){
					car_ypos += 1;
				}

				//printf("%d \r\n",ch);

			}

			//바위 움직이기
			rock_acc_tick += delta_tick;
			if(rock_acc_tick > 0.5) {
				rock_acc_tick = 0;
				rock_ypos += 1;
				//화면 끝 도달
				if(rock_ypos >= 8) {
					rock_ypos = 0;
					rock_cur_table_index++;
					rock_cur_table_index %= 8;
					rock_xpos = rock_pos_table [ rock_cur_table_index];
				}
			}

			//폭탄 움직이기
			bomb_acc_tick += delta_tick;
			if(bomb_acc_tick > 0.7) {
				bomb_acc_tick = 0;
				bomb_ypos += 1;
				//화면 끝 도달
				if(bomb_ypos >= 8) {
					bomb_ypos = 0;
					bomb_cur_table_index++;
					bomb_cur_table_index %= 8;
					bomb_xpos = bomb_pos_table [ bomb_cur_table_index];
				}
			}


			//게임로직 판정
			if( (rock_ypos == car_ypos && rock_xpos == car_xpos) || (bomb_ypos == car_ypos && bomb_xpos == car_xpos))
			{
				//bLoop = 0;

				setColor(36,40);
				printf("\r\n- Game Over - \r\n");
				printf("\r\n재도전[Press 'p'] , 나가기[Press 'q'] \r\n");	

				char ch = getch();
				if(ch == 'p') {
					system("clear");
					bLoop = 1;
					nStep = 0;
					nFSM = 0;

					//버퍼 초기화
					for(int i=0;i<64;i++){
						screen_buffer[i] = 0;
					}

					set_conio_terminal_mode();

					acc_tick = last_tick = 0;
					system("clear");

					car_ypos = 7;
					car_xpos = 1;

					rock_ypos = 0;
					rock_xpos = rock_pos_table[ rock_cur_table_index ];

					bomb_ypos = 0;
					bomb_xpos = bomb_pos_table[ bomb_cur_table_index ];

				}
				else if(ch == 'q'){
					printf("Bye bye~ \r\n");
					setColor(0,0);
					bLoop = 0;
				}
			}

			//버퍼 초기화
			for(int i=0;i<64;i++){
				screen_buffer[i] = 0;
			}

			//자동차 그리기
			screen_buffer[car_ypos *8 + car_xpos] =2;

			//바위 그리기
			screen_buffer[ rock_ypos*8 + rock_xpos ] =1;		

			acc_tick += delta_tick;
			if(acc_tick > 0.1 | bLoop == 0){
				acc_tick =0;
				drawGame(8,8,screen_buffer);

			}

			//폭탄 그리기
			screen_buffer[ bomb_ypos*8 + bomb_xpos ] =3;		

			acc_tick += delta_tick;
			if(acc_tick > 0.1 | bLoop == 0){
				acc_tick =0;
				drawGame(8,8,screen_buffer);

			}
			break;
	
	}



}

void rg_apply_mainTitle()
{
	switch(nStep) {

		case 0:
			setColor(36,40);
			puts("- Press to start -");
			setColor(0,0);
			nStep = 1;
			break;
		case 1:
			//사용자 입력처리
			if(kbhit() != 0) {
				char ch = getch();
				nFSM =1;
				nStep = 0;
			}
			break;

	}
}

int main()
{
	//버퍼 초기화
	for(int i=0;i<64;i++){
		screen_buffer[i] = 0;
	}

	set_conio_terminal_mode();

	acc_tick = last_tick = 0;
	system("clear");

	car_ypos = 7;
	car_xpos = 3;

	rock_ypos = 0;
	rock_xpos = rock_pos_table[ rock_cur_table_index ];

	bomb_ypos = 0;
	bomb_xpos = bomb_pos_table[ bomb_cur_table_index ];

	while(bLoop) {

		//타이밍처리
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec +
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

		if(nFSM == 0) { //타이틀 메뉴 상태
			//puts("Press to start");
			rg_apply_mainTitle(delta_tick);
		}
		else if(nFSM == 1) { //게임 상태
			rg_PlayGame(delta_tick);
		}
		else {
		}
	}

	return 0;
}
