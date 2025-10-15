#pragma once

#include <iostream>
using namespace std;

enum Colour {
	Red,
	Black
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;
	Colour _col;

	// 新结点默认是红色的
	RBTreeNode(const pair<K, V>& kv, Colour col = Red)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_col(col)
	{ }
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
private:
	RBTreeNode<K, V>* _root;

public:
	bool insert(const pair<K, V>& kv)
	{
		// 先走二叉搜索树的插入逻辑
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = Black;	// 性质 根节点是黑色的
			return true;
		}
		// _root 不为空时，二叉搜索树的逻辑
		Node* parent = nullptr;
		Node* curNode = _root;
		// 先找空，找到一个可以插入的位置
		while (curNode)
		{
			if (kv.first < curNode->_kv.first)
			{
				parent = curNode;
				curNode = curNode->_left;
			}
			else if (kv.first > curNode->_kv.first)
			{
				parent = curNode;
				curNode = curNode->_right;
			}
			// 搜索树中不允许有重复的值  对于已有值，不插入
			else
				return false;
		}
		// while 循环结束后，代表找到了可以插入的位置
		// 找到位置了，但父节点不知道 新结点比自己大还是比自己小
		curNode = new Node(kv);
		if (curNode->_kv.first < parent->_kv.first)
			parent->_left = curNode;
		else
			parent->_right = curNode;
		
		curNode->_parent = parent;

		// 以上是二叉搜索树的插入逻辑，这样插入可能导致树不平衡，从而导致查找效率退化为 O(n)
		// 以下是红黑树的性质控制，是对二叉搜索树 进行的 控制平衡 操作
		// 控制近似平衡 ... 



		return true;
	}
};