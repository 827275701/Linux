/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Mar 2018 11:50:29 PM PDT
 ************************************************************************/

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
#include"test.h"

//typedef struct P{
//    char name[64];
//    char tel[12];
//}P;

P* Peo[1000];
int i = 0;

void face()
{
    printf("_____________________________________\n");
    printf("|***********************************|\n");
    printf("|              welcome!             |\n");
    printf("|***********************************|\n");
    printf("|-----------------------------------|\n");
    printf("|  1.添加联系人                     |\n");
    printf("|  2.删除联系人                     |\n");
    printf("|  3.查找联系人                     |\n");
    printf("|  4.修改联系人信息                 |\n");
    printf("|  5.显示所有联系人信息             |\n");
    printf("|  6.清空所有联系人                 |\n");
    printf("|  7.以名字排序所有联系人           |\n");
    printf("|  0.退出                           |\n");
    printf("|___________________________________|\n");
}

void AddAContact()
{
    if(i >= 1000)
    {
        printf("内存已满，无法继续保存！");
        return;
    }
    Peo[i] = malloc(sizeof(P));
    printf("请输入姓名:>");
    scanf("%s",Peo[i]->name);
    printf("请输入电话号码:>");
    scanf("%s",Peo[i]->tel);
    Peo[i]->tel[11] = 0;
    printf("操作成功!\n");
    i++;
}

void DeleteAContact(const char *n, const char *t)
{
    if(i == 0)
    {
        printf("没有联系人，不能删除\n");
        return;
    }

    int k = 0;
    int j = 0;
    while(strcmp(n, Peo[k]->name) || strcmp(t, Peo[k]->tel))
    {
        k++;
        if(k == i)
        {
            printf("没有找到此联系人\n");
            return;
        }
    }

    for(j = 0; j < 64; j++)
    {
        Peo[k]->name[j] = 0;
    }
    for(j = 0; j < 12; j++) 
    {
        Peo[k]->tel[j] = 0;
    }
    free(Peo[k]);
    Peo[k] = NULL;

    while(k < i-1)
    {
        Peo[k] = Peo[k+1];
        k++;
    }
    i--;
    Peo[i] == NULL;
    printf("操作成功\n");
}

void SearchAContact(const char *name)
{
    if(name == NULL)
    {
        printf("请输入正确的姓名\n");
        return;
    }
    int j = 0;
    for(j=0; j<i; j++)
    {
        if(strcmp(name,Peo[j]->name) == 0 )
        {
            printf("这位联系人的电话号码: %s\n",Peo[j]->tel);
            printf("操作成功\n");
            return;
        }
    }
    printf("not find the contact!\n");
}

int ModifyAContact(const char* p)
{
    if(p == NULL)
    {
        return 1;
    }

    int j = 0;

    for(; j < i; j++)
    {
        if((strcmp(p, Peo[j]->name) == 0) || strcmp(p, Peo[j]->tel) == 0)
        {
            printf("找到了此联系人，请输入新信息\n");
            printf("姓名:");
            scanf("%s",Peo[j]->name);
            printf("电话号码:");
            scanf("%s",Peo[j]->tel);
            printf("操作成功\n");
            return 0;
        }
    }
    printf("没有找到此联系人\n");
    return 0;
}

void ShowAllContact()
{
    int j = 0;
    
    printf("---------------------------------------------\n");
    for(; j < i; j++)
    {
        printf("Name is %s\n", Peo[j]->name);
        printf("tel is %s\n", Peo[j]->tel);
        printf("---------------------------------------------\n");
    }
}

void EmptyAllContact()
{
    while(i>0)
    {
        free(Peo[i-1]);
        Peo[i-1] = NULL;
        i--;
    }
}

static void swop(P *a,P *b)
{
    P *peo = malloc(sizeof(P));
    
    strcpy(peo->name, a->name);
    strcpy(peo->tel, a->tel);
    strcpy(a->name, b->name);
    strcpy(a->tel, b->tel);
    strcpy(b->name, peo->name);
    strcpy(b->tel, peo->tel);
    free(peo);
}

void SortAllContact()
{
    int j = 0;
    int k = 0;
    int flag = 0;
    for(; j<i; j++)
    {
        for(k=j; k<i; k++)
            {
            if(Peo[j]->name[0] > Peo[k]->name[0])
            {
             swop(Peo[j],Peo[k]);
            }
        }
    }
}
/*************************************************************************
   以下为测试代码：
 ************************************************************************/



//int main()
//{
//    int n = 0;
//    while(1)
//    {
//        face();
//        printf("请选择(0~7):>");    
//        scanf("%d",&n);
//        while(n > 7 || n < 0)
//        {
//            printf("enter error!\n");    
//            printf("pleace choose(0~7):>");    
//            scanf("%d",&n);
//        }
//        switch(n)
//        {
//            case 0:
//                return 0;
//            break;
//            
//            case 1:
//                AddAContact();
//            break;
//            
//            case 2:
//                DeleteAContact("Bob","18165151223");
//            break;
//            
//            case 3:
//                SearchAContact("Bob");
//            break;
//            
//            case 4:
//                ModifyAContact("Bob");
//            break;
//            
//            case 5:
//                ShowAllContact();
//            break;
//            
//            case 6:
//                EmptyAllContact();
//            break;
//            
//            case 7:
//                SortAllContact();
//            break;
//            default:
//            break;
//        }
//    }
//    return 0;
//}
