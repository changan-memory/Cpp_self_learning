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

	// �½��Ĭ���Ǻ�ɫ��
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
		// ���߶����������Ĳ����߼�
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = Black;	// ���� ���ڵ��Ǻ�ɫ��
			return true;
		}
		// _root ��Ϊ��ʱ���������������߼�
		Node* parent = nullptr;
		Node* curNode = _root;
		// ���ҿգ��ҵ�һ�����Բ����λ��
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
			// �������в��������ظ���ֵ  ��������ֵ��������
			else
				return false;
		}
		// while ѭ�������󣬴����ҵ��˿��Բ����λ��
		// �ҵ�λ���ˣ������ڵ㲻֪�� �½����Լ����Ǳ��Լ�С
		curNode = new Node(kv);
		if (curNode->_kv.first < parent->_kv.first)
			parent->_left = curNode;
		else
			parent->_right = curNode;
		
		curNode->_parent = parent;

		// �����Ƕ����������Ĳ����߼�������������ܵ�������ƽ�⣬�Ӷ����²���Ч���˻�Ϊ O(n)
		// �����Ǻ���������ʿ��ƣ��ǶԶ��������� ���е� ����ƽ�� ����
		// ���ƽ���ƽ�� ... 



		return true;
	}
};