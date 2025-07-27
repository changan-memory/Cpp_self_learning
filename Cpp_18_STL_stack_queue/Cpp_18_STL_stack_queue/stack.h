//#pragma once
//
//
//// ������ģʽ
//// û��Ҫ�ٴ�0ʵ��һ��ջ�� ���ݵĴ洢��������������ʵ�֡�ջ�����������������
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
//			// return _con[size-1];	//���Ǵ���д�� ������[] ��Ϊ��������listʱ��û��[]����
//			return _con.back();
//		}
//		size_t size() const {
//			return _con.size();
//		}
//		bool empty() const {
//			return _con.empty();
//		}
//	private:
//		Container _con;		// �����Զ������ͣ�����������ʵ�ֹ��캯������������
//	};
//	// ���л�����ṹ����ʽ�ṹ
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
// ������ģʽ
// û��Ҫ�ٴ�0ʵ��һ��ջ�� ���ݵĴ洢��������������ʵ�֡�ջ�����������������
// ��������һ��ģ�����������������Ȼ��
// �������������� �����е�������װ���죬��Ƴ���Ҫ������

// STL�и���Ĭ������������deque
namespace m_stack {
	template<typename T, typename Container = deque<T>>
	class stack {
	private:
		Container _con;		// �����Զ������ͣ�����������ʵ�ֹ��캯������������
	public:
		// ������ �Զ������ͣ����캯����������������ʵ��
		// ������Ĭ�����ɵ� ���Զ����� �Զ������͵Ĺ��캯������������
		// stack(){}
		// ~stack(){}		
		void push(const T& val) {
			_con.push_back(val);
		}
		void pop() {
			_con.pop_back();
		}
		// top Ӧ��ͬʱʵ�� const �� ��const �汾 ��ֻ֤��stack�Ϳ��޸�stack��ʹ��
		const T& top() const {
			// return _con[size-1];	//���Ǵ���д�� ������[] ��Ϊ��������listʱ��û��[]����
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
	// ���л�����ṹ����ʽ�ṹ
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