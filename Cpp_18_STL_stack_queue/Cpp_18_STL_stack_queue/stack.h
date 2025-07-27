//#pragma once
//
//
//// 适配器模式
//// 没必要再从0实现一个栈， 数据的存储可以用其他容器实现。栈由其他容器适配出来
//namespace m_stack {
//	template<class T, class Container = list<T> >
//	class stack {
//	public:
//		stack(){}
//		void push(const T& ele) {
//			_con.push_back(ele);
//		}
//
//		void pop() {
//			_con.pop_back();
//		}
//		T& top() {
//			// return _con[size-1];	//这是错误写法 不能用[] 因为适配器是list时，没有[]重载
//			return _con.back();
//		}
//		size_t size() const {
//			return _con.size();
//		}
//		bool empty() const {
//			return _con.empty();
//		}
//	private:
//		Container _con;		// 这是自定义类型，该类内无需实现构造函数和析构函数
//	};
//	// 秒切换数组结构和链式结构
//	void testChange() {
//		stack<int, vector<int>> st1;
//		stack<int, list<int>> st2;
//		stack<int, deque<int>> st3;
//	}
//	void testStack() {
//		m_stack::stack<int, vector<int>> st1;
//		st1.push(1);
//		st1.push(2);
//		st1.push(3);
//		st1.push(4);
//		while (!st1.empty()) {
//			int top = st1.top();
//			st1.pop();
//			cout << top << " ";
//		}
//		cout << endl;
//
//		m_stack::stack<int, list<int>> st2;
//		st2.push(1);
//		st2.push(2);
//		st2.push(3);
//		st2.push(4);
//		while (!st2.empty()) {
//			int top = st2.top();
//			st2.pop();
//			cout << top << " ";
//		}
//		cout << endl;
//	}
//}

#pragma once
// 适配器模式
// 没必要再从0实现一个栈， 数据的存储可以用其他容器实现。栈由其他容器适配出来
// 可以增加一个模板参数来接受容器，然后
// 容器适配器就是 将已有的容器封装改造，设计出想要的容器

// STL中给的默认适配容器是deque
namespace m_stack {
	template<typename T, typename Container = deque<T>>
	class stack {
	private:
		Container _con;		// 这是自定义类型，该类内无需实现构造函数和析构函数
	public:
		// 类内是 自定义类型，构造函数和析构函数无需实现
		// 编译器默认生成的 会自动调用 自定义类型的构造函数和析构函数
		// stack(){}
		// ~stack(){}		
		void push(const T& val) {
			_con.push_back(val);
		}
		void pop() {
			_con.pop_back();
		}
		// top 应该同时实现 const 和 非const 版本 保证只读stack和可修改stack的使用
		const T& top() const {
			// return _con[size-1];	//这是错误写法 不能用[] 因为适配器是list时，没有[]重载
			return _con.back();
		}
		T& top() {
			return _con.back();
		}
		size_t size() const {
			return _con.size();
		}
		bool empty() const {
			return _con.empty();
		}
	};
	// 秒切换数组结构和链式结构
	void testChange() {
		stack<int, vector<int>> st1;
		stack<int, list<int>> st2;
		stack<int, deque<int>> st3;
	}
	void testStack() {
		m_stack::stack<int, vector<int>> st1;
		st1.push(1);
		st1.push(2);
		st1.push(3);
		st1.push(4);
		while (!st1.empty()) {
			int top = st1.top();
			st1.pop();
			cout << top << " ";
		}
		cout << endl;

		m_stack::stack<int, list<int>> st2;
		st2.push(1);
		st2.push(2);
		st2.push(3);
		st2.push(4);
		while (!st2.empty()) {
			int top = st2.top();
			st2.pop();
			cout << top << " ";
		}
		cout << endl;
	}

}