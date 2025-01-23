#include "SLinkList_test.h"

//��������
void SListPrint(SLinkListNode* phead) {
	//ֵ����
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
	//��ʼ�����
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//������β��
void SListPushBack(SLinkListNode** pphead, SLTDataType data) {
	//�����ڵ�
	SLinkListNode* newNode = BuyNode(data);

	//����տ�ʼ����Ϊ�գ�ֱ�ӽ��½����Ϊ��һ�����  !!!!!!!!!!!!!!!  ��Ҫ����
	if (*pphead == NULL) {
		*pphead = newNode;
		return;
	}
	//β�巨��Ҫ���ҵ�β��			!!!!!!!!!!!!!!!  ��Ҫ����
	SLinkListNode* tail = *pphead;
	while (tail->next != NULL) {	// tail->next Ϊ��ʱ����ʾ��ʱtailΪβ��
		tail = tail->next;
	}
	//�����һ�������½��������
	tail->next = newNode;
}
//������ͷ�巨
void SListPushFront(SLinkListNode** pphead, SLTDataType data) {
	SLinkListNode* newNode = BuyNode(data);
	//��鷵��ֵ
	if (newNode == NULL) {
		return;
	}
	newNode->next = *pphead;
	*pphead = newNode;
}
//������ͷɾ��
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
//������βɾ��
void SListPopBack(SLinkListNode** pphead) {
	if (*pphead == NULL) {
		printf("The list is already empty.\n");
		return;
	}
	//βɾ  ��Ҫ�ҵ����һ���ڵ�� ��һ���ڵ�
	SLinkListNode* cur = *pphead;
	while (cur->next->next != NULL) {

	}
}

//�����������
void SListDestroy(SLinkListNode** pphead) {
	SLinkListNode* cur = *pphead;	//�õ���һ�����
	while (cur != NULL) {
		SLinkListNode* next = cur->next;	//������һ���ڵ�ĵ�ַ
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}