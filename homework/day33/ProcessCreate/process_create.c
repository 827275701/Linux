#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>

void* fun_child(void *arg) {
    char* str = (char*)arg;
    printf("%s\n", str);
}


void process_creat(pid_t* pid, void* func(void *), void* arg) {
    if(pid == NULL || func == NULL) {
        return;
    }
    *pid = fork();
    if(*pid < 0) {
        perror("fork");
        exit(1);
    }
    else if(*pid == 0) {
        while(1) {
            func(arg);
            sleep(1);
        }
    }
    else{ 
        int status;
        //pid_t ret = waitpid(-1, &status, 0);
        pid_t ret = wait(&status);
        printf("子进程的pid:%u  子进程被%d号信号杀死\n", ret, status);
    }
}

int main()
{
    char* arg = "child is runing!";
    pid_t pid;
    process_creat(&pid, fun_child, arg);

    return 0;
}
