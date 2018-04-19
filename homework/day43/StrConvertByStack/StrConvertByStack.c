#include"SeqStack.h"
#include<stdio.h>

int Convert(char* dst, char* src, int len_src, int len_dst) {
    if(dst == NULL || src == NULL) {
        return -1;
    }
    if(len_src != len_dst) {
        return 0;
    }
    SeqStack stack;
    SeqStackInit(&stack);
    int i = 0;
    int j = 0;
    StackType top_value;
    for(; i<len_src; i++) {
        SeqStackPush(&stack, src[i]);
        while(j < len_dst) {
            if(stack.size == 0) {
                SeqStackPush(&stack, src[i]);
            }
            SeqStackTop(&stack, &top_value);
            if(top_value == dst[j]) {
                j++;
                SeqStackPop(&stack);
                continue;
            }
            break;
        }
    }
    if(stack.size == 0) {
        return 1;
    }
    return 0;
}


int main() {
    char src[] = {'a', 'b', 'c', 'd', 'e'};
    char dst[] = {'b', 'd', 'c', 'e', 'a'};
    int len_src = sizeof(src)/sizeof(src[0]);
    int len_dst = sizeof(dst)/sizeof(dst[0]);
    int ret =  Convert(dst, src, len_src, len_dst);
    if(ret) {
        printf("src 字符串可以通过栈得到 dst\n");
    }
    else if(ret == 0){
        printf("src 字符串不可以通过栈得到 dst\n");
    }
    else {
        printf("输入错误\n");
    }
    return 0;
}
