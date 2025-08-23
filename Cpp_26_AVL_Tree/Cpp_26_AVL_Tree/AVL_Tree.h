#pragma once
#include <iostream>
using namespace std;

// 这里的树的结点，定义为三叉链的形式
template<class K, class V>
struct AVLTreeNode {
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
	{ }

};



template<class K, class V>
class AVLTree {
	typedef struct AVLTreeNode<K, V> Node;
private:
	AVLTree<K, V>* _root = nullptr;

public:
	bool Insert(const pair<K, V>& kv) {
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}
		Node* curNode = _root;
		Node* parent = nullptr;
		// curNode找空，记录可用于插入的位置
		while (curNode) {
			if (kv.first > curNode->_kv.first) {
				parent = curNode;
				curNode = curNode->_right;
			}
			else if (kv.first < curNode->_kv.first) {
				parent = curNode;
				curNode = curNode->_left;
			}
			else // Key 不允许重复
				return false;
		}
		//走完循环curNode 找到了可以插入的位置
		// 但要插入结点，必须修改父节点的指针，父节点并不知道key是比自己大还是自己小，只知道下面可以插
		// 因此要再比较一次
		curNode = new Node(kv.first);
		if (kv.first > parent->_kv.first) {
			parent->_right = curNode;
		}
		else
			parent->_left = curNode;
		curNode->_parent = parent;	// 三叉链
		// 以上是搜索二叉树的逻辑，这样插入可能导致树不平衡，从而导致查找效率退化为 O(n)
		// 以下是AVL树对二叉搜索树 进行的保持平衡操作

		return true;
	}
};
