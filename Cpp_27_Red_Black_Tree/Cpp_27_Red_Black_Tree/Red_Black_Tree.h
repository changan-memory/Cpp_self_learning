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

		// while ѭ������ ��ɫ�������ϸ���

		// �²���Ľ��Ϊ��ɫ ��� parent ������ parent Ϊ��ɫʱ������Ҫ������ɫ ���ߵ���
		// 
		// ѭ���ĸ������
		//		1. curNode Ϊ���ڵ�ʱ��parentΪ�գ�ֱ�ӽ� _root ��Ϊ��ɫ
		//		2. parent Ϊ��ɫʱ������ȥѭ��
		//		3. parent Ϊ��ɫʱ�����Ž���ѭ�� ���ϵ���
		while (parent && parent->_col == Red)
		{
			Node* grandFather = parent->_parent;
			// parent �� grandFather ��ĳ���
			if (parent == grandFather->_left)
			{
				Node* uncle = grandFather->_right;
				// ���һ curΪ��  parentΪ��   grandFatherΪ�ڣ�uncle ������Ϊ��
				if (uncle && uncle->_col == Red)
				{
					// p �� u ��ڣ�g ��죬cur ��� grandFather �������ϸ���
					// ��ɫ
					parent->_col = uncle->_col = Black;
					grandFather->_col = Red;
					// �������ϴ���
					curNode = grandFather;
					parent = curNode->_parent;
					// ���������� grandFather Ϊ��ɫ��
					//						1. g Ϊ���ڵ㣬��ôparentΪ��
					//						2. g ���滹�н��  
					//									����Ǻ�ɫ�ģ����账������ȥѭ��
					//									����Ǻ�ɫ����������
				}
				// u������ �� u������Ϊ��
				else
				{
					// ���� -> �ҵ���
					if (curNode == parent->_left)
					{
						//     g
						//   p
						// c
						RotateR(grandFather);
						parent->_col = Black;
						grandFather->_col = Red;
					}
					// ���� ->  ����˫��
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
			// parent �� grandFather �ҵĳ���
			else
			{
				Node* uncle = grandFather->_left;
				// ���һ curΪ��  parentΪ��   grandFatherΪ�ڣ�uncle ������Ϊ��
				if (uncle && uncle->_col == Red)
				{
					// p �� u ��ڣ�g ��죬cur ��� grandFather �������ϸ���
					// ��ɫ
					parent->_col = uncle->_col = Black;
					grandFather->_col = Red;
					// �������ϴ���
					curNode = grandFather;
					parent = curNode->_parent;
					// ���������� grandFather Ϊ��ɫ��
					//						1. g Ϊ���ڵ㣬��ôparentΪ��
					//						2. g ���滹�н��  
					//									����Ǻ�ɫ�ģ����账������ȥѭ��
					//									����Ǻ�ɫ����������
				}
				// u������ �� u������Ϊ��
				else
				{
					// ���� -> ����
					if (curNode == parent->_right)
					{
						//  g
						//    p
						//      c
						RotateL(grandFather);
						parent->_col = Black;
						grandFather->_col = Red;
					}
					// ���� ->  ����˫��
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
		// �������ϴ��� parent = curNode->_parent  ��� parent == nullptr �����ѭ��
		// parent == nullptr ����ѭ��ʱ����ʱcurNodeΪ_root��㣬��Ҫ�� _root �ڵ��ɫ
		// ���ڵ�ʼ���Ǻ�ɫ��
		_root->_col = Black;	// �ֱ��Ĵ���ֱ�ӽ����ڵ���Ϊ��ɫ�����ڵ�Ϊ��ɫ������ȷ��

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
		// ����ɫ�ڵ������
		if (root->_col == Black)
			++blacknum;
		// �����û�������ĺ�ɫ���
		if (root->_col == Red && root->_parent && root->_parent->_col == Red)
		{
			cout << root->_kv.first << "����������ɫ�ڵ�" << endl;
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

		// ��׼ֵ
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
	// ����  2 1 newNode �����ߣ��������ұ߸�
	void RotateL(Node* parent)
	{
		_rotateCount++;		// ������ת����

		if (parent == nullptr || parent->_right == nullptr)
			return;
		Node* curNode = parent->_right;
		Node* curLeft = curNode->_left;	// curLeft �п���Ϊ��

		// �ȴ��� curNode �� left ��㣬curLeft �п����ǿ�
		parent->_right = curLeft;
		if (curLeft)
			curLeft->_parent = parent;

		// �ٴ��� curNode ���
		// parent �п����Ǹ��ڵ㣬Ҳ�п����������ĸ��ڵ�
		if (parent == _root)
		{
			// �����¸�
			_root = curNode;
			curNode->_parent = nullptr;

			// �ٹҾɸ�
			parent->_parent = curNode;
			curNode->_left = parent;
		}
		else
		{
			Node* ppNode = parent->_parent;
			// ���ﲻ֪�� parent �� ppNode �� ���� ���� �Һ��� 
			if (parent == ppNode->_left)
				ppNode->_left = curNode;
			else
				ppNode->_right = curNode;

			curNode->_parent = ppNode;

			// �� parent
			parent->_parent = curNode;
			curNode->_left = parent;
		}
	}

	// �ҵ��� -2 -1 newNode �����ߣ���������߸�
	void RotateR(Node* parent)
	{
		_rotateCount++;		// ������ת����

		// parent Ϊ�� �� curNode Ϊ�յ����
		if (parent == nullptr || parent->_left == nullptr)
			return;

		Node* curNode = parent->_left;
		Node* curRight = curNode->_right;

		// �� curNode �� right ���� parent �� left
		parent->_left = curRight;
		if (curRight)
			curRight->_parent = parent;

		if (parent == _root)
		{
			// �����¸�
			_root = curNode;
			curNode->_parent = nullptr;
			// �ٹҾɸ�
			curNode->_right = parent;
			parent->_parent = curNode;
		}
		else
		{
			Node* ppNode = parent->_parent;
			// �� parent �� ppNode ��������
			if (parent == ppNode->_left)
				ppNode->_left = curNode;
			else
				ppNode->_right = curNode;

			curNode->_parent = ppNode;
			// �� parent
			curNode->_right = parent;
			parent->_parent = curNode;
		}
	}
};