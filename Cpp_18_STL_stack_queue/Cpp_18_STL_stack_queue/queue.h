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
//		Container _con;		// �����Զ������ͣ�����������ʵ�ֹ��캯������������
//	};
//
//	// ���л�����ṹ����ʽ�ṹ
//	void testChange() {
//		//queue<int, vector<int>> q1;	//queue���ʺ���vector��������
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
		Container _con;		// �����Զ������ͣ�����������ʵ�ֹ��캯������������
	public:
		// ������ �Զ������ͣ����캯����������������ʵ��
		// ������Ĭ�����ɵ� ���Զ����� �Զ������͵Ĺ��캯������������
		// queue(){}
		// ~queue(){}		
		void push(const T& val) {
			_con.push_back(val);
		}
		void pop() {
			_con.pop_front();
			//_con.erase(_con.begin());		// ����ǿ��ʹ��vector����
			// ���ǲ����ʣ���ΪvectorͷɾЧ�ʸ���
		}

		// front �� back Ӧ��ͬʱʵ�� const �� ��const �汾 ��ֻ֤��stack�Ϳ��޸�stack��ʹ��
		const T& front() const {
			// return _con[size-1];	//���Ǵ���д�� ������[] ��Ϊ��������listʱ��û��[]����
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

	// ���л�����ṹ����ʽ�ṹ
	void testChange() {
		//queue<int, vector<int>> q1;	//queue���ʺ���vector��������
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