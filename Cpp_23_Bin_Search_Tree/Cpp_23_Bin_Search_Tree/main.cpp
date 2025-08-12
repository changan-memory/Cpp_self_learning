// ¶þ²æËÑË÷Ê÷
// ¶þ²æËÑË÷Ê÷
#include "BinarySearchTree.h"
void test_insert() {
	BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a) {
		t.insert(e);
	}
	t.Inorder();
}
void test_erase() {
	BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a) {
		t.insert(e);
	}
	t.erase(3);
	t.Inorder();
	t.erase(8);
	t.Inorder();
	t.erase(7);
	t.Inorder();
	t.erase(3);
	t.Inorder();
	t.erase(14);
	t.erase(6);
	t.Inorder();
	t.Inorder();
	for (auto e : a) {
		t.erase(e);
	}
	t.Inorder();
}
void test_erase_R() {
	BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a) {
		t.insert_R(e);
	}
	t.erase_R(3);
	t.Inorder();
	t.erase_R(8);
	t.Inorder();
	t.erase_R(7);
	t.Inorder();
	t.erase_R(3);
	t.Inorder();
	t.erase_R(14);
	t.Inorder();
	t.erase_R(6);
	t.Inorder();
	for (auto e : a) {
		t.erase_R(e);
	}
	t.Inorder();
}
void test_destructor() {
	BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a) {
		t.insert_R(e);
	}
	t.Inorder();
}
void test_copyConstructor() {
	BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a) {
		t.insert_R(e);
	}
	BSTree<int> t1(t);
	t.Inorder();
	t1.Inorder();
	BSTree<int> t2;
	t2 = t1;
	t2.Inorder();
}
int main() {
	//test_insert();
	//test_erase();
	//test_erase_R();
	//test_destructor();
	test_copyConstructor();
	return 0;
}