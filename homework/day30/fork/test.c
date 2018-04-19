#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    
    pid_t pid = fork();    
    if(pid < 0) {
        perror("fork");
        return 1;
    }
    else if(pid == 0) {
        //子进程
        printf("我是子进程~~\n");
        pid_t ppid = getppid();
        printf("c: my ppid :%d\n", ppid);
        sleep(5);
        ppid = getppid();
        printf("c: my ppid :%d\n", ppid);
        printf("子进程退出~~\n");
    }
    else {
        //父进程
        printf("我是父进程~~\n");
        sleep(3);
        printf("父进程退出~~\n");
    }

    return 0;
}
