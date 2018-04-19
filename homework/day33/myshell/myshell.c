/***********
 **************************************************************
	> File Name: myshell.c
	> Author: 
	> Mail: 
	> Created Time: Sat 17 Mar 2018 05:18:06 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

char *strs[128] = {};
int argc = 0;

void stok(char *buf, const char *ch)
{
    if(buf == NULL)
    {
        return;
    }
    char *token = strtok(buf, ch);
    strs[argc] = token;
    while((token = strtok(NULL, ch)) != NULL)
    { 
        argc++;
        strs[argc] =token;
    }
    strs[argc+1] = NULL;
}

int main()
{
    char buf[256] = {};
    while(1)
    {
        pid_t pid = fork();
    
        if(pid == 0)
        {
            printf("myshell#");
            scanf("%[^\n]%*c", buf);    
            stok(buf, " "); //打断buf字符串
            execvp(strs[0], strs);
        }
        else
        {
            int status = 0;
            pid_t id = waitpid(pid,&status, 0);   
            if(id < 0)
            {
                printf("wait runing error!\n");
            }
        }
    }
    return 0;
}















