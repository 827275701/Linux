#pragma once

#define MinStackMaxSize 1000

#define MinStackType char

typedef struct MinStack {
    MinStackType data[MinStackMaxSize];
    size_t size;
}MinStack;

void MinStackInit(MinStack* minstack);

void MinStackPush(MinStack* minstack, MinStackType value);

void MinStackPop(MinStack* minstack);

int MinStackTop(MinStack* minstack, MinStackType* min_value);
