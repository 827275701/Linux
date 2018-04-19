#include<stdio.h>
#include<stdlib.h>
#include"test.h"
#define FUNCHEAD printf("\n=========================%s======================\n", __FUNCTION__)


LinkNode* CreatLinkNode(LinkType value)
{
    LinkNode* ret = malloc(sizeof(LinkNode));
    if(ret == NULL)
    {
        return NULL;
    }
    ret->next = NULL;
    ret->data = value;
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
        (*head) = CreatLinkNode(value);
        if(*head == NULL)
        {
            //malloc失败
            return ;
        }
        return;
    }
    while(LP->next != NULL)
    {
        LP = LP->next;
    }
    LP->next = CreatLinkNode(value);
    if(LP == NULL)
    {
        //malloc失败
        return ;
    }
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
    *head = CreatLinkNode(value);
    if(*head == NULL)
    {
        //malloc失败
        return;
    }
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


void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value)
{
    if(head == NULL || pos == NULL)
    {
        return;
    }
    if(*head == NULL)
    {
        return;
    }

    LinkNode* LPS = *head;
    LinkNode* LPF = (*head)->next;
    if(LPS == pos)
    {
        LinkListPushFront(head, value);
        return;
    }
    for(; LPF != NULL; LPF = LPF->next, LPS = LPS->next)
    {
        if(LPF == pos)
        {
            LinkListPushFront(&(LPS->next),value);
            return;
        }
    }
}

void LinkListResver(LinkNode** head)
{
    if(head == NULL)
    {
        return;
    }
    if(*head == NULL)
    {
        return;
    }
    LinkNode* LP = (*head)->next;
    LinkNode* cur = (*head)->next;
    (*head)->next = NULL;
    while(LP != NULL)
    {
        LP = LP->next;
        cur->next = *head;
        *head = cur;
        cur = LP;
    }
}

void LinkListResver2(LinkNode** head)
{
    if(head == NULL)
    {
        return;
    }
    if(*head == NULL)
    {
        return;
    }
    LinkNode* LPS = (*head)->next;
    LinkNode* LPF= LPS->next;
    (*head)->next = NULL;
    while(LPF != NULL)
    {
        LPS->next = *head;
        *head = LPS;
        LPS = LPF;
        LPF = LPF->next;
    }
    LPS->next = *head;
    *head = LPS;
}

static void swap(LinkNode** linknode1,LinkNode** linknode2)
{
    LinkType box;
    box = (*linknode1)->data;
    (*linknode1)->data = (*linknode2)->data;
    (*linknode2)->data = box;
}

void LinkListBubbleSort(LinkNode* head)
{
    if(head == NULL)
    {
        return;
    }

    LinkNode* LPS = head;
    LinkNode* LPF = head;
    for(; LPS->next != NULL; LPS = LPS->next)
    {
        for(LPF = LPS->next; LPF != NULL; LPF = LPF->next)
        {
            if(LPS->data > LPF->data)
            {
                swap(&LPS, &LPF);
            }
        }
    }
}

LinkNode* LinkListMerge(LinkNode* head1, LinkNode* head2)
{
    if(head1 == NULL || head2 == NULL)
    {
        return NULL;
    }
    
    LinkNode* new_head = NULL;
    LinkNode* new_tail = NULL;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data > head2->data)
        {
            if(new_head == NULL)
            {
                new_head = head2;
                new_tail = new_head;
            }
            else
            {
                new_tail->next = head2;
                new_tail = new_tail->next;
            }
            head2 = head2->next;
            continue;
        }
        else
        {
            if(new_head == NULL)
            {
                new_head = head1;
                new_tail = new_head;
            }
            else
            {
                new_tail->next = head1;
                new_tail = new_tail->next;
            }
            head1 = head1->next;
            continue;
        }
    }
    if(head1 == NULL)
    {
        new_tail->next = head2;
    }
    if(head2 == NULL)
    {
        new_tail->next = head1;
    }
    return new_head;
}

