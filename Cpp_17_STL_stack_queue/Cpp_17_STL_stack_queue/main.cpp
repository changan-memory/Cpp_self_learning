#include <iostream>
#include <stack>
#include <queue>

using namespace std;
#include "stack.h"

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

int main() {

	//testUse_stack_queue();
	m_stack::testStack();
	return 0;
}