#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}

void test1() {
	// 通过 reserve 预留空间 来减少 不断找新空间的次数
	vector<int> v1;
	v1.reserve(100000);
	int num = 0;
	int* p = nullptr;
	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];
			num++;
		}
	}
	cout << num << endl;
	
}

int main() {
	test1();
	return 0;
}