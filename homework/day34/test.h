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


/** 
 * * @brief 逆序打印单链表. 
 * * 
 * * @param head 
 * */ 
 void LinkListReversePrint(LinkNode* head); 

 /** 
  * * @brief 不允许遍历链表, 在 pos之前插入 
  * * 
  * * @param head 
  * * @param pos 
  * * @param value 
  * */ 
  void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value); 

  LinkNode* JosephCycle(LinkNode* head, size_t food); 

  /** 
   * * @brief 单链表逆置 
   * * 
   * * @param head 
   * */ 
  void LinkListReverse(LinkNode** head); 
  void LinkListReverse2(LinkNode** head); 

  /** 
   * * @brief 单链表的冒泡排序 
   * * 
   * * @param head 
   * */ 
  void LinkListBubbleSort(LinkNode* head); 

  /** 
   * * @brief 将两个有序链表, 合并成一个有序链表 
   * * 
   * * @param head1 
   * * @param head2 
   * * 
   * * @return 
   * */ 
   LinkNode* LinkListMerge(LinkNode* head1, LinkNode* head2); 

   LinkNode* FindMidNode(LinkNode* head); 

   /** 
    * * @brief 找到倒数第 K 个节点. 
    * * 
    * * @param head 
    * * 
    * * @return 
    * */ 
    LinkNode* FindLastKNode(LinkNode* head, size_t K); 

    /** 
     * * @brief 删除倒数第K个节点 
     * * 
     * * @param head 
     * * @param K 
     * */ 
    void EraseLastKNode(LinkNode** head, size_t K); 

    /** 
     * * @brief 判定单链表是否带环. 如果带环返回1  不带环返回零 
     * * 
     * * @param head 
     * * 
     * * @return 
     * */ 
    int HasCycle(LinkNode* head); 

    /** 
     * * @brief 如果链表带环, 求出环的长度 
     * * 
     * * @param head 
     * * 
     * * @return 
     * */ 
    size_t GetCycleLen(LinkNode* head); 

    /** 
     * * @brief 如果链表带环, 求出环的入口 
     * * 
     * * @param head 
     * * 
     * * @return 
     * */ 
     LinkNode* GetCycleEntry(LinkNode* head); 

     /** 
      * * @brief 判定两个链表是否相交, 并求出交点 
      * * 
      * * @param head1 
      * * @param head2 
      * * 
      * * @return 
      * */ 
      LinkNode* HasCross(LinkNode* head1, LinkNode* head2);

      /** 
       * * @brief 判定两个链表是否相交. 但是链表可能带环 
       * * 
       * * @param head1 
       * * @param head2 
       * * 
       * * @return 如果相交, 返回1, 否则返回0 
       * */ 
       int HasCrossWithCycle(LinkNode* head1, LinkNode* head2); 

       /** 
        * * @brief 求两个有序链表的交集 
        * * 
        * * @param head1 
        * * @param head2 
        * * 
        * * @return 返回表示交集的新链表 
        * */ 
        LinkNode* UnionSet(LinkNode* head1, LinkNode* head2); 

        typedef struct ComplexNode { 
        LinkType data; 
        struct ComplexNode* next; 
        struct ComplexNode* random; 
        } ComplexNode; 

        /** 
         * * @brief 拷贝复杂链表 
         * * 
         * * @param head 
         * * 
         * * @return 
         * */ 
         ComplexNode* CopyComplex(ComplexNode* head); 
         ComplexNode* CopyComplex2(ComplexNode* head); 