LinkNode* FindMidNode(LinkNode* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    LinkNode* LP = head;
    size_t size = LinkListSize(head);
    size/=2;
    size_t i = 0;
    
    for(; i<size; i++)
    {
        LP = LP->next;
    }
    return LP;
}

LinkNode* FindLastKNode(LinkNode* head, size_t K)
{
    if(head == NULL || K == 0)
    {
        return NULL;
    }
    
    size_t size = LinkListSize(head);
    if(K > size)
    {
        return NULL;
    }
    size = size - K;
    size_t i = 0;
    for(; i<size; i++)
    {
        head = head->next;
    }
    return head;
}

void EraseLastKNode(LinkNode** head, size_t K)
{
    if(head == NULL || K == 0)
    {
        return;
    }
    if(*head == NULL)
    {
        return;
    }
    size_t size = LinkListSize(*head);
    if(K > size)
    {
        return;
    }
    size = size - K;
    size_t i;
    LinkNode* LP = *head;
    LinkNode* P;
    if(size == 0)
    {
        *head = (*head)->next;
        DeleteLinkNode(LP);
        return;
    }
    for(i = 1; i < size; i++)
    {
        LP = LP->next;
    }
    
    LP->next->data = LP->data;
    P = LP->next;
    LP->next = LP->next->next;
    DeleteLinkNode(P);
}

int HasCycle(LinkNode* head)
{
    if(head == NULL)
    {
        return -1;
    }
    LinkNode* LPF = head;
    LinkNode* LPS = head;
    while(LPF != NULL && LPF->next != NULL)
    {
        LPF = LPF->next->next;
        LPS = LPS->next;
        if(LPF == LPS)
        {
            return 1;
        }
    }
    return 0;
}

size_t GetCycleLen(LinkNode* head)
{
    if(head == NULL)
    {
        return 0;
    }
    LinkNode* LPF = head;
    LinkNode* LPS = head;
    while(LPF->next != NULL && LPF != NULL)
    {
        LPF = LPF->next->next;
        LPS = LPS->next;
        if(LPF == LPS)
        {
            break;
        }
    }
    if(LPF == LPS)
    {
        size_t count = 1;
        LPS = LPS->next;
        while(LPS != LPF)
        {
            count++;
            LPS = LPS->next;
        }
        return count;
    }
    return 0;
}

LinkNode* GetCycleEntry(LinkNode* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head == NULL)
    {
        return NULL;
    }
    LinkNode* LPF = head;
    LinkNode* LPS = head;
    while(LPF != NULL && LPF->next != NULL)
    {
        LPF = LPF->next->next;
        LPS = LPS->next;
        if(LPF == LPS)
        {
            break;
        }
    }
    if(LPF == NULL || LPF->next == NULL )
    {
        return NULL;
    }
    LPS = head;
    while(LPF != LPS)
    {
        LPS = LPS->next;
        LPF = LPF->next;
    }
    return LPS;
}

LinkNode* HasCross(LinkNode* head1, LinkNode* head2)
{
    if(head1 == NULL || head2 == NULL)
    {
        return 0;
    }
    LinkNode* LP1 = head1;
    LinkNode* LP2 = head2;
    for(; LP1->next != NULL; LP1 = LP1->next);
    for(; LP2->next != NULL; LP2 = LP2->next);
    if(LP1 == LP2)
    {
        //两链表相交
        int count1 = 0;
        int count2 = 0;
        for(LP1 = head1; LP1->next != NULL; LP1 = LP1->next) count1++;
        for(LP2 = head2; LP2->next != NULL; LP2 = LP2->next) count2++;
        int distance = count1 > count2 ? count1 - count2 : count2 - count2;
        LP1 = head1;
        LP2 = head2;
        if(count1 > count2)
        {
            while(distance--)
            {
                LP1 = LP1->next;
            }
        }
        else
        {
            while(distance--)
            {
                LP2 = LP2->next;
            }
        }
        while(LP1 != LP2)
        {
            LP1 = LP1->next;
            LP2 = LP2->next;
        }
        return LP1;
    }
    return NULL;
}

