#pragma once
#include <iostream>
#include <deque>
// 适配器模式
namespace m_stack {
	template<class T, class Container = std::deque<T> >
	class stack {
	public:
		//stack() {}
		// 模板声明和定义分离
		void push(const T& ele);
		void pop();

		T& top() {
			// return _con[size-1];	//这是错误写法 不能用[] 因为适配器是list时，没有[]重载
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
	 /*编译过后，push 和 pop 的地址无法确定    函数的声明是承诺，声明的语法正确，编译就会通过
	 在编译阶段(预处理后的多个.cpp文件隔离开独自进行编译)看，声明和定义分离的函数，在当前文件内只有声明
	 所以编译检查声明的函数名 参数 返回值 是否可以对得上
	 在当前文件内 有定义的函数，在编译期间直接就能确定地址，只有声明的函数，在编译期间无法确定地址
	 无法确定地址的函数，等着链接的时候，拿着修饰后的函数名，取其他文件的符号表中查找

	 一般的函数，有声明 但没有定义，发生链接错误
	 声明和定义分离的模板，有声明，有定义，但找不到，发生链接错误

	 push 定义处所在的文件，的符号表中，找不到 push 的地址，编译器没有生成 push 函数的地址，

	 涉及模板的，在模板实例化后，才会生成地址*/

	// 解决办法 1. 显式实例化
	//template class stack<int>;		//  对类模板进行显式实例化
	//template class stack<double>;		//  对类模板进行显式实例化
	// 显式实例化治标不治本，每增加一个类型，就要显式实例化一份

	// 模板不支持直接的分离编译，有更好的解决方法
	// STL中 是将 声明和定义分离开，但放在了同一个文件中
	// 当前已经放在了同一个文件中


}
