#pragma once
#include <iostream>
#include <deque>
// ������ģʽ
namespace m_stack {
	template<class T, class Container = std::deque<T> >
	class stack {
	public:
		//stack() {}
		// ģ�������Ͷ������
		void push(const T& ele);
		void pop();

		T& top() {
			// return _con[size-1];	//���Ǵ���д�� ������[] ��Ϊ��������listʱ��û��[]����
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
	 /*�������push �� pop �ĵ�ַ�޷�ȷ��    �����������ǳ�ŵ���������﷨��ȷ������ͻ�ͨ��
	 �ڱ���׶�(Ԥ�����Ķ��.cpp�ļ����뿪���Խ��б���)���������Ͷ������ĺ������ڵ�ǰ�ļ���ֻ������
	 ���Ա����������ĺ����� ���� ����ֵ �Ƿ���ԶԵ���
	 �ڵ�ǰ�ļ��� �ж���ĺ������ڱ����ڼ�ֱ�Ӿ���ȷ����ַ��ֻ�������ĺ������ڱ����ڼ��޷�ȷ����ַ
	 �޷�ȷ����ַ�ĺ������������ӵ�ʱ���������κ�ĺ�������ȡ�����ļ��ķ��ű��в���

	 һ��ĺ����������� ��û�ж��壬�������Ӵ���
	 �����Ͷ�������ģ�壬���������ж��壬���Ҳ������������Ӵ���

	 push ���崦���ڵ��ļ����ķ��ű��У��Ҳ��� push �ĵ�ַ��������û������ push �����ĵ�ַ��

	 �漰ģ��ģ���ģ��ʵ�����󣬲Ż����ɵ�ַ*/

	// ����취 1. ��ʽʵ����
	//template class stack<int>;		//  ����ģ�������ʽʵ����
	//template class stack<double>;		//  ����ģ�������ʽʵ����
	// ��ʽʵ�����α겻�α���ÿ����һ�����ͣ���Ҫ��ʽʵ����һ��

	// ģ�岻֧��ֱ�ӵķ�����룬�и��õĽ������
	// STL�� �ǽ� �����Ͷ�����뿪����������ͬһ���ļ���
	// ��ǰ�Ѿ�������ͬһ���ļ���


}
