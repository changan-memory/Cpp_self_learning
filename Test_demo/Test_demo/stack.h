#include <iostream>
#include <deque>
// 适配器模式
namespace m_stack {
	template<class T, class Container = std::deque<T> >
	class stack {
	public:
		// 模板声明和定义分离
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
		Container _con;		// 这是自定义类型，该类内无需实现构造函数和析构函数
	};
}


