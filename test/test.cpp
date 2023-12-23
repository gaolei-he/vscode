#include<stdio.h>
#include<unistd.h>  
#include<signal.h>   
#include<stdlib.h>  
#include<sys/wait.h>
int x1, x2;
int main() {
    int fd[2];
    char buf[100], s[100];
    pipe(fd);
    while ((x1 = fork()) == -1);
    if (x1 == 0) { // 如果是子进程
        lockf(fd[1], 1, 0);
        sprintf(buf, "child1 is sending a message!");
        write(fd[1], buf, 100); /*把buf中的字符写入管道*/
        lockf(fd[1], 0, 0);
        sleep(1);              /*睡眠1秒，让父进程读*/
        exit(0);               /*关闭x，子进程自我中止*/
    } else {
        while ((x2 = fork()) == -1);
        if (x2 == 0) {
            sleep(0);
            lockf(fd[1], 1, 0);
            sprintf(buf, "child2 is sending a message!");
            write(fd[1], buf, 100); /*把buf中的字符写入管道*/
            lockf(fd[1], 0, 0);
            sleep(1);              /*睡眠1秒，让父进程读*/
            exit(0);               /*关闭x，子进程自我中止*/
        } else {
            sleep(1);
            read(fd[0], s, 100);
            printf("%s\n", s);
            sleep(1);
            read(fd[0], s, 100);
            printf("%s\n", s);
            exit(0);
        }
    }
    return 0;
}