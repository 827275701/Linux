#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    pid_t id = fork();
    if(id == 0) {
        printf("我是子进程\n");
    } 
    else if(id > 0) {
        printf("我是父进程\n");
    } 
    else {
        perror("fork");
        exit(1);
    }
}
