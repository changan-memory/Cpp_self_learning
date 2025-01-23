#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SLinkList {
	SLTDataType data;
	struct SLinkList* next;
}SLinkListNode;

//��������
void SListPrint(SLinkListNode* phead);
//����������
void SListDestroy(SLinkListNode** pphead);

//�������ڵ��װ��һ������
SLinkListNode* BuyNode(SLTDataType data);

//������β���ͷ��
void SListPushBack(SLinkListNode** pphead, SLTDataType data);
void SListPushFront(SLinkListNode** pphead, SLTDataType data);

//������ͷɾ��βɾ
void SListPopFront(SLinkListNode** pphead);
void SListPopBack(SLinkListNode** pphead);