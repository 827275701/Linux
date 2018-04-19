#pragma once 

#define SeqListMaxSize 1000 
typedef char SeqType; 

typedef struct SeqList { 
    SeqType data[SeqListMaxSize]; 
    size_t size; 
} SeqList; 

/** 
* @brief 给一个顺序表进行初始化 
* 
* @param seq 表示一个顺序表结构的指针 
*/ 
void SeqListInit(SeqList* seq); 

/** 
* @brief 将一个元素插入到顺序表的末尾 
* 
* @param seq 顺序表结构的指针 
* @param value 新插入的值 
*/ 
void SeqListPushBack(SeqList* seq, SeqType value); 

/** 
* @brief 将顺序表的最后一个元素删除 
* 
* @param seq 顺序表结构的指针 
*/ 
void SeqListPopBack(SeqList* seq); 

/** 
* @brief 往顺序表的前面插入一个元素 
* 
* @param seq 顺序表结构的指针 
* @param value 新插入的值 
*/ 
void SeqListPushFront(SeqList* seq, SeqType value); 

/** 
* @brief 删除顺序表的第一个元素 
* 
* @param seq 顺序表结构的指针 
*/ 
void SeqListPopFront(SeqList* seq); 

/** 
* @brief 取顺序表中任意位置的一个元素 
* 
* @param seq 顺序表的指针 
* @param pos 要取的元素的下标 
* @param default_value 如果取元素失败, 就返回这个值 
* 
* @return 对应下标位置的元素的值 
*/ 
SeqType SeqListGet(SeqList* seq, size_t pos, SeqType default_value); 

/** 
* @brief 将顺序表中指定位置的值进行设置 
* 
* @param seq 顺序表的结构指针 
* @param pos 要修改的顺序表的元素位置 
* @param value 要设置的值. 
*/ 
void SeqListSet(SeqList* seq, size_t pos, 
                SeqType value); 

/** 
* @brief 查找顺序表中指定元素的下标 
* 
* @param seq 顺序表结构指针 
* @param value 要查找的值 
* 
* @return 对应值的下标. 如果找不到, 就返回 
* (size_t)-1 
*/ 
size_t SeqListFind(SeqList* seq, SeqType value); 

/** 
* @brief 在指定位置插入元素 
* 
* @param seq 顺序表指针 
* @param pos 要插入的位置 
* @param value 要插入的值. 
*/ 
void SeqListInsert(SeqList* seq, size_t pos, 
                   SeqType value); 

/** 
* @brief 删除指定位置的元素 
* 
* @param seq 顺序表指针 
* @param pos 要删除的元素位置 
*/ 
void SeqListErase(SeqList* seq, size_t pos); 

/** 
* @brief 删除顺序表中指定的值, 如果存在重复元素, 只删除第一个 
* 
* @param seq 顺序表指针 
* @param to_delete 待删除的值 
*/ 
void SeqListRemove(SeqList* seq, SeqType to_delete); 

/** 
* @brief 删除顺序表中所有的指定的值, 另外要实现一个时间复杂度为 O(N) 的优化版本 
* 
* @param seq 顺序表指针 
* @param to_delete 待删除的元素 
*/ 
void SeqListRemoveAll(SeqList* seq, SeqType to_delete); 

/** 
* @brief 获取顺序表元素个数 
* 
* @param seq 顺序表指针 
* 
* @return 顺序表元素的个数 
*/ 
size_t SeqListSize(SeqList* seq); 

/** 
* @brief 判定顺序表是否为空 
* 
* @param seq 顺序表指针 
* 
* @return 如果顺序表为空, 返回 1; 否则返回 0 
*/ 
int SeqListEmpty(SeqList* seq); 

/** 
* @brief 冒泡排序 
* 
* @param seq 顺序表指针 
*/ 
void SeqListBubbleSort(SeqList* seq); 


/** 
* @brief 冒泡排序 
* 
* @param seq 顺序表指针 
*/ 
//void SeqListBubbleSortEx(SeqList* seq, int (*cmp)(SType , SType)); 
