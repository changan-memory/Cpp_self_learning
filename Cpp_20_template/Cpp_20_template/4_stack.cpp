#include "stack.h"

namespace m_stack {
	template<class T, class Container>
	void stack<T, Container>::push(const T& ele) {
		_con.push_back(ele);
	}

	template<class T, class Container>
	void stack<T, Container>:: pop() {
		_con.pop_back();
	}
}