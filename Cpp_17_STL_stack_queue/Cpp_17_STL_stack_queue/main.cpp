#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

#include "stack.h"
#include "queue.h"

// stack 和 queue 的使用
void testUse_stack_queue() {
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	while (!st.empty()) {
		int top = st.top();
		st.pop();
		cout << top << " ";
	}
	cout << endl;

	queue<int> q;
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";
	}

}

//int main() {
//
//	//m_stack::testStack();
//	m_queue::testQueue();
//	return 0;
//}