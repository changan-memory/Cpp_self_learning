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
int main() {
	test_insert();
	return 0;
}