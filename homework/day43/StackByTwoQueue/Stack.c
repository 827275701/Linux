#include"Stack.h"
#include<stdio.h>

void StackInit(Stack* stack) {
    if(stack == NULL) {
        return;
    }
    SeqQueueInit(&stack->queue1);
    SeqQueueInit(&stack->queue2);

    return;
}

void StackDestroy(Stack* stack) {
    if(stack == NULL) {
        return;
    }
    DestroyQueue(&stack->queue1);
    DestroyQueue(&stack->queue2);
    return;
}

void StackPush(Stack* stack, QueueType value) {
    if(stack == NULL) {
        return;
    }
    SeqQueue* queue_p = NULL;
    //queue_p指向一个不为空的队列,如果都为空栈，queue_p指向stack->queue2
    if(stack->queue1.size != 0) {
        queue_p = &stack->queue1;
    }
    else {
        queue_p = &stack->queue2;
    }
    SeqQueueIn(queue_p, value);
    return;
}

void StackPop(Stack* stack) {
    if(stack == NULL) {
        return;
    }
    SeqQueue* empty_queue_p;//指向一个空队列
    SeqQueue* non_empty_queue_p;//指向一个非空队列
    if(stack->queue1.size == 0) {
        empty_queue_p = &stack->queue1;
        non_empty_queue_p = &stack->queue2;
    } 
    else if(stack->queue2.size == 0) {
        empty_queue_p = &stack->queue2;
        non_empty_queue_p = &stack->queue1;
    }
    else {
        return ;
    }
    QueueType box;//用于保存非空队列的队首元素，并保存到空队列内
    while(non_empty_queue_p->size > 1) {
        SeqQueueFront(non_empty_queue_p, &box);
        SeqQueueOut(non_empty_queue_p);
        SeqQueueIn(empty_queue_p, box);
    }
    SeqQueueOut(non_empty_queue_p);
    return;
}

int StackTop(Stack* stack, QueueType* value) {
    if(stack == NULL) {
        return 0;
    }
    SeqQueue* empty_queue_p;//指向一个空队列
    SeqQueue* non_empty_queue_p;//指向一个非空队列
    if(stack->queue1.size == 0) {
        empty_queue_p = &stack->queue1;
        non_empty_queue_p = &stack->queue2;
    } 
    else if(stack->queue2.size == 0) {
        empty_queue_p = &stack->queue2;
        non_empty_queue_p = &stack->queue1;
    }
    else {
        return 0;
    }
    if(non_empty_queue_p->size == 0) {
        return 0;
    }
    while(non_empty_queue_p->size > 0) {
        SeqQueueFront(non_empty_queue_p, value);
        SeqQueueOut(non_empty_queue_p);
        SeqQueueIn(empty_queue_p, *value);
    }
    return 1;

}
/////////////////////////////////////////////////////////////////
// 以下为测试代码 
/////////////////////////////////////////////////////////////////
void TestStack() {
    Stack stack;
    StackInit(&stack);
    StackPush(&stack, 'a');
    StackPush(&stack, 'b');
    StackPush(&stack, 'c');
    StackPush(&stack, 'd');

    int ret;
    QueueType top_value;
    ret = StackTop(&stack, &top_value);
    printf("ret expect 1, actual %d\n", ret);
    printf("top_value expect d, actual %c\n", top_value);
    StackPop(&stack);
    ret = StackTop(&stack, &top_value);
    printf("ret expect 1, actual %d\n", ret);
    printf("top_value expect c, actual %c\n", top_value);
    StackPop(&stack);
    ret = StackTop(&stack, &top_value);
    printf("ret expect 1, actual %d\n", ret);
    printf("top_value expect b, actual %c\n", top_value);
    StackPop(&stack);
    ret = StackTop(&stack, &top_value);
    printf("ret expect 1, actual %d\n", ret);
    printf("top_value expect a, actual %c\n", top_value);
    StackPop(&stack);
    ret = StackTop(&stack, &top_value);
    printf("ret expect 0, actual %d\n", ret);
    StackPop(&stack);//尝试对空栈进行出栈
    StackDestroy(&stack);
}
int main()
{
    TestStack();
    return 0;
}
