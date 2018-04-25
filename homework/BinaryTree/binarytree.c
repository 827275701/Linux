#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"
#include"SeqQueue.h"

void TreeInit(TreeNode** root) {
    if(root == NULL) {
        //非法输入
        return;
    }
    *root = NULL;
}

TreeNode* CreatTreeNode(TreeNodeType data) {
    TreeNode* new_node = malloc(sizeof(TreeNode)); 
    new_node->data = data;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    return new_node;
}

void DestroyTreeNode(TreeNode* node) {
    if(node == NULL) {
        return;
    }
    free(node);
}

void PreOrder(TreeNode* root) {
    if(root == NULL) {
        //空树
        return;
    }
    printf("%c ", root->data);
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}
    
void InOrder(TreeNode* root) {
    if(root == NULL) {
        //空树
        return;
    }
    InOrder(root->lchild);
    printf("%c ", root->data);
    InOrder(root->rchild);
}

void PostOrder(TreeNode* root) {
    if(root == NULL) {
        //空树
        return;
    }
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    printf("%c ", root->data);
}

void LevelOrder(TreeNode* root) {
    if(root == NULL) {
        //空树
        return;
    }
    SeqQueue queue;
    SeqQueueInit(&queue);
    SeqQueueIn(&queue, root);
    TreeNode* cur;
    while(1) {
        if(queue.size == 0) {
            break;
        }
        SeqQueueFront(&queue, &cur);
        printf("%c ", cur->data);
        if(cur->lchild != NULL) {
            SeqQueueIn(&queue, cur->lchild);
        }
        if(cur->rchild != NULL) {
            SeqQueueIn(&queue, cur->rchild);
        }
        SeqQueueOut(&queue);
    }    
    printf("\n");
}
////////////////////////////////////////////////////////////////////////////
//以下为测试代码
////////////////////////////////////////////////////////////////////////////
#if 1
#define FUNHEAD printf("\n==========================%s=========================\n", __FUNCTION__)

void TestPreOrder() {
    FUNHEAD;
    TreeNode* root;
    TreeInit(&root);
    TreeNode *a, *b, *c, *d, *e, *f, *g;
    a = CreatTreeNode('a');
    b = CreatTreeNode('b');
    c = CreatTreeNode('c');
    d = CreatTreeNode('d');
    e = CreatTreeNode('e');
    f = CreatTreeNode('f');
    g = CreatTreeNode('g');
    root = a;
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    c->rchild = f;
    e->lchild = g;
   PreOrder(root);
    printf("\n");
}


void TestInOrder() {
    FUNHEAD;
    TreeNode* root;
    TreeInit(&root);
    TreeNode *a, *b, *c, *d, *e, *f, *g;
    a = CreatTreeNode('a');
    b = CreatTreeNode('b');
    c = CreatTreeNode('c');
    d = CreatTreeNode('d');
    e = CreatTreeNode('e');
    f = CreatTreeNode('f');
    g = CreatTreeNode('g');
    root = a;
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    c->rchild = f;
    e->lchild = g;
    InOrder(root);
    printf("\n");
}

void TestPostOrder() {
    FUNHEAD;
    TreeNode* root;
    TreeInit(&root);
    TreeNode *a, *b, *c, *d, *e, *f, *g;
    a = CreatTreeNode('a');
    b = CreatTreeNode('b');
    c = CreatTreeNode('c');
    d = CreatTreeNode('d');
    e = CreatTreeNode('e');
    f = CreatTreeNode('f');
    g = CreatTreeNode('g');
    root = a;
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    c->rchild = f;
    e->lchild = g;
    PostOrder(root);
    printf("\n");
}

void TestLevelOrder() {
    FUNHEAD;
    TreeNode* root;
    TreeInit(&root);
    TreeNode *a, *b, *c, *d, *e, *f, *g;
    a = CreatTreeNode('a');
    b = CreatTreeNode('b');
    c = CreatTreeNode('c');
    d = CreatTreeNode('d');
    e = CreatTreeNode('e');
    f = CreatTreeNode('f');
    g = CreatTreeNode('g');
    root = a;
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    c->rchild = f;
    e->lchild = g;
    LevelOrder(root);
    printf("\n");
}

int main()
{
    TestPreOrder();
    TestInOrder();
    TestPostOrder();
    TestLevelOrder();
    return 0;
}

#endif

