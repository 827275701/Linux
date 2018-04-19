#pragma once

#define MinStackMaxSize 1000

#define MinStackType char

typedef struct MinStack {
    MinStackType data[MinStackMaxSize];
    size_t size;
}MinStack;

typedef struct MinStackByTwo {
    MinStack stack;
    MinStack min_stack;
}MinStackByTwo;

void MinStackInit(MinStackByTwo* minstack_bytwo);

void MinStackPush(MinStackByTwo* minstack_bytwo, MinStackType value);

void MinStackPop(MinStackByTwo* minstack_bytwo);

int MinStackTop(MinStackByTwo* minstack_bytwo, MinStackType* top, MinStackType* min_value);

