#include<stdio.h>
#include<stdlib.h>
#include"DLinkList.h"

#define FUNCTION printf("\n===================================%s======================================\n", __FUNCTION__)

DLinkNode* CreatDLinkNode(DLinkType value){
    DLinkNode* new_node = (DLinkNode*)malloc(sizeof(DLinkNode));
    if(new_node == NULL)
    {
        return NULL;
    }
    new_node->data = value;
    new_node->prev = new_node;
    new_node->next = new_node;
    return new_node;
}

void DestroyDLinkNode(DLinkNode* to_destroy_node){
    if(to_destroy_node == NULL){
        return;
    }
    free(to_destroy_node);
}

void DLinkListInit(DLinkNode** head){
    if(head == NULL){
        return;
    }
    *head = CreatDLinkNode(0);
}

void DLinkListPushBack(DLinkNode* head, DLinkType value){
    if(head == NULL){
        return;
    }
    DLinkNode* tail = head->prev;;
    DLinkNode* new_node = CreatDLinkNode(value);
    if(new_node == NULL){
        return;
    }
    new_node->data = value;
    head->prev = new_node;
    new_node->next = head;
    tail->next = new_node;
    new_node->prev = tail;
}

void DLinkListPopBack(DLinkNode* head){
    if(head == NULL){
        return;
    }
    DLinkNode* tail = head->prev;
    head->prev = tail->prev;
    head->prev->next = head;
    DestroyDLinkNode(tail);
}

void DLinkListPushFront(DLinkNode* head, DLinkType value){
    if(head == NULL){
        return;
    }
    DLinkNode* new_node = CreatDLinkNode(value);
    if(new_node == NULL)
    {
        return;
    }
    DLinkNode* next = head->next;
    head->next = new_node;
    new_node->prev = head;
    new_node->next = next;
    next->prev = new_node;
}

void DLinkListPopFront(DLinkNode* head){
    if(head == NULL){
        return;
    }
    DLinkNode* to_destroy_node = head->next;
    head->next = to_destroy_node->next;
    to_destroy_node->next->prev = head;
    DestroyDLinkNode(to_destroy_node);
}

DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find){
    if(head == NULL){
        return NULL;
    }
    DLinkNode* cur = head->next;
    for(; cur != head; cur = cur->next){
        if(cur->data == to_find){
            return cur;
        }
    }
}

void DLinkListInsert(DLinkNode* head, DLinkNode* pos, DLinkType value){
    if(head == NULL || pos == NULL){
        return;
    }
    DLinkNode* cur = head->next;
    for(; cur != head; cur = cur->next){
        if(cur == pos){
            DLinkNode* prev = CreatDLinkNode(value);
            cur->prev->next = prev;
            prev->prev =  cur->prev;
            prev->next = cur;
            cur->prev = prev;
            return;
        }
    }
}

void DLinkListInsertAfter(DLinkNode* head, DLinkNode* pos , DLinkType value){
    if(head == NULL || pos == NULL){
        return;
    }
    DLinkNode* cur = head->next;
    for(; cur != head; cur = cur->next){
        if(cur == pos){
            DLinkNode* next = CreatDLinkNode(value);
            next->next = cur->next;
            next->prev = cur;
            cur->next = next;
            next->next->prev = next;
            return;
        }
    }
}

void DLinkListErase(DLinkNode* head, DLinkNode* pos){
    if(head == NULL || pos == NULL){
        return;
    }
    DLinkNode* cur = head->next;
    for(; cur != head; cur = cur->next){
        if(cur == pos){
            DLinkNode* prev = cur->prev;
            prev->next = cur->next;
            cur->next = prev;
            DestroyDLinkNode(cur);
            return;
        }
    }
}

void DLinkListRemove(DLinkNode* head, DLinkType to_delete){
    if(head == NULL){
        return;
    }
    DLinkNode* cur = head->next;
    for(; cur != head; cur = cur->next){
        if(cur->data == to_delete){
            DLinkNode* prev = cur->prev;
            prev->next = cur->next;
            cur->next = prev;
            DestroyDLinkNode(cur);
            return;
        }
    }
}

void DLinkListRemoveAll(DLinkNode* head){
    if(head == NULL){
        return;
    }
    DLinkNode* cur = head->next;
    for(; cur != head; cur = head->next){
        head->next = cur->next;
        DestroyDLinkNode(cur);
    }
}

size_t DLinkListSize(DLinkNode* head){
    if(head == NULL){
        return 0;
    }
    size_t ret = 0;
    DLinkNode* cur = head->next;
    for(; cur != head; cur = cur->next){
        ret++;
    }
    return ret;
}

int DLinkListEmpty(DLinkNode* head){
    if(head == NULL){
        return 0;
    }
    if(head->prev == head && head->next == head)
    {
        return 0;
    }
    return 1;
}
////////////////////////////////////////////////////
//以下为测试代码
////////////////////////////////////////////////////

