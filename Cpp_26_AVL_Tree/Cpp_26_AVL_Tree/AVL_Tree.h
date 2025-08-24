#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

// 这里的树的结点，定义为三叉链的形式
template<class K, class V>
struct AVLTreeNode {
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;		// 插入后，需要更新平衡因子，有了_parent,可以很方便的找父节点
	// 平衡因子，用于判断当前子树 有没有出现不平衡的问题
	int _balanceFactor;	// balance factor	平衡因子
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_balanceFactor(0)	// 新结点的平衡因子为 0
	{ }

	// 我们使用 平衡因子 = 右子树的高度 - 左子树的高度
};

// 左右子树高度之差的绝对值 小于等于 1(-1 0 1)
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
		// 以下是AVL树对二叉搜索树 进行的 控制平衡 操作
		// 控制平衡
		// 插入后 ，先更新平衡因子
		// 插入后，最坏可能root的平衡因子需要更新，只有root的parent为空
		while (parent) {
			if (curNode == parent->_left)
				parent->_balanceFactor--;
			else  // 新插入的节点，不是左就是右
				parent->_balanceFactor++;

			// 根据插入后，parent平衡因子不同的值，采取不同的措施
			if (parent->_balanceFactor == 0) {
				break;	// == 0 时直接结束
			}
			else if (parent->_balanceFactor == 1 || parent->_balanceFactor == -1) {
				// 继续往上更新
				curNode = curNode->_parent;
				parent = parent->_parent;
			}
			else if (parent->_balanceFactor == 2 || parent->_balanceFactor == -2) {
				// 子树不平衡，需要旋转

				break;	// 旋转后，变成平衡树，同时降低了子树的高度
			}
			else {
				assert(false);	// 也可以抛异常
			}
		}

		return true;
	}
private:
	// 左单旋
	// 右子树的高度特别高时，进行左单旋
	void RotateLeft(Node* parent) {
		Node* curNode = parent->_right;
		Node* curLeft = curNode->_left;
		
		if (parent == _root) {
			_root = curNode;
			curNode->_left = parent;
			curNode->_parent = nullptr;

			parent->_parent = curNode;
			parent->_right = curLeft;
		}
		// parent != _root
		else {
			Node* ppNode = parent->_parent;
			// 判断 parent 时 ppNode 的左还是有
			if (parent == ppNode->_left) {
				ppNode->_left = curNode;
			}
			else {
				ppNode->_right = curNode;
			}
			curNode->_parent = ppNode;
		}
	}
};
