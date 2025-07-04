#include "stack.h"
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
}