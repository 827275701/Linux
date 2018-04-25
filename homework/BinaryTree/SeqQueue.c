#include<stdio.h>
#include<stdlib.h>
#include"SeqQueue.h"

void SeqQueueInit(SeqQueue* queue) {
    queue->max_size = 100;
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
    queue->place = malloc(queue->max_size * sizeof(SeqQueue));
    if(queue->place == NULL) {
        printf("malloc 失败！\n");
        exit(1);
    }
}

void DestroyQueue(SeqQueue* queue) {
    if(queue == NULL) {
        return;
    }
    free(queue->place);
    queue->place = NULL;
    queue->max_size = 0;
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
}

void SeqQueueIn(SeqQueue* queue, QueueType value) {
    if(queue == NULL) {
        return;
    }
    if(value == NULL) {
        return;
    }
    if(queue->tail == queue->max_size) {
        queue->tail = 0;
    }
    if(queue->head == queue->max_size) {
        queue->head = 0;
    }
    queue->place[queue->tail] = value;
    queue->tail++;
    queue->size++;
}

void SeqQueueOut(SeqQueue* queue) { 
    if(queue == NULL) {
        return;
    }
    if(queue->size == 0) {
        return;
    }
    if(queue->head == queue->max_size) {
        queue->head = 0;
    }
    queue->head++;
    queue->size--;
}

int SeqQueueFront(SeqQueue* queue, QueueType* output_value) {
    if(queue == NULL || output_value == NULL) {
        *output_value = 0;
        return 0;
    }
    if(queue->size == 0) {
        *output_value = 0;
        return 0;
    }
    *output_value = queue->place[queue->head];
    return 1;
}
///////////////////////////////////////////////////
//以下为测试代码
///////////////////////////////////////////////////

//void TestQueue() {
//    SeqQueue queue;
//    SeqQueueInit(&queue);
//    SeqQueueIn(&queue, 'a');
//    SeqQueueIn(&queue, 'b');
//    SeqQueueIn(&queue, 'c');
//    SeqQueueIn(&queue, 'd');
//
//    int ret;
//    QueueType value;
//    ret = SeqQueueFront(&queue, &value);
//    printf("expected a, actrual %c\n", value);
//    printf("expected 1, actrual %d\n", ret);
//    SeqQueueOut(&queue);
//
//    ret = SeqQueueFront(&queue, &value);
//    printf("expected b, actrual %c\n", value);
//    printf("expected 1, actrual %d\n", ret);
//    SeqQueueOut(&queue);
//
//    ret = SeqQueueFront(&queue, &value);
//    printf("expected c, actrual %c\n", value);
//    printf("expected 1, actrual %d\n", ret);
//    SeqQueueOut(&queue);
//    
//    ret = SeqQueueFront(&queue, &value);
//    printf("expected d, actrual %c\n", value);
//    printf("expected 1, actrual %d\n", ret);
//    SeqQueueOut(&queue);
//    
//    ret = SeqQueueFront(&queue, &value);
//    printf("expected 0, actrual %d\n", value);
//    printf("expected 0, actrual %d\n", ret);
//    SeqQueueOut(&queue);
//}
//
//
//int main(){
//    TestQueue();
//    return 0;
//}
