#pragma once

//typedef char QueueType;

struct TreeNode;

typedef struct TreeNode* QueueType;

typedef struct SeqQueue{
    QueueType* place;
    size_t head;
    size_t tail;
    size_t size;
    size_t max_size;
}SeqQueue;


void SeqQueueInit(SeqQueue* queue);

void DestroyQueue(SeqQueue* queue);

void SeqQueueIn(SeqQueue* queue, QueueType value);

void SeqQueueOut(SeqQueue* queue);

int SeqQueueFront(SeqQueue* queue, QueueType* output_value);
