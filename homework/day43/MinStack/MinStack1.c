#include<stdio.h>
#include"MinStack1.h"

void MinStackInit(MinStack* minstack) {
    if(minstack == NULL) {
        return;
    }
    minstack->size = 0;
    return;
}

void MinStackPush(MinStack* minstack, MinStackType value) {
    if(minstack == NULL || minstack->size >= MinStackMaxSize) {
        return;
    }
    if(minstack->size == 0) {
        minstack->data[minstack->size] = value;    
        minstack->size++;
        minstack->data[minstack->size] = value;    
        minstack->size++;
        return;
    }
    MinStackType min;
    min = minstack->data[minstack->size - 1] > value ? value : minstack->data[minstack->size - 1];
    minstack->data[minstack->size] = value;    
    minstack->size++;
    minstack->data[minstack->size] = min;    
    minstack->size++;
    return;
}

void MinStackPop(MinStack* minstack) {
    if(minstack == NULL || minstack->size == 0) {
        return;
    }
    minstack->size -= 2;
}

int MinStackTop(MinStack* minstack, MinStackType* min_value) {
    if(minstack == NULL || min_value == NULL) {
        return 0;
    }
    if(minstack->size == 0) {
        return 0;
    }
    *min_value = minstack->data[minstack->size - 1];
    return 1;
}

/////////////////////////////////////////////////////////////////
//以下为测试代码
//////////////////////////////////////////////////////////////////
MinStack minstack;
void TestMinStack() {
    MinStackInit(&minstack);
    MinStackPush(&minstack, '9');
    MinStackPush(&minstack, '5');
    MinStackPush(&minstack, '7');
    MinStackPush(&minstack, '2');
    
    MinStackType top;
    int ret;
    ret = MinStackTop(&minstack, &top);
    printf("ret expected 1, actual %d\n", ret);
    printf("top expected 2, actual %c\n", top);
    MinStackPop(&minstack);

    ret = MinStackTop(&minstack, &top);
    printf("ret expected 1, actual %d\n", ret);
    printf("top expected 5, actual %c\n", top);
    MinStackPop(&minstack);
    
    ret = MinStackTop(&minstack, &top);
    printf("ret expected 1, actual %d\n", ret);
    printf("top expected 5, actual %c\n", top);
    MinStackPop(&minstack);
    
    ret = MinStackTop(&minstack, &top);
    printf("ret expected 1, actual %d\n", ret);
    printf("top expected 9, actual %c\n", top);
    MinStackPop(&minstack);
    
    ret = MinStackTop(&minstack, &top);
    printf("ret expected 0, actual %d\n", ret);
    MinStackPop(&minstack);
}



int main()
{
    TestMinStack();

    return 0;
}
