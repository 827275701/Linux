#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* thread_run(void* reg) {
    pthread_detach(pthread_self());
    char* str = (char*)reg;
    printf("%s\n", str);
    return NULL;
}


int main()
{
    pthread_t tid;
    if(pthread_create(&tid, NULL, thread_run, "new thread is run ...") != 0 ) {
        printf("pthread_create is error\n");
        exit(1);
    }
    
    sleep(1);
    if(pthread_join(tid, NULL) == 0) {
        printf("线程等待成功！\n");
        return 0;
    }
    else {
        printf("线程等待失败！\n");
        return 1;
    }
    return 0;
}
