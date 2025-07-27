#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

void test_deque() {
	deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_front(3);
	dq.push_front(4);
	for (auto& e : dq)
		cout << e << " ";
	cout << endl;
}

int main() {

	test_deque();

	return 0;
}