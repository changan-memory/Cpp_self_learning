#include <iostream>
using namespace std;
#include <stack>

void test1() {
	stack<int> s;
	if (s.empty())
		cout << s.size() << endl;
	// stack û�е�����
	for (int i = 0; i < 10; i++) {
		s.push(i);
	}
	cout << "��ǰ��СΪ" << s.size() << endl;
	while (!s.empty()) {
		cout << "ջ��Ԫ��Ϊ" << s.top() << endl;
		s.pop();
	}
	if (s.empty())
		cout << "ջΪ��" << endl;
}

int main() {

	test1();
	return 0;
}