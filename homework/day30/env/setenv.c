#include<stdio.h>
#include<stdlib.h>

int main()
{
    char* p = getenv("MYENV");
    printf("%s\n", p);
    setenv("MYENV", "hello world", 1);
    p = getenv("MYENV");
    printf("%s\n", p);
    return 0;
}






//int main(int argc, char *argv[], char* env[])
//{
//    int i = 0;
//    for(;env[i];i++) {
//        printf("%s\n",env[i]);
//    }
//
//    return 0;
//}
