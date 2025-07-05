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
		// 该类内，编译器默认生成的构造函数和析构函数，会自动调用自定义类的构造函数和析构函数
	};
}

// 多个命名空间自动合并
// 模板声明和定义分离，会发生链接错误
namespace m_stack {
	// 声明处给了 Container 的默认容器，定义处就不要给了
	template<class T, class Container>
	void stack<T, Container>::push(const T& ele) {
		_con.push_back(ele);
	}

	template<class T, class Container>
	void stack<T, Container>::pop() {
		_con.pop_back();
	}
	//// 解决办法 1. 显式实例化
	//template class stack<int>;		//  对类模板进行显式实例化
	//template class stack<double>;		//  对类模板进行显式实例化
	//// 显式实例化治标不治本，每增加一个类型，就要显式实例化一份
}


