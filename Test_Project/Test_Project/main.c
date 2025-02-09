#include "SLinkList_test.h"

void TestSLinkList() {
	SLinkListNode* head = NULL;

	SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPrint(head);	//复制打印

	SListPushFront(&head, 1);
	SListPushFront(&head, 2);
	SListPushFront(&head, 3);
	SListPushFront(&head, 4);
	SListPrint(head);	//复制打印

	SListPopFront(&head);
	SListPopFront(&head);
	SListPrint(head);	//复制打印

	SListPopFront(&head);
	SListPopFront(&head);
	SListPrint(head);	//复制打印

	SListPopFront(&head);
	SListPrint(head);	//复制打印
	SListPopFront(&head);
	SListPopFront(&head);
	SListPopFront(&head);
	SListPrint(head);	//复制打印
	SListPopFront(&head);
	SListPrint(head);	//复制打印
	SListDestroy(&head);
	
}
int main() {

	TestSLinkList();
	return 0;
}


