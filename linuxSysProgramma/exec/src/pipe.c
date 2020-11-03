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


#define BUFSZ PIPE_BUF  /*PIPE_BUF管道默认一次性读写的数据长度*/
int main ( void )
{
    int fd[2];
    char buf[BUFSZ];
    char hackrf_r_cmd[] = "hackrf-read";
    char hackrf_w_cmd[] = "hackrf-write";
    int status = -1;
    int ret = -1;

    pid_t child_pid;
    pid_t ret_pid;
    ssize_t len;
    if ( (pipe(fd)) < 0 ){                        /*创建管道*/
        perror ( "failed to pipe" );
        exit( 1 );
    }
    if ( (child_pid = fork()) < 0 ){                    /* 创建一个子进程 */
        perror ( "failed to fork " );
        exit( 1 );
    }
    else if (child_pid > 0 ){
        close ( fd[0] );                        /*父进程中关闭管道的读出端*/
        write (fd[1], "hackrf-write", 20 );    /*父进程向管道写入数据*/
        sleep(2);
        ret_pid = waitpid(child_pid, &status, WNOHANG);
        if(ret_pid > 0){
            char wait_succ[] = "child wait success";
            write(STDOUT_FILENO, wait_succ , sizeof(wait_succ)+1);    /*输出到标准输出*/
            exit (0);
        }
        if(ret_pid < 0){
            perror("wait faild");
        }
        if(ret_pid == 0){
            char child_run[] = "child still run";
            write(STDOUT_FILENO, child_run, sizeof(child_run)+1);    /*输出到标准输出*/
            sleep(2);
            ret = kill( child_pid,SIGKILL );
            if ( ret )
             {
                 puts( "kill failed." );
                 perror( "kill" );
                 waitpid( child_pid, &status, 0 );
             }
             else
             {
                 printf( "%d killed\n", child_pid);
             }
            exit (0);
        }
    }
    else {
        close ( fd[1] );                        /*子进程关闭管道的写入端*/
        len = read (fd[0], buf, BUFSZ );        /*子进程从管道中读出数据*/
        if ( len < 0 ){
            perror ( "process failed when read a pipe " );
            exit( 1 );
        }
        else
            if (strcmp(hackrf_w_cmd, buf) == 0){                
                if( execlp( "python2.7", "python2.7", "udp_tx_rx_sim.py", NULL ) < 0 ){
                    perror( "execlp error " );
                    exit(1);
                }
            }
            else{
            write(STDOUT_FILENO, buf, len);    /*输出到标准输出*/
            }
        exit(0);
    }
}
