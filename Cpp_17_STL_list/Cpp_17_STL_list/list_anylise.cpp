
#pragma once
#include <assert.h>

namespace mm_list {

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
		{
		}
	};
	// 自定义一个迭代器, 完成迭代器++it取下一个位置或*it取数据的功能
	// list 迭代器 本质是一个自定义类型，内嵌了node*
	// 由于list空间不是连续的，无法像vector一样  使用原生指针定义迭代器
	// 因此 用一个自定义类型 封装node*，再利用运算符重载，改变*it ++it的行为
	// 自定义类型 配合 运算符重载，可以实现自定义抽象类型的 各种实现

	// 模板 只要给不同的模板参数，就是不同的类型！
	// typedef __list_iterator<T, T&> iterator;
	// typedef __list_iterator<T, const T&> const_iterator;
	template<typename T, typename Ref, typename Ptr>
	struct __list_iterator {
	public:
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;	// 这里的 self 表示迭代器自己
	public:
		Node* _node;
	public:
		// 单参数的构造函数 支持隐式类型转换
		// 用一个结点的指针构造迭代器
		__list_iterator(Node* node)		// 本来写了 const Node* node  但_node为非 const 因此错误
			:_node(node)				// 这里实现浅拷贝没有问题，
		{
		}
		//// 解引用, 节点中的数据
		////const T& operator*() {  返回 const T& 时，调用*it 返回的是 常引用, 不能修改改对象
		//T& operator*() {
		//	// 出了作用域 结点还在，因此可以用引用返回
		//	return _node->_val;
		//}

		Ref operator*() {
			// 出了作用域 结点还在，因此可以用引用返回
			return _node->_val;
		}
		//T* operator->() {
		//	return &_node->_val;
		//	//return &(operator*());  // 标准库中的写法  两种写法等价
		//}
		Ptr operator->() {
			return &_node->_val;
			//return &(operator*());  // 标准库中的写法  两种写法等价
		}
		// 为了解决const迭代器的问题，operator->的返回值用了模板，同时兼顾了const和非const类型
		// 迭代器++，返回迭代器		
		self& operator++() {
			_node = _node->_next;
			return *this;		// ++之后变成下一个位置的迭代器，因此要返回*this
		}
		// 后置++  返回self 表示自己
		self operator++(int) {
			self tmp(*this);
			_node = _node->_next;
			return tmp;		// 返回的是临时对象的拷贝，不能引用返回
		}
		self& operator--() {
			_node = _node->_prev;
			return *this;
		}
		self operator--(int) {
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		// 迭代器比较，self 自己和自己比较 自定义的迭代器需要重载 !=
		bool operator!=(const self& it) const {
			//return _node != it->_node;
			return _node != it._node;
		}
		bool operator==(const self& it) const {
			//return _node != it->_node;
			return _node == it._node;
		}
		// 迭代器类无需实现析构函数，因为iterator无需管理结点的释放
	};

	//template<typename T>
	//struct __list_const_iterator {
	//public:
	//	typedef list_node<T> Node;
	//public:
	//	Node* _node;
	//public:
	//	__list_const_iterator(Node* node)		// 本来写了 const Node* node  但_node为非 const 因此错误
	//		:_node(node)				// 这里实现浅拷贝没有问题，
	//	{ }
	//	const T& operator*() {
	//		return _node->_val;
	//	}
	//	__list_const_iterator<T>& operator++() {
	//		_node = _node->_next;
	//		return *this;		// ++之后变成下一个位置的迭代器，因此要返回*this
	//	}
	//	__list_const_iterator<T> operator++(int) {
	//		__list_const_iterator<T> tmp(*this);
	//		_node = _node->_next;
	//		return tmp;		// 返回的是临时对象的拷贝，不能引用返回
	//	}
	//	bool operator!=(const __list_const_iterator<T>& it) {
	//		//return _node != it->_node;
	//		return _node != it._node;
	//	}
	//	bool operator==(const __list_const_iterator<T>& it) {
	//		//return _node != it->_node;
	//		return _node == it._node;
	//	}
	//};

	template<typename T>
	class list {
		// 类型重定义
		typedef list_node<T> Node;
		// list的空间不是连续的，不能用Node*作为iterator
		// 把Node*封装成自定义类型，内部实现运算符重载，实现*it访问数据，++it访问下一个结点

	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		//typedef __list_const_iterator<T> const_iterator;  
		//typedef __list_const_iterator<T> const_iterator; 这么设计const迭代器太冗余了
		// 我们学习标准库中的实现	
		// 实现const迭代器的不推荐的方案 将上述iterator复制一份,改名为__list_const_iterator<T>
		// 然后仅让 operator* 返回 const T&

		//typedef const __list_iterator<T> const_iterator;	// 该写法导致 迭代器本身是const
		// const __list_iterator<T> 表示迭代器本身	// 而不是表示迭代器指向的对象是const的
		// const __list_iterator<T> 这种写法会导致 iterator 不能++

		/*const T* ptr1;		// const 迭代器模拟的是该种 const 指针
		T* const ptr2;*/
		// 如何设计 const 迭代器

		// begin 和 end 都是返回一个 我们自定义的 iterator 对象
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
		const_iterator begin() const {
			return _head->_next;		// 单参数的构造函数 
			//return const_iterator(_head);	// 以上两种写法都是生成一个匿名对象 最终返回
		}
		const_iterator end() const {
			//return _head;		// 单参数的构造函数 支持隐式类型转换
			return const_iterator(_head);	// 以上两种写法都是生成一个匿名对象 最终返回
		}

	public:
		list()
			:_size(0)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		~list() {
			// ... iterator 无需实现析构函数, iterator只是帮助我们访问数据
			clear();
			delete _head;
			_head = nullptr;
		}
		void clear() {
			iterator it = begin();
			while (it != end()) {
				it = erase(it);
			}
			//_size = 0;  没必要写，每次erase, size都会减一
		}
		void push_back(const T& val) {
			//Node* newNode = new Node(val);
			//// 尾插先找尾
			//Node* tail = _head->_prev;
			//// 链接
			//tail->_next = newNode;
			//newNode->_prev = tail;
			//newNode->_next = _head;
			//_head->_prev = newNode;
			//++_size;
			insert(end(), val);
		}
		void pop_back() {
			erase(_head->_prev);
			//erase(--end());
		}
		void push_front(const T& val) {
			insert(_head->_next, val);
			//insert(begin(), val);
		}
		void pop_front() {
			erase(_head->_next);
			//erase(begin());
		}
		size_t size() const {
			return _size;
		}
		// 在pos位置之前进行插入
		iterator insert(iterator pos, const T& val) {
			Node* newNode = new Node(val);
			newNode->_next = pos._node;
			newNode->_prev = pos._node->_prev;
			pos._node->_prev->_next = newNode;
			pos._node->_prev = newNode;
			++_size;
			return iterator(newNode);	// 返回新插入元素的位置
			// 两种实现
			/*Node* prev = pos._node->_prev;
			Node* next = pos._node;
			newNode->_next = next;
			newNode->_prev = prev;
			prev->_next = newNode;
			next->_prev = newNode;*/
			//delete next;	// 这是插入操作，不能删除结点!!!
		}
		iterator erase(iterator pos) {
			/*if (pos == end() || _head->_next == _head)
				return ;*/
			assert(pos != end());  // 调试模式检查  不能删哨兵位的头结点
			assert(_head->_next != _head);  // 可选：额外检查空链表
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			prev->_next = next;
			next->_prev = prev;
			delete pos._node;	// pos 指向的位置已经被释放了，迭代器失效
			--_size;
			return iterator(next);
		}
	private:
		//list_node<T>* _head;
		Node* _head = nullptr;	// 哨兵位头结点的指针
		size_t _size;		// 记录链表的节点数
	};

}
