//#include "stack.h"
//// 多个命名空间自动合并
//// 模板声明和定义分离，会发生链接错误
//namespace m_stack {
//	// 声明处给了 Container 的默认容器，定义处就不要给了
//	template<class T, class Container>
//	void stack<T, Container>::push(const T& ele) {
//		_con.push_back(ele);
//	}
//
//	template<class T, class Container>
//	void stack<T, Container>::pop() {
//		_con.pop_back();
//	}
//	//// 解决办法 1. 显式实例化
//	//template class stack<int>;		//  对类模板进行显式实例化
//	//template class stack<double>;		//  对类模板进行显式实例化
//	//// 显式实例化治标不治本，每增加一个类型，就要显式实例化一份
//}