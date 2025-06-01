#include "stack.h"
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
}