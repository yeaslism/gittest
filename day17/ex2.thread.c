#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid;

int bLoop =1;

void *doSomeThing(void *arg)
{
	while(1)
	{
		char ch = getchar();
		if(ch == 'q') {
			bLoop = 0;
		}
	}
	return NULL;
}

int main()
{

	int err;
	err = pthread_create(&tid,NULL,&doSomeThing,NULL);
	if(err != 0) {
		printf("\r\n cannot read thread : [%s] \r\n",strerror(err));
	}
	else {
		printf("\r\n thread created successfully \r\n");
	}

	while(bLoop) {
		puts("test");
		sleep(1);
	}

	printf("bye \r\n");

	return 0;
}


