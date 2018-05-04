#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int ticket = 100;
pthread_mutex_t mutex;

void *route(void* arg){
    char* tid = (char*)arg;
    while(1){
        pthread_mutex_lock(&mutex);
        if(ticket > 0) {
            usleep(10000);
            printf("%s正在卖票,还剩%d张票\n", tid, ticket);
            ticket--;
            pthread_mutex_unlock(&mutex);
        } else {
            pthread_mutex_unlock(&mutex);
            break;
        }
    }
}

int main()
{
    pthread_t t1, t2, t3, t4;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&t1, NULL, route, "一号售票员");
    pthread_create(&t2, NULL, route, "二号售票员");
    pthread_create(&t3, NULL, route, "三号售票员");
    pthread_create(&t4, NULL, route, "四号售票员");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
