#pragma once
#include <iostream>
using namespace std;

namespace K {
	// ���������� version -- K
	template<class K>
	struct BSTreeNode {
		typedef BSTreeNode<K> Node;
		BSTreeNode(const K& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{
		}
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;
	};

	template<typename K>
	class BSTree {
		typedef BSTreeNode<K> Node;
	public:
		BSTree()
			:_root(nullptr)
		{
		}

		BSTree(const BSTree<K>& tree)
			:_root(nullptr)
		{
			_root = Copy(tree._root);
		}
		// ����д���ĸ�ֵ
		// t2 = t1
		BSTree<K>& operator=(BSTree<K> tmp) {
			std::swap(_root, tmp._root);
			return *this;
		}
		~BSTree() {
			Destroy(_root);
		}
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

		// ���ﲻ�������ô���ָ�룬��Ϊָ����Ըı�ָ������һ���󶨣�ָ�򲻿��޸�
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
		// find�����ĵݹ�汾
		// д��һ���Ӻ�������Ϊ�ݹ���Ҫ�õ�Private��Ա_root�������Ƶݹ������ķ�֧
		// �����д�Ӻ�������Ҫ�����ṩһ��getRoot��������ʹ��
		bool find_R(const K& key) const {
			return _find_R(_root, key);
		}
		bool insert_R(const K& key) {
			return _insert_R(_root, key);
		}
		bool erase_R(const K& key) {
			return _erase_R(_root, key);
		}
	private:
		Node* Copy(Node* root) {
			if (root == nullptr)
				return nullptr;
			else {
				Node* newRoot = new Node(root->_key);
				// �ֱ�ݹ鿽�� ����������������󣬵ݹ��ȥ����
				newRoot->_left = Copy(root->_left);
				newRoot->_right = Copy(root->_right);
				return newRoot;
			}
		}
		void Destroy(Node*& root) {
			if (root == nullptr)
				return;
			// ���������������ߺ������ɾ��
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
			root = nullptr;
		}
		void _Inorder(Node* root = _root) const {
			if (root == nullptr) {
				return;
			}
			_Inorder(root->_left);
			cout << root->_key << " " << endl;;
			_Inorder(root->_right);
		}
		bool _find_R(const Node* root, const K& key) const {
			if (root == nullptr)
				return false;
			if (key < root->_key)
				return _find_R(root->_left, key);
			else if (key > root->_key)
				return _find_R(root->_right, key);
			// �� < �� > �������ҳɹ�
			else
				return true;
		}
		// �������root�����ã��޸�ָ��
		bool _insert_R(Node*& root, const K& key) {
			// �ߵ��յĵط������Կ�ʼ������
			// ������Լ�¼���ڵ㣬�޸ĸ��ڵ��ָ����ɲ��롣�����Ƚϸ��ӣ�����ʹ��
			if (root == nullptr) {
				root = new Node(key);
				return true;
			}
			if (key < root->_key)
				return _insert_R(root->_left, key);
			else if (key > root->_key)
				return _insert_R(root->_right, key);
			else
				return false;
		}
		bool _erase_R(Node*& root, const K& key) {
			if (root == nullptr)
				return false;
			if (key > root->_key)
				return _erase_R(root->_right, key);
			else if (key < root->_key)
				return _erase_R(root->_left, key);
			// ���ʱҪɾ��
			else {
				Node* delNode = root;
				// 1. curNode ��Ϊ��
				if (root->_left == nullptr) {
					root = root->_right;
				}
				// 2. curNode ��Ϊ��
				else if (root->_right == nullptr) {
					root = root->_left;
				}
				// 3. curNode ���Ҷ���Ϊ��
				else {
					// �������������Ľ��
					Node* maxNode = root->_left;
					while (maxNode->_right) {
						maxNode = maxNode->_right;
					}
					std::swap(maxNode->_key, root->_key);
					// ��������ԭ����maxNode�������������Ľ�㣬�����������һ��Ϊ��
					// ��ȥ��������ɾ��һ��
					return _erase_R(root->_left, key);
					//return _erase_R(maxNode, key);	// ������ôд
				}
				delete delNode;
				return true;
			}
		}
	private:
		Node* _root;
	};
}

namespace K_V {
	// ���������� version -- K_V
	// �����ͬʱ�棬key �� ��Ӧ�� value
	template<class K, class V>
	struct BSTreeNode {
		typedef BSTreeNode<K, V> Node;
		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			,_value(value)
		{
		}
		BSTreeNode* _left;
		BSTreeNode* _right;
		K _key;
		V _value;
	};

	template<typename K, typename V>
	class BSTree {
	public:
		typedef BSTreeNode<K, V> Node;
		BSTree()
			:_root(nullptr)
		{
		}

