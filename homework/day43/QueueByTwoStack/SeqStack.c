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
    if(stack->size == 0) {
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

/////////////////////////////////////////////////////////////////
//以下为测试代码
/////////////////////////////////////////////////////////////////
void TestSeqStack() {
    SeqStack stack;
    SeqStackInit(&stack);
    printf("stack->size expected 0, actual %d\n", stack.size);

    SeqStackPush(&stack, 'a');
    SeqStackPush(&stack, 'b');
    SeqStackPush(&stack, 'c');
    SeqStackPush(&stack, 'd');
    printf("stack->size expected 4, actual %d\n", stack.size);
    
    StackType value;
    int ret;
    ret = SeqStackTop(&stack, &value);
    printf("stack->space expected d, actual %c\n", stack.space[stack.size-1]);
    printf("stack->size expected 1, actual %d\n", ret);
    SeqStackPop(&stack);

    ret = SeqStackTop(&stack, &value);
    printf("stack->space expected c, actual %c\n", stack.space[stack.size-1]);
    printf("stack->size expected 1, actual %d\n", ret);
    SeqStackPop(&stack);

    ret = SeqStackTop(&stack, &value);
    printf("stack->space expected b, actual %c\n", stack.space[stack.size-1]);
    printf("stack->size expected 1, actual %d\n", ret);
    SeqStackPop(&stack);

    ret = SeqStackTop(&stack, &value);
    printf("stack->space expected a, actual %c\n", stack.space[stack.size-1]);
    printf("stack->size expected 1, actual %d\n", ret);
    SeqStackPop(&stack);

    ret = SeqStackTop(&stack, &value);
    printf("stack->space expected 0, actual %d\n", stack.space[stack.size-1]);
    printf("stack->size expected 0, actual %d\n", ret);
}
#if 0
int main(){
    TestSeqStack();
    return 0;
}

#endif
