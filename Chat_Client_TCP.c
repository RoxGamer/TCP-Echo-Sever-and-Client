//Prabhjot Singh
//102003153

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include <arpa/inet.h>
#include <fcntl.h> //for open
#include <unistd.h> //for close

int main(int argc,char **argv)
{
	int sockfd,n;
	char sendline[100];
	char recvline[100];
	struct sockaddr_in servaddr;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof servaddr);
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(2002);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
		
	while(1)
	{
		bzero( sendline, 100);
		bzero( recvline, 100);
		fgets(sendline,100,stdin); 
		send(sockfd,sendline,strlen(sendline),0);
		recv(sockfd,recvline,100,0);
		printf("Server - %s",recvline);
	}
}
