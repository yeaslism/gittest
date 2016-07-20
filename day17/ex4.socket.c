#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct _S_PACKET_REQ_SETPOS {
	unsigned short header;
	unsigned short req_type;
	unsigned int index;
	float m_fXpos;
	float m_fYpos;
} _S_PACKET_REQ_SETPOS;


int main()
{
	int socket_desc;
	struct sockaddr_in server;
	static char read_buffer[2000];
	
	_S_PACKET_REQ_SETPOS testPacket = {1004,200,0,15.0,17.0};

	printf("%d, %d \r\n",testPacket.header,testPacket.req_type);

	socket_desc = socket(AF_INET,SOCK_STREAM,0);
	if(socket_desc == -1)
	{
		puts("err create socket");
	}
	server.sin_addr.s_addr = inet_addr("192.168.0.78");
	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	if(connect(socket_desc,(struct sockaddr *)&server,sizeof(server)) < 0) {
		puts("connect error");
		return 1;
	}
	printf("%d \r\n",sizeof(testPacket));
	if(send(socket_desc,&testPacket,sizeof(testPacket),0) < 0) {
		puts("send failed");
	}
	puts("send success");


	return 0;
}
