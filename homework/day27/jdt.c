#include<stdio.h>
#include<stdlib.h>
int main()
{
    char jdt[103] = " ";
    int i = 0;
    int j = 0;
    int flag = 0;
    char arr[4] = {'+','x'};
    jdt[0] = '[';
    jdt[102] = ']';
    jdt[101] = '\0';
    for(i=1; i<101; i++)
    {
        jdt[i] = ' ';
    }
  for(i=1; i<102; i++)
  {
        printf("\033[;31m%c%-100s%c\033[0m\033[;34m[%3d%%]\033[0m\033[;32m[%c]\033[0m\r", jdt[0], &jdt[1], jdt[102], i-1, arr[i%2]);
        usleep(100000);
        fflush(stdout);
        jdt[i] = '#';
    }
    printf("\n");
    return 0;
}
