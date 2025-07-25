#include <iostream>
#include "m_vector.h"
using namespace std;

//int main() {
//	mm_vector::vector<int> v1;
//	v1.reserve(4);
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	for (auto& e : v1)
//		cout << e << " ";
//	cout << endl;
//	// 外部迭代器失效
//	// 不能排除有人会这样子调用insert函数
//	mm_vector::vector<int>::iterator p = v1.begin() + 3;
//	v1.insert(p, 300);
//	cout << "insert之后，*p之前 : ";
//	for (auto& e : v1)
//		cout << e << " ";
//	cout << endl <<"*p之后:              ";
//	*p += 100;
//	for (auto& e : v1)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}

//int main() {
//
//	mm_vector::vector<int> v1;
//	//std::vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.push_back(6);
//	for (auto& e : v1)
//		cout << e << " ";
//	cout << endl;
//	mm_vector::vector<int>::iterator it = v1.begin();
//	v1.erase(it);
//	cout << *it << endl;
//	for (auto& e : v1)
//		cout << e << " ";
//	cout << endl;
//}

int main() {
	mm_vector::vector<int> v1(10, 1);
	for (auto& e : v1)
		cout << e << " ";
	cout << endl;
	return 0;
}