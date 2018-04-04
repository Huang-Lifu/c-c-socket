#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#define PORT 8089
int main()
{
char buffer[1024]={0};

//socket(...);
int server_fd;
server_fd=socket(AF_INET,SOCK_STREAM,0);

 
int opt=1;
setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&opt,sizeof(opt));

//bind(...);
struct sockaddr_in address;
int addrlen=sizeof(address);
address.sin_family=AF_INET;
address.sin_addr.s_addr= INADDR_ANY;
address.sin_port=htons(PORT);
int bindtest=bind(server_fd,(struct sockaddr*)&address,sizeof(address));

//listen(...);
int listen1=listen(server_fd,3);

//accept(...);
int new_socket=accept(server_fd,(struct sockaddr *)&address,(socklen_t*)&addrlen);

//read(...);
recv(new_socket,buffer,1024,0);

	
printf("%s\n",buffer);
return 0;
}
