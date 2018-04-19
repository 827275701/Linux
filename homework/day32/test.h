typedef char LinkType; 

typedef struct LinkNode { 
LinkType data; 
struct LinkNode* next; 
} LinkNode; 

/** 
* @brief 初始化链表 
* 
* @param head 
*/ 
void LinkListInit(LinkNode** head); 

/** 
* @brief 尾插一个元素到链表中 
* 
* @param head 
* @param value 
*/ 
void LinkListPushBack(LinkNode** head, LinkType value); 

/** 
* @brief 尾删一个元素 
* 
* @param head 
*/ 
void LinkListPopBack(LinkNode** head); 

/** 
* @brief 头插一个元素 
* 
* @param head 
* @param value 
*/ 
void LinkListPushFront(LinkNode** head, LinkType value); 

/** 
* @brief 头删一个元素 
* 
* @param head 
*/ 
void LinkListPopFront(LinkNode** head); 

/** 
* @brief 查找元素在链表中的位置 
* 
* @param head 
* @param to_find 要查找的值 
* 
* @return 这个值对应的节点的地址 
*/ 
LinkNode* LinkListFind(LinkNode* head, LinkType to_find); 

/** 
* @brief 在pos之前插入元素 
* 
* @param head 
* @param pos 
* @param value 
*/ 
void LinkListInsert(LinkNode** head, LinkNode* pos, LinkType value); 

/** 
* @brief 在pos之后插入元素 
* 
* @param head 
* @param pos 
* @param value 
*/ 
void LinkListInsertAfter(LinkNode** head, LinkNode* pos, LinkType value); 

/** 
* @brief 删除指定位置的元素 
*/ 
void LinkListErase(LinkNode** head, LinkNode* pos); 

void LinkListErase2(LinkNode** head, LinkNode** pos); 

/** 
* @brief 删除指定值的元素 
* 
* @param head 
* @param to_delete 
*/ 
void LinkListRemove(LinkNode** head, LinkType to_delete); 

/** 
* @brief 指定值的所有元素都删掉. 
* 
* @param head 
* @param value 
*/ 
void LinkListRemoveAll(LinkNode** head, LinkType value); 

/** 
* @brief 判定链表为空 
* 
* @return 链表为空, 返回1, 否则返回0 
*/ 
int LinkListEmpty(LinkNode* head); 

/** 
* @brief 求链表的元素个数 
* 
* @param head 
* 
* @return 
*/ 
size_t LinkListSize(LinkNode* head); 

/** 
* @brief 逆序打印单链表. 
* 
* @param head 
*/ 
void LinkListReversePrint(LinkNode* head); 

/*
* 约瑟夫环
*/
LinkNode* JosephCycle(LinkNode* head, size_t food); 
