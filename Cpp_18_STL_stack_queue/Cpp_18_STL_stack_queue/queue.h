//#pragma once
//
//namespace m_queue {
//	template<class T, class Container = list<T> >
//	class queue {
//	public:
//		queue() {}
//
//		void push(const T& ele) {
//			_con.push_back(ele);
//		}
//
//		void pop() {
//			_con.pop_front();
//		}
//		T& front() {
//			return _con.front();
//		}
//		T& back() {
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
//
//	// 秒切换数组结构和链式结构
//	void testChange() {
//		//queue<int, vector<int>> q1;	//queue不适合用vector进行适配
//		queue<int, list<int>> q2;
//		queue<int, deque<int>> q3;
//	}
//	void testQueue() {
//		m_queue::queue<int, list<int>> q1;
//		q1.push(1);
//		q1.push(2);
//		q1.push(3);
//		q1.push(4);
//		while (!q1.empty()) {
//			int front = q1.front();
//			q1.pop();
//			cout << front << " ";
//		}
//		cout << endl;
//
//		m_queue::queue<int, deque<int>> q2;
//		q2.push(1);
//		q2.push(2);
//		q2.push(3);
//		q2.push(4);
//		while (!q2.empty()) {
//			int front = q2.front();
//			q2.pop();
//			cout << front << " ";
//		}
//		cout << endl;
//	}
//}


#pragma once

namespace m_queue {
	template<typename T, typename Container = deque<T>>
	class queue {
	private:
		Container _con;		// 这是自定义类型，该类内无需实现构造函数和析构函数
	public:
		// 类内是 自定义类型，构造函数和析构函数无需实现
		// 编译器默认生成的 会自动调用 自定义类型的构造函数和析构函数
		// queue(){}
		// ~queue(){}		
		void push(const T& val) {
			_con.push_back(val);
		}
		void pop() {
			_con.pop_front();
			//_con.erase(_con.begin());		// 可以强制使用vector适配
			// 但是不合适，因为vector头删效率更低
		}

		// front 和 back 应该同时实现 const 和 非const 版本 保证只读stack和可修改stack的使用
		const T& front() const {
			// return _con[size-1];	//这是错误写法 不能用[] 因为适配器是list时，没有[]重载
			return _con.front();
		}
		T& front() { 
			return _con.front(); 
		}

		const T& back() const {
			return _con.back();
		}
		T& back() { 
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
		//queue<int, vector<int>> q1;	//queue不适合用vector进行适配
		queue<int, list<int>> q2;
		queue<int, deque<int>> q3;
	}
	void testQueue() {
		m_queue::queue<int, list<int>> q1;
		q1.push(1);
		q1.push(2);
		q1.push(3);
		q1.push(4);
		while (!q1.empty()) {
			int front = q1.front();
			q1.pop();
			cout << front << " ";
		}
		cout << endl;

		m_queue::queue<int, deque<int>> q2;
		q2.push(1);
		q2.push(2);
		q2.push(3);
		q2.push(4);
		while (!q2.empty()) {
			int front = q2.front();
			q2.pop();
			cout << front << " ";
		}
		cout << endl;
	}
}