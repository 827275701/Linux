#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/syscall.h>


void* start_fun(void* arg) {
    pid_t tid;
    int i = 5;
    printf("%p\n",pthread_self);
    while(i--){
        sleep(1);
        tid = syscall(SYS_gettid);
        printf("I am new thread, mytid is %d\n",tid);
    }
}

int main()
{
    pthread_t tid;
    if(pthread_create(&tid, NULL, start_fun, NULL) != 0) {
        perror("pthread_create");
        exit(1);
    }

    pid_t main_tid;
    while(1) {
        sleep(1);
        main_tid = syscall(SYS_gettid);
        printf("I am main thread, mytid is %d\n",main_tid);
    }

    return 0;
}
