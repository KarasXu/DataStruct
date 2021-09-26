#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100             //����˳������󳤶�

typedef int ElemType;           //����˳����е�����Ϊ����

typedef struct
{
    ElemType data[MAXSIZE];     //������洢˳����е�Ԫ��
    unsigned int length;        //˳����е�Ԫ�ظ���
}SeqList, *PSeqList;

//˳���L�ĳ�ʼ������
void InitList(PSeqList L)
{
    if(L == NULL)               //�ж�˳����Ƿ����
    {
        return;
    }
    L->length = 0;              //���ñ�Ϊ0
    memset(L->data, 0, sizeof(ElemType)*MAXSIZE);       //����0��MAXSIZE��ǰ������L->data
};

//����˳���L
void DestoryList(PSeqList L)
{
    isExistL(L);
    return;
};

//��˳���ĵ�i��λ�ò���Ԫ��e������ֵ��-1��ʾ���Ա����Ԫ�ز����ڣ�0ʧ�ܣ�1�ɹ�
int InsertList(PSeqList L, unsigned int i, ElemType *e)
{
    isExistL(L);
    isExistE(e);
    isLegal(L, i);

    /*
    **��L->data[k-1](��β) ���Ƶ� L->data[k]
    **void *memcpy(void *str1, const void *str2, size_t n) �Ӵ洢�� str2 ���� n ���ֽڵ��洢�� str1
    */
    //��i֮���Ԫ������ƶ�
    int k;
    for(k = L->length; k >= i; k--)
    {
        //memcpy(L->data+k, L->data+k-1, sizeof(ElemType));
        memcpy(&L->data[k], &L->data[k-1], sizeof(ElemType));       //������ʽ
    }
    //��Ԫ��e����λ��i
    //memcpy(L->data+i-1, e, sizeof(ElemType));
    memcpy(&L->data[i-1], e, sizeof(ElemType));
    L->length++;        //����+1
    return 1;

};

//��˳���L��ͷ������Ԫ��e������ֵ��-1��ʾ���Ա����Ԫ�ز����ڣ�0ʧ�ܣ�1�ɹ�
int PushFront(PSeqList L, ElemType *e)
{
    return  InsertList(L, 1, e);
};

//��˳���L��β�ڵ����Ԫ��e������ֵ��-1��ʾ���Ա����Ԫ�ز����ڣ�0ʧ�ܣ�1�ɹ�
int PushBack(PSeqList L, ElemType *e)
{
    return  InsertList(L, L->length+1, e);
}

//��˳���ĳ��ȣ�����ֵ��-1��ʾ���Ա����ڣ����ⳣ��Ϊ���Ա���
int lengthList(PSeqList L)
{
    if(L == NULL)
    {
        return;
    }
    return L->length;
};

//��ȡ˳���L�е�i��Ԫ�ص�ֵ������ֵ��-1��ʾ���Ա�0ʧ�ܣ�1�ɹ�
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

//���˳���
void ClearList(PSeqList L)
{
    InitList(L);
};

//��ӡ˳����е�ȫ��Ԫ��
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

//����e��˳����е�λ�ã�����ֵ��-1��ʾ���Ա����ڣ�0��ʾλ�ò��Ϸ���1�ɹ�
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

//ɾ��˳����еĵ�i��Ԫ�أ�����ֵ��-1��ʾ���Ա����ڣ�0��ʾλ�ò��Ϸ���1�ɹ�
void DeleteElem(PSeqList L, unsigned int i)
{
    isExistL(L);
    isLegal(L, i);
    //��i֮���Ԫ����ǰ�ƶ�
    int k;
    for(k = i; k < L->length; k++)
    {
        //memcpy(L->data+k, L->data+k+1, sizeof(ElemType));
        memcpy(&L->data[k], &L->data[k+1], sizeof(ElemType));       //������ʽ
    }
    L->length--;        //����-1
    return 1;

};

//ɾ��˳����е�ͷԪ�أ�����ֵ��-1��ʾ���Ա����ڣ�0��ʾλ�ò��Ϸ���1�ɹ�
void PopFront(PSeqList L)
{
    return DeleteElem(L, 1);
};

//ɾ��˳����еĶ�βԪ�أ�����ֵ��-1��ʾ���Ա����ڣ�0��ʾλ�ò��Ϸ���1�ɹ�
void PopBack(PSeqList L)
{
    return DeleteElem(L, L->length);
};

//���ù鲢�ķ�������������˳���La��Lb�ϲ���һ������˳���Lc
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc)
{
    isExistL(La);
    isExistL(Lb);
};

//�ж�˳����Ƿ���ڣ�����λ���Ƿ�Ϸ�
void isExistL(PSeqList L)
{
    //˳���L����Ԫ��e�����ڣ�����-1
    if(L == NULL)
    {
        printf("˳�������\n");
        return -1;
    }
}


void isLegal(PSeqList L, unsigned int i)
{
    if(i < 1 || i > (L->length))
    {
        printf("�����λ�ò��Ϸ���\n");
    }
}


void isExistE(ElemType *e)
{
    //˳���L����Ԫ��e�����ڣ�����-1
    if(e == NULL)
    {
        printf("Ԫ�ز�����\n");
        return -1;
    }

}

void isEmpty(PSeqList L)
{
    if(L->length == 0)
    {
        printf("��Ϊ��\n");
    }
}


int main()
{
    int i;
    SeqList L;                  //����˳���
    ElemType e;                 //����һ������Ԫ��
    InitList(&L);               //��ʼ��˳���
    printf("��Ԫ�ر��в���Ԫ��(1,2,3,4,5,6,7,8,9,10)\n");
    for(i = 0; i < 10; i++)
    {
        e = i;
        InsertList(&L, 1, &e);
    }
    Printist(&L);
    return 0;
}
