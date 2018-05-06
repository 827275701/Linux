#include<stdio.h>
#include<pthread.h>

void* t1_fun(void* arg) {
    char* str = (char*)arg;
    printf("this is %s\n", str);
    int a = 1;
    int b = 1;
    int c;
    c = a + b;
    while(1)
    {
        printf("a + b = %d\n", c);
    }
}

void* t2_fun(void* arg) {
    char* str = (char*)arg;
    printf("this is %s\n", str);
    int x = 2;
    int y = 2;
    int z;
    z = x + y;
    printf("x + y = %d\n", z);
}

int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, t1_fun, "pthread1");
    pthread_create(&t2, NULL, t2_fun, "pthread2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
