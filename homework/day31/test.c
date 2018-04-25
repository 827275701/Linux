#include<stdio.h>
#include<stdlib.h>
#include"test.h"
#define HEADNAME printf("\n=========================%s======================\n",__FUNCTION__)


void SeqListInit(SeqList* seq)
{
    int i = 0;
    seq->size = 0;
    for(; i<SeqListMaxSize; ++i)
    {
        seq->data[i] = 0;
    }
}

void SeqListPrint(SeqList* seq)
{
    if(seq == NULL)
    {
        //空指针
        return;
    }
    int i = 0;
    for(; i < seq->size; ++i)
    {
        printf("[%c] ", seq->data[i]);
    }
    printf("\n");
}

void SeqListPushBack(SeqList* seq, SeqType value)
{
    if(seq == NULL)
    {  
        //非法输入
        return;
    }
    if(seq->size == SeqListMaxSize - 1)
    {
        //线性表满
        return;
    }
 
    seq->data[seq->size] = value;
    ++seq->size;
}

void SeqListPopBack(SeqList* seq)
{
    if(seq == NULL)
    {
        //输入错误
        return;
    }
    if(seq->size == 0)
    {
        //空线性表
        return;
    }

    seq->data[seq->size-1] = 0;
    --seq->size;
}

void SeqListPushFront(SeqList* seq, SeqType value)
{
    if(seq == NULL)
    {
        //非法输入
        return;
    }
    if(seq->size == SeqListMaxSize - 1)
    {
        //线性表满
        return;
    }
    
    int i = seq->size;
    while(i > 0)
    {
        seq->data[i] = seq->data[i-1];
        --i;
    }
    ++seq->size;
    seq->data[0] = value;
}

void SeqListPopFront(SeqList* seq)
{
    if(seq == NULL)
    {
        //非法输人
        return;
    }
    if(seq->size == 0)
    {
        //空顺序表
        return;
    }
    if(seq->size == 1)
    {
        --seq->size;
        seq->data[seq->size] = 0;
        return;
    }
    int i = 0;
    
    for(i = 0; i < seq->size-1; ++i)
    {
        seq->data[i] = seq->data[i+1];
    }
    --seq->size;
    seq->data[seq->size] = 0;
}

SeqType SeqListGet(SeqList* seq, size_t pos, SeqType default_value)
{
    if(seq == NULL || pos < 0 || pos >= seq->size)
    {
        //非法输入
        return default_value;
    }
    
    return seq->data[pos];
}


void SeqListSet(SeqList* seq, size_t pos, SeqType value)
{
    if(seq == NULL || pos < 0 || pos >= seq->size)
    {
        //非法输入
        return;
    }
    if(seq->size == 0)
    {
        //空线性表
        return;
    }
    seq->data[pos] = value;
}

