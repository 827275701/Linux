#pragma once 

#include<stdio.h>
#include"SeqStack.h"

typedef struct Queue{
    SeqStack stack_input;
    SeqStack stack_output;
}Queue;

void QueueInit(Queue* queue);

void QueueDestroy(Queue* queue);

void QueueIn(Queue* queue, StackType value);

void QueueOut(Queue* queue);

int QueueFront(Queue* queue, StackType* value);


