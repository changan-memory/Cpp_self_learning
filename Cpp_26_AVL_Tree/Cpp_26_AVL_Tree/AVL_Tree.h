//#pragma once
//#include <iostream>
//#include <assert.h>
//using namespace std;
//
//// ��������Ľ�㣬����Ϊ����������ʽ
//template<class K, class V>
//struct AVLTreeNode 
//{
//	pair<K, V> _kv;
//
//	AVLTreeNode<K, V>* _left;
//	AVLTreeNode<K, V>* _right;
//	AVLTreeNode<K, V>* _parent;		// �������Ҫ����ƽ�����ӣ�����_parent,���Ժܷ�����Ҹ��ڵ�
//	// ƽ�����ӣ������жϵ�ǰ���� ��û�г��ֲ�ƽ�������
//	int _balanceFactor;	// balance factor	ƽ������
//	AVLTreeNode(const pair<K, V>& kv)
//		:_kv(kv)
//		,_left(nullptr)
//		,_right(nullptr)
//		,_parent(nullptr)
//		,_balanceFactor(0)	// �½���ƽ������Ϊ 0
//	{ }
//
//	// ����ʹ�� ƽ������ = �������ĸ߶� - �������ĸ߶�
//	// AVL ����ʵ�ֲ���һ����Ҫƽ�����ӣ�Ҳ���Զ�̬�ļ���߶����ж�
//	// ʹ��ƽ������ʵ��ֻ������һ�ַ�ʽ
//};
//
//// ���������߶�֮��ľ���ֵ С�ڵ��� 1(-1 0 1)
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
//		// curNode�ҿգ���¼�����ڲ����λ��
//		while (curNode) {
//			if (kv.first > curNode->_kv.first) {
//				parent = curNode;
//				curNode = curNode->_right;
//			}
//			else if (kv.first < curNode->_kv.first) {
//				parent = curNode;
//				curNode = curNode->_left;
//			}
//			else // Key �������ظ�
//				return false;
//		}
//		//����ѭ��curNode �ҵ��˿��Բ����λ��
//		// ��Ҫ�����㣬�����޸ĸ��ڵ��ָ�룬���ڵ㲢��֪��key�Ǳ��Լ������Լ�С��ֻ֪��������Բ�
//		// ���Ҫ�ٱȽ�һ��
//		curNode = new Node(kv.first);
//		if (kv.first > parent->_kv.first) {
//			parent->_right = curNode;
//		}
//		else
//			parent->_left = curNode;
//		curNode->_parent = parent;	// ������
//		// �������������������߼�������������ܵ�������ƽ�⣬�Ӷ����²���Ч���˻�Ϊ O(n)
//		// ������AVL���Զ��������� ���е� ����ƽ�� ����
//		// ����ƽ��
//		// ����� ���ȸ���ƽ������
//		// ����������root��ƽ��������Ҫ���£�ֻ��root��parentΪ��
//		while (parent) {
//			if (curNode == parent->_left)
//				parent->_balanceFactor--;
//			else  // �²���Ľڵ㣬�����������
//				parent->_balanceFactor++;
//
//			// ���ݲ����parentƽ�����Ӳ�ͬ��ֵ����ȡ��ͬ�Ĵ�ʩ
//			if (parent->_balanceFactor == 0) {
//				break;	// == 0 ʱֱ�ӽ���
//			}
//			else if (parent->_balanceFactor == 1 || parent->_balanceFactor == -1) {
//				// �������ϸ���
//				curNode = curNode->_parent;
//				parent = parent->_parent;
//			}
//			else if (parent->_balanceFactor == 2 || parent->_balanceFactor == -2) {
//				// ������ƽ�⣬��Ҫ��ת
//
//				break;	// ��ת�󣬱��ƽ������ͬʱ�����������ĸ߶�
//			}
//			else {
//				assert(false);	// Ҳ�������쳣
//			}
//		}
//
//		return true;
//	}
//private:
//	// ����   ���Ĳ����� 
//	// parent->right = curNode->left   curNode->left = parent
//	// �������ĸ߶��ر��ʱ����������
//	void RotateLeft(Node* parent) {
//		Node* curNode = parent->_right;
//		Node* curLeft = curNode->_left;
//		Node* ppNode = parent->_parent;
//		
//		// ���� curNode �����ӹ�ϵ
//		curNode->_left = parent;
//
//		// ���� parent �� ���ӹ�ϵ
//		parent->_parent = curNode;
//		parent->_right = curLeft;
//		if (curLeft != nullptr)
//			curLeft->_parent = parent;
//
//		// �ж����� parent �Ƿ�Ϊ ���ڵ�
//		if (parent == _root) {
//			_root = curNode;
//			curNode->_parent = nullptr;
//		}
//		// parent != _root
//		else {
//			// �ж� parent �� ppNode ��������
//			if (parent == ppNode->_right)
//				ppNode->_right = curNode;
//			else
//				ppNode->_left = curNode;
//			curNode->_parent = ppNode;
//		}
//		parent->_balanceFactor = curNode->_balanceFactor = 0;
//	}
//
//	// �ҵ���   ���Ĳ����� 
//	// parent->left = curNode->right   curNode->right = parent
//	// �������ĸ߶��ر��ʱ�������ҵ���
//	void RotateRight(Node* parent) {
//		Node* curNode = parent->_left;
//		Node* curRight = curNode->_right;
//		Node* ppNode = parent->_parent;
//
//		// ���� curNode �����ӹ�ϵ
//		curNode->_right = parent;
//
//		// ���� parent �� ���ӹ�ϵ
//		parent->_parent = curNode;
//		parent->_left = curRight;
//		if (curRight != nullptr)
//			curRight->_parent = parent;
//
//		// �ж����� parent �Ƿ�Ϊ ���ڵ�
//		if (parent == _root) {
//			_root = curNode;
//			curNode->_parent = nullptr;
//		}
//		// parent != _root
//		else {
//			// �ж� parent �� ppNode ��������
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
	pair<K, V> _kv;		// ��ֵ��
	// ������
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;	// ���������Ҫ����ƽ�����ӣ�����_parent,���Ժܷ�����Ҹ��ڵ�

	// ƽ�����ӣ������жϵ�ǰ���� ��û�г��ֲ�ƽ�������
	int _balanceFactor;	// balance factor	ƽ������

	// Node �Ĺ��캯��
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		,_parent(nullptr)
		, _balanceFactor(0)		// �½�� ��ʼ��ƽ������Ϊ 0
	{ }

	// ����ʹ�� ƽ������ = �������ĸ߶� - �������ĸ߶�
	// AVL ����ʵ�ֲ���һ����Ҫƽ�����ӣ�Ҳ���Զ�̬�ļ���߶����ж�
	// ʹ��ƽ������ʵ��ֻ������һ�ַ�ʽ
};


