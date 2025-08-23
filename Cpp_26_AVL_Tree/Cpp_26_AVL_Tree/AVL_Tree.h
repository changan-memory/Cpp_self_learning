#pragma once
#include <iostream>
using namespace std;

// ��������Ľ�㣬����Ϊ����������ʽ
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
		// curNode�ҿգ���¼�����ڲ����λ��
		while (curNode) {
			if (kv.first > curNode->_kv.first) {
				parent = curNode;
				curNode = curNode->_right;
			}
			else if (kv.first < curNode->_kv.first) {
				parent = curNode;
				curNode = curNode->_left;
			}
			else // Key �������ظ�
				return false;
		}
		//����ѭ��curNode �ҵ��˿��Բ����λ��
		// ��Ҫ�����㣬�����޸ĸ��ڵ��ָ�룬���ڵ㲢��֪��key�Ǳ��Լ������Լ�С��ֻ֪��������Բ�
		// ���Ҫ�ٱȽ�һ��
		curNode = new Node(kv.first);
		if (kv.first > parent->_kv.first) {
			parent->_right = curNode;
		}
		else
			parent->_left = curNode;
		curNode->_parent = parent;	// ������
		// �������������������߼�������������ܵ�������ƽ�⣬�Ӷ����²���Ч���˻�Ϊ O(n)
		// ������AVL���Զ��������� ���еı���ƽ�����

		return true;
	}
};
