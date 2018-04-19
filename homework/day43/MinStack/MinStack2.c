#include<stdio.h>
#include"MinStack2.h"

void MinStackInit(MinStackByTwo* minstack_bytwo) {
    if(minstack_bytwo == NULL) {
        return;
    }
    minstack_bytwo->stack.size = 0;
    minstack_bytwo->min_stack.size = 0;
    return;
}

void MinStackPush(MinStackByTwo* minstack_bytwo, MinStackType value) {
    if(minstack_bytwo == NULL || minstack_bytwo->stack.size >= MinStackMaxSize) {
        return;
    }
    if(minstack_bytwo->stack.size == 0) {
        minstack_bytwo->stack.data[minstack_bytwo->stack.size] = value;    
        minstack_bytwo->stack.size++;
        minstack_bytwo->min_stack.data[minstack_bytwo->min_stack.size] = value;    
        minstack_bytwo->min_stack.size++;
        return;
    }
    MinStackType min = value;
    if(value >= minstack_bytwo->min_stack.data[minstack_bytwo->min_stack.size - 1]) {
        min = minstack_bytwo->min_stack.data[minstack_bytwo->min_stack.size - 1];
    }
    minstack_bytwo->stack.data[minstack_bytwo->stack.size++] = value;    
    minstack_bytwo->min_stack.data[minstack_bytwo->min_stack.size++] = min;    
    return;
}

void MinStackPop(MinStackByTwo* minstack_bytwo) {
    if(minstack_bytwo == NULL || minstack_bytwo->stack.size == 0) {
        return;
    }
    minstack_bytwo->stack.size -= 1;
    minstack_bytwo->min_stack.size -= 1;
    return;
}

int MinStackTop(MinStackByTwo* minstack_bytwo,MinStackType* top_value, MinStackType* min_value) {
    if(minstack_bytwo == NULL || min_value == NULL) {
        return 0;
    }
    if(minstack_bytwo->stack.size == 0) {
        return 0;
    }
    *min_value = minstack_bytwo->min_stack.data[minstack_bytwo->min_stack.size - 1];
    *top_value = minstack_bytwo->stack.data[minstack_bytwo->stack.size - 1];
    return 1;
}


/////////////////////////////////////////////////////////////////
//以下为测试代码
//////////////////////////////////////////////////////////////////

void TestMinStackByTwo() {
    MinStackByTwo minstack;
    MinStackInit(&minstack);
    MinStackPush(&minstack, '9');
    MinStackPush(&minstack, '5');
    MinStackPush(&minstack, '7');
    MinStackPush(&minstack, '2');

    MinStackType min;
    MinStackType top;
    int ret;
    ret = MinStackTop(&minstack, &top, &min);
    printf("ret expected 1, actual %d\n", ret);
    printf("top expected 2, actual %c\n", top);
    printf("min expected 2, actual %c\n", min);
    MinStackPop(&minstack);

    ret = MinStackTop(&minstack, &top, &min);
    printf("ret expected 1, actual %d\n", ret);
    printf("top expected 7, actual %c\n", top);
    printf("min expected 5, actual %c\n", min);
    MinStackPop(&minstack);
    
    ret = MinStackTop(&minstack, &top, &min);
    printf("ret expected 1, actual %d\n", ret);
    printf("top expected 5, actual %c\n", top);
    printf("min expected 5, actual %c\n", min);
    MinStackPop(&minstack);
    
    ret = MinStackTop(&minstack, &top, &min);
    printf("ret expected 1, actual %d\n", ret);
    printf("top expected 9, actual %c\n", top);
    printf("min expected 9, actual %c\n", min);
    MinStackPop(&minstack);

    ret = MinStackTop(&minstack, &top, &min);
    printf("ret expected 0, actual %d\n", ret);
    MinStackPop(&minstack);
}




int main()
{
    TestMinStackByTwo();

    return 0;
}
