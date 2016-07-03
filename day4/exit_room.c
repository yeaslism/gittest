#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"
#include "exit_room.h"

/*
 
 1: 벽 #
 2: 열린문 M
 3: 게이머 A
 4: 잠긴문 m
 5: 키 K

 */


int world_map[] = {
	1,1,1,1,1,1,1,1,
	1,0,1,0,0,0,0,1,
	1,0,1,1,0,0,0,1,
	1,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,1,
	4,0,0,0,5,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

int world_map2[] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,5,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,4,
	1,1,1,0,0,0,0,1,
	1,0,0,1,0,0,0,1,
	1,0,0,1,0,0,0,1,
	1,1,1,1,1,1,1,1

};

int game_version = 1;
char *game_name = "방탈출 게임";

int player_inven; // 0:없음, 1:키 보유

int main()
{
	char cmd;
	int bLoop = 1;

	while(bLoop) {

		switch(nFSM) {
			case 0:
				printf("%s의 세계에 오신걸 환영합니다. v. %d \r\n",game_name,game_version);
				printf("게임을 시작할까요? \r\n 시작[p], 나가기[x]\r\n");
				//printf("select => [p,x] \r\n");
				break;
			case 1:
				printf("명령을 선택하세요, \r\n\
	i(up),j(left),k(right), \r\n\
	m(down),s(show map),x(exit)\r\n");
				break;
			case 2://미션클리어
				printf("\r\n다음 스테이지로 가겠습니까? \r\n 다음 스테이지[y] \r\n 그만두기[n]");
				break;

				}


		//버퍼 초기화
		for(int i=0;i<64;i++) {
			buffer_map[i] = world_map[i];
		}

		scanf("%c",&cmd);
		getchar();

		if(nFSM == 0) {
			switch(cmd) {
				case 'p': //게임 스타트
					nFSM =1;
					player_ypos = 5;
					player_xpos = 1;

					key_ypos = 5;
					key_xpos = 4;
					
					door_ypos = 5;
					door_xpos = 0;

					printf("게임을 시작합니다.");
					break;
				case 'x':
					bLoop = 0;
					break;
			}
		}

		else if(nFSM == 1 ) { //게임 플레이중
			move_player(cmd);

			switch(cmd) {
				case 's':
					map_drawAll(buffer_map);
					break;
				case 'x':
					bLoop = 0;
					printf("Bye bye~ \r\n");
					break;
			}
		}
		else if(nFSM == 2){
			switch(cmd) {
				case 'y':
					map_drawAll(world_map2);	
					break;
				case 'n':
					bLoop=0;
					printf("Bye bye~ \r\n");
					break;
			}

			//nFSM = 3;

		}

	}


	return 0;
}
