#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
int main(int argc , char *argv[])
{
    char buf[1024];

    int count = 0;
 
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1==-1){
        perror("open argv1 error");
        exit(1);
    }
    
    int fd2 = open(argv[2], O_RDWR|O_CREAT|O_TRUNC, 0644);
    if (fd2==-1){
        perror("open argv2 error");
        exit(1);
    }



    while ((count =  read(fd1, buf, 1024)) != 0 ){   
        if(count < 0){
            perror("read error");
            exit(1);
        }
        write(fd2, buf, count);
    }

    close(fd1);
    close(fd2);

    return 0;
}

