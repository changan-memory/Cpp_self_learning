#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "m_list.h"
#include "string_me.h"

using namespace std;



 //模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
 //模板的万能引用只是提供了能够 同时接收左值引用和右值引用的能力，
 //但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
 //我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要用我们下面学习的完美转发

 //实参是左值: 就是左值引用(引用折叠)
 //实参是右值: 就是右值引用
template<typename T>
void wideRef(T&& t)
{
	// ...
}

void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }

void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }

template<typename T>
void PerfectForward(T&& t)
{
	//Fun(t);
	
	// 完美转发保持对象的原生属性
	// 完美转发: 折叠后 t 是左值引用，t保持左值属性
	// 完美转发: 折叠后 t 是右值引用，t保持右值属性
	Fun(forward<T> (t));
}

//void PerfectForward(int&& t)
//{
//	Fun(t);
//}
void test11() {
	PerfectForward(10); // 右值  void PerfectForward(int&& t);

	int a;
	PerfectForward(a);  // 左值  void PerfectForward(int& t);
	PerfectForward(std::move(a)); // 右值

	const int b = 8;
	PerfectForward(b); // const 左值
	PerfectForward(std::move(b)); // const 右值
}

void test12() {
	PerfectForward(10); // 右值  int&&

	int a;
	PerfectForward(std::move(a)); // 右值
}

//void test13() {
//	int a = 19;
//	int& r = a;
//	int&& rr = std::move(a);
//
//	cout << &r << " "<< ++r << endl;
//	cout << &rr << " " << ++rr << endl;
//}
//void test14() {
//	int&& rr = 10;
//	rr++;
//	cout << rr << " " << &rr << endl;
//}
void test15() {
	m_list::list<m_string::string> lt;
	//std::list<m_string::string> lt;
	m_string::string s1("111111111111111111111");
	lt.push_back(s1);

	cout << endl;
	m_string::string s2("111111111111111111111");
 	lt.push_back(move(s2));

	cout << endl;
	lt.push_back("22222222222222222222222222");
}
int main() {
	//test11();
	//test12();
	//test13();
	//test14();
	test15();

	return 0;
}