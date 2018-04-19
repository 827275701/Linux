#include<stdio.h>
#include<stdlib.h>
#include"test.h"
#define FUNCHEAD printf("\n=========================%s======================\n", __FUNCTION__)


LinkNode* CreatLinkNode()
{
    LinkNode* ret = malloc(sizeof(LinkNode));
    if(ret == NULL)
    {
        return NULL;
    }
    return ret;
}

void DeleteLinkNode(LinkNode* Node)
{
    if(Node == NULL)
    {
        return;
    }
    free(Node);
}

void LinkListInit(LinkNode** head){
    if(head == NULL)
    {
        //非法输入
        return;
    }
    
    *head = NULL;
}

void LinkListPushBack(LinkNode** head, LinkType value)
{
    if(head == NULL)
    {
        //非法输入
        return;
    }
    
    LinkNode* LP = *head;
    if(*head == NULL)
    {
        (*head) = CreatLinkNode();
        if(*head == NULL)
        {
            //malloc失败
            return ;
        }
        (*head)->data = value;
        (*head)->next = NULL;
        return;
    }
    while(LP->next != NULL)
    {
        LP = LP->next;
    }
    LP->next = CreatLinkNode();
    if(LP == NULL)
    {
        //malloc失败
        return ;
    }
    LP->next->data = value;
    LP->next->next = NULL;
}

void LinkListPopback(LinkNode** head)
{
    if(head == NULL)
    {
        //非法输入
        return;
    }
    if(*head == NULL)
    {
        //空链表
        return;
    }

    if((*head)->next == NULL)
    {
        DeleteLinkNode(*head);
        head = NULL;
    }
    LinkNode* LP = *head;
    while(LP->next->next != NULL)
    {
        LP = LP->next;
    }
    
    DeleteLinkNode(LP->next);
    LP->next = NULL;
}

void LinkListPushFront(LinkNode** head ,LinkType value)
{
    if(head == NULL)
    {
        //非法输入
        return;
    }
    
    LinkNode* LP = *head;
    *head = CreatLinkNode();
    if(*head == NULL)
    {
        //malloc失败
        return;
    }
    (*head)->data = value;
    (*head)->next = LP;
}

void LinkListPopFront(LinkNode** head)
{
    if(head == NULL)
    {
        //非法输入
        return;
    }
    if(*head == NULL)
    {
        //空链表
        return;
    }

    LinkNode* LP = *head;
    *head = (*head)->next;
    DeleteLinkNode(LP);
}

LinkNode* LinkListFind(LinkNode* head, LinkType to_find)
{
    if(head == NULL)
    {
        return NULL;
    }

    LinkNode* LP = head;
    while(LP != NULL)
    {
        if(LP->data == to_find)
        {
            return LP;
        }
        LP = LP->next;
    }
    return NULL;
}

void LinkListInsert(LinkNode** head, LinkNode* pos, LinkType value)
{
    if(head == NULL)
    {
        //非法输入
        return;
    }
    if(*head == NULL)
    {
        //空链表
        return;
    }
    
    LinkNode* FLP = (*head)->next;
    LinkNode* SLP = *head;
    if(SLP == pos)
    {
        LinkListPushFront(head, value);
        return;
    }
    while(FLP != NULL)
    {
        if(FLP == pos)
        {
            LinkListPushFront(&(SLP->next), value);
            
            return;
        }
        FLP = FLP->next;
        SLP = SLP->next;
    }
}

void LinkListInsertAfter(LinkNode** head, LinkNode* pos, LinkType value)
{
    if(head == NULL)
    {
        //非法输入
        return;
    }
    if(*head == NULL)
    {
        //空链表
        return;
    }
    
    LinkNode* LP = *head;
    while(LP != NULL)
    {
        if(LP == pos)
        {
            LinkListPushFront(&(LP->next), value);
            return;
        }
        LP = LP->next;
    }
}

void LinkListErase(LinkNode** head, LinkNode* pos)
{
    if(head == NULL || pos == NULL)
    {
        //非法输入
        return;
    }
    if(*head == NULL)
    {
        //空链表
        return;
    }
    if(*head == pos)
    {
        LinkListPopFront(head);
        return;
    }
    LinkNode* LP = *head;
    while(LP!= NULL)
    {
        if(LP->next == pos)
        {
            LinkListPopFront(&(LP->next));
        }
        LP = LP->next;
    }
}

void LinkListRemove(LinkNode** head, LinkType to_delete)
{
    if(head == NULL)
    {
        //非法输入
        return;
    }
    if(*head == NULL)
    {
        //空链表
        return;
    }
    if((*head)->data == to_delete)
    {
        LinkListPopFront(head);
        return;
    }
    LinkNode* LP = *head;
    while(LP->next != NULL)
    {
       if(LP->next->data == to_delete)
        {
            LinkNode* P = LP->next;
            LP->next = LP->next->next;
            DeleteLinkNode(P);
            return;
        }
        LP = LP->next;
    }
}

void LinkListRemoveAll(LinkNode** head, LinkType value)
{
    if(head == NULL)
    {
        //非法输入
        return;
    }
    if(*head == NULL)
    {
        //空链表
        return;
    }

    LinkNode* LP = *head;
    while(LP->next != NULL)
    {
        LinkListRemove(head, value);
        LP = LP->next;
    }
}

int LinkListEmpty(LinkNode* head)
{
    return head == NULL ? 1 : 0;
}

