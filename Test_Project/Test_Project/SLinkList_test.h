#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SLinkList {
	SLTDataType data;
	struct SLinkList* next;
}SLinkListNode;

//遍历链表
void SListPrint(SLinkListNode* phead);
//单链表销毁
void SListDestroy(SLinkListNode** pphead);

//将创建节点封装成一个函数
SLinkListNode* BuyNode(SLTDataType data);

//单链表尾插和头插
void SListPushBack(SLinkListNode** pphead, SLTDataType data);
void SListPushFront(SLinkListNode** pphead, SLTDataType data);

//单链表头删和尾删
void SListPopFront(SLinkListNode** pphead);
void SListPopBack(SLinkListNode** pphead);