
#pragma once
#include <assert.h>

namespace mm_list {

	// ��ͷ˫��ѭ������
	template<typename T>
	//class list_node {		// ����˴���struct  
	struct list_node {
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;
		// ��㴴��ʱ�Ĺ��캯��
		list_node(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _val(val)
		{
		}
	};
	// �Զ���һ��������, ��ɵ�����++itȡ��һ��λ�û�*itȡ���ݵĹ���
	// list ������ ������һ���Զ������ͣ���Ƕ��node*
	// ����list�ռ䲻�������ģ��޷���vectorһ��  ʹ��ԭ��ָ�붨�������
	// ��� ��һ���Զ������� ��װnode*����������������أ��ı�*it ++it����Ϊ
	// �Զ������� ��� ��������أ�����ʵ���Զ���������͵� ����ʵ��

	// ģ�� ֻҪ����ͬ��ģ����������ǲ�ͬ�����ͣ�
	// typedef __list_iterator<T, T&> iterator;
	// typedef __list_iterator<T, const T&> const_iterator;
	template<typename T, typename Ref, typename Ptr>
	struct __list_iterator {
	public:
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;	// ����� self ��ʾ�������Լ�
	public:
		Node* _node;
	public:
		// �������Ĺ��캯�� ֧����ʽ����ת��
		// ��һ������ָ�빹�������
		__list_iterator(Node* node)		// ����д�� const Node* node  ��_nodeΪ�� const ��˴���
			:_node(node)				// ����ʵ��ǳ����û�����⣬
		{
		}
		//// ������, �ڵ��е�����
		////const T& operator*() {  ���� const T& ʱ������*it ���ص��� ������, �����޸ĸĶ���
		//T& operator*() {
		//	// ���������� ��㻹�ڣ���˿��������÷���
		//	return _node->_val;
		//}

		Ref operator*() {
			// ���������� ��㻹�ڣ���˿��������÷���
			return _node->_val;
		}
		//T* operator->() {
		//	return &_node->_val;
		//	//return &(operator*());  // ��׼���е�д��  ����д���ȼ�
		//}
		Ptr operator->() {
			return &_node->_val;
			//return &(operator*());  // ��׼���е�д��  ����д���ȼ�
		}
		// Ϊ�˽��const�����������⣬operator->�ķ���ֵ����ģ�壬ͬʱ�����const�ͷ�const����
		// ������++�����ص�����		
		self& operator++() {
			_node = _node->_next;
			return *this;		// ++֮������һ��λ�õĵ����������Ҫ����*this
		}
		// ����++  ����self ��ʾ�Լ�
		self operator++(int) {
			self tmp(*this);
			_node = _node->_next;
			return tmp;		// ���ص�����ʱ����Ŀ������������÷���
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
		// �������Ƚϣ�self �Լ����Լ��Ƚ� �Զ���ĵ�������Ҫ���� !=
		bool operator!=(const self& it) const {
			//return _node != it->_node;
			return _node != it._node;
		}
		bool operator==(const self& it) const {
			//return _node != it->_node;
			return _node == it._node;
		}
		// ������������ʵ��������������Ϊiterator�����������ͷ�
	};

