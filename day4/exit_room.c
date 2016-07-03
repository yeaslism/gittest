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
				setColor(36,40);
				printf("%s의 세계에 오신걸 환영합니다. v. %d \r\n",game_name,game_version);
				printf("\r\n게임을 시작할까요? \r\n 시작[p], 나가기[x]\r\n");
				setColor(0,0);
				//printf("select => [p,x] \r\n");
				break;
			case 1:
				setColor(36,40);
				printf("\r\n명령을 선택하세요. \r\n\
 위[i],왼쪽[j],오른쪽[k], \r\n\
 아래[m],맵 보기[s],나가기[x]\r\n");
				setColor(0,0);
				break;
			case 2://미션클리어
				setColor(36,40);
				printf("\r\n다음 스테이지로 가겠습니까? \r\n 예[y] \r\n 아니오[n] \r\n");
				setColor(0,0);
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

					printf("게임을 시작합니다.\r\n");
					break;
				case 'x':
					bLoop = 0;
					printf("다음에 또 봐요~ \r\n");
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
					printf("다음에 또 봐요~ \r\n");
					break;
			}
		}
		else if(nFSM == 2){
			switch(cmd) {
				case 'y': //다음 스테이지
				nFSM = 1;
				//map_drawAll(world_map2);

				player_ypos = 1;
				player_xpos = 1;

				key_ypos = 1;
				key_xpos = 4;
					
				door_ypos = 2;
				door_xpos = 7;


				break;
				
				case 'n':
				bLoop=0;
				printf("다음에 또 봐요~ \r\n");
				break;
			}

			//nFSM = 0;

		}

	}


	return 0;
}
