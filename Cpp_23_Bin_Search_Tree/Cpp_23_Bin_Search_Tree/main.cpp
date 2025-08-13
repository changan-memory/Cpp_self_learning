// ����������
// ����������
#include "BinarySearchTree.h"
namespace K {
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
}

namespace K_V {
	// ���׵��ֵ��ѯ����
	void test1() {
		BSTree<string, string> dict;
		dict.insert_R("sort", "����");
		dict.insert_R("sex", "�Ըе�");
		dict.insert("gender", "�Ա�");
		dict.insert("left", "���");
		dict.insert("right", "�ұ�");
		string str;
		while (cin >> str) {
			BSTree<string, string>::Node* ret = dict.find(str);
			if (ret) {
				cout << ret->_value << endl;
			}
			else {
				cout << "�޴˵���" << endl;
			}
		}
	}
	// ͳ��ˮ�����ֵĴ���
	void test2() {
		// ͳ��ˮ�����ֵĴ���
		string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
		"ƻ��", "�㽶", "ƻ��", "�㽶" };
		BSTree<string, int> countTree;
		BSTree<string, int>::Node* ret;
		for (auto& e : arr) {
			ret = countTree.find_R(e);
			if (ret == nullptr) {
				countTree.insert(e, 1);
			}
			else {
				ret->_value++;
			}
		}
		countTree.Inorder();
	}
}
int main() {
	K::test_insert();
	K::test_erase();
	K::test_erase_R();
	K::test_destructor();
	K::test_copyConstructor();
	//K_V::test1();
	//K_V::test2();
	return 0;
}