	//template<typename T>
	//struct __list_const_iterator {
	//public:
	//	typedef list_node<T> Node;
	//public:
	//	Node* _node;
	//public:
	//	__list_const_iterator(Node* node)		// ����д�� const Node* node  ��_nodeΪ�� const ��˴���
	//		:_node(node)				// ����ʵ��ǳ����û�����⣬
	//	{ }
	//	const T& operator*() {
	//		return _node->_val;
	//	}
	//	__list_const_iterator<T>& operator++() {
	//		_node = _node->_next;
	//		return *this;		// ++֮������һ��λ�õĵ����������Ҫ����*this
	//	}
	//	__list_const_iterator<T> operator++(int) {
	//		__list_const_iterator<T> tmp(*this);
	//		_node = _node->_next;
	//		return tmp;		// ���ص�����ʱ����Ŀ������������÷���
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
		// �����ض���
		typedef list_node<T> Node;
		// list�Ŀռ䲻�������ģ�������Node*��Ϊiterator
		// ��Node*��װ���Զ������ͣ��ڲ�ʵ����������أ�ʵ��*it�������ݣ�++it������һ�����

	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		//typedef __list_const_iterator<T> const_iterator;  
		//typedef __list_const_iterator<T> const_iterator; ��ô���const������̫������
		// ����ѧϰ��׼���е�ʵ��	
		// ʵ��const�������Ĳ��Ƽ��ķ��� ������iterator����һ��,����Ϊ__list_const_iterator<T>
		// Ȼ����� operator* ���� const T&

		//typedef const __list_iterator<T> const_iterator;	// ��д������ ������������const
		// const __list_iterator<T> ��ʾ����������	// �����Ǳ�ʾ������ָ��Ķ�����const��
		// const __list_iterator<T> ����д���ᵼ�� iterator ����++

		/*const T* ptr1;		// const ������ģ����Ǹ��� const ָ��
		T* const ptr2;*/
		// ������ const ������

		// begin �� end ���Ƿ���һ�� �����Զ���� iterator ����
		iterator begin() {
			return _head->_next;		// �������Ĺ��캯�� ֧����ʽ����ת��
			//return iterator(_head->_next);	
			// ��������д����������һ����������
		}
		iterator end() {
			//return _head;		// �������Ĺ��캯�� ֧����ʽ����ת��
			return iterator(_head);
			// ��������д����������һ���������� ���շ���
		}
		const_iterator begin() const {
			return _head->_next;		// �������Ĺ��캯�� 
			//return const_iterator(_head);	// ��������д����������һ���������� ���շ���
		}
		const_iterator end() const {
			//return _head;		// �������Ĺ��캯�� ֧����ʽ����ת��
			return const_iterator(_head);	// ��������д����������һ���������� ���շ���
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
			// ... iterator ����ʵ����������, iteratorֻ�ǰ������Ƿ�������
			clear();
			delete _head;
			_head = nullptr;
		}
		void clear() {
			iterator it = begin();
			while (it != end()) {
				it = erase(it);
			}
			//_size = 0;  û��Ҫд��ÿ��erase, size�����һ
		}
		void push_back(const T& val) {
			//Node* newNode = new Node(val);
			//// β������β
			//Node* tail = _head->_prev;
			//// ����
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
		// ��posλ��֮ǰ���в���
		iterator insert(iterator pos, const T& val) {
			Node* newNode = new Node(val);
			newNode->_next = pos._node;
			newNode->_prev = pos._node->_prev;
			pos._node->_prev->_next = newNode;
			pos._node->_prev = newNode;
			++_size;
			return iterator(newNode);	// �����²���Ԫ�ص�λ��
			// ����ʵ��
			/*Node* prev = pos._node->_prev;
			Node* next = pos._node;
			newNode->_next = next;
			newNode->_prev = prev;
			prev->_next = newNode;
			next->_prev = newNode;*/
			//delete next;	// ���ǲ������������ɾ�����!!!
		}
		iterator erase(iterator pos) {
			/*if (pos == end() || _head->_next == _head)
				return ;*/
			assert(pos != end());  // ����ģʽ���  ����ɾ�ڱ�λ��ͷ���
			assert(_head->_next != _head);  // ��ѡ�������������
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			prev->_next = next;
			next->_prev = prev;
			delete pos._node;	// pos ָ���λ���Ѿ����ͷ��ˣ�������ʧЧ
			--_size;
			return iterator(next);
		}
	private:
		//list_node<T>* _head;
		Node* _head = nullptr;	// �ڱ�λͷ����ָ��
		size_t _size;		// ��¼����Ľڵ���
	};

}
