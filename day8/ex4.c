#include <stdio.h>
#include <string.h>

struct _S_PLAYER {
	char m_szName[128];
	int m_nHp;
};

int main()
{

	struct _S_PLAYER players[] = {
		{"John Snow",300},
		{"Sansa Stak",200},
		{"Seosai Ranerster",250}
	};

	for(int i=0;i<3;i++) {
		printf("name : %s, hp : %d \r\n",players[i].m_szName,players[i].m_nHp);
	}


	return 0;
}

