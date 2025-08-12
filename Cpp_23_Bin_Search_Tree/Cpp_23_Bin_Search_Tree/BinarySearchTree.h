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
		printf("\n");
	}
	bool find(const K& key) const {
		Node* curNode = _root;
		while (curNode) {
			if (key == curNode->_key)
				return true;
			else if (key > curNode->_key)
				curNode = curNode->_right;
			else
				curNode = curNode->_left;
		}
		return false;
	}
	// find函数的递归版本
	// 写了一个子函数，因为递归需要用到Private成员_root，来控制递归子树的分支
	// 如果不写子函数，需要对外提供一个getRoot供调用者使用
	bool find_R(const K& key) const {
		return _find_R(_root, key);
	}
	bool erase(const K& key) {
		Node* parent = nullptr;
		Node* curNode = _root;
		// _root为空时，进不去while循环，会直接return false 
		// 找节点
		while (curNode) {
			if (key > curNode->_key) {
				parent = curNode;
				curNode = curNode->_right;
			}
			else if (key < curNode->_key) {
				parent = curNode;
				curNode = curNode->_left;
			}
			// 找到了，找到了，删除分为三种情况
			else {
				// curNode 的左为空
				if (curNode->_left == nullptr) {
					// 特殊情况，左为空且curNode 为_root
					if (curNode == _root)
						_root = curNode->_right;

					// 托孤
					// 当前结点是父的左节点
					else if (curNode == parent->_left) {
						parent->_left = curNode->_right;
					}
					// 当前结点是父的右节点
					else {
						parent->_right = curNode->_right;
					}
					delete curNode;
					return true;
				}
				// curNode 的右为空
				else if (curNode->_right == nullptr) {
					if (curNode == _root)
						_root = curNode->_left;
					// 托孤
					// 当前结点是父的左节点
					else if (curNode == parent->_left) {
						parent->_left = curNode->_left;
					}
					// 当前结点是父的右节点
					else {
						parent->_right = curNode->_left;
					}
					delete curNode;
					return true;
				}
				// curNode的左右都不为空，需要在树中找一个结点替换curNode
				else {
					// 需要找左子树中最大的、或右子树中最小的替换当前结点
					// 二叉搜索树中，子树的最大结点，是树中最右边的结点
					//               子树的最小结点，是树中最左边的结点
					// 这里找左子树中最大的结点
					Node* maxNode = curNode->_left;
					Node* maxParent = curNode;
					// 有可能进不去while循环，对应与删除时的 else 条件
					// 进不去while时，此时maxNode初识就是左子树的最大结点，parent和curNode重合
					while (maxNode->_right != nullptr) {
						maxParent = maxNode;
						maxNode = maxNode->_right;
					}// 循环结束后，maxNode为左子树中最大的结点
					curNode->_key = maxNode->_key;	// 替换值

					// 左子树的最大结点一定没有右孩子，但可能有左孩子
					// maxNode可能是Parent的右孩子，且maxNode可能有左孩子
					if (maxNode == maxParent->_right) {
						maxParent->_right = maxNode->_left;
					}
					// maxNode也可能是Parent的左孩子，且maxNode可能有左孩子
					else { // maxNode是curNode->_left，此时pareng->_left就是maxNode
						maxParent->_left = maxNode->_left;
					}
					delete maxNode;
					//Node* maxNode = curNode->_left;
					//Node* maxParent = curNode;
					//while (maxNode->_right != nullptr) {
					//	maxParent = maxNode;
					//	maxNode = maxNode->_right;
					//}// 循环结束后，maxNode为左子树中最大的结点
					//std::swap(maxNode->_key, curNode->_key);
					//delete maxNode;
					//maxParent->_right = nullptr;	// 错误逻辑
				}
				return true;
			}
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
	bool _find_R(const Node* root, const K& key) const {
		if (root == nullptr)
			return false;
		if (key < root->_key)
			return _find_R(root->_left, key);
		else if (key > root->_key)
			return _find_R(root->_right, key);
		else
			return true;
	}
	bool _insert_R() {

	}
private:
	Node* _root;
};