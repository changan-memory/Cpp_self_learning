#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

// ��������Ľ�㣬����Ϊ����������ʽ
template<class K, class V>
struct AVLTreeNode {
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;		// �������Ҫ����ƽ�����ӣ�����_parent,���Ժܷ�����Ҹ��ڵ�
	// ƽ�����ӣ������жϵ�ǰ���� ��û�г��ֲ�ƽ�������
	int _balanceFactor;	// balance factor	ƽ������
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_balanceFactor(0)	// �½���ƽ������Ϊ 0
	{ }

	// ����ʹ�� ƽ������ = �������ĸ߶� - �������ĸ߶�
};

// ���������߶�֮��ľ���ֵ С�ڵ��� 1(-1 0 1)
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
		// ������AVL���Զ��������� ���е� ����ƽ�� ����
		// ����ƽ��
		// ����� ���ȸ���ƽ������
		// ����������root��ƽ��������Ҫ���£�ֻ��root��parentΪ��
		while (parent) {
			if (curNode == parent->_left)
				parent->_balanceFactor--;
			else  // �²���Ľڵ㣬�����������
				parent->_balanceFactor++;

			// ���ݲ����parentƽ�����Ӳ�ͬ��ֵ����ȡ��ͬ�Ĵ�ʩ
			if (parent->_balanceFactor == 0) {
				break;	// == 0 ʱֱ�ӽ���
			}
			else if (parent->_balanceFactor == 1 || parent->_balanceFactor == -1) {
				// �������ϸ���
				curNode = curNode->_parent;
				parent = parent->_parent;
			}
			else if (parent->_balanceFactor == 2 || parent->_balanceFactor == -2) {
				// ������ƽ�⣬��Ҫ��ת

				break;	// ��ת�󣬱��ƽ������ͬʱ�����������ĸ߶�
			}
			else {
				assert(false);	// Ҳ�������쳣
			}
		}

		return true;
	}
private:
	// ����
	// �������ĸ߶��ر��ʱ����������
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
			// �ж� parent ʱ ppNode ��������
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
