#include<stdio.h>
#include<stdlib.h>

int main()
{
    char* env = getenv("MYENV");
    if(env) {
        printf("%s\n");
    }

    return 0;
}

