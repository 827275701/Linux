#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
    char* const argv[] = {"ps", "-ef", NULL};
    char* const envp[] = {"PATH=/bin:/usr/bin", "TERM=console", NULL};

    execl("/bin/ps", "ps", "-ef", NULL);

    //带p可以使用环境变量PATH，无需路径
    execlp("ps", "ps", "-ef", NULL);

    //带e需要自己组装环境变量
    execle("ps", "ps", "-ef", NULL, envp);

    execv("/bin/ps", argv);

    execvp("ps", argv);

    execve("/bin/ps", argv, envp);

    exit(0);
}
