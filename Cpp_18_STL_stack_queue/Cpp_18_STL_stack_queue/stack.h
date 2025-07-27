#pragma once


// 适配器模式
// 没必要再从0实现一个栈， 数据的存储可以用其他容器实现。栈由其他容器适配出来
namespace m_stack {
	template<class T, class Container = list<T> >
	class stack {
	public:
		stack(){}
		void push(const T& ele) {
			_con.push_back(ele);
		}

		void pop() {
			_con.pop_back();
		}
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