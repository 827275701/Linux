/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Mar 2018 11:50:29 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"test.h"

typedef struct PeopleLinkNode{
    char name[NAME_MAX];
    char sex[SEX_MAX];
    char tel[TEL_MAX];
    struct PoepleLinkNode* next;
}PeopleLinkNode;

void face()
{
    printf("\n_____________________________________\n");
    printf("|***********************************|\n");
    printf("|            欢迎使用通讯录!        |\n");
    printf("|***********************************|\n");
    printf("|-----------------------------------|\n");
    printf("|  1.添加一个联系人                 |\n");
    printf("|  2.删除指定个联系人               |\n");
    printf("|  3.查询指定联系人信息             |\n");
    printf("|  4.修改指定联系人信息             |\n");
    printf("|  5.显示所有联系人信息             |\n");
    printf("|  6.清空有联系人信息               |\n");
    printf("|  7.排序所有联系人                 |\n");
    printf("|  0.退出                           |\n");
    printf("|___________________________________|\n");
}

void AddAContact()
{
    PeopleLinkNode new_people;
    FILE* fp = fopen("book.txt", "a+");
    if(fp == NULL)
    {
        printf("打开电话簿失败！\n");
        return;
    }
    printf("姓名:>");
    scanf("%s", new_people.name);
    printf("性别:>");
    scanf("%s", new_people.sex);
    to:    printf("电话:>");
    scanf("%s",new_people.tel);
    if(strlen(new_people.tel) != 11)
    {
        printf("输入错误!\n");
        goto to;
    }
    new_people.next = NULL;
    fwrite(new_people.name, 1, strlen(new_people.name), fp);
    fwrite(" ", 1, 1, fp);
    fwrite(new_people.sex, 1, strlen(new_people.sex), fp);
    fwrite(" ", 1, 1, fp);
    fwrite(new_people.tel, 1, strlen(new_people.tel), fp);
    fwrite("\n", 1, 1, fp);
    printf("操作成功!\n");
    fclose(fp);
}

void DeleteAContact(char* to_delete_name)
{
    if(to_delete_name == NULL)
    {
        return;
    }
    
    typedef struct BoxNode{
        char buf[NODE_MAX_SIZE];
        struct BoxNode* next;
    }BoxNode;
    BoxNode* head = NULL;
    BoxNode* tail = NULL;
    BoxNode people = {"\0", NULL};
    char c;
    int i = 0;
    char name[NAME_MAX];
    FILE* fp = fopen("book.txt", "r");
    if(fp == NULL)
    {
        printf("打开电话簿失败！\n");
        return;
    }
    
    while(fread(&c, 1, 1,fp ))
    {
        people.buf[i] = c;
        i++;
        if(c == '\n')
        {
            sscanf(people.buf, "%s", name);
            if(strcmp(to_delete_name, name) == 0)
            {
                memset(people.buf, 0, NODE_MAX_SIZE);
                memset(name, 0, NODE_MAX_SIZE);
                i = 0;
            }
            else
            {
                if(head == NULL)
                {
                    head = malloc(sizeof(BoxNode));
                    tail = head;
                    strcpy(head->buf, people.buf);
                }
                else
                {
                    tail->next = malloc(sizeof(BoxNode));
                    tail = tail->next;
                    strcpy(tail->buf, people.buf);
                }
                memset(people.buf, 0, NODE_MAX_SIZE);
                memset(name, 0, NODE_MAX_SIZE);
                i = 0;
            }
        }
    }
    fclose(fp);
    fp = fopen("book.txt", "w");
    if(fp == NULL)
    {
        printf("打开电话簿失败！\n");
        return;
    }
    tail = head;
    while(head != NULL)
    {
        fwrite(head->buf, 1, strlen(head->buf), fp);
        head = head->next;
        free(tail);
        tail = head;
    }
    fclose(fp);
}

