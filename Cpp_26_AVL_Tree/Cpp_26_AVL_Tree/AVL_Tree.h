//#pragma once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//// 这里的树的结点，定义为三叉链的形式
//template<class K, class V>
//struct AVLTreeNode 
//{
//	pair<K, V> _kv;
//
//	AVLTreeNode<K, V>* _left;
//	AVLTreeNode<K, V>* _right;
//	AVLTreeNode<K, V>* _parent;		// 插入后，需要更新平衡因子，有了_parent,可以很方便的找父节点
//	// 平衡因子，用于判断当前子树 有没有出现不平衡的问题
//	int _balanceFactor;	// balance factor	平衡因子
//	AVLTreeNode(const pair<K, V>& kv)
//		:_kv(kv)
//		,_left(nullptr)
//		,_right(nullptr)
//		,_parent(nullptr)
//		,_balanceFactor(0)	// 新结点的平衡因子为 0
//	{ }
//
//	// 我们使用 平衡因子 = 右子树的高度 - 左子树的高度
//	// AVL 树的实现不是一定需要平衡因子，也可以动态的计算高度来判断
//	// 使用平衡因子实现只是其中一种方式
//};
//
//// 左右子树高度之差的绝对值 小于等于 1(-1 0 1)
//template<class K, class V>
//class AVLTree {
//	typedef struct AVLTreeNode<K, V> Node;
//private:
//	AVLTree<K, V>* _root = nullptr;
//
//public:
//	bool Insert(const pair<K, V>& kv) {
//		if (_root == nullptr) {
//			_root = new Node(kv);
//			return true;
//		}
//		Node* curNode = _root;
//		Node* parent = nullptr;
//		// curNode找空，记录可用于插入的位置
//		while (curNode) {
//			if (kv.first > curNode->_kv.first) {
//				parent = curNode;
//				curNode = curNode->_right;
//			}
//			else if (kv.first < curNode->_kv.first) {
//				parent = curNode;
//				curNode = curNode->_left;
//			}
//			else // Key 不允许重复
//				return false;
//		}
//		//走完循环curNode 找到了可以插入的位置
//		// 但要插入结点，必须修改父节点的指针，父节点并不知道key是比自己大还是自己小，只知道下面可以插
//		// 因此要再比较一次
//		curNode = new Node(kv.first);
//		if (kv.first > parent->_kv.first) {
//			parent->_right = curNode;
//		}
//		else
//			parent->_left = curNode;
//		curNode->_parent = parent;	// 三叉链
//		// 以上是搜索二叉树的逻辑，这样插入可能导致树不平衡，从而导致查找效率退化为 O(n)
//		// 以下是AVL树对二叉搜索树 进行的 控制平衡 操作
//		// 控制平衡
//		// 插入后 ，先更新平衡因子
//		// 插入后，最坏可能root的平衡因子需要更新，只有root的parent为空
//		while (parent) {
//			if (curNode == parent->_left)
//				parent->_balanceFactor--;
//			else  // 新插入的节点，不是左就是右
//				parent->_balanceFactor++;
//
//			// 根据插入后，parent平衡因子不同的值，采取不同的措施
//			if (parent->_balanceFactor == 0) {
//				break;	// == 0 时直接结束
//			}
//			else if (parent->_balanceFactor == 1 || parent->_balanceFactor == -1) {
//				// 继续往上更新
//				curNode = curNode->_parent;
//				parent = parent->_parent;
//			}
//			else if (parent->_balanceFactor == 2 || parent->_balanceFactor == -2) {
//				// 子树不平衡，需要旋转
//
//				break;	// 旋转后，变成平衡树，同时降低了子树的高度
//			}
//			else {
//				assert(false);	// 也可以抛异常
//			}
//		}
//
//		return true;
//	}
//private:
//	// 左单旋   核心操作是 
//	// parent->right = curNode->left   curNode->left = parent
//	// 右子树的高度特别高时，进行左单旋
//	void RotateLeft(Node* parent) {
//		Node* curNode = parent->_right;
//		Node* curLeft = curNode->_left;
//		Node* ppNode = parent->_parent;
//		
//		// 更新 curNode 的链接关系
//		curNode->_left = parent;
//
//		// 更新 parent 的 链接关系
//		parent->_parent = curNode;
//		parent->_right = curLeft;
//		if (curLeft != nullptr)
//			curLeft->_parent = parent;
//
//		// 判断区分 parent 是否为 根节点
//		if (parent == _root) {
//			_root = curNode;
//			curNode->_parent = nullptr;
//		}
//		// parent != _root
//		else {
//			// 判断 parent 是 ppNode 的左还是右
//			if (parent == ppNode->_right)
//				ppNode->_right = curNode;
//			else
//				ppNode->_left = curNode;
//			curNode->_parent = ppNode;
//		}
//		parent->_balanceFactor = curNode->_balanceFactor = 0;
//	}
//
//	// 右单旋   核心操作是 
//	// parent->left = curNode->right   curNode->right = parent
//	// 左子树的高度特别高时，进行右单旋
//	void RotateRight(Node* parent) {
//		Node* curNode = parent->_left;
//		Node* curRight = curNode->_right;
//		Node* ppNode = parent->_parent;
//
//		// 更新 curNode 的链接关系
//		curNode->_right = parent;
//
//		// 更新 parent 的 链接关系
//		parent->_parent = curNode;
//		parent->_left = curRight;
//		if (curRight != nullptr)
//			curRight->_parent = parent;
//
//		// 判断区分 parent 是否为 根节点
//		if (parent == _root) {
//			_root = curNode;
//			curNode->_parent = nullptr;
//		}
//		// parent != _root
//		else {
//			// 判断 parent 是 ppNode 的左还是右
//			if (parent == ppNode->_right)
//				ppNode->_right = curNode;
//			else
//				ppNode->_left = curNode;
//
//			curNode->_parent = ppNode;
//		}
//		parent->_balanceFactor = curNode->_balanceFactor = 0;
//	}
//};
#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

