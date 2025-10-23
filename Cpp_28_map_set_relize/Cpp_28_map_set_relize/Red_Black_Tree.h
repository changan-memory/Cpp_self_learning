#pragma once

#include <iostream>
#include <utility>
using namespace std;

enum Colour {
	Red,
	Black
};


// �������ʵ���� �����ݣ�һ�� _data �� K ���ͣ�һ��_data �� pair<K, V> ����
template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;

	Colour _col;

	// �½��Ĭ���Ǻ�ɫ��
	RBTreeNode(const T& data)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
		,_col(Red)
	{ }
};

template<class T, class Ptr, class Ref>
struct __TreeIterator
{
	typedef RBTreeNode<T> Node;

	typedef __TreeIterator<T, Ptr, Ref> Self;
	typedef __TreeIterator<T, T*, T&> Iterator;

	Node* _node;

	__TreeIterator(Node* node)
		:_node(node)
	{ }

	// const �������൱������һ��ģ��
	Ref operator*() const
	{
		return _node->_data;
	}
	Ptr operator->() const
	{
		return &(_node->_data);
	}
	bool operator!=(const Self& s) const 
	{ 
		return _node != s._node; 
	}
	bool operator==(const Self& s) const 
	{ 
		return _node == s._node; 
	}

	Self operator--(int)
	{
		Self tmp = *this;
		--*this;
		return tmp;
	}
	Self& operator--()
	{
		if (_node->_left)
		{
			Node* subRight = _node->_left;
			while (subRight->_right)
			{
				subRight = subRight->_right;
			}
			_node = subRight;
		}
		else
		{
			// �����Ǹ��׵��ҵ��Ǹ��ڵ�
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	
	Self& operator++()
	{
		// ������Ϊ�գ��ͷ���������������
		if (_node->_right)
		{
			// ������������ڵ�(��С�ڵ�)
			Node* subLeft = _node->_right;
			while (subLeft->_left)
				subLeft = subLeft->_left;

			_node = subLeft;
		}
		// ����Ϊ��ʱ�������������
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			// �Һ����Ǹ�������Ǹ����Ƚڵ㣬������һ��Ҫ���ʵĽڵ�
			while (parent)
			{
				// cur Ϊ ���׵�����ʱ����һ��Ҫ���ʵľ��� ���ף�����ѭ��, ָ�� _node = parent
				if (cur == parent->_left)
					break;
				// cur Ϊ ���׵��ҽ��ʱ����һ��Ҫ���ʵľ��� ���ף�����ѭ��, ָ�� _node = parent
				else
				{
					cur = cur->_parent;
					parent = parent->_parent;
				}
			}
			// ��������������ѭ��  
			// 1. cur == parent->_left ʱ�� ��һ�����ʵľ���cur �� ���ף�_node = parent
			// 2. parent Ϊ �� ʱ��cur ��ʱΪ���ڵ㣬 �� cur ����Ϊ�գ���ʱ�����������
			_node = parent;
		}
		return *this;
	}
};



// KeyOfT ��һ���º���
// Set->RBTree<K��K��SetKeyOfT> _t
// map->RBTree<K��pair<K��V>, MapKeyOfT> _t;
template<class K, class T, class KeyOfT>
class RBTree
{
//public:
//	int _rotateCount = 0;
public:
	// ͬһ����ģ�� ����ͬ�Ĳ�����ʵ��������ͬ������
	typedef __TreeIterator<T, T*, T&> iterator;
	typedef __TreeIterator<T, const T*, const T&> const_iterator;

	// begin ���ص��� ��������ĵ�һ��λ��
	iterator begin()
	{
		Node* leftMin = _root;
		while (leftMin && leftMin->_left)
			leftMin = leftMin->_left;

		return iterator(leftMin);
	}
	iterator end()
	{
		return iterator(nullptr);
	}

	// const �汾
	const_iterator begin() const
	{
		Node* leftMin = _root;
		while (leftMin && leftMin->_left)
		{
			leftMin = leftMin->_left;
		}
		return const_iterator(leftMin);
	}
	const_iterator end() const
	{
		return const_iterator(nullptr);
	}

private:
	typedef RBTreeNode<T> Node;
	RBTreeNode<T>* _root = nullptr;

	
public:
	// find ����Ҳ��Ҫ�� KeyOfT ����
	Node* find(const K& key) const
	{
		Node* curNode = _root;
		KeyOfT kot;
		while (curNode)
		{
			if (key > kot(curNode->_data))
				curNode = curNode->_right;
			else if (key < kot(curNode->_data))
				curNode = curNode->_left;
			else
				return curNode;
		}
		return nullptr;
	}

	bool insert(const T& data)
	{
		// ���߶����������Ĳ����߼�
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = Black;	// ���� ���ڵ��Ǻ�ɫ��
			return true;
		}
		// _root ��Ϊ��ʱ���������������߼�
		Node* parent = nullptr;
		Node* curNode = _root;
		// ���ҿգ��ҵ�һ�����Բ����λ��

		// ʹ�� ��ȡ�� ȡ�� Key   ����൱����
		// ��׼���е� pair ����ֱ�ӱȽϴ�С����������� һ����ȡ�� ����ȡ�� T �е� Key
		// ������Ϊ������ set Ǩ���� map ,��Ϊset�� K ����ֱ�ӱȽϣ�map ��pair<K, V> ��Ҫȡ�� Key
		// ���� map �� set ����ƣ�_data ������ K,Ҳ������ pair
		// ����� K,����ֱ�ӱȽϣ������map����׼���е� pair<K, V> �ıȽ϶���֧�ֽ��Ƚ�K
		// ��������˷º��� KeyOfT ����� set ���� K, �����map �е� pair<K, V>��ȡ�� K ���бȽ�
		// KeyOfT ��ȫ��Ϊ�� map ��Ƶģ�
		KeyOfT kot;
		while (curNode)
		{
			if (kot(data) < kot(curNode->_data))
			{
				parent = curNode;
				curNode = curNode->_left;
			}
			else if (kot(data) > kot(curNode->_data))
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
		curNode = new Node(data);
		if (kot(curNode->_data) < kot(parent->_data))
			parent->_left = curNode;
		else
			parent->_right = curNode;
		
		curNode->_parent = parent;

		// �����Ƕ����������Ĳ����߼�������������ܵ�������ƽ�⣬�Ӷ����²���Ч���˻�Ϊ O(n)
		// �����Ǻ���������ʿ��ƣ��ǶԶ��������� ���е� ����ƽ�� ����
		// ���ƽ���ƽ�� ... 

		// while ѭ������ ��ɫ�������ϸ���

		// �²���Ľ��Ϊ��ɫ ��� parent ������ parent Ϊ��ɫʱ������Ҫ������ɫ
		// 
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
		// parent == nullptr ����ѭ��ʱ��curNodeΪ_root��㣬��Ҫ�� _root �ڵ��ɫ
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
		//_rotateCount++;		// ������ת����

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
		//_rotateCount++;		// ������ת����

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