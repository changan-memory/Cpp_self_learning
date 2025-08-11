#pragma once
#include <iostream>
using namespace std;
// ����������
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
	// ����ʱ���ҵ�һ����λ�ò��뼴��   Ĭ�ϲ����Ԫ�ز����ظ�
	bool insert(const K& key) {
		// ����ʱΪ����
		if (_root == nullptr) {
			_root = new Node(key);
			return true;
		}
		// ���ǿ���ʱ
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
		// �ߵ������ζ��curNode�Ѿ��ҵ�����ȷ��λ��,��ʱcurNodeΪnullptr
		// parent ΪcurNode�ĸ��ڵ�
		// curNode Ϊ ���ָ��Ŀ������޸�curNode�����޸Ľ��ָ���ָ��
		curNode = new Node(key);
		if (key > parent->_key) {
			parent->_right = curNode;
		}
		else
			parent->_left = curNode;
		return true;
		// key�����ܵ���parent->_key  ���������ѭ�����Ǵ����
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