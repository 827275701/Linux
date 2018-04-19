#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef char StackType;

typedef struct ShareStack{
    StackType* space;
    size_t size_left;
    size_t size_right;
    size_t max_size;
}ShareStack;

void ShareStackInit(ShareStack* stack); //共享栈的初始化

void ShareStackDestroy(ShareStack* stack); //销毁共享栈


//对左边栈进行操作
void LeftShareStackPush(ShareStack* stack, StackType value);//入栈

void LeftShareStackPop(ShareStack* stack); //出栈

int LeftShareStackTop(ShareStack* stack, StackType* value); //取栈顶元素


//对右边栈进行操作
void RightShareStackPush(ShareStack* stack, StackType value); //入栈

void RightShareStackPop(ShareStack* stack); //出栈

int RightShareStackTop(ShareStack* stack, StackType* value);//取栈顶元素

