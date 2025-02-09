#include "SLinkList_test.h"

void TestSLinkList() {
	SLinkListNode* head = NULL;

	SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPrint(head);	//���ƴ�ӡ

	SListPushFront(&head, 1);
	SListPushFront(&head, 2);
	SListPushFront(&head, 3);
	SListPushFront(&head, 4);
	SListPrint(head);	//���ƴ�ӡ

	SListPopFront(&head);
	SListPopFront(&head);
	SListPrint(head);	//���ƴ�ӡ

	SListPopFront(&head);
	SListPopFront(&head);
	SListPrint(head);	//���ƴ�ӡ

	SListPopFront(&head);
	SListPrint(head);	//���ƴ�ӡ
	SListPopFront(&head);
	SListPopFront(&head);
	SListPopFront(&head);
	SListPrint(head);	//���ƴ�ӡ
	SListPopFront(&head);
	SListPrint(head);	//���ƴ�ӡ
	SListDestroy(&head);
	
}
int main() {

	TestSLinkList();
	return 0;
}


