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
	// find�����ĵݹ�汾
	// д��һ���Ӻ�������Ϊ�ݹ���Ҫ�õ�Private��Ա_root�������Ƶݹ������ķ�֧
	// �����д�Ӻ�������Ҫ�����ṩһ��getRoot��������ʹ��
	bool find_R(const K& key) const {
		return _find_R(_root, key);
	}
	bool erase(const K& key) {
		Node* parent = nullptr;
		Node* curNode = _root;
		// _rootΪ��ʱ������ȥwhileѭ������ֱ��return false 
		// �ҽڵ�
		while (curNode) {
			if (key > curNode->_key) {
				parent = curNode;
				curNode = curNode->_right;
			}
			else if (key < curNode->_key) {
				parent = curNode;
				curNode = curNode->_left;
			}
			// �ҵ��ˣ��ҵ��ˣ�ɾ����Ϊ�������
			else {
				// curNode ����Ϊ��
				if (curNode->_left == nullptr) {
					// �����������Ϊ����curNode Ϊ_root
					if (curNode == _root)
						_root = curNode->_right;

					// �й�
					// ��ǰ����Ǹ�����ڵ�
					else if (curNode == parent->_left) {
						parent->_left = curNode->_right;
					}
					// ��ǰ����Ǹ����ҽڵ�
					else {
						parent->_right = curNode->_right;
					}
					delete curNode;
					return true;
				}
				// curNode ����Ϊ��
				else if (curNode->_right == nullptr) {
					if (curNode == _root)
						_root = curNode->_left;
					// �й�
					// ��ǰ����Ǹ�����ڵ�
					else if (curNode == parent->_left) {
						parent->_left = curNode->_left;
					}
					// ��ǰ����Ǹ����ҽڵ�
					else {
						parent->_right = curNode->_left;
					}
					delete curNode;
					return true;
				}
				// curNode�����Ҷ���Ϊ�գ���Ҫ��������һ������滻curNode
				else {
					// ��Ҫ�������������ġ�������������С���滻��ǰ���
					// �����������У�����������㣬���������ұߵĽ��
					//               ��������С��㣬����������ߵĽ��
					// �����������������Ľ��
					Node* maxNode = curNode->_left;
					Node* maxParent = curNode;
					// �п��ܽ���ȥwhileѭ������Ӧ��ɾ��ʱ�� else ����
					// ����ȥwhileʱ����ʱmaxNode��ʶ����������������㣬parent��curNode�غ�
					while (maxNode->_right != nullptr) {
						maxParent = maxNode;
						maxNode = maxNode->_right;
					}// ѭ��������maxNodeΪ�����������Ľ��
					curNode->_key = maxNode->_key;	// �滻ֵ

					// �������������һ��û���Һ��ӣ�������������
					// maxNode������Parent���Һ��ӣ���maxNode����������
					if (maxNode == maxParent->_right) {
						maxParent->_right = maxNode->_left;
					}
					// maxNodeҲ������Parent�����ӣ���maxNode����������
					else { // maxNode��curNode->_left����ʱpareng->_left����maxNode
						maxParent->_left = maxNode->_left;
					}
					delete maxNode;
					//Node* maxNode = curNode->_left;
					//Node* maxParent = curNode;
					//while (maxNode->_right != nullptr) {
					//	maxParent = maxNode;
					//	maxNode = maxNode->_right;
					//}// ѭ��������maxNodeΪ�����������Ľ��
					//std::swap(maxNode->_key, curNode->_key);
					//delete maxNode;
					//maxParent->_right = nullptr;	// �����߼�
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