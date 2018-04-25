#pragma once 

typedef char TreeNodeType; 

typedef struct TreeNode { 
    TreeNodeType data; 
    struct TreeNode* lchild; 
    struct TreeNode* rchild; 
} TreeNode; 

void TreeInit(TreeNode** root); 

void PreOrder(TreeNode* root); 

void InOrder(TreeNode* root); 

void PostOrder(TreeNode* root); 

void LevelOrder(TreeNode* root); 

/** 
* @brief 根据先序遍历结果(带有空节点标记), 
* 构造一棵树 
* 
* @param array[] 先序遍历的结果 
* @param size 数组中元素个数
* @param null_node 数组中空节点的特殊标记. 
* 
* @return 
*/ 
TreeNode* TreeCreate(TreeNodeType array[], 
                     size_t size, TreeNodeType null_node); 

void TreeDestroy(TreeNode** root); 

TreeNode* TreeClone(TreeNode* root); 

size_t TreeSize(TreeNode* root); 

/** 
* @brief 求一棵树的叶子节点个数 
* 
* @param root 
* 
* @return 
*/ 
size_t TreeLeafSize(TreeNode* root); 

/** 
* @brief 求一棵树第 K 层节点的个数 
* 
* @param root 
* 
* @return 
*/ 
size_t TreeKLevelSize(TreeNode* root, int K); 

size_t TreeHeight(TreeNode* root); 

TreeNode* TreeFind(TreeNode* root, TreeNodeType to_find); 

TreeNode* LChild(TreeNode* node); 

TreeNode* RChild(TreeNode* node); 

TreeNode* Parent(TreeNode* root, TreeNode* node); 

void PreOrderByLoop(TreeNode* root); 

void InOrderByLoop(TreeNode* root); 

void PostOrderByLoop(TreeNode* root); 

void TreeMirror(TreeNode* root); 

int IsCompleteTree(TreeNode* root);
