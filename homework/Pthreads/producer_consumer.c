#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>



#define CONSUMERS_COUNT 2
#define PRODUCERS_COUNT 2

struct msg{
    struct msg* next;
    int num;
};

struct msg* head = NULL;

pthread_cond_t cond;
pthread_mutex_t mutex;
pthread_t pthreads[CONSUMERS_COUNT+PRODUCERS_COUNT];

void* consumer(void* arg) {
    int num = *(int*)arg;
    free(arg);
    struct msg *mp;
    for(;;) {
        pthread_mutex_lock(&mutex);
        while(head == NULL) {
            printf("consumer%d wait a producer ... \n");
            pthread_cond_wait(&cond, &mutex);
        }
        printf("consumer%d end wait ...\n",num);
        printf("consumer%d begin consume ...\n",num);
        mp = head;
        head = mp->next;
        printf("consumer%d Consume %d\n", num, mp->num);
        free(mp);
        pthread_mutex_unlock(&mutex);
        printf("consumer%d end ...\n",num);
        sleep(rand()%5);
    }
}

void* producer(void* arg) {
    int num = *(int*)arg;
    free(arg);
    struct msg* mp;
    for(;;){
        printf("producer%d begin produce ...\n", num);
        mp = (struct msg*)malloc(sizeof(struct msg));
        mp->num = rand()%1000 + 1;
        printf("producer%d produce %d\n", num, mp->num);
        pthread_mutex_lock(&mutex);
        mp->next = head;
        head = mp;
        printf("producer%d end produce ...\n");
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(rand()%5);
    }
}


int main()
{
    srand(time(NULL));

    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);
    
    int i = 0;
    for(; i<CONSUMERS_COUNT; i++) {
        int* p = (int*)malloc(sizeof(int));
        *p = i;
        pthread_create(&pthreads[i], NULL, consumer, (void*)p);
    }

    for(i=0; i<PRODUCERS_COUNT; i++) {
        int* p = (int*)malloc(sizeof(int));
        *p = i;
        pthread_create(&pthreads[CONSUMERS_COUNT+i], NULL, producer, (void*)p);
    }

    for(i=0; i<CONSUMERS_COUNT+PRODUCERS_COUNT; i++) {
        pthread_join(pthreads[i], NULL);
    }

    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);
    return 0;
}
