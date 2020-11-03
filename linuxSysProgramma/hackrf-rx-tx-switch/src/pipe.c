// File Name: pipe.c
// Author: Steve Wang
// Created Time: 2020年06月04日 星期四 09时11分01秒

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct sockaddr* saddrp;
#define BUFFSIZE 1024
//#define BUFSZ PIPE_BUF  /*PIPE_BUF管道默认一次性读写的数据长度*/
int main ( void )
{
    char stdin_buff[BUFFSIZE] = {};
    char hackrf_r_cmd[] = "hackrf-read";
    char hackrf_reply[] = "hackrf-start";
    char hackrf_w_cmd[] = "hackrf-write";
    char *gnuradio_py[] = {
    "nothing",
    "udp_tx/udp_tx.py",
    "udp_rx/udp_rx.py"
    };
    pid_t child_pid;
    int ret = -1;
    int rx_tx_flag = 0;

    char print_buff[1024];
    
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0){
        perror("sockfd create error");
        exit(1);
    }

     //准备地址
     struct sockaddr_in addr = {};
     addr.sin_family = AF_INET;//ipv4
     addr.sin_port = htons(5577);//端口号
     addr.sin_addr.s_addr = inet_addr("192.168.7.100");//我的ip地址
        
     //绑定
     ret = bind(sockfd,(saddrp)&addr,sizeof(addr));
     //这里的saddrp其实就是sockaddr* ,
     //由于addr是sockaddr_in结构体类型的,需要对其进行强制转换这样编译器不会报错.
     if (ret < 0){
          perror("bind error");
          ret = -1;
          exit(1);
     }


     struct sockaddr_in src_addr ={};
     //接受任意的报文
     socklen_t addr_len = sizeof(struct sockaddr_in);



     char udp_buf[BUFFSIZE] = {};
    //while(fgets(stdin_buff, BUFFSIZE, stdin)){
    while(1){
        memset(udp_buf, 0, sizeof(udp_buf));
        //stdin_buff[strlen(stdin_buff)-1] = '\0';
        //puts(stdin_buff);
        recvfrom(sockfd,udp_buf,sizeof(udp_buf),0,(saddrp)&src_addr,&addr_len);
        puts(udp_buf);
        rx_tx_flag = 0;//1 for rx, 2 for tx , 0 for nothing;
        if (strcmp(hackrf_w_cmd, udp_buf) == 0){
            puts("cmd hackrf to tx");
            rx_tx_flag+=2;
        }
        else if(strcmp(hackrf_r_cmd, udp_buf) == 0){
            puts("cmd hackrf to rx");
            rx_tx_flag+=1;
        }

        if (rx_tx_flag >0){
            child_pid = fork();
            if (child_pid < 0){
                perror("failed to fork");
                exit(1);
            }

            if(child_pid == 0){//子进程开启程序
                if( execlp( "python2.7", "python2.7", gnuradio_py[rx_tx_flag], NULL ) < 0 ){
                    perror( "execlp error " );
                    exit(1);
                }
                sendto(sockfd,hackrf_reply,strlen(hackrf_reply),0,(saddrp)&src_addr,addr_len);
            }

            if(child_pid > 0){//父进程
                sleep(5);
                ret = kill( child_pid , SIGKILL);
                if (ret < 0){
                    puts( "kill failed." );
                    perror( "kill" );
                    exit(1);
                }
                else{
                    sprintf(print_buff, "%d was killed", child_pid);
                    puts(print_buff);
                }
            }
        }
    }
    close(sockfd);
    return 0;
}