/////////////////////////////////////////////////////////


int HasCrossWithCycle(LinkNode* head1, LinkNode* head2)
{
    if(head1 == NULL || head2 == NULL)
    {
        return 0;
    }
    if(HasCycle(head1) || HasCycle(head2))
    {
        //肯定有一个带环
        if(HasCycle(head1) && HasCycle(head2))
        {
            // 两条链表都带环，两种情况，相交有一个环，       不相交，有两个环
            LinkNode* point1 = GetCycleEntry(head1);
            LinkNode* point2 = GetCycleEntry(head2);
            if(point1 == point2)
            {
                //交点在环外
                return 1;
            }
            LinkNode* flag1 = point1->next;
            while(flag1 != point1)
            {
                if(flag1 == point2)
                {
                    //交点在环上
                    return 1;
                }
                flag1 = flag1->next;
            }
            //两条链表都各自有环，不相交
            return 0;
        }
        else
        {
            //一个带环，一个不带环 则肯定不相交
            return 0;
        }
    }
    else
    {
        //都不带环
        for(; head1->next != NULL; head1 = head1->next);
        for(; head2->next != NULL; head2 = head2->next);
        if(head1 == head2)
        {
            return 1;
        }
        return 0;
    }
}

LinkNode* UnionSet(LinkNode* head1, LinkNode* head2)
{
    if(head1 == NULL || head2 == NULL)
    {
        return NULL;
    }
    LinkNode *new_head = NULL;
    LinkNode *new_tail = NULL;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data > head2->data)
        {
            head2 = head2->next;
        }
        else if(head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else
        {
            if(new_head == NULL)
            {
                new_head = CreatLinkNode(head1->data);
                new_tail = new_head;
            }
            else
            {
                new_tail->next = CreatLinkNode(head1->data);
                new_tail = new_tail->next; 
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return new_head;
}


//typedef struct ComplexNode{
//    LinkType data;
//    struct ComplexNode* next;
//    struct ComplexNode* random;
//}ComplexNode;

ComplexNode* CreatNode(LinkType value)
{
    ComplexNode* new_node = malloc(sizeof(ComplexNode));
    if(new_node == NULL)
    {
        return NULL;
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

ComplexNode* CopyComplex1(ComplexNode* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    ComplexNode* new_head = CreatNode(head->data);
    ComplexNode* memory = head;   
    head = head->next;
    ComplexNode* new_tail = new_head;
    while(head != NULL)
    {
        new_tail->next = CreatNode(head->data);
        head = head->next;
    }
    int count = 0;
    new_tail = new_head;
    ComplexNode* PRandom = memory;
    ComplexNode* new_PRandom = new_head;
    for(head = memory; head != NULL; head = head->next, PRandom = memory)
    {
        if(head->random == NULL)
        {
            new_tail->random = NULL;
            continue;
        }
        while(PRandom != NULL)
        {
            if(PRandom == head->random)
            {
                break;
            }
            count++;
        }
        while(count)
        {
            new_PRandom = new_PRandom->next;
            count--;
        }
        new_tail->random = new_PRandom;
        new_PRandom = new_head;
    }
    return new_head;
}

ComplexNode* CopyComplex2(ComplexNode* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    
    ComplexNode* LPF = head->next;
    ComplexNode* LPS = head;
    for(; LPS != NULL; LPS = LPF, LPF = LPF->next)
    {
        LPS->next = malloc(sizeof(ComplexNode));
        if(LPS->next == NULL)
        {
            return NULL;
        }
        LPS->next->data = LPS->data;
        LPS->next->next = LPF;
        if(LPF == NULL)
        {
            break;
        }
    }
    ComplexNode* LP = head;
    for(; LP != NULL; LP = LP->next->next)
    {
        if(LP->random == NULL)
        {
            LP->next->random == NULL;
        }
        else
        {
            LP->next->random = LP->random->next;    
        }
    }
    LPS = head;
    LPF = head->next;
    ComplexNode* new_head = head->next;
    while(LPF->next != NULL)
    {
        LPS->next = LPF->next;
        LPS = LPS->next;
        LPF->next = LPS->next;
        LPF = LPF->next;
    }
    LPS->next = NULL;
    return new_head;

}

void ComplexNodePrint(ComplexNode* head)
{
    if(head == NULL)
    {
        return;
    }
    ComplexNode* P = head;
    while(head != NULL)
    {
        printf("[%c] ", head->data);
        head = head->next;
    }
    printf("\n");
    head = P;
    while(head != NULL)
    {
        if(head->random == NULL)
        {
            printf("[] ");
        }
        else
        {
            printf("[%c] ", head->random->data);
        }
        head = head->next;
    }
    printf("\n");
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

/////////////////////////////////////////////////////////////
void TestInsertBefore()
{
    FUNCHEAD;
    LinkNode *h;
    LinkListInit(&h);
    LinkListPushBack(&h, 'a');
    LinkListPushBack(&h, 'b');
    LinkListPushBack(&h, 'c');
    LinkListPushBack(&h, 'd');
    LinkListPrint(h);
    LinkListInsertBefore(&h, LinkListFind(h, 'a'), 'F');
    LinkListInsertBefore(&h, LinkListFind(h, 'c'), 'F');
    LinkListInsertBefore(&h, LinkListFind(h, 'd'), 'F');
    LinkListInsertBefore(&h, NULL, 'F');
    LinkListPrint(h);
}

void TestReverse()
{
    FUNCHEAD;
    LinkNode *h;
    LinkListInit(&h);
    LinkListPushBack(&h, 'a');
    LinkListPushBack(&h, 'b');
    LinkListPushBack(&h, 'c');
    LinkListPushBack(&h, 'd');
    LinkListPrint(h);
    LinkListResver(&h);
    LinkListPrint(h);
}

void TestReverse2()
{
    FUNCHEAD;
    LinkNode *h;
    LinkListInit(&h);
    LinkListPushBack(&h, 'a');
    LinkListPushBack(&h, 'b');
    LinkListPushBack(&h, 'c');
    LinkListPushBack(&h, 'd');
    LinkListPrint(h);
    LinkListResver2(&h);
    LinkListPrint(h);
}

void TestBubbleSort()
{
    FUNCHEAD;
    LinkNode *h;
    LinkListInit(&h);
    LinkListPushBack(&h, '3');
    LinkListPushBack(&h, '1');
    LinkListPushBack(&h, '4');
    LinkListPushBack(&h, '2');
    LinkListPrint(h);
    LinkListBubbleSort(h);
    LinkListPrint(h);
}

void TestMerge()
{
    FUNCHEAD;
    LinkNode *h1;
    LinkListInit(&h1);
    LinkListPushBack(&h1, '1');
    LinkListPushBack(&h1, '3');
    LinkListPushBack(&h1, '5');
    LinkListPushBack(&h1, '7');
    LinkNode *h2;
    LinkListInit(&h2);
    LinkListPushBack(&h2, '2');
    LinkListPushBack(&h2, '4');
    LinkListPushBack(&h2, '6');
    LinkListPushBack(&h2, '8');
    LinkNode* ret = LinkListMerge(h1, h2);
    LinkListPrint(ret);
}

void TestMidNote()
{
    FUNCHEAD;
    LinkNode *h1;
    LinkListInit(&h1);
    LinkListPushBack(&h1, 'a');
    LinkListPushBack(&h1, 'b');
    LinkListPushBack(&h1, 'c');
    LinkListPushBack(&h1, 'd');
    LinkListPushBack(&h1, 'e');
    LinkNode* midnode = FindMidNode(h1);
    printf("midnode expect c ,actral %c\n", midnode->data);
}

void TestLastKNode()

{
    FUNCHEAD;
    LinkNode *h1;
    LinkListInit(&h1);
    LinkListPushBack(&h1, 'a');
    LinkListPushBack(&h1, 'b');
    LinkListPushBack(&h1, 'c');
    LinkListPushBack(&h1, 'd');
    LinkListPushBack(&h1, 'e');
    LinkNode* lastknode = FindLastKNode(h1, 5);
    printf("lastknode expect a ,actral %c\n", lastknode->data);
    lastknode = FindLastKNode(h1, 1);
    printf("lastknode expect e ,actral %c\n", lastknode->data);
}

void TestEraseLastKNode()
{
    FUNCHEAD;
    LinkNode *h1;
    LinkListInit(&h1);
    LinkListPushBack(&h1, 'a');
    LinkListPushBack(&h1, 'b');
    LinkListPushBack(&h1, 'c');
    LinkListPushBack(&h1, 'd');
    LinkListPushBack(&h1, 'e');
    EraseLastKNode(&h1, 5);
    LinkListPrint(h1);
    EraseLastKNode(&h1, 1);
    LinkListPrint(h1);
    EraseLastKNode(&h1, 10);
    LinkListPrint(h1);
}

void TestHasCycle()
{
    FUNCHEAD;
    LinkNode *h1, *a, *b, *c, *d, *e;
    LinkListInit(&h1);
    a = CreatLinkNode('a'); 
    b = CreatLinkNode('b'); 
    c = CreatLinkNode('c'); 
    d = CreatLinkNode('d'); 
    e = CreatLinkNode('e'); 
    h1 = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    int ret;
    ret = HasCycle(h1);
    printf("expect 0, actual %d\n", ret);
    e->next = a;
    ret = HasCycle(h1);
    printf("expect 1, actual %d\n", ret);
    a->next = a;
    ret = HasCycle(h1);
    printf("expect 1, actual %d\n", ret);
    ret = HasCycle(NULL);
    printf("expect -1, actual %d\n", ret);
}

void TestGetCycleLen()
{
    FUNCHEAD;
    LinkNode *h1, *a, *b, *c, *d, *e;
    LinkListInit(&h1);
    a = CreatLinkNode('a'); 
    b = CreatLinkNode('b'); 
    c = CreatLinkNode('c'); 
    d = CreatLinkNode('d'); 
    e = CreatLinkNode('e'); 
    h1 = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    LinkListPrint(h1);
    size_t len;
    len = GetCycleLen(h1);
    printf("expect 0,actual %d\n", len);
    e->next = a;
    len = GetCycleLen(h1);
    printf("expect 5,actual %d\n", len);
    a->next = a;
    len = GetCycleLen(h1);
    printf("expect 1,actual %d\n",len);
}

void TestCycleEntery()
{
    FUNCHEAD;
    LinkNode *h1, *a, *b, *c, *d, *e;
    LinkListInit(&h1);
    a = CreatLinkNode('a'); 
    b = CreatLinkNode('b'); 
    c = CreatLinkNode('c'); 
    d = CreatLinkNode('d'); 
    e = CreatLinkNode('e'); 
    h1 = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = a;
    LinkNode* ret; 
    ret = GetCycleEntry(h1);
    printf("[%c|%p]\n", ret->data, ret);
    e->next = c;
    ret = GetCycleEntry(h1);
    printf("[%c|%p]\n", ret->data, ret);
}

void TestHasCross()
{
    FUNCHEAD;
    LinkNode *h1, *h2, *a, *b, *c, *d, *e, *f, *i;
    LinkListInit(&h1);
    e->next = a;
    a = CreatLinkNode('a'); 
    b = CreatLinkNode('b'); 
    c = CreatLinkNode('c'); 
    d = CreatLinkNode('d'); 
    e = CreatLinkNode('e'); 
    h1 = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    f = CreatLinkNode('f'); 
    i = CreatLinkNode('i');
    h2 = f;
    f->next = i;
    i->next = d;
    LinkNode* ret; 
    ret = HasCross(h1, h2);
    printf("[%c|%p]\n", ret->data, ret);
}
////////////////////////////////////////////////////

void TestHasCrossWithCycle()
{
    FUNCHEAD;
    LinkNode *h1, *h2, *a, *b, *c, *d, *e, *f, *i;
    LinkListInit(&h1);
    e->next = a;
    a = CreatLinkNode('a'); 
    b = CreatLinkNode('b'); 
    c = CreatLinkNode('c'); 
    d = CreatLinkNode('d'); 
    e = CreatLinkNode('e'); 
    h1 = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    f = CreatLinkNode('f'); 
    i = CreatLinkNode('i');
    h2 = f;
    f->next = i;
    int ret;
    ret = HasCrossWithCycle(h1, h2);
    printf("expect 0 actral %d\n",ret);
    i->next = c;
    ret = HasCrossWithCycle(h1, h2);
    printf("expect 1 actral %d\n",ret);
    e->next = d;
    ret = HasCrossWithCycle(h1, h2);
    printf("expect 1 actral %d\n",ret);
    e->next = b;
    ret = HasCrossWithCycle(h1, h2);
    printf("expect 1 actral %d\n",ret);
    i->next = NULL;
    ret = HasCrossWithCycle(h1, h2);
    printf("expect 0 actral %d\n",ret);
    i->next = f;
    ret = HasCrossWithCycle(h1, h2);
    printf("expect 0 actral %d\n",ret);

}

void TestUnionSet()
{
    FUNCHEAD;
    LinkNode *h1, *h2, *a, *b, *c, *d, *e, *f, *g, *h;
    LinkListInit(&h1);
    a = CreatLinkNode('1'); 
    b = CreatLinkNode('3'); 
    c = CreatLinkNode('5'); 
    d = CreatLinkNode('7'); 
    h1 = a;
    a->next = b;
    b->next = c;
    c->next = d;
    e = CreatLinkNode('1'); 
    f = CreatLinkNode('4'); 
    g = CreatLinkNode('7');
    h = CreatLinkNode('9'); 
    h2 = e;
    e->next = f;
    f->next = g;
    g->next = h;
    LinkNode* ret = UnionSet(h1, h2);
    LinkListPrint(ret);
}

void TestCopyComplex1()
{
    FUNCHEAD;
    ComplexNode* a = malloc(sizeof(ComplexNode));
    ComplexNode* b = malloc(sizeof(ComplexNode));
    ComplexNode* c = malloc(sizeof(ComplexNode));
    ComplexNode* d = malloc(sizeof(ComplexNode));
    ComplexNode* head = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;
    a->data = 'a';
    b->data = 'b';
    c->data = 'c';
    d->data = 'd';
    a->random = c;
    b->random = a;
    c->random = NULL;
    d->random = d;
    ComplexNodePrint(head);

}


void TestCopyComplex2()
{
    FUNCHEAD;
    ComplexNode* a = malloc(sizeof(ComplexNode));
    ComplexNode* b = malloc(sizeof(ComplexNode));
    ComplexNode* c = malloc(sizeof(ComplexNode));
    ComplexNode* d = malloc(sizeof(ComplexNode));
    ComplexNode* head = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;
    a->data = 'a';
    b->data = 'b';
    c->data = 'c';
    d->data = 'd';
    a->random = c;
    b->random = a;
    c->random = NULL;
    d->random = d;
    ComplexNodePrint(head);
    ComplexNode* ret;
    ret =  CopyComplex2(head);
    ComplexNodePrint(ret);
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
////////////////////////////////////////////////////////////
    TestInsertBefore();
    TestReverse();
    TestReverse2();
    TestBubbleSort();
    TestMerge();
    TestMidNote();
    TestLastKNode();
    TestEraseLastKNode();
    TestHasCycle();
    TestGetCycleLen();
    TestCycleEntery();
    TestHasCross();
////////////////////////////////////////////////////////////
    TestHasCrossWithCycle();
    TestUnionSet();
    TestCopyComplex1();
    TestCopyComplex2();
    return 0;
}