void Print(DLinkNode* head, char* str){
    DLinkNode* cur = head->next;
    printf("[%s]\n", str);
    while(cur != head)
    {
        printf("[%c] ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}


void TestInit()
{
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    printf("head->data expected 0, actrue is %d\n", head->data);
    printf("head->prev expected %p, actrue is %p\n", head, head->prev);
    printf("head->next expected %p, actrue is %p\n", head, head->next);
}

void TestPushBack(){
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head, 'a');
    DLinkListPushBack(head, 'b');
    DLinkListPushBack(head, 'c');
    DLinkListPushBack(head, 'd');
    Print(head,"尾插四个元素");
}

void TestPopBack(){
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head, 'a');
    DLinkListPushBack(head, 'b');
    DLinkListPushBack(head, 'c');
    DLinkListPushBack(head, 'd');
    DLinkListPopBack(head);
    DLinkListPopBack(head);
    Print(head,"尾删两个元素");
    DLinkListPopBack(head);
    DLinkListPopBack(head);
    Print(head,"再尾删两个元素");
    DLinkListPopBack(head);
    Print(head,"尾差空链表");
}

void TestPushFront(){
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head, 'a');   
    DLinkListPushFront(head, 'b');   
    DLinkListPushFront(head, 'c');   
    DLinkListPushFront(head, 'd');   
    Print(head,"头插四个元素");
}

void TestPopFront(){
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head, 'a');   
    DLinkListPushFront(head, 'b');   
    DLinkListPushFront(head, 'c');   
    DLinkListPushFront(head, 'd');   
    DLinkListPopFront(head);
    DLinkListPopFront(head);
    Print(head,"头删两个元素");
    DLinkListPopFront(head);
    DLinkListPopFront(head);
    Print(head,"再头删两个元素");
    DLinkListPopFront(head);
    Print(head,"头删空链表");
}

void TestFind(){
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head, 'a');   
    DLinkListPushFront(head, 'b');   
    DLinkListPushFront(head, 'c');   
    DLinkListPushFront(head, 'd');   
    DLinkNode* ret;
    ret = DLinkListFind(head, 'a');
    printf("expected %p, actrue %p\n", head->prev, ret);
    ret = DLinkListFind(head, 'd');
    printf("expected %p, actrue %p\n", head->next, ret);
}

void TestInsert(){
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head, 'a');   
    DLinkListPushFront(head, 'b');   
    DLinkListPushFront(head, 'c');   
    DLinkListPushFront(head, 'd');   
    Print(head, "头插四个元素");
    DLinkNode* pos;
    pos = DLinkListFind(head, 'a');
    DLinkListInsert(head, pos, 'X');
    Print(head, "指定位置前插入一个元素");
    pos = DLinkListFind(head, 'd');
    DLinkListInsert(head, pos, 'Y');
    Print(head, "指定位置前插入一个元素");

}

void TestInsertAfter(){
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head, 'a');   
    DLinkListPushFront(head, 'b');   
    DLinkListPushFront(head, 'c');   
    DLinkListPushFront(head, 'd');   
    Print(head, "头插四个元素");
    DLinkNode* pos;
    pos = DLinkListFind(head, 'a');
    DLinkListInsertAfter(head, pos, 'X');
    Print(head, "指定位置后插入一个元素");
    pos = DLinkListFind(head, 'd');
    DLinkListInsertAfter(head, pos, 'Y');
    Print(head, "指定位置后插入一个元素");
}

void TestErase(){
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head, 'a');   
    DLinkListPushFront(head, 'b');   
    DLinkListPushFront(head, 'c');   
    DLinkListPushFront(head, 'd');   
    Print(head, "头插四个元素");
    DLinkNode* pos;
    pos = DLinkListFind(head, 'a');
    DLinkListErase(head, pos);
    Print(head, "删除a");
    pos = DLinkListFind(head, 'd');
    DLinkListErase(head, pos);
    Print(head, "删除d");
    pos = DLinkListFind(head, 'A');
    DLinkListErase(head, pos);
    Print(head, "删除没有的元素");
}

void TestRemove(){
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head, 'a');   
    DLinkListPushFront(head, 'b');   
    DLinkListPushFront(head, 'c');   
    DLinkListPushFront(head, 'd');   
    Print(head, "头插四个元素");
    DLinkListRemove(head, 'a');
    Print(head, "删除a");
    DLinkListRemove(head, 'd');
    Print(head, "删除d");
    DLinkListRemove(head, 'A');
    Print(head, "删除没有的元素");
}

void TestRemoveAll(){
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head, 'a');   
    DLinkListPushFront(head, 'b');   
    DLinkListPushFront(head, 'c');   
    DLinkListPushFront(head, 'd');   
    Print(head, "头插四个元素");
    DLinkListRemoveAll(head);
    Print(head, "删除所有元素");
    DLinkListRemoveAll(head);
    Print(head, "对空链表进行删除");
}

void TestSize(){
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    size_t ret;
    DLinkListPushFront(head, 'a');   
    DLinkListPushFront(head, 'b');   
    Print(head, "头插两个元素");
    ret = DLinkListSize(head);
    printf("expected 2, actrue %u\n", ret);
    DLinkListPushFront(head, 'c');   
    DLinkListPushFront(head, 'd');   
    Print(head, "头插四个元素");
    ret = DLinkListSize(head);
    printf("expected 4, actrue %u\n", ret);
}

void TestEmpty(){
    FUNCTION;
    DLinkNode* head;
    DLinkListInit(&head);
    int ret;
    ret = DLinkListEmpty(head);
    printf("expected 0, actrue %d\n", ret);
    DLinkListPushFront(head, 'a');   
    DLinkListPushFront(head, 'b');   
    Print(head, "头插两个元素");
    ret = DLinkListEmpty(head);
    printf("expected 1, actrue %d\n", ret);

}

int main()
{
    TestInit();
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
    TestSize();
    TestEmpty();
    return 0;
}
