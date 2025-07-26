#pragma once

namespace m_list {

	// 带头双向循环链表
	template<typename T>
	//class list_node {		// 建议此处用struct  
	struct list_node {
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;
		// 结点创建时的构造函数
		list_node(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _val(val)
		{ }
	};
	// list 迭代器 本质是一个自定义类型，内嵌了node*
	// 由于list空间不是连续的，用一个自定义类型 封装node*，再利用运算符重载，改变*it ++it的行为
	// 自定义类型 配合 运算符重载，可以实现自定义抽象类型的 各种实现
	template<typename T>
	struct __list_iterator {
		typedef list_node<T> Node;
		Node* _node;
		// 单参数的构造函数 支持隐式类型转换
		// 用一个结点的指针构造迭代器
		__list_iterator(Node* node)		// 本来写了 const Node* node  但_node为非 const 因此错误
			:_node(node)				// 这里实现浅拷贝没有问题，
		{ }
		// 解引用, 节点中的数据
		T& operator*() {
			// 出了作用域 结点还在，因此可以用引用
			return _node->_val;
		}
		// 迭代器++，返回迭代器		
		// 前置++
		__list_iterator<T>& operator++() {	
			_node = _node->_next;
			return *this;
		}
		// 后置++
		__list_iterator<T>& operator++(int) {
			__list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		// 迭代器比较，自定义的迭代器需要重载 !=
		bool operator!=(const __list_iterator<T>& it) {
			//return _node != it->_node;
			return _node != it._node;
		}
		bool operator==(const __list_iterator<T>& it) {
			//return _node != it->_node;
			return _node == it._node;
		}
		// 迭代器无需实现析构函数，因为iterator无需管理结点的释放
		// 
	};

	template<typename T>
	class list {
		// 类型重定义
		typedef list_node<T> Node;
		// list的空间不是连续的，不能用Node*作为iterator
		// 把Node*封装成自定义类型，内部实现运算符重载，实现*it访问数据，++it访问下一个结点

	public:
		typedef __list_iterator<T> iterator;
		// 如何设计 const 迭代器

		iterator begin() {
			return _head->_next;		// 单参数的构造函数 支持隐式类型转换
			//return iterator(_head->_next);	
			// 以上两种写法都是生成一个匿名对象
		}
		iterator end() {
			//return _head;		// 单参数的构造函数 支持隐式类型转换
			return iterator(_head);
			// 以上两种写法都是生成一个匿名对象 最终返回
		}

	public:
		list(){
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		void push_back(const T& val) {
			Node* newNode = new Node(val);
			// 尾插先找尾
			Node* tail = _head->_prev;
			// 链接
			tail->_next = newNode;
			newNode->_prev = tail;
			newNode->_next = _head;
			_head->_prev = newNode;
		}
	private:
		//list_node<T>* _head;
		Node* _head = nullptr;	// 哨兵位头结点的指针
	};

}
