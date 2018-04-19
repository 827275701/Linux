#pragma once

typedef char  DLinkType;

typedef struct DLinkNode{
    DLinkType data;
    struct DLinkNode* prev;
    struct DLinkNode* next;
}DLinkNode;

/*
 *双向链表初始化
 */
void DLinkListInit(DLinkNode** head);

/*
 *尾插
 */
void DLinkListPushBack(DLinkNode* head, DLinkType value);

/*
 *尾删
 */
void DLinkListPopBack(DLinkNode* head);

/*
 *头插
 */
void DLinkListPushiFront(DLinkNode* head, DLinkType value);

/*
 *头删
 */
void DLinkListPopFront(DLinkNode* head);

/*
 *查找指定元素的位置
 */
DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find);

/*
* 在指定位置的前面插入一个元素
*/
void DLinkListInsert(DLinkNode* head, DLinkNode* pos, DLinkType to_insert);

/*
 *在指定位置的后面插入一个元素
 */
void DLinkListInsertAfter(DLinkNode* head, DLinkNode* pos, DLinkType to_insert);

/*
 *删除指定位置的元素
 */
void DLinkListErase(DLinkNode* head, DLinkNode* pos);

/*
 *删除指定元素
 */
void DLinkListRemove(DLinkNode* head, DLinkType to_delete);

/*
 *删除所有元素
 */
void DLinkListRemoveAll(DLinkNode* head);

/*
 *求双向链表的长度
 */
size_t DLinkListSize(DLinkNode* head);

/*
 *判断双向链表是否为空
 */
int DLinkEmpty(DLinkNode* head);