// ���������߶�֮��ľ���ֵ С�ڵ��� 1 (-1 0 1)
template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
private:
	AVLTreeNode<K, V>* _root = nullptr;

public:
	bool insert(const pair<K, V>& kv) 
	{
		// ���߶����������Ĳ����߼�
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		else {
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
				// �������в��������ظ���ֵ
				else
				{
					// ��������ֵ��������
					return false;
				}
			}
			// while ѭ�������󣬴����ҵ��˿��Բ����λ��
			// �ҵ�λ���ˣ������ڵ㲻֪�� �½����Լ����Ǳ��Լ�С
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
			// �����Ƕ����������Ĳ����߼�������������ܵ�������ƽ�⣬�Ӷ����²���Ч���˻�Ϊ O(n)
			// ������AVL���Զ��������� ���е� ����ƽ�� ����
			// ����ƽ�� ... 

			// ����� ���ȸ���ƽ������
			// ����������root��ƽ��������Ҫ���£�ֻ��root��parentΪ��
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

				// ��ǰparent���������ˣ��ж��Ƿ���Ҫ�����ϸ���
				if (parent->_balanceFactor == 0)	// parent���������߶Ȳ��䣬�������
				{
					break;
				}
				 // parent���������߶ȱ��ˣ��������ϸ���
				else if (parent->_balanceFactor == 1 || parent->_balanceFactor == -1)
				{
					curNode = parent;
					parent = parent->_parent;
				}
				else if (parent->_balanceFactor == 2 || parent->_balanceFactor == -2)
				{
					// ��ǰ������ƽ���ˣ���Ҫ��ת
					// ���� ���������Ҹߡ���һ�����

					//  2   1  newNode �ų�ֱ�ߣ�����
					if (parent->_balanceFactor == 2 && curNode->_balanceFactor == 1) 
					{
						RotateL(parent);
					}
					// -2  -1  newNode �ų�ֱ�ߣ��ҵ���
					else if (parent->_balanceFactor == -2 && curNode->_balanceFactor == -1)
					{
						RotateR(parent);
					}
					// 2 -1 newNode �ų�����  ����˫��
					else if (parent->_balanceFactor == 2 && curNode->_balanceFactor == -1)
					{
						RotateRL(parent);
					}
					// -2 1 newNode �ų�����  ����˫��
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
					assert(false);	// ƽ�����Ӳ��� 0 1 -1 2 -2  ֱ�ӱ���
				}
			}
		}
		return true;
	}

	// �ж��Ƿ��� AVL ��
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
		// ��һ�㱩��
		if (rightHeight - leftHeight != root->_balanceFactor)
		{
			cout << " ƽ�������쳣: " << root->_kv.first << "->" << root->_balanceFactor << endl;
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
		// �ֱ������������ĸ߶�
		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		// ���������� �߶ȸ�����Ǹ� + 1
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	// ����
	void RotateL(Node* parent)
	{
		if (parent == nullptr || parent->_right == nullptr)
			return;

		Node* curNode = parent->_right;
		Node* curLeft = curNode->_left;	// curLeft �п���Ϊ��

		// �ȴ��� curNode �� left ���
		parent->_right = curLeft;
		if(curLeft)
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
			{
				ppNode->_left = curNode;
			}
			else
			{
				ppNode->_right = curNode;
			}
			curNode->_parent = ppNode;

			// �� parent
			parent->_parent = curNode;
			curNode->_left = parent;

		}
		parent->_balanceFactor = curNode->_balanceFactor = 0;
	}

	// �ҵ���
	void RotateR(Node* parent)
	{
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
			{
				ppNode->_left = curNode;
			}
			else
			{
				ppNode->_right = curNode;
			}
			curNode->_parent = ppNode;
			// �� parent
			curNode->_right = parent;
			parent->_parent = curNode;
		}
		curNode->_balanceFactor = parent->_balanceFactor = 0;
	}

	// ����˫��
	void RotateRL(Node* parent) 
	{
		Node* curNode = parent->_right;
		Node* curLeft = curNode->_left;
		int bf = curLeft->_balanceFactor;

		RotateR(parent->_right);
		RotateL(parent);
		// ˫��  ������鷳�� ��ƽ�����ӵĸ���

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
		// ˫��  ������鷳�� ��ƽ�����ӵĸ���

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
