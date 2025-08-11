#pragma once
#include <iostream>
using namespace std;
// 二叉搜索树
template<class K>
struct BSTreeNode {
	typedef BSTreeNode<K> Node;
	BSTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{ }
	BSTreeNode* _left;
	BSTreeNode* _right;
	K _key;
};

template<typename K>
class BSTree {
	typedef BSTreeNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{ }
	// 插入时，找到一个空位置插入即可   默认插入的元素不能重复
	bool insert(const K& key) {
		// 插入时为空树
		if (_root == nullptr) {
			_root = new Node(key);
			return true;
		}
		// 不是空树时
		Node* parent = nullptr;
		Node* curNode = _root;
		while (curNode != nullptr) {
			if (key > curNode->_key) {
				parent = curNode;
				curNode = curNode->_right;
			}
			else if (key < curNode->_key) {
				parent = curNode;
				curNode = curNode->_left;
			}
			else {
				return false;
			}
		}
		// 走到这里，意味着curNode已经找到了正确的位置,此时curNode为nullptr
		// parent 为curNode的父节点
		// curNode 为 结点指针的拷贝，修改curNode不能修改结点指针的指向
		curNode = new Node(key);
		if (key > parent->_key) {
			parent->_right = curNode;
		}
		else
			parent->_left = curNode;
		return true;
		// key不可能等于parent->_key  否则上面的循环就是错误的
		/*else {
			return false;
		}*/
	}
	void Inorder() const {
		_Inorder(_root);
	}
	bool find(const K& key) const {
		Node* curNode = _root;
		while (curNode) {
			if (key == curNode->_key) {
				return true;
			}
			else if (key > curNode->_key)
				curNode = curNode->_right;
			else
				curNode = curNode->_left;
		}
		return false;
	}
private:
	void _Inorder(Node* root = _root) const {
		if (root == nullptr) {
			return;
		}
		_Inorder(root->_left);
		cout << root->_key << " ";
		_Inorder(root->_right);
	}
private:
	Node* _root;
};