template<class K, class V>
struct AVLTreeNode {
	pair<K, V> _kv;		// 键值对
	// 三叉链
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;	// 插入结点后，需要更新平衡因子，有了_parent,可以很方便的找父节点

	// 平衡因子，用于判断当前子树 有没有出现不平衡的问题
	int _balanceFactor;	// balance factor	平衡因子

	// Node 的构造函数
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		,_parent(nullptr)
		, _balanceFactor(0)		// 新结点 初始的平衡因子为 0
	{ }

	// 我们使用 平衡因子 = 右子树的高度 - 左子树的高度
	// AVL 树的实现不是一定需要平衡因子，也可以动态的计算高度来判断
	// 使用平衡因子实现只是其中一种方式
};


// 左右子树高度之差的绝对值 小于等于 1 (-1 0 1)
template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
private:
	AVLTreeNode<K, V>* _root = nullptr;

public:
	bool insert(const pair<K, V>& kv) 
	{
		// 先走二叉搜索树的插入逻辑
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		else {
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
				// 搜索树中不允许有重复的值
				else
				{
					// 对于已有值，不插入
					return false;
				}
			}
			// while 循环结束后，代表找到了可以插入的位置
			// 找到位置了，但父节点不知道 新结点比自己大还是比自己小
			curNode = new Node(kv);
			if (curNode->_kv.first < parent->_kv.first)
			{
				parent->_left = curNode;
			}
			else 
			{
				parent->_right = curNode;
			}
			curNode->_parent = parent;
			// 以上是二叉搜索树的插入逻辑，这样插入可能导致树不平衡，从而导致查找效率退化为 O(n)
			// 以下是AVL树对二叉搜索树 进行的 控制平衡 操作
			// 控制平衡 ... 

			// 插入后 ，先更新平衡因子
			// 插入后，最坏可能root的平衡因子需要更新，只有root的parent为空
			while (parent)
			{
				if (curNode == parent->_left)
				{
					--parent->_balanceFactor;
				}
				else // if (curNode == parent->_right)
				{
					++parent->_balanceFactor;
				}

				// 当前parent结点更新完了，判断是否还需要再往上更新
				if (parent->_balanceFactor == 0)	// parent所在子树高度不变，无需更新
				{
					break;
				}
				 // parent所在子树高度变了，继续往上更新
				else if (parent->_balanceFactor == 1 || parent->_balanceFactor == -1)
				{
					curNode = parent;
					parent = parent->_parent;
				}
				else if (parent->_balanceFactor == 2 || parent->_balanceFactor == -2)
				{
					// 当前子树不平衡了，需要旋转
					// 左单旋 “右子树右高”的一种情况

					//  2   1  newNode 排成直线，左单旋
					if (parent->_balanceFactor == 2 && curNode->_balanceFactor == 1) 
					{
						RotateL(parent);
					}
					// -2  -1  newNode 排成直线，右单旋
					else if (parent->_balanceFactor == -2 && curNode->_balanceFactor == -1)
					{
						RotateR(parent);
					}
					// 2 -1 newNode 排成折线  右左双旋
					else if (parent->_balanceFactor == 2 && curNode->_balanceFactor == -1)
					{
						RotateRL(parent);
					}
					// -2 1 newNode 排成折线  左右双旋
					else if (parent->_balanceFactor == -2 && curNode->_balanceFactor == 1)
					{
						RotateLR(parent);
					}

					else
					{

					}
					break;

				}
				else
				{
					assert(false);	// 平衡因子不是 0 1 -1 2 -2  直接报错
				}
			}
		}
		return true;
	}

	// 判断是否是 AVL 树
	bool isBalance()
	{
		return _IsBalance(_root);
	}