		BSTree(const BSTree<K, V>& tree)
			:_root(nullptr)
		{
			_root = Copy(tree._root);
		}
		// ����д���ĸ�ֵ
		// t2 = t1
		BSTree<K, V>& operator=(BSTree<K, V> tmp) {
			std::swap(_root, tmp._root);
			return *this;
		}
		~BSTree() {
			Destroy(_root);
		}
		// ����ʱ���ҵ�һ����λ�ò��뼴��   Ĭ�ϲ����Ԫ�ز����ظ�
		bool insert(const K& key, const V& value) {
			// ����ʱΪ����
			if (_root == nullptr) {
				_root = new Node(key, value);
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
			curNode = new Node(key, value);
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
			cout << endl;
		}
		Node* find(const K& key) const {
			Node* curNode = _root;
			while (curNode) {
				if (key == curNode->_key)
					return curNode;
				else if (key > curNode->_key)
					curNode = curNode->_right;
				else
					curNode = curNode->_left;
			}
			return nullptr;
		}

		// ���ﲻ�������ô���ָ�룬��Ϊָ����Ըı�ָ������һ���󶨣�ָ�򲻿��޸�
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
						curNode->_value = maxNode->_value;

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
		// find�����ĵݹ�汾
		// д��һ���Ӻ�������Ϊ�ݹ���Ҫ�õ�Private��Ա_root�������Ƶݹ������ķ�֧
		// �����д�Ӻ�������Ҫ�����ṩһ��getRoot��������ʹ��
		Node* find_R(const K& key) const {
			return _find_R(_root, key);
		}
		bool insert_R(const K& key, const V& value) {
			return _insert_R(_root, key, value);
		}
		bool erase_R(const K& key) {
			return _erase_R(_root, key);
		}
	private:
		Node* Copy(Node* root) {
			if (root == nullptr)
				return nullptr;
			else {
				Node* newRoot = new Node(root->_key, root->_value);
				// �ֱ�ݹ鿽�� ����������������󣬵ݹ��ȥ����
				newRoot->_left = Copy(root->_left);
				newRoot->_right = Copy(root->_right);
				return newRoot;
			}
		}
		void Destroy(Node*& root) {
			if (root == nullptr)
				return;
			// ���������������ߺ������ɾ��
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
			root = nullptr;
		}
		void _Inorder(Node* root = _root) const {
			if (root == nullptr) {
				return;
			}
			_Inorder(root->_left);
			cout << root->_key << ": " << root->_value << endl;;
			_Inorder(root->_right);
		}
		Node* _find_R(Node* root, const K& key) const {
			if (root == nullptr)
				return nullptr;
			if (key < root->_key)
				return _find_R(root->_left, key);
			else if (key > root->_key)
				return _find_R(root->_right, key);
			// �� < �� > �������ҳɹ�
			else
				return root;
		}
		// �������root�����ã��޸�ָ��
		bool _insert_R(Node*& root, const K& key, const V& value) {
			// �ߵ��յĵط������Կ�ʼ������
			// ������Լ�¼���ڵ㣬�޸ĸ��ڵ��ָ����ɲ��롣�����Ƚϸ��ӣ�����ʹ��
			if (root == nullptr) {
				root = new Node(key, value);
				return true;
			}
			if (key < root->_key)
				return _insert_R(root->_left, key, value);
			else if (key > root->_key)
				return _insert_R(root->_right, key, value);
			else
				return false;
		}
		bool _erase_R(Node*& root, const K& key) {
			if (root == nullptr)
				return false;
			if (key > root->_key)
				return _erase_R(root->_right, key);
			else if (key < root->_key)
				return _erase_R(root->_left, key);
			// ���ʱҪɾ��
			else {
				Node* delNode = root;
				// 1. curNode ��Ϊ��
				if (root->_left == nullptr) {
					root = root->_right;
				}
				// 2. curNode ��Ϊ��
				else if (root->_right == nullptr) {
					root = root->_left;
				}
				// 3. curNode ���Ҷ���Ϊ��
				else {
					// �������������Ľ��
					Node* maxNode = root->_left;
					while (maxNode->_right) {
						maxNode = maxNode->_right;
					}
					std::swap(maxNode->_key, root->_key);
					std::swap(maxNode->_value, root->_value);
					// ��������ԭ����maxNode�������������Ľ�㣬�����������һ��Ϊ��
					// ��ȥ��������ɾ��һ��
					return _erase_R(root->_left, key);
					//return _erase_R(maxNode, key);	// ������ôд
				}
				delete delNode;
				return true;
			}
		}
	private:
		Node* _root;
	};
}