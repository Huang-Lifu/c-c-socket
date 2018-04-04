#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8089

int main()
{char *hello="ha ha";

//socket(...);       
int socket_file_descriptor;
socket_file_descriptor=socket(AF_INET,SOCK_STREAM,0);

//connect(...);
struct sockaddr_in serv_addr;
inet_pton(AF_INET,"192.168.140.131",&serv_addr.sin_addr);
serv_addr.sin_family=AF_INET; 
serv_addr.sin_port=htons(PORT);
connect(socket_file_descriptor,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

//send(...);
send(socket_file_descriptor,hello,sizeof(hello),0);
printf("message sent\n");  		
return 0;
}