int SeqLisFind(SeqList* seq, SeqType value)
{
    if(seq == NULL)
    {
        //非法输入
        return -1;
    }
    
    int i = 0;
    for(i = 0; i < seq->size; ++i)
    {
        if(seq->data[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void SeqListInsert(SeqList* seq, size_t pos, SeqType value)
{
    if(seq == NULL || pos < 0 || pos > seq->size)
    {
        //非法输入
        return;
    } 
    if(seq->size == SeqListMaxSize - 1)
    {
        //线性表满
        return;
    }
    int i = seq->size;
    for(i = seq->size; i > pos; --i)
    {
        seq->data[i] = seq->data[i-1];
    }
    seq->data[pos] = value;
    ++seq->size;
}

void SeqListErase(SeqList* seq, size_t pos)
{
    if(seq == NULL || pos < 0 || pos > seq->size)
    {
       //非法输入
        return;
    }
    if(seq->size == 0)
    {
        //空顺序表
        return;
    }
    while(pos < seq->size)
    {
        seq->data[pos] = seq->data[pos+1];
        pos++;
    }
    seq->data[pos] = 0;
    --seq->size;
}

void SeqListRemove(SeqList* seq, SeqType to_delete)
{
    if(seq == NULL)
    {
        //非法输入
        return;
    }
    if(seq->size == 0)
    {
        //空顺序表
        return;
    }

    int i = 0;
    int flag = 0;
    for(i = 0; i < seq->size; ++i)
    {
        if(seq->data[i] == to_delete)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        while(i < seq->size)
        {
            seq->data[i] = seq->data[i+1];
            ++i;
        }
        seq->data[i] = 0;
        --seq->size;
    }
}

void SeqListRemoveAll(SeqList* seq, SeqType to_delete)
{
    if(seq == NULL)
    {
        //非法输入
        return;
    }
    if(seq->size == 0)
    {
        //空顺序表
        return;
    }
    int i = 0;
    int count = 0;
    for(i = 0; i < seq->size; ++i)
    {
        if(seq->data[i] == to_delete)
        {
            count++;
            continue;
        }
        seq->data[i - count] = seq->data[i];
    }
    for(; count > 0; count--, seq->size--)
    {
        seq->data[seq->size - 1] = 0;
    }
}

size_t SeqListSize(SeqList* seq)
{
    return seq->size;
}

int SeqLisEmpty(SeqList* seq)
{
    if(seq->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void SeqListBubbleSort(SeqList* seq)
{
    int i = 0;
    int j = 0;
    int flag = 0;
    for(i = 0; i < seq->size; ++i)
    {
        for(j = i + 1; j<seq->size; ++j)
        {
            if(seq->data[i] > seq->data[j])
            {
                SeqType box;
                flag = 1;
                box = seq->data[i];
                seq->data[i] = seq->data[j];
                seq->data[j] = box;
            }
        }
        if(flag != 1)
        {
            return;
        }
    }
}
////////////////////////////////////////////////
//以下为测试代码
////////////////////////////////////////////////
SeqList seqlist;

void TestPushBack()
{
    HEADNAME;
    SeqListInit(&seqlist);
    SeqListPushBack(&seqlist, 'a');
    SeqListPushBack(&seqlist, 'b');
    SeqListPushBack(&seqlist, 'c');
    SeqListPushBack(&seqlist, 'd');
    SeqListPrint(&seqlist);
}

void TestPopBack()
{
    HEADNAME;
    SeqListInit(&seqlist);
    SeqListPushBack(&seqlist, 'a');
    SeqListPushBack(&seqlist, 'b');
    SeqListPushBack(&seqlist, 'c');
    SeqListPushBack(&seqlist, 'd');
    SeqListPopBack(&seqlist);
    SeqListPopBack(&seqlist);
    SeqListPrint(&seqlist);
}

void TestPushFront()
{   
    HEADNAME;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist, 'a');
    SeqListPushFront(&seqlist, 'b');
    SeqListPushFront(&seqlist, 'c');
    SeqListPushFront(&seqlist, 'd');
    SeqListPrint(&seqlist);
}

void TestPopFront()
{
    HEADNAME;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist, 'a');
    SeqListPushFront(&seqlist, 'b');
    SeqListPushFront(&seqlist, 'c');
    SeqListPushFront(&seqlist, 'd');
    SeqListPopFront(&seqlist);
    SeqListPopFront(&seqlist);
    SeqListPrint(&seqlist);
    SeqListPopFront(&seqlist);
    SeqListPrint(&seqlist);
    SeqListPopFront(&seqlist);
    SeqListPrint(&seqlist);
}

void TestGet()
{
    HEADNAME;
    SeqType ret;
    SeqListPushFront(&seqlist, 'a');
    SeqListPrint(&seqlist);
    ret = SeqListGet(&seqlist, 0, -1);
    printf("ret is %d\n", ret);
    ret = SeqListGet(&seqlist, 1, -1);
    printf("ret is %d\n", ret);
    SeqListPopFront(&seqlist);
}

void TestSet()
{
    HEADNAME;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist, 'a');
    SeqListPushFront(&seqlist, 'b');
    SeqListPushFront(&seqlist, 'c');
    SeqListPushFront(&seqlist, 'd');
    SeqListPrint(&seqlist);
    SeqListSet(&seqlist, 0, 'Z');
    SeqListSet(&seqlist, 4, 'X');
    SeqListSet(&seqlist, 3, 'Y');
    SeqListPrint(&seqlist);
}

void TestFind()
{
    HEADNAME;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist, 'a');
    SeqListPushFront(&seqlist, 'b');
    SeqListPushFront(&seqlist, 'c');
    SeqListPushFront(&seqlist, 'd');
    SeqListPrint(&seqlist);
    int pos = -1;
    pos = SeqLisFind(&seqlist, 'b');
    printf("[b] ---> %d\n", pos);
    pos = SeqLisFind(&seqlist, 's');
    printf("[s] ---> %d\n", pos);

}

void TestInsert()
{
    HEADNAME;
    SeqListInit(&seqlist);
    SeqListInsert(&seqlist, 0, 'z');
    SeqListInsert(&seqlist, 0, 'y');
    SeqListPrint(&seqlist);
    SeqListInsert(&seqlist, 0, 'x');
    SeqListInsert(&seqlist, 0, 'w');
    SeqListPrint(&seqlist);
}

void TestErase()
{
    HEADNAME;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist, 'a');
    SeqListPushFront(&seqlist, 'b');
    SeqListPushFront(&seqlist, 'c');
    SeqListPushFront(&seqlist, 'd');
    SeqListPrint(&seqlist);
    SeqListErase(&seqlist, 3);
    SeqListErase(&seqlist, 0);
    SeqListPrint(&seqlist);

}

void TestRomve()
{
    HEADNAME;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist, 'A');
    SeqListPushFront(&seqlist, 'B');
    SeqListPushFront(&seqlist, 'C');
    SeqListPushFront(&seqlist, 'D');
    SeqListPrint(&seqlist);
    SeqListRemove(&seqlist, 'A');    
    SeqListRemove(&seqlist, 'D');
    SeqListRemove(&seqlist, 's');
    SeqListPrint(&seqlist);

}
void TestEraseAll()
{
    HEADNAME;
    SeqListPushFront(&seqlist, 'A');
    SeqListPushFront(&seqlist, 'A');
    SeqListPushFront(&seqlist, 'A');
    SeqListPushFront(&seqlist, 'A');
    SeqListPushFront(&seqlist, 'A');
    SeqListPushBack(&seqlist, 'A');
    SeqListPushBack(&seqlist, 'A');
    SeqListPushBack(&seqlist, 'A');
    SeqListPushBack(&seqlist, 'A');
    SeqListPrint(&seqlist);
    SeqListRemoveAll(&seqlist, 'A');
    SeqListPrint(&seqlist);
}

