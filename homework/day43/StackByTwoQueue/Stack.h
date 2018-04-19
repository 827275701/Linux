#pragma once

#include"SeqQueue.h"

typedef struct Stack{
    SeqQueue queue1;
    SeqQueue queue2;
}Stack;

void StackInit(Stack* queue);

void StackDestroy(Stack* queue);

void StackPush(Stack* queue, QueueType value);

void SatckPop(Stack* queue);

int StackTop(Stack* queue, QueueType* value);
