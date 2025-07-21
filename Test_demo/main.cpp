//#include <iostream>
//#include <string>
//using namespace std;

//// 函数模板
//template<class T>
//bool Less(T left, T right) {
//	return left < right;
//}
//
//int main() {
//	cout << Less(1, 2) << endl;
//	double a = 2.2, b = 1.1;
//	double* pa = &a, * pb = &b;
//	cout << Less(pa, pb) << endl;
//	return 0;
//}


#include <iostream>
#include "stack.hpp"
using namespace std;

//int main() {
//	m_stack::stack<int> st1;
//	st1.push(1);
//	st1.push(2);	//调用push，链接错误
//	// 链接错误，在符号表中，找不到push函数的地址
//	st1.top();		// top
//	st1.size();		//调用size无链接错误
//	cout << "stack.hpp" << endl;
//	return 0;
//}