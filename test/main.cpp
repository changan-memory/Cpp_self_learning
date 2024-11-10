//单链表(大众写法)   配合typedef

#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
//typedef struct book {	
//	string name;
//	long id;
//}book;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, *headNode;

headNode creatLinkList() {
	LNode* headNode = new LNode;
	headNode->next = nullptr;
	return headNode;
}

LNode* creatNode(int data) {
	LNode* newNode = new LNode;
	newNode->data = data;
	newNode->next = nullptr;
	return newNode;
}

void InsertNodeByhead(LNode* headNode, int data) {
	LNode* newNode = creatNode(data);
	newNode->data = data;
	newNode->next = headNode->next;
	headNode->next = newNode;
}

void deleteNodeByVal(LNode* headNode, int posData) {
	LNode* posNode = headNode->next;
	LNode* posNodeFont = headNode;
	while (posNode->data != posData) {
		posNodeFont = posNode;
		posNode = posNodeFont->next;
	}
	posNodeFont->next = posNode->next;
	delete posNode;
}

void printList(LNode* headNode) {
	LNode* pMove = headNode->next;
	assert(pMove);
	while (pMove) {
		cout << pMove->data<<" ";
		pMove = pMove->next;
	}
	cout << "\n";
}

int main() {
	LNode* headNode = creatLinkList();
	InsertNodeByhead(headNode, 5);
	InsertNodeByhead(headNode, 4);
	InsertNodeByhead(headNode, 3);
	InsertNodeByhead(headNode, 2);
	InsertNodeByhead(headNode, 1);
	printList(headNode);
	deleteNodeByVal(headNode, 3);
	printList(headNode);

	return 0;
}