void SearchAContact(char* to_search_name)
{
    if(to_search_name == NULL)
    {
        return;
    }
    typedef struct BoxNode{
        char buf[NODE_MAX_SIZE];
        struct BoxNode* next;
    }BoxNode;
    BoxNode people = {"\0", NULL};
    char c;
    int i = 0;
    char name[NAME_MAX];
    char sex[SEX_MAX];
    char tel[TEL_MAX];
    FILE* fp = fopen("book.txt", "r");
    if(fp == NULL)
    {
        printf("打开电话簿失败！\n");
        return;
    }
    if(!fread(&c, 1, 1, fp))
    {
        return;
    }
    while(fread(&c, 1, 1,fp ))
    {
        people.buf[i] = c;
        i++;
        if(c == '\n')
        {
            sscanf(people.buf, "%s", name);
            if(strcmp(to_search_name, name) == 0)
            {
                sscanf(people.buf, "%*s%s%s", sex, tel);
                printf("%s %s %s\n", name, sex, tel);
            }
            memset(people.buf, 0, NODE_MAX_SIZE);
            memset(name, 0, NODE_MAX_SIZE);
            i = 0;
        }
    }
    fclose(fp);
}

void ModifyAContact(char* to_modify_name)
{
    if(to_modify_name == NULL)
    {
        return;
    }

    typedef struct BoxNode{
        char buf[NODE_MAX_SIZE];
        struct BoxNode* next;
    }BoxNode;
    BoxNode* head = NULL;
    BoxNode* tail = NULL;
    BoxNode people = {"\0", NULL};
    char c;
    int i = 0;
    char name[NAME_MAX];
    char sex[SEX_MAX];
    char tel[TEL_MAX];
    FILE* fp = fopen("book.txt", "r");
    if(fp == NULL)
    {
        printf("打开电话簿失败！\n");
        return;
    }
    
    while(fread(&c, 1, 1,fp ))
    {
        people.buf[i] = c;
        i++;
        if(c == '\n')
        {
            sscanf(people.buf, "%s", name);
            if(strcmp(to_modify_name, name) == 0)
            {
                memset(people.buf, 0, NODE_MAX_SIZE);
                memset(name, 0, NODE_MAX_SIZE);
                printf("请输入新的姓名:>");
                scanf("%s", name);
                printf("请输入新的性别:>");
                scanf("%s", sex);
                printf("请输入新的电话:>");
                scanf("%s", tel);
                sprintf(people.buf, "%s %s %s", name, sex, tel);
                if(head == NULL)
                {
                    head = malloc(sizeof(BoxNode));
                    tail = head;
                    strcpy(head->buf, people.buf);
                }
                else
                {
                    tail->next = malloc(sizeof(BoxNode));
                    tail = tail->next;
                    strcpy(tail->buf, people.buf);
                }
                memset(people.buf, 0, NODE_MAX_SIZE);
                memset(name, 0, NODE_MAX_SIZE);
                i = 0;
            }
            else
            {
                if(head == NULL)
                {
                    head = malloc(sizeof(BoxNode));
                    tail = head;
                    strcpy(head->buf, people.buf);
                }
                else
                {
                    tail->next = malloc(sizeof(BoxNode));
                    tail = tail->next;
                    strcpy(tail->buf, people.buf);
                }
                memset(people.buf, 0, NODE_MAX_SIZE);
                memset(name, 0, NODE_MAX_SIZE);
                i = 0;
            }
        }
    }
    fclose(fp);
    fp = fopen("book.txt", "w");
    if(fp == NULL)
    {
        printf("打开电话簿失败！\n");
        return;
    }
    tail = head;
    while(head != NULL)
    {
        fwrite(head->buf, 1, strlen(head->buf), fp);
        head = head->next;
        free(tail);
        tail = head;
    }
    fclose(fp);
}


void ShowAllContact()
{
    FILE* fp = fopen("book.txt", "r");
    if(fp == NULL)
    {
        printf("打开电话簿失败！\n");
        return;
    }
    char c;
    size_t n = 0;
    printf("---------------------------------------\n");
    printf("             联系人信息   \n");
    printf("---------------------------------------\n");
    while(1)
    {
        n = fread(&c, 1, 1, fp);
        if(n == 0)
        {
            break;
        }
        printf("%c", c);
        if(c == ' ')
        {
            printf("    ");
        }
        if(c == '\n')
        {
            printf("---------------------------------------\n");
        }
    }
    fclose(fp);
}

