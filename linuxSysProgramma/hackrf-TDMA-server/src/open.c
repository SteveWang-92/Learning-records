#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

typedef struct sockaddr* saddrp;

struct hackrf-client{
    int ID;
    struct sockaddr_in client_addr;
};

int main(int argc, char const *argv[])
{







     //创建socket
     int sockfd = socket(AF_INET,SOCK_DGRAM,0);
     if (0 > sockfd)
     {
          perror("sockfd");
          return -1;
     }
     //准备地址
     struct sockaddr_in addr = {};
     addr.sin_family = AF_INET;//ipv4
     addr.sin_port = htons(5577);//端口号
     addr.sin_addr.s_addr = inet_addr("192.168.1.100");//我的ip地址
     //绑定
     int ret = bind(sockfd,(saddrp)&addr,sizeof(addr));
     //这里的saddrp其实就是sockaddr* ,
     //由于addr是sockaddr_in结构体类型的,需要对其进行强制转换这样编译器不会报错.
     if (0 > ret)
     {
          perror("bind");
          return -1;
     }
     struct sockaddr_in src_addr ={};
     //接受任意的报文
     socklen_t addr_len = sizeof(struct sockaddr_in);
     while(1)
     {
          char buf[255] = {};
          //接收数据和来源的ip地址
          recvfrom(sockfd,buf,sizeof(buf),0,(saddrp)&src_addr,&addr_len);
          printf("Recv:%s\n",buf);
          if (0 == strcmp(buf,"hackrf-register")) 
              sendto(sockfd,buf,strlen(buf),0,(saddrp)&src_addr,addr_len);
              break;
          //发送数据给目标地址
          //printf("Please input the return value:");
          //read(0, buf, sizeof(buf));
          //sleep(3);
          sendto(sockfd,buf,strlen(buf),0,(saddrp)&src_addr,addr_len);
          if (0 == strcmp(buf,"q")) break;
     }  
     //关闭socket对象
     close(sockfd);
     return 0;
}
