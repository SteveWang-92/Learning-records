#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
typedef struct sockaddr* saddrp;

int main(int argc, char const *argv[])
{
     int sockfd = socket(AF_INET,SOCK_DGRAM,0);
     if (0 > sockfd)
     {
          perror("socket");
          return -1;
     }
     struct sockaddr_in addr = {};
     addr.sin_family = AF_INET;
     addr.sin_port = htons(5577);
     addr.sin_addr.s_addr = inet_addr("192.168.1.10");

     socklen_t addr_len = sizeof(struct sockaddr_in);
     while(1)
     {
          char buf[255] = {};
          printf("Plz input data:");
          read(0, buf, sizeof(buf));
          sendto(sockfd,buf,strlen(buf),0,(saddrp)&addr,sizeof(addr));
          if(0 == strcmp(buf,"q")) break;

          recvfrom(sockfd,buf,sizeof(buf),0,(saddrp)&addr,&addr_len);
          printf("Recv:%s\n",buf);
          if(0 == strcmp(buf,"q")) break;

     }
     close(sockfd);
     return 0;
}
