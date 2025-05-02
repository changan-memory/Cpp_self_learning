#include <iostream>
#include <list>

using namespace std;

void test_listAccess() {
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	list<int>::iterator it = lt.begin();
	while (it != lt.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//范围for输出的是元素
	for (auto& e : lt) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
	test_listAccess();
	return 0;
}