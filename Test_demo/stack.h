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
	};
}


