#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
int main(int argc , char *argv[])
{

    int fd = open(argv[1], O_RDWR);

    if (fd==-1){
        perror("open argv1 error");
        exit(1);
    }

    int length = lseek(fd, 111, SEEK_END);

    printf("file size:%d\n", length);    

    write(fd, "a", 1);
    close(fd);

    return 0;
}

