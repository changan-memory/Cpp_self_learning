#pragma once
#include <iostream>
using namespace std;

namespace K {
	// 二叉搜索树 version -- K
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
		// 现在写法的赋值
		// t2 = t1
		BSTree<K>& operator=(BSTree<K> tmp) {
			std::swap(_root, tmp._root);
			return *this;
		}
		~BSTree() {
			Destroy(_root);
		}
		// 插入时，找到一个空位置插入即可   默认插入的元素不能重复
		bool insert(const K& key) {
			// 插入时为空树
			if (_root == nullptr) {
				_root = new Node(key);
				return true;
			}
			// 不是空树时
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
			// 走到这里，意味着curNode已经找到了正确的位置,此时curNode为nullptr
			// parent 为curNode的父节点
			// curNode 为 结点指针的拷贝，修改curNode不能修改结点指针的指向
			curNode = new Node(key);
			if (key > parent->_key) {
				parent->_right = curNode;
			}
			else
				parent->_left = curNode;
			return true;
			// key不可能等于parent->_key  否则上面的循环就是错误的
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

		// 这里不能用引用代替指针，因为指针可以改变指向，引用一旦绑定，指向不可修改
		bool erase(const K& key) {
			Node* parent = nullptr;
			Node* curNode = _root;
			// _root为空时，进不去while循环，会直接return false 
			// 找节点
			while (curNode) {
				if (key > curNode->_key) {
					parent = curNode;
					curNode = curNode->_right;
				}
				else if (key < curNode->_key) {
					parent = curNode;
					curNode = curNode->_left;
				}
				// 找到了，找到了，删除分为三种情况
				else {
					// curNode 的左为空
					if (curNode->_left == nullptr) {
						// 特殊情况，左为空且curNode 为_root
						if (curNode == _root)
							_root = curNode->_right;

						// 托孤
						// 当前结点是父的左节点
						else if (curNode == parent->_left) {
							parent->_left = curNode->_right;
						}
						// 当前结点是父的右节点
						else {
							parent->_right = curNode->_right;
						}
						delete curNode;
						return true;
					}
					// curNode 的右为空
					else if (curNode->_right == nullptr) {
						if (curNode == _root)
							_root = curNode->_left;
						// 托孤
						// 当前结点是父的左节点
						else if (curNode == parent->_left) {
							parent->_left = curNode->_left;
						}
						// 当前结点是父的右节点
						else {
							parent->_right = curNode->_left;
						}
						delete curNode;
						return true;
					}
					// curNode的左右都不为空，需要在树中找一个结点替换curNode
					else {
						// 需要找左子树中最大的、或右子树中最小的替换当前结点
						// 二叉搜索树中，子树的最大结点，是树中最右边的结点
						//               子树的最小结点，是树中最左边的结点
						// 这里找左子树中最大的结点
						Node* maxNode = curNode->_left;
						Node* maxParent = curNode;
						// 有可能进不去while循环，对应与删除时的 else 条件
						// 进不去while时，此时maxNode初识就是左子树的最大结点，parent和curNode重合
						while (maxNode->_right != nullptr) {
							maxParent = maxNode;
							maxNode = maxNode->_right;
						}// 循环结束后，maxNode为左子树中最大的结点
						curNode->_key = maxNode->_key;	// 替换值

						// 左子树的最大结点一定没有右孩子，但可能有左孩子
						// maxNode可能是Parent的右孩子，且maxNode可能有左孩子
						if (maxNode == maxParent->_right) {
							maxParent->_right = maxNode->_left;
						}
						// maxNode也可能是Parent的左孩子，且maxNode可能有左孩子
						else { // maxNode是curNode->_left，此时pareng->_left就是maxNode
							maxParent->_left = maxNode->_left;
						}
						delete maxNode;
						//Node* maxNode = curNode->_left;
						//Node* maxParent = curNode;
						//while (maxNode->_right != nullptr) {
						//	maxParent = maxNode;
						//	maxNode = maxNode->_right;
						//}// 循环结束后，maxNode为左子树中最大的结点
						//std::swap(maxNode->_key, curNode->_key);
						//delete maxNode;
						//maxParent->_right = nullptr;	// 错误逻辑
					}
					return true;
				}
			}
			return false;
		}
		// find函数的递归版本
		// 写了一个子函数，因为递归需要用到Private成员_root，来控制递归子树的分支
		// 如果不写子函数，需要对外提供一个getRoot供调用者使用
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
				// 分别递归拷贝 左右子树，拷贝完后，递归回去连接
				newRoot->_left = Copy(root->_left);
				newRoot->_right = Copy(root->_right);
				return newRoot;
			}
		}
		void Destroy(Node*& root) {
			if (root == nullptr)
				return;
			// 二叉树的析构，走后序遍历删除
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
			// 不 < 不 > 表明查找成功
			else
				return true;
		}
		// 这里参数root加引用，修改指针
		bool _insert_R(Node*& root, const K& key) {
			// 走到空的地方，可以开始插入了
			// 这里可以记录父节点，修改父节点的指针完成插入。不过比较复杂，这里使用
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
			// 相等时要删除
			else {
				Node* delNode = root;
				// 1. curNode 左为空
				if (root->_left == nullptr) {
					root = root->_right;
				}
				// 2. curNode 右为空
				else if (root->_right == nullptr) {
					root = root->_left;
				}
				// 3. curNode 左右都不为空
				else {
					// 找左子树中最大的结点
					Node* maxNode = root->_left;
					while (maxNode->_right) {
						maxNode = maxNode->_right;
					}
					std::swap(maxNode->_key, root->_key);
					// 交换过后，原来的maxNode是左子树中最大的结点，因此其右子树一定为空
					// 再去左子树中删除一遍
					return _erase_R(root->_left, key);
					//return _erase_R(maxNode, key);	// 不能这么写
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
	// 二叉搜索树 version -- K_V
	// 结点中同时存，key 和 对应的 value
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
		// 现在写法的赋值
		// t2 = t1
		BSTree<K, V>& operator=(BSTree<K, V> tmp) {
			std::swap(_root, tmp._root);
			return *this;
		}
		~BSTree() {
			Destroy(_root);
		}
		// 插入时，找到一个空位置插入即可   默认插入的元素不能重复
		bool insert(const K& key, const V& value) {
			// 插入时为空树
			if (_root == nullptr) {
				_root = new Node(key, value);
				return true;
			}
			// 不是空树时
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
			// 走到这里，意味着curNode已经找到了正确的位置,此时curNode为nullptr
			// parent 为curNode的父节点
			// curNode 为 结点指针的拷贝，修改curNode不能修改结点指针的指向
			curNode = new Node(key, value);
			if (key > parent->_key) {
				parent->_right = curNode;
			}
			else
				parent->_left = curNode;
			return true;
			// key不可能等于parent->_key  否则上面的循环就是错误的
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

		// 这里不能用引用代替指针，因为指针可以改变指向，引用一旦绑定，指向不可修改
		bool erase(const K& key) {
			Node* parent = nullptr;
			Node* curNode = _root;
			// _root为空时，进不去while循环，会直接return false 
			// 找节点
			while (curNode) {
				if (key > curNode->_key) {
					parent = curNode;
					curNode = curNode->_right;
				}
				else if (key < curNode->_key) {
					parent = curNode;
					curNode = curNode->_left;
				}
				// 找到了，找到了，删除分为三种情况
				else {
					// curNode 的左为空
					if (curNode->_left == nullptr) {
						// 特殊情况，左为空且curNode 为_root
						if (curNode == _root)
							_root = curNode->_right;

						// 托孤
						// 当前结点是父的左节点
						else if (curNode == parent->_left) {
							parent->_left = curNode->_right;
						}
						// 当前结点是父的右节点
						else {
							parent->_right = curNode->_right;
						}
						delete curNode;
						return true;
					}
					// curNode 的右为空
					else if (curNode->_right == nullptr) {
						if (curNode == _root)
							_root = curNode->_left;
						// 托孤
						// 当前结点是父的左节点
						else if (curNode == parent->_left) {
							parent->_left = curNode->_left;
						}
						// 当前结点是父的右节点
						else {
							parent->_right = curNode->_left;
						}
						delete curNode;
						return true;
					}
					// curNode的左右都不为空，需要在树中找一个结点替换curNode
					else {
						// 需要找左子树中最大的、或右子树中最小的替换当前结点
						// 二叉搜索树中，子树的最大结点，是树中最右边的结点
						//               子树的最小结点，是树中最左边的结点
						// 这里找左子树中最大的结点
						Node* maxNode = curNode->_left;
						Node* maxParent = curNode;
						// 有可能进不去while循环，对应与删除时的 else 条件
						// 进不去while时，此时maxNode初识就是左子树的最大结点，parent和curNode重合
						while (maxNode->_right != nullptr) {
							maxParent = maxNode;
							maxNode = maxNode->_right;
						}// 循环结束后，maxNode为左子树中最大的结点
						curNode->_key = maxNode->_key;	// 替换值
						curNode->_value = maxNode->_value;

						// 左子树的最大结点一定没有右孩子，但可能有左孩子
						// maxNode可能是Parent的右孩子，且maxNode可能有左孩子
						if (maxNode == maxParent->_right) {
							maxParent->_right = maxNode->_left;
						}
						// maxNode也可能是Parent的左孩子，且maxNode可能有左孩子
						else { // maxNode是curNode->_left，此时pareng->_left就是maxNode
							maxParent->_left = maxNode->_left;
						}
						delete maxNode;
						//Node* maxNode = curNode->_left;
						//Node* maxParent = curNode;
						//while (maxNode->_right != nullptr) {
						//	maxParent = maxNode;
						//	maxNode = maxNode->_right;
						//}// 循环结束后，maxNode为左子树中最大的结点
						//std::swap(maxNode->_key, curNode->_key);
						//delete maxNode;
						//maxParent->_right = nullptr;	// 错误逻辑
					}
					return true;
				}
			}
			return false;
		}
		// find函数的递归版本
		// 写了一个子函数，因为递归需要用到Private成员_root，来控制递归子树的分支
		// 如果不写子函数，需要对外提供一个getRoot供调用者使用
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
				// 分别递归拷贝 左右子树，拷贝完后，递归回去连接
				newRoot->_left = Copy(root->_left);
				newRoot->_right = Copy(root->_right);
				return newRoot;
			}
		}
		void Destroy(Node*& root) {
			if (root == nullptr)
				return;
			// 二叉树的析构，走后序遍历删除
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
			// 不 < 不 > 表明查找成功
			else
				return root;
		}
		// 这里参数root加引用，修改指针
		bool _insert_R(Node*& root, const K& key, const V& value) {
			// 走到空的地方，可以开始插入了
			// 这里可以记录父节点，修改父节点的指针完成插入。不过比较复杂，这里使用
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
			// 相等时要删除
			else {
				Node* delNode = root;
				// 1. curNode 左为空
				if (root->_left == nullptr) {
					root = root->_right;
				}
				// 2. curNode 右为空
				else if (root->_right == nullptr) {
					root = root->_left;
				}
				// 3. curNode 左右都不为空
				else {
					// 找左子树中最大的结点
					Node* maxNode = root->_left;
					while (maxNode->_right) {
						maxNode = maxNode->_right;
					}
					std::swap(maxNode->_key, root->_key);
					std::swap(maxNode->_value, root->_value);
					// 交换过后，原来的maxNode是左子树中最大的结点，因此其右子树一定为空
					// 再去左子树中删除一遍
					return _erase_R(root->_left, key);
					//return _erase_R(maxNode, key);	// 不能这么写
				}
				delete delNode;
				return true;
			}
		}
	private:
		Node* _root;
	};
}