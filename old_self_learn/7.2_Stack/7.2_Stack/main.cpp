#include <iostream>
using namespace std;
#include <stack>

void test1() {
	stack<int> s;
	if (s.empty())
		cout << s.size() << endl;
	// stack 没有迭代器
	for (int i = 0; i < 10; i++) {
		s.push(i);
	}
	cout << "当前大小为" << s.size() << endl;
	while (!s.empty()) {
		cout << "栈顶元素为" << s.top() << endl;
		s.pop();
	}
	if (s.empty())
		cout << "栈为空" << endl;
}

int main() {

	test1();
	return 0;
}