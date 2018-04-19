#include"ShareStack.h"

void ShareStackInit(ShareStack* stack) {
    if(stack == NULL) {
        return;
    }
    stack->max_size = 10;
    stack->size_left = 0;
    stack->size_right = stack->max_size;
    stack->space = malloc(stack->max_size * sizeof(ShareStack));
    return;
}

void ShareStackDestroy(ShareStack* stack) {
    if(stack == NULL) {
        return;
    }
    stack->max_size = 0;
    stack->size_left = 0;
    stack->size_right = 0;
    free(stack->space);
    stack->space = NULL;
}

void LeftShareStackPush(ShareStack* stack, StackType value) {
    if(stack == NULL) {
        return;
    }
    if(stack->size_left == stack->size_right) {
        return;
    }
    stack->space[stack->size_left] = value;
    stack->size_left++;
    return;
}

void LeftShareStackPop(ShareStack* stack) {
    if(stack == NULL) {
        return;
    }
    if(stack->size_left == 0) {
        return;
    }
    stack->size_left--;
    return;
}

int LeftShareStackTop(ShareStack* stack, StackType* value) {
    if(stack == NULL || value == NULL) {
        return 0;
    }
    if(stack->size_left == 0) {
        return 0;
    }
    *value = stack->space[stack->size_left - 1];
    return 1;
}


void RightShareStackPush(ShareStack* stack, StackType value) {
    if(stack == NULL) {
        return;
    }
    if(stack->size_left == stack->size_right) {
        return;
    }
    stack->size_right--;
    stack->space[stack->size_right] = value;
    return;
}

void RightShareStackPop(ShareStack* stack) {
    if(stack == NULL) {
        return;
    }
    if(stack->size_left == stack->max_size) {
        return;
    }
    stack->size_right++;
    return;
}

int RightShareStackTop(ShareStack* stack, StackType* value) {
    if(stack == NULL || value == NULL) {
        return 0;
    }
    if(stack->size_right == stack->max_size) {
        return 0;
    }
    *value = stack->space[stack->size_right];
    return 1;
}

///////////////////////////////////////////////////////////////////
//以下为测试代码
///////////////////////////////////////////////////////////////////

void TestShareStack() {
    int ret;
    StackType value;
    ShareStack stack;
    ShareStackInit(&stack);
    printf("LeftStack:\n");
    LeftShareStackPush(&stack, 'a');
    LeftShareStackPush(&stack, 'b');
    LeftShareStackPush(&stack, 'c');
    LeftShareStackPush(&stack, 'd');
    ret = LeftShareStackTop(&stack, &value);
    printf("ret expect 1, actual %d\n", ret);
    printf("value expect d, actual %c\n", value);
    LeftShareStackPop(&stack);

    ret = LeftShareStackTop(&stack, &value);
    printf("ret expect 1, actual %d\n", ret);
    printf("value expect c, actual %c\n", value);
    LeftShareStackPop(&stack);

    ret = LeftShareStackTop(&stack, &value);
    printf("ret expect 1, actual %d\n", ret);
    printf("value expect b, actual %c\n", value);
    LeftShareStackPop(&stack);

    ret = LeftShareStackTop(&stack, &value);
    printf("ret expect 1, actual %d\n", ret);
    printf("value expect a, actual %c\n", value);
    LeftShareStackPop(&stack);

   ret = LeftShareStackTop(&stack, &value); //对空栈进行取栈顶元素
    LeftShareStackPop(&stack); //对空栈出栈
    printf("ret expect 0, actual %d\n", ret);



    printf("\nRightStack\n");
    RightShareStackPush(&stack, 'A');
    RightShareStackPush(&stack, 'B');
    RightShareStackPush(&stack, 'C');
    RightShareStackPush(&stack, 'D');

    ret = RightShareStackTop(&stack, &value);
    printf("ret expect 1, actual %d\n", ret);
    printf("value expect D, actual %c\n", value);
    RightShareStackPop(&stack);

    ret = RightShareStackTop(&stack, &value);
    printf("ret expect 1, actual %d\n", ret);
    printf("value expect C, actual %c\n", value);
    RightShareStackPop(&stack);

    ret = RightShareStackTop(&stack, &value);
    printf("ret expect 1, actual %d\n", ret);
    printf("value expect B, actual %c\n", value);
    RightShareStackPop(&stack);

    ret = RightShareStackTop(&stack, &value);
    printf("ret expect 1, actual %d\n", ret);
    printf("value expect A, actual %c\n", value);
    RightShareStackPop(&stack);

   ret = RightShareStackTop(&stack, &value); //对空栈进行取栈顶元素
    RightShareStackPop(&stack); //对空栈出栈
    printf("ret expect 0, actual %d\n", ret);

    ShareStackDestroy(&stack);
}



int main()
{
    TestShareStack();
    return 0;
}
