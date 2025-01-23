#include "SLinkList_test.h"

//遍历链表
void SListPrint(SLinkListNode* phead) {
	//值拷贝
	SLinkListNode* cur = phead;
	while (cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
SLinkListNode* BuyNode(SLTDataType data) {
	SLinkListNode* newNode = (SLinkListNode*)malloc(sizeof(SLinkListNode));
	if (newNode == NULL) {
		perror("malloc failed");
		return;
	}
	//初始化结点
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//单链表尾插
void SListPushBack(SLinkListNode** pphead, SLTDataType data) {
	//创建节点
	SLinkListNode* newNode = BuyNode(data);

	//如果刚开始链表为空，直接将新结点作为第一个结点  !!!!!!!!!!!!!!!  重要步骤
	if (*pphead == NULL) {
		*pphead = newNode;
		return;
	}
	//尾插法需要先找到尾部			!!!!!!!!!!!!!!!  重要步骤
	SLinkListNode* tail = *pphead;
	while (tail->next != NULL) {	// tail->next 为空时，表示此时tail为尾部
		tail = tail->next;
	}
	//把最后一个结点和新结点连接上
	tail->next = newNode;
}
//单链表头插法
void SListPushFront(SLinkListNode** pphead, SLTDataType data) {
	SLinkListNode* newNode = BuyNode(data);
	//检查返回值
	if (newNode == NULL) {
		return;
	}
	newNode->next = *pphead;
	*pphead = newNode;
}
//单链表头删法
void SListPopFront(SLinkListNode** pphead) {
	if (*pphead == NULL) {
		printf("The list is already empty.\n");
		return;
	}
	SLinkListNode* curNode = *pphead;
	*pphead = curNode->next;
	curNode->next = NULL;
	free(curNode);
	curNode = NULL;
}
//单链表尾删法
void SListPopBack(SLinkListNode** pphead) {
	if (*pphead == NULL) {
		printf("The list is already empty.\n");
		return;
	}
	//尾删  需要找到最后一个节点的 上一个节点
	SLinkListNode* cur = *pphead;
	while (cur->next->next != NULL) {

	}
}

//单链表的销毁
void SListDestroy(SLinkListNode** pphead) {
	SLinkListNode* cur = *pphead;	//拿到第一个结点
	while (cur != NULL) {
		SLinkListNode* next = cur->next;	//保存下一个节点的地址
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}