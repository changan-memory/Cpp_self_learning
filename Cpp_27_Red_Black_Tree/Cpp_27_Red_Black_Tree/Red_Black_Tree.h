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
	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_col(Red)
	{ }
};

template<class K, class V>
class RBTree
{
public:
	int _rotateCount = 0;

private:
	typedef RBTreeNode<K, V> Node;
	RBTreeNode<K, V>* _root = nullptr;

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

		// while 循环控制 颜色继续往上更新

		// 新插入的结点为红色 因此 parent 存在且 parent 为红色时，才需要更新颜色 或者调整
		// 
		// 循环的各种情况
		//		1. curNode 为根节点时，parent为空，直接将 _root 设为黑色
		//		2. parent 为黑色时，进不去循环
		//		3. parent 为红色时，接着进入循环 向上调整
		while (parent && parent->_col == Red)
		{
			Node* grandFather = parent->_parent;
			// parent 在 grandFather 左的场景
			if (parent == grandFather->_left)
			{
				Node* uncle = grandFather->_right;
				// 情况一 cur为红  parent为红   grandFather为黑，uncle 存在且为红
				if (uncle && uncle->_col == Red)
				{
					// p 和 u 变黑，g 变红，cur 变成 grandFather 继续往上更新
					// 变色
					parent->_col = uncle->_col = Black;
					grandFather->_col = Red;
					// 继续向上处理
					curNode = grandFather;
					parent = curNode->_parent;
					// 如果更新完后 grandFather 为红色：
					//						1. g 为根节点，那么parent为空
					//						2. g 上面还有结点  
					//									如果是黑色的，无需处理，进不去循环
					//									如果是红色，继续处理
				}
				// u不存在 或 u存在且为黑
				else
				{
					// 左左 -> 右单旋
					if (curNode == parent->_left)
					{
						//     g
						//   p
						// c
						RotateR(grandFather);
						parent->_col = Black;
						grandFather->_col = Red;
					}
					// 左右 ->  左右双旋
					else
					{
						//     g
						//   p
						//      c
						RotateL(parent);
						RotateR(grandFather);
						curNode->_col = Black;
						grandFather->_col = Red;
					}
					break;
				}
			}
			// parent 在 grandFather 右的场景
			else
			{
				Node* uncle = grandFather->_left;
				// 情况一 cur为红  parent为红   grandFather为黑，uncle 存在且为红
				if (uncle && uncle->_col == Red)
				{
					// p 和 u 变黑，g 变红，cur 变成 grandFather 继续往上更新
					// 变色
					parent->_col = uncle->_col = Black;
					grandFather->_col = Red;
					// 继续向上处理
					curNode = grandFather;
					parent = curNode->_parent;
					// 如果更新完后 grandFather 为红色：
					//						1. g 为根节点，那么parent为空
					//						2. g 上面还有结点  
					//									如果是黑色的，无需处理，进不去循环
					//									如果是红色，继续处理
				}
				// u不存在 或 u存在且为黑
				else
				{
					// 右右 -> 左单旋
					if (curNode == parent->_right)
					{
						//  g
						//    p
						//      c
						RotateL(grandFather);
						parent->_col = Black;
						grandFather->_col = Red;
					}
					// 右左 ->  右左双旋
					else
					{
						//  g
						//    p
						//  c
						RotateR(parent);
						RotateL(grandFather);
						curNode->_col = Black;
						grandFather->_col = Red;
					}
					break;
				}
			}
		}
		// 继续向上处理 parent = curNode->_parent  如果 parent == nullptr 会结束循环
		// parent == nullptr 结束循环时，此时curNode为_root结点，需要对 _root 节点变色
		// 根节点始终是黑色的
		_root->_col = Black;	// 粗暴的处理，直接将根节点设为黑色，根节点为黑色总是正确的

		return true;
	}

	bool CheckColour(Node* root, int blacknum, int benchmark)
	{
		if (root == nullptr)
		{
			if (blacknum != benchmark)
				return false;
			return true;
		}
		// 检查黑色节点的数量
		if (root->_col == Black)
			++blacknum;
		// 检查有没有连续的红色结点
		if (root->_col == Red && root->_parent && root->_parent->_col == Red)
		{
			cout << root->_kv.first << "出现连续红色节点" << endl;
			return false;
		}

		return CheckColour(root->_left, blacknum, benchmark)
			&& CheckColour(root->_right, blacknum, benchmark);
	}

	bool isBalance()
	{
		return _isBalance(_root);
	}

	bool _isBalance(Node* root = _root)
	{
		if (root == nullptr)
			return true;

		if (root->_col != Black)
			return false;

		// 基准值
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == Black)
				++benchmark;
			cur = cur->_left;
		}
		return CheckColour(root, 0, benchmark);
	}

	int Height()
	{
		return _Height(_root);
	}

	int _Height(Node* root = _root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

private:
	// 左单旋  2 1 newNode 练成线，单纯的右边高
	void RotateL(Node* parent)
	{
		_rotateCount++;		// 测试旋转次数

		if (parent == nullptr || parent->_right == nullptr)
			return;
		Node* curNode = parent->_right;
		Node* curLeft = curNode->_left;	// curLeft 有可能为空

		// 先处理 curNode 的 left 结点，curLeft 有可能是空
		parent->_right = curLeft;
		if (curLeft)
			curLeft->_parent = parent;

		// 再处理 curNode 结点
		// parent 有可能是根节点，也有可能是子树的根节点
		if (parent == _root)
		{
			// 先立新根
			_root = curNode;
			curNode->_parent = nullptr;

			// 再挂旧根
			parent->_parent = curNode;
			curNode->_left = parent;
		}
		else
		{
			Node* ppNode = parent->_parent;
			// 这里不知道 parent 是 ppNode 的 左孩子 还是 右孩子 
			if (parent == ppNode->_left)
				ppNode->_left = curNode;
			else
				ppNode->_right = curNode;

			curNode->_parent = ppNode;

			// 挂 parent
			parent->_parent = curNode;
			curNode->_left = parent;
		}
	}

	// 右单旋 -2 -1 newNode 连成线，单纯的左边高
	void RotateR(Node* parent)
	{
		_rotateCount++;		// 测试旋转次数

		// parent 为空 或 curNode 为空的情况
		if (parent == nullptr || parent->_left == nullptr)
			return;

		Node* curNode = parent->_left;
		Node* curRight = curNode->_right;

		// 把 curNode 的 right 给给 parent 的 left
		parent->_left = curRight;
		if (curRight)
			curRight->_parent = parent;

		if (parent == _root)
		{
			// 先立新根
			_root = curNode;
			curNode->_parent = nullptr;
			// 再挂旧根
			curNode->_right = parent;
			parent->_parent = curNode;
		}
		else
		{
			Node* ppNode = parent->_parent;
			// 找 parent 是 ppNode 的左还是右
			if (parent == ppNode->_left)
				ppNode->_left = curNode;
			else
				ppNode->_right = curNode;

			curNode->_parent = ppNode;
			// 挂 parent
			curNode->_right = parent;
			parent->_parent = curNode;
		}
	}
};