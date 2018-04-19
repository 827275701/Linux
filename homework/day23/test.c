/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Mar 2018 11:50:29 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct P{
    char name[64];
    char tel[12];
}P;

P Peo[1000];
static int i = 0;

void face()
{
    printf("_____________________________________\n");
    printf("|***********************************|\n");
    printf("|              welcome!             |\n");
    printf("|***********************************|\n");
    printf("|-----------------------------------|\n");
    printf("|  1.add a contact                  |\n");
    printf("|  2.delet a contact                |\n");
    printf("|  3.search a contact               |\n");
    printf("|  4.modify a contact information   |\n");
    printf("|  5.show all contact information   |\n");
    printf("|  6.empty all contact              |\n");
    printf("|  7.sorting contact with name      |\n");
    printf("|  0.exit                           |\n");
    printf("|___________________________________|\n");
}

void AddAContact(P *p)
{
    if(p == NULL)
    {
        return;
    }
    printf("please import name:>");
    scanf("%s",p->name);
    to:    printf("please import tel:>");
    scanf("%s",p->tel);
    if(strlen(p->tel) != 11){
        printf("inpurt error!\n");
    goto to;
   }
    printf("succeful!\n");
}

void DeleteAContact(P *p)
{
    if(i == 0)
    {
        return;
    }
    int j = 0;
   for(j = 0; j < 64; j++)
    {
        p->name[j] = 0;
    }
   for(j = 0; j < 12; j++) 
   {
        p->tel[j] = 0;
   }
}

void SearchAContact(char *name)
{
    if(name == NULL)
    {
        printf("this P is NULL!\n");
        return;
    }
    int j = 0;
    while(j < i)
    {
        if(strcmp(name,Peo[j].name) == 0 )
        {
            printf("the contact's tel num is: %s\n",Peo[j].tel);
            return;
        }
        else
        {
            j++;
        }
    }
    printf("not find the contact!\n");
}

int ModifyAContact(const char* p)
{
    if(p == NULL)
    {
        return;
    }
    
    int j = 0;
    
    for(; j < i; j++)
    {
        if((strcmp(p, Peo[j].name) == 0) || strcmp(p, Peo[j].tel) == 0)
       {
           printf("find this contat,please enter nwe information\n");
           printf("please enter new name;>");
            scanf("%s",Peo[j].name);
           printf("please enter new tel;>");
            scanf("%s",Peo[j].tel);
            return 1;
       }
    }
    printf("No contact was found\n");
    return 0;
}

void ShowAllContact()
{
    int j = 0;
    
    printf("---------------------------------------------\n");
    for(; j < i; j++)
    {
        printf("Name is %s\n", Peo[j].name);
        printf("tel is %s\n", Peo[j].tel);
        printf("---------------------------------------------\n");
    }
}

void EmptyAllContact()
{
    while(i>0)
    {
        char* p = Peo[i-1].name;
       while(*p != '\0')
        {
            *p = '\0';
            p++;
        } 
        p = Peo[i-1].tel;
       while(*p != '\0')
        {
            *p = '\0';
            p++;
        } 
       i--; 
    }
}

static void swop(P *a, P *b)
{
    P peo;
    strcpy(peo.name, a->name);
    strcpy(peo.tel, a->tel);
    strcpy(a->name, b->name);
    strcpy(a->tel, b->tel);
    strcpy(b->name, peo.name);
    strcpy(b->tel, peo.tel);
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
            if(Peo[j].name[0] > Peo[k].name[0])
            {
             swop(&Peo[j],&Peo[k]);
            }
        }
    }
}
/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Mar 2018 09:48:05 AM PDT
 ************************************************************************/



int main()
{
    int n = 0;
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
                AddAContact(&Peo[i]);
                i++;
            break;
            
            case 2:
                DeleteAContact(&Peo[i-1]);
                i--;
            break;
            
            case 3:
                SearchAContact("Bob");
            break;
            
            case 4:
                ModifyAContact("Bob");
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
