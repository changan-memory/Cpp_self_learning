#include <iostream>
#include <deque>
// ������ģʽ
namespace m_stack {
	template<class T, class Container = std::deque<T> >
	class stack {
	public:
		// ģ�������Ͷ������
		void push(const T& ele);
		void pop();

		T& top() {
			return _con.back();
		}
		size_t size() const {
			return _con.size();
		}
		bool empty() const {
			return _con.empty();
		}
	private:
		Container _con;		// �����Զ������ͣ�����������ʵ�ֹ��캯������������
		// �����ڣ�������Ĭ�����ɵĹ��캯�����������������Զ������Զ�����Ĺ��캯������������
	};
}

// ��������ռ��Զ��ϲ�
// ģ�������Ͷ�����룬�ᷢ�����Ӵ���
namespace m_stack {
	// ���������� Container ��Ĭ�����������崦�Ͳ�Ҫ����
	template<class T, class Container>
	void stack<T, Container>::push(const T& ele) {
		_con.push_back(ele);
	}

	template<class T, class Container>
	void stack<T, Container>::pop() {
		_con.pop_back();
	}
	//// ����취 1. ��ʽʵ����
	//template class stack<int>;		//  ����ģ�������ʽʵ����
	//template class stack<double>;		//  ����ģ�������ʽʵ����
	//// ��ʽʵ�����α겻�α���ÿ����һ�����ͣ���Ҫ��ʽʵ����һ��
}


