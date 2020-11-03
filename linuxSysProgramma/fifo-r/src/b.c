// File Name: b.c
// Author: Steve Wang
// Created Time: 2020年06月04日 星期四 09时29分14秒
//
//
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    int infd = open("my.p",O_RDONLY);
    if(infd==-1)
        perror("open my.p"),exit(1);
    char buf[1024]={};
    int n = 0;
    while((n = read(infd,buf,1024))>0)
    {
        write(1,buf,n);
        memset(buf,0x00,1024);
    }
    close(infd);                                                                                                         
    unlink("my.p"); //删除管道
    return 0;
}