void TestSize()
{
    HEADNAME;
    SeqListInit(&seqlist);
    size_t count = 0;
    count = SeqListSize(&seqlist);
    printf("seqlist->size :%d\n", count);
    SeqListPushFront(&seqlist, 'A');
    SeqListPushFront(&seqlist, 'B');
    SeqListPushFront(&seqlist, 'C');
    SeqListPushFront(&seqlist, 'D');
    count = SeqListSize(&seqlist);
    printf("seqlist->size :%d\n", count);
}

void TestEmpty()
{
    HEADNAME;
    SeqListInit(&seqlist);
    int count = SeqLisEmpty(&seqlist);
    //printf("SeqLisEmpty:%d\n", SeqLisEmpty(&seqlist));
    printf("SeqLisEmpty:%d\n", count);
    SeqListPushFront(&seqlist, 'A');
    SeqListPushFront(&seqlist, 'B');
    count = SeqLisEmpty(&seqlist);
    printf("SeqLisEmpty:%d\n", count);    
}

void TestBubbleSort()
{
    HEADNAME;
    SeqListInit(&seqlist);
    SeqListPushFront(&seqlist, 'd');
    SeqListPushFront(&seqlist, 'b');
    SeqListPushFront(&seqlist, 'a');
    SeqListPushFront(&seqlist, 'c');
    SeqListPrint(&seqlist);
    SeqListBubbleSort(&seqlist);
    SeqListPrint(&seqlist);
}


int main()
{
    TestPushBack();
    TestPopBack();
    TestPushFront();
    TestPopFront();
    TestGet();
    TestSet();
    TestFind();
    TestInsert();
    TestErase();
    TestRomve();
    TestEraseAll();
    TestSize();
    TestEmpty();
    TestBubbleSort();
    return 0;
}
