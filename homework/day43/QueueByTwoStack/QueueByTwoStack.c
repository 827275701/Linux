#include"QueueByTwoStack.h"

void QueueInit(Queue* queue) {
    if(queue == NULL) {
        return;
    }
    SeqStackInit(&queue->stack_input);
    SeqStackInit(&queue->stack_output);
    return;
}

void QueueDestroy(Queue* queue) {
    if(queue == NULL) {
        return;
    }
    SeqStackDestroy(&queue->stack_input);
    SeqStackDestroy(&queue->stack_output);
    return;
}

void QueueIn(Queue* queue, StackType value) {
    if(queue == NULL) {
        return;
    }
    StackType box;
    while(queue->stack_output.size > 0) {
        SeqStackTop(&queue->stack_output, &box);
        SeqStackPop(&queue->stack_output);
        SeqStackPush(&queue->stack_input,box);
    }
    SeqStackPush(&queue->stack_input,value);
    return;
}

void QueueOut(Queue* queue) {
    if(queue == NULL) {
        return;
    }
    while(queue->stack_input.size != 0) {
        StackType box;
        SeqStackTop(&queue->stack_input,&box);
        SeqStackPop(&queue->stack_input);
        SeqStackPush(&queue->stack_output, box);
    }
    SeqStackPop(&queue->stack_output);
    return;
}

int QueueFront(Queue* queue, StackType* value) {
    if(queue == NULL || value == NULL) {
        return 0;
    }
    StackType box;
    while(queue->stack_input.size != 0) {
        SeqStackTop(&queue->stack_input,&box);
        SeqStackPop(&queue->stack_input);
        SeqStackPush(&queue->stack_output, box);
    }
    if(queue->stack_output.size == 0) {
        return 0;
    }
    SeqStackTop(&queue->stack_output,value);
    return 1;
}

//////////////////////////////////////////////////////
//以下为测试代码
//////////////////////////////////////////////////////
void TestQueue() {
    Queue queue;
    QueueInit(&queue);
    QueueIn(&queue, 'a');
    QueueIn(&queue, 'b');
    QueueIn(&queue, 'c');
    QueueIn(&queue, 'd');
    int ret;
    StackType value;
    ret = QueueFront(&queue, &value);
    printf("ret expected 1, actual %d\n", ret);
    printf("value expected a, actual %c\n", value);
    QueueOut(&queue);

    ret = QueueFront(&queue, &value);
    printf("ret expected 1, actual %d\n", ret);
    printf("value expected b, actual %c\n", value);
    QueueOut(&queue);

    ret = QueueFront(&queue, &value);
    printf("ret expected 1, actual %d\n", ret);
    printf("value expected c, actual %c\n", value);
    QueueOut(&queue);

    ret = QueueFront(&queue, &value);
    printf("ret expected 1, actual %d\n", ret);
    printf("value expected d, actual %c\n", value);
    QueueOut(&queue);

    ret = QueueFront(&queue, &value);
    printf("ret expected 0, actual %d\n", ret);
    QueueOut(&queue);

    QueueDestroy(&queue);
}


int main() 
{
    TestQueue();

    return 0;
}
