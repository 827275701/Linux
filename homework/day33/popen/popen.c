#include<stdio.h>
#include<stdlib.h>

int main()
{
    char str[128] = {};
    FILE* fp;
    fp = popen("ls -al", "w");
    if(fp == NULL) {
        perror("popen");
        exit(1);
    }
    pclose(fp);
    return 0;
}