void EmptyAllContact()
{
    FILE* fp = fopen("book.txt", "w");
    fwrite("\0", 1, 1, fp);
    fclose(fp);
}

void SortAllContact()
{

    typedef struct BoxNode{
        char buf[NODE_MAX_SIZE];
        struct BoxNode* next;
    }BoxNode;
    BoxNode* head = NULL;
    BoxNode* tail = NULL;
    BoxNode people = {"\0", NULL};
    char c;
    int i = 0;
    FILE* fp = fopen("book.txt", "r");
    if(fp == NULL)
    {
        printf("打开电话簿失败！\n");
        return;
    }
    memset(people.buf, 0, NODE_MAX_SIZE);
    while(fread(&c, 1, 1,fp ))
    {
        people.buf[i] = c;
        i++;
        if(c == '\n')
        {
            if(head == NULL)
            {
                head = malloc(sizeof(BoxNode));
                tail = head;
                strcpy(head->buf, people.buf);
            }
            else
            {
                tail->next = malloc(sizeof(BoxNode));
                tail = tail->next;
                strcpy(tail->buf, people.buf);
            }
            memset(people.buf, 0, NODE_MAX_SIZE);
            i = 0;
        }
    }
    fclose(fp);
    if(head != NULL)
    {
        BoxNode* PFast = head;
        BoxNode* PSlow = head;
        char exchange_buf[NODE_MAX_SIZE];      //用来协助交换的一个中间指针 
        char name_fast[NAME_MAX];
        char name_slow[NAME_MAX];
        while(PSlow != NULL)
        {
            PFast = PSlow;
            for(; PFast != NULL; PFast = PFast->next)
            {
                sscanf(PFast->buf, "%s", name_fast);
                sscanf(PSlow->buf, "%s", name_slow);
                if(name_fast[0] < name_slow[0])
                {
                    strcpy(exchange_buf, PFast->buf);
                    strcpy(PFast->buf, PSlow->buf);
                    strcpy(PSlow->buf, exchange_buf);
                    memset(name_fast, 0, NAME_MAX);
                    memset(name_slow, 0, NAME_MAX);
                    memset(exchange_buf, 0, NODE_MAX_SIZE);
                }
            }
            PSlow = PSlow->next;
        }
    }
    fp = fopen("book.txt", "w");
    if(fp == NULL)
    {
        printf("打开电话簿失败！\n");
        return;
    }
    tail = head;
    while(head != NULL)
    {
        fwrite(head->buf, 1, strlen(head->buf), fp);
        head = head->next;
        free(tail);
        tail = head;
    }
    fclose(fp);
}
/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Mar 2018 09:48:05 AM PDT
 ************************************************************************/

PeopleLinkNode* head;

int main()
{
    FILE* fp = fopen("book.txt", "w");
    fclose(fp);
    int n = 0;
    char name[32]; 
    while(1)
    {
        face();
        printf("pleace choose(0~7):>");    
        scanf("%d",&n);
        while(n > 7 || n < 0)
        {
            printf("enter error!\n");    
            printf("pleace choose(0~7):>");    
            scanf("%d",&n);
        }
        switch(n)
        {
            case 0:
                return 0;
            break;
            
            case 1:
                AddAContact();
            break;
            
            case 2:
            {
                char to_delete_name[NAME_MAX];
                printf("请输入要删除联系人的姓名:>");
                scanf("%s",to_delete_name);
                DeleteAContact(to_delete_name);
            }
            break;

            case 3:
            {
                char to_search_name[NAME_MAX];
                printf("请输入要查询联系人的姓名:>");
                scanf("%s",to_search_name);
                SearchAContact(to_search_name);
            }
            break;

            case 4:
            {
                char to_modify_name[NAME_MAX];
                printf("请输入要修改联系人的姓名:>");
                scanf("%s", to_modify_name);
                ModifyAContact(to_modify_name);
            }
            break;
            
           case 5:
               ShowAllContact();
           break;
           
            case 6:
                EmptyAllContact();
            break;
            
            case 7:
                SortAllContact();
            break;
            default:
            break;
        }
    }
    return 0;
}
