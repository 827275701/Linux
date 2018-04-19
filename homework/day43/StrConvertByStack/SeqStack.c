#include"SeqStack.h"

void SeqStackInit(SeqStack* stack){
    if(stack == NULL) {
        return;
    }
    stack->size = 0;
    stack->max_size = 1000;
    stack->space = malloc(stack->max_size * sizeof(StackType));
}

void SeqStackDestroy(SeqStack* stack) {
    if(stack == NULL) {
        return;
    }
    free(stack->space);
    stack->space = NULL;
    stack->size = 0;
    stack->max_size = 0;
}

void SeqStackPush(SeqStack* stack, StackType value) {
    if(stack == NULL) {
        return;
    }
    if(stack->size >= stack->max_size) {
        stack->max_size = stack->max_size * 2 + 1;
        SeqStack* new_stack = malloc(stack->max_size * sizeof(SeqStack));
        int i = 0;
        for(; i < stack->size; i++) {
            new_stack->space[i] = stack->space[i];            
        }
        SeqStackDestroy(stack);
        stack = new_stack;
    }
    stack->space[stack->size] = value;
    stack->size++;
}

void SeqStackPop(SeqStack* stack) {
    if(stack == NULL) {
        return;
    }
    stack->size--;
}

int SeqStackTop(SeqStack* stack, StackType* output_value) {
    if(stack == NULL || output_value == NULL) {
        return 0;
    }
    if(stack->size == 0){
        return 0;
    }
    *output_value = stack->space[stack->size - 1];
    return 1;
}

