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
	// AVL ����ʵ�ֲ���һ����Ҫƽ�����ӣ�Ҳ���Զ�̬�ļ���߶����ж�
	// ʹ��ƽ������ʵ��ֻ������һ�ַ�ʽ
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
	// ����   ���Ĳ����� 
	// parent->right = curNode->left   curNode->left = parent
	// �������ĸ߶��ر��ʱ����������
	void RotateLeft(Node* parent) {
		Node* curNode = parent->_right;
		Node* curLeft = curNode->_left;
		Node* ppNode = parent->_parent;
		
		// ���� curNode �����ӹ�ϵ
		curNode->_left = parent;

		// ���� parent �� ���ӹ�ϵ
		parent->_parent = curNode;
		parent->_right = curLeft;
		if (curLeft != nullptr)
			curLeft->_parent = parent;

		// �ж����� parent �Ƿ�Ϊ ���ڵ�
		if (parent == _root) {
			_root = curNode;
			curNode->_parent = nullptr;
		}
		// parent != _root
		else {
			// �ж� parent �� ppNode ��������
			if (parent == ppNode->_right)
				ppNode->_right = curNode;
			else
				ppNode->_left = curNode;
			curNode->_parent = ppNode;
		}
		parent->_balanceFactor = curNode->_balanceFactor = 0;
	}

	// �ҵ���   ���Ĳ����� 
	// parent->left = curNode->right   curNode->right = parent
	// �������ĸ߶��ر��ʱ�������ҵ���
	void RotateRight(Node* parent) {
		Node* curNode = parent->_left;
		Node* curRight = curNode->_right;
		Node* ppNode = parent->_parent;

		// ���� curNode �����ӹ�ϵ
		curNode->_right = parent;

		// ���� parent �� ���ӹ�ϵ
		parent->_parent = curNode;
		parent->_left = curRight;
		if (curRight != nullptr)
			curRight->_parent = parent;

		// �ж����� parent �Ƿ�Ϊ ���ڵ�
		if (parent == _root) {
			_root = curNode;
			curNode->_parent = nullptr;
		}
		// parent != _root
		else {
			// �ж� parent �� ppNode ��������
			if (parent == ppNode->_right)
				ppNode->_right = curNode;
			else
				ppNode->_left = curNode;

			curNode->_parent = ppNode;
		}
		parent->_balanceFactor = curNode->_balanceFactor = 0;
	}
};
