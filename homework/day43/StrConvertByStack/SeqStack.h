#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef char StackType;

typedef struct SeqStack{
    StackType* space;
    size_t size;
    size_t max_size;
}SeqStack;

void SeqStackInit(SeqStack* stack);

void SeqStackDestroy(SeqStack* stack);

void SeqStackPush(SeqStack* stack, StackType value);

void SeqStackPop(SeqStack* stack);

int SeqStackTop(SeqStack* stack, StackType* output_value);
