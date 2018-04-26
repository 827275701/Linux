#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* thread1(void* arg){
    printf("thread1 is run ...\n");
    int *p = malloc(sizeof(int));
    *p = 1;
    return (void* )p;
}

void* thread2(void* arg){
    printf("thread2 is run ...\n");
    int *p = malloc(sizeof(int));
    *p = 2;
    pthread_exit((void* )p);
}

void* thread3(void* arg) {
    while(1) {
        printf("thread3 is run ...\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid;
    void* ret;
    
    //return返回
    pthread_create(&tid, NULL, thread1, NULL);
    pthread_join(tid, &ret);
    printf("thread1 id is %X, return code %d\n", tid, *(int *)ret);

    //pthread_exit返回
    pthread_create(&tid, NULL, thread2, NULL);
    pthread_join(tid, &ret);
    printf("thread2 id is %X, return code %d\n", tid, *(int *)ret);

    //被主线程返回
    pthread_create(&tid, NULL, thread3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &ret);
    if(ret == PTHREAD_CANCELED){
        printf("thread3 id is %X, return code: PTHREAN_CANCELED\n", tid);
    }
    else {
        printf("thread3 id is %X, return code: NULL\n", tid);
    }
    return 0;
}
