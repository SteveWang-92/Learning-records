#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
int main(int argc , char *argv[])
{
    int fd;

    fd = open("./test.txt", O_RDONLY);
    if (fd==-1)
    {   
        perror("open error");
        exit(1);
        /* code */
    }
    struct stat sbuf;
    int ret =  fstat(fd, &sbuf);

    if (ret==-1)
    {   
        perror("fstat error");
        exit(1);
        /* code */
    }

    printf("fd = %d, ret = %d, sbuf.st_mode = %d\n", fd, ret, sbuf.st_mode);

    close(fd);

    return 0;
}

