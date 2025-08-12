// ¶ş²æËÑË÷Ê÷
// ¶ş²æËÑË÷Ê÷
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
	t.Inorder();
	for (auto e : a) {
		t.erase(e);
	}
	t.Inorder();
}
int main() {
	//test_insert();
	test_erase();
	return 0;
}