private:
	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		// 加一层暴涨
		if (rightHeight - leftHeight != root->_balanceFactor)
		{
			cout << " 平衡因子异常: " << root->_kv.first << "->" << root->_balanceFactor << endl;
			return false;
		}

		return abs(rightHeight - leftHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		// 分别求左右子树的高度
		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		// 左右子树中 高度更大的那个 + 1
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	// 左单旋
	void RotateL(Node* parent)
	{
		if (parent == nullptr || parent->_right == nullptr)
			return;

		Node* curNode = parent->_right;
		Node* curLeft = curNode->_left;	// curLeft 有可能为空

		// 先处理 curNode 的 left 结点
		parent->_right = curLeft;
		if(curLeft)
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
			{
				ppNode->_left = curNode;
			}
			else
			{
				ppNode->_right = curNode;
			}
			curNode->_parent = ppNode;

			// 挂 parent
			parent->_parent = curNode;
			curNode->_left = parent;

		}
		parent->_balanceFactor = curNode->_balanceFactor = 0;
	}

	// 右单旋
	void RotateR(Node* parent)
	{
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
			{
				ppNode->_left = curNode;
			}
			else
			{
				ppNode->_right = curNode;
			}
			curNode->_parent = ppNode;
			// 挂 parent
			curNode->_right = parent;
			parent->_parent = curNode;
		}
		curNode->_balanceFactor = parent->_balanceFactor = 0;
	}

	// 右左双旋
	void RotateRL(Node* parent) 
	{
		Node* curNode = parent->_right;
		Node* curLeft = curNode->_left;
		int bf = curLeft->_balanceFactor;

		RotateR(parent->_right);
		RotateL(parent);
		// 双旋  这里的麻烦事 是平衡因子的更新

		if (bf == 0)
		{
			parent->_balanceFactor = 0;
			curNode->_balanceFactor = 0;
			curLeft->_balanceFactor = 0;
		}
		else if (bf == 1)
		{
			parent->_balanceFactor = -1;
			curNode->_balanceFactor = 0;
			curLeft->_balanceFactor = 0;
		}
		else if (bf == -1)
		{
			parent->_balanceFactor = 0;
			curNode->_balanceFactor = 1;
			curLeft->_balanceFactor = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateLR(Node* parent)
	{
		Node* curNode = parent->_left;
		Node* curRight = curNode->_right;
		int bf = curRight->_balanceFactor;

		RotateL(parent->_left);
		RotateR(parent);
		// 双旋  这里的麻烦事 是平衡因子的更新

		if (bf == 0)
		{
			parent->_balanceFactor = 0;
			curNode->_balanceFactor = 0;
			curRight->_balanceFactor = 0;
		}
		else if (bf == 1)
		{
			parent->_balanceFactor = 0;
			curNode->_balanceFactor = -1;
			curRight->_balanceFactor = 0;
		}
		else if (bf == -1)
		{
			parent->_balanceFactor = 1;
			curNode->_balanceFactor = 0;
			curRight->_balanceFactor = 0;
		}
		else
		{
			assert(false);
		}
	}
};
