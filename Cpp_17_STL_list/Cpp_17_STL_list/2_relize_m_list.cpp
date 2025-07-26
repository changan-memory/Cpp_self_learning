#include "m_list.h"
#include <iostream>

void test_list1() {
	m_list::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	m_list::list<int>::iterator it = lt.begin();	// 自定义迭代器类型 赋值调用拷贝构造函数
													// 这里的需要是完成浅拷贝即可
	while (it != lt.end()) {
		std::cout << (*it) << " ";
		++it;
	}
	std::cout << std::endl;
	for (auto& e : lt)
		std::cout << e << " "; std::cout << std::endl;
}
//int main() {
//	test_list1();
//
//	return 0;
//}