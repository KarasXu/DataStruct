#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100             //定义顺序表的最大长度

typedef int ElemType;           //定义顺序表中的数据为整数

typedef struct
{
    ElemType data[MAXSIZE];     //用数组存储顺序表中的元素
    unsigned int length;        //顺序表中的元素个数
}SeqList, *PSeqList;

//顺序表L的初始化操作
void InitList(PSeqList L)
{
    if(L == NULL)               //判断顺序表是否存在
    {
        return;
    }
    L->length = 0;              //设置表长为0
    memset(L->data, 0, sizeof(ElemType)*MAXSIZE);       //复制0到MAXSIZE以前的所有L->data
};

//销毁顺序表L
void DestoryList(PSeqList L)
{
    isExistL(L);
    return;
};

//在顺序表的第i个位置插入元素e，返回值：-1表示线性表或者元素不存在；0失败；1成功
int InsertList(PSeqList L, unsigned int i, ElemType *e)
{
    isExistL(L);
    isExistE(e);
    isLegal(L, i);

    /*
    **从L->data[k-1](队尾) 复制到 L->data[k]
    **void *memcpy(void *str1, const void *str2, size_t n) 从存储区 str2 复制 n 个字节到存储区 str1
    */
    //把i之后的元素向后移动
    int k;
    for(k = L->length; k >= i; k--)
    {
        //memcpy(L->data+k, L->data+k-1, sizeof(ElemType));
        memcpy(&L->data[k], &L->data[k-1], sizeof(ElemType));       //数组形式
    }
    //将元素e插入位置i
    //memcpy(L->data+i-1, e, sizeof(ElemType));
    memcpy(&L->data[i-1], e, sizeof(ElemType));
    L->length++;        //表长度+1
    return 1;

};

//在顺序表L的头结点插入元素e，返回值：-1表示线性表或者元素不存在；0失败；1成功
int PushFront(PSeqList L, ElemType *e)
{
    return  InsertList(L, 1, e);
};

//在顺序表L的尾节点插入元素e，返回值：-1表示线性表或者元素不存在；0失败；1成功
int PushBack(PSeqList L, ElemType *e)
{
    return  InsertList(L, L->length+1, e);
}

//求顺序表的长度，返回值：-1表示线性表不存在；任意常数为线性表长度
int lengthList(PSeqList L)
{
    if(L == NULL)
    {
        return;
    }
    return L->length;
};

//获取顺序表L中第i个元素的值，返回值：-1表示线性表；0失败；1成功
int GetItem(PSeqList L, unsigned int i, ElemType *e)
{
    isExistL(L);
    isExistE(e);
    isLegal(L, i);
    /*
    for(int k = 0, k <= i; k++)
    {
        if(k == i-1)
        {

        }
    }
    */
    //memcpy(e, L->data+i-1, sizeof(ElemType));
    memcpy(e, &L->data[i-1], sizeof(ElemType));
};

//清空顺序表
void ClearList(PSeqList L)
{
    InitList(L);
};

//打印顺序表中的全部元素
void Printist(PSeqList L)
{
    isExistL(L);
    isEmpty(L);
    int k;
    for(k = 0; (k < L->length); k++)
    {
        //printf("%-3d", L->data+k);
        printf("%-3d", L->data[k]);
    }
    printf("\n");
};

//查找e在顺序表中的位置，返回值：-1表示线性表不存在；0表示位置不合法；1成功
int LocateElem(PSeqList L, ElemType *e)
{
    isExistL(L);
    isExistE(e);
    int k;
    for(k = 0; k < L->length; k++)
    {
        if(L->data[k] == *e)
        {
            return k + 1;
        }
    }
    return 0;

};

//删除顺序表中的第i个元素，返回值：-1表示线性表不存在；0表示位置不合法；1成功
void DeleteElem(PSeqList L, unsigned int i)
{
    isExistL(L);
    isLegal(L, i);
    //把i之后的元素向前移动
    int k;
    for(k = i; k < L->length; k++)
    {
        //memcpy(L->data+k, L->data+k+1, sizeof(ElemType));
        memcpy(&L->data[k], &L->data[k+1], sizeof(ElemType));       //数组形式
    }
    L->length--;        //表长度-1
    return 1;

};

//删除顺序表中的头元素，返回值：-1表示线性表不存在；0表示位置不合法；1成功
void PopFront(PSeqList L)
{
    return DeleteElem(L, 1);
};

//删除顺序表中的队尾元素，返回值：-1表示线性表不存在；0表示位置不合法；1成功
void PopBack(PSeqList L)
{
    return DeleteElem(L, L->length);
};

//采用归并的方法将两个升序顺序表La和Lb合并成一个升序顺序表Lc
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc)
{
    isExistL(La);
    isExistL(Lb);
};

//判断顺序表是否存在，插入位置是否合法
void isExistL(PSeqList L)
{
    //顺序表L或者元素e不存在，返回-1
    if(L == NULL)
    {
        printf("顺序表不存在\n");
        return -1;
    }
}


void isLegal(PSeqList L, unsigned int i)
{
    if(i < 1 || i > (L->length))
    {
        printf("插入的位置不合法！\n");
    }
}


void isExistE(ElemType *e)
{
    //顺序表L或者元素e不存在，返回-1
    if(e == NULL)
    {
        printf("元素不存在\n");
        return -1;
    }

}

void isEmpty(PSeqList L)
{
    if(L->length == 0)
    {
        printf("表为空\n");
    }
}


int main()
{
    int i;
    SeqList L;                  //创建顺序表
    ElemType e;                 //创建一个数据元素
    InitList(&L);               //初始化顺序表
    printf("在元素表中插入元素(1,2,3,4,5,6,7,8,9,10)\n");
    for(i = 0; i < 10; i++)
    {
        e = i;
        InsertList(&L, 1, &e);
    }
    Printist(&L);
    return 0;
}