size_t LinkListSize(LinkNode* head)
{
    size_t count = 0; 
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void LinkLisTReversePrint(LinkNode* head)
{
    if(head == NULL)
    {
        return;
    }
    LinkLisTReversePrint(head->next);
    printf("[%c] ", head->data);
}

LinkNode* JosephCycle(LinkNode* head, size_t food)
{
    if(head == NULL)
    {
        return NULL;
    }
    
    LinkNode* LP = head;
    while(LP->next != NULL)
    {
        LP = LP->next;
    }
    LP->next = head;
    LinkNode* LPS = LP;
    LinkNode* LPF = LP->next;
    int i;
    while(LPF != LPF->next)
    {;
        for(i = 1; i < food; i++)
        {
            LPS = LPS->next;
            LPF = LPF->next;
        }
        printf("[%c]\n", LPF->data);
        LPS->next = LPF->next;
        DeleteLinkNode(LPF);
        LPF = LPS->next;
    }
    return LPF;
}


///////////////////////////////////////////////////////////
//以下为测试代码
///////////////////////////////////////////////////////////

LinkNode* head = NULL; 

void LinkListPrint(LinkNode* head)
{
    if(head == NULL)
    {
        return;
    }
    
    while(head->next != NULL)
    {
        printf("[%c] ", head->data);
        head = head->next;
    }
    printf("[%c] ", head->data);
    printf("\n");
}


void TestPushBack()
{
    FUNCHEAD;
    LinkListInit(&head);
    LinkListPushBack(&head, 'a');
    LinkListPushBack(&head, 'b');
    LinkListPushBack(&head, 'c');
    LinkListPushBack(&head, 'd');
    LinkListPrint(head);
}

void TestPopBack()
{
    FUNCHEAD;
    LinkListPopback(&head);
    LinkListPrint(head);
    LinkListPopback(&head);
    LinkListPrint(head);
}

void TestPushFront()
{
    FUNCHEAD;
    LinkListPushFront(&head, 'X');
    LinkListPrint(head);
    LinkListPushFront(&head, 'Y');
    LinkListPrint(head);
    LinkListPushFront(&head, 'Z');
    LinkListPrint(head);
}

void TestPopFront()
{
    FUNCHEAD;
    LinkListPopFront(&head);
    LinkListPrint(head);
    LinkListPopFront(&head);
    LinkListPrint(head);
}

void TestFind()
{
    FUNCHEAD;
    LinkNode* ret = LinkListFind(NULL, 'A');
    printf("LinkList is NULL,to_find = A, ret = %p\n", ret);
    ret = LinkListFind(head, 'X');
    printf("to_find = X, ret = %p\n", ret);
    ret = LinkListFind(head, 'Z');
    printf("to_find = Z, ret = %p\n", ret);
}

void TestInsert()
{
    FUNCHEAD;
    LinkListInsert(&head,LinkListFind(head, 'X') ,'F');
    LinkListInsert(&head,LinkListFind(head, 'X') ,'F');
    LinkListInsert(&head,LinkListFind(head, 'b') ,'F');
    LinkListInsert(&head,LinkListFind(head, 'f') ,'F');
    LinkListPrint(head);
}

void TestInsertAfter()
{
    FUNCHEAD;
    LinkListInsertAfter(&head,LinkListFind(head, 'F') ,'O');
    LinkListInsertAfter(&head,LinkListFind(head, 'b') ,'J');
    LinkListInsertAfter(&head,LinkListFind(head, 'f') ,'F');
    LinkListPrint(head);
}

void TestErase()
{
    FUNCHEAD;
    LinkListErase(&head, LinkListFind(head, 'F'));
    LinkListErase(&head, LinkListFind(head, 'J'));
    LinkListErase(&head, LinkListFind(head, 'Q'));
    LinkListPrint(head);
}

void TestRemove()
{
    FUNCHEAD;
    LinkListRemove(&head, 'O');
    LinkListRemove(&head, 'O');
    LinkListRemove(&head, 'b');
    LinkListPrint(head);
}

void TestRemoveAll()
{
    FUNCHEAD;
    LinkListRemoveAll(&head, 'F');
    LinkListPrint(head);
}

void TestEmpty()
{
    FUNCHEAD;
    int ret;
    ret = LinkListEmpty(head);
    printf("expect:0, actual:%d\n", ret);
    ret = LinkListEmpty(NULL);
    printf("expect:1, actual:%d\n", ret);
}

void TestSize()
{
    FUNCHEAD;
    size_t size = 0;
    size = LinkListSize(head);
    printf("size = %u\n", size);
}

void TestReversePrint()
{
    FUNCHEAD;
    LinkListPushFront(&head, 'A');
    LinkListPushFront(&head, 'B');
    LinkListPushFront(&head, 'C');
    LinkListPrint(head);
    LinkLisTReversePrint(head);
    printf("\n");
}

void TestJosephCycle()
{
    FUNCHEAD;
    LinkNode* ret = JosephCycle(head, 5);
    printf("<%c>\n",ret->data);
}

int main()
{
    TestPushBack();
    TestPopBack();
    TestPushFront();
    TestPopFront();
    TestFind();
    TestInsert();
    TestInsertAfter();
    TestErase();
    TestRemove();
    TestRemoveAll();
    TestEmpty();
    TestSize();
    TestReversePrint();
    TestJosephCycle();
    return 0;
}
