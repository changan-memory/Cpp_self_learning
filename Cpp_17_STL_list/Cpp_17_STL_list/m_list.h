#pragma once

namespace m_list {

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
		{ }
	};
	// list ������ ������һ���Զ������ͣ���Ƕ��node*
	// ����list�ռ䲻�������ģ���һ���Զ������� ��װnode*����������������أ��ı�*it ++it����Ϊ
	// �Զ������� ��� ��������أ�����ʵ���Զ���������͵� ����ʵ��
	template<typename T>
	struct __list_iterator {
		typedef list_node<T> Node;
		Node* _node;
		// �������Ĺ��캯�� ֧����ʽ����ת��
		// ��һ������ָ�빹�������
		__list_iterator(Node* node)		// ����д�� const Node* node  ��_nodeΪ�� const ��˴���
			:_node(node)				// ����ʵ��ǳ����û�����⣬
		{ }
		// ������, �ڵ��е�����
		T& operator*() {
			// ���������� ��㻹�ڣ���˿���������
			return _node->_val;
		}
		// ������++�����ص�����		
		// ǰ��++
		__list_iterator<T>& operator++() {	
			_node = _node->_next;
			return *this;
		}
		// ����++
		__list_iterator<T>& operator++(int) {
			__list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		// �������Ƚϣ��Զ���ĵ�������Ҫ���� !=
		bool operator!=(const __list_iterator<T>& it) {
			//return _node != it->_node;
			return _node != it._node;
		}
		bool operator==(const __list_iterator<T>& it) {
			//return _node != it->_node;
			return _node == it._node;
		}
		// ����������ʵ��������������Ϊiterator�����������ͷ�
		// 
	};

	template<typename T>
	class list {
		// �����ض���
		typedef list_node<T> Node;
		// list�Ŀռ䲻�������ģ�������Node*��Ϊiterator
		// ��Node*��װ���Զ������ͣ��ڲ�ʵ����������أ�ʵ��*it�������ݣ�++it������һ�����

	public:
		typedef __list_iterator<T> iterator;
		// ������ const ������

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

	public:
		list(){
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		void push_back(const T& val) {
			Node* newNode = new Node(val);
			// β������β
			Node* tail = _head->_prev;
			// ����
			tail->_next = newNode;
			newNode->_prev = tail;
			newNode->_next = _head;
			_head->_prev = newNode;
		}
	private:
		//list_node<T>* _head;
		Node* _head = nullptr;	// �ڱ�λͷ����ָ��
	};

}
