#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>


using namespace std;

// 左值
// 左值一定可以取地址，一般可以赋值
void test1() {
	int a = 10;
	int b = a;
	const int c = 30;	// 被const修饰的左值  依然是左值
	const int* d = &c;
	// 以下的 p , b,  c,  *p 都是左值
	int* p = new int(10);
	int q = 1;
	const int x = 2;


	"xxxxxx";  // 该表达式的含义是 该字符串首元素的地址
	const char* px = "xxxxxx"; // 该表达式的含义是，把 "xxxxxx" 首元素的地址赋值给 px
	
	p[2];
	cout << &"xxxxx" << endl;	// 可以取地址， 左值
	cout << &px[2] << endl;		// 可以取地址， 左值



	// 以下几个是对上面左值的左值引用
	int*& rp = p;
	int& rb = b;
	const int& rc = c;
	int& pvalue = *p;
}
// 右值
int fmin(int a, int b) {
	return a < b ? a : b;
}
void test2() {
	// 以下为常见的右值
	double x = 1.1, y = 2.2;
	// 以下几个都是常见的右值
	10;
	x + y;
	fmin(x, y);	// 这里的右值指的 是 函数传值返回时，返回的 拷贝出来的 那个临时对象
	// 右值不能取地址
	/*cout << &10 << endl;
	cout << &(x + y) << endl;
	cout << &fmin(1, 2) << endl;*/
}

 //左值引用 右值引用
 //引用是取别名
 //左值引用 :  给左值取别名
 //右值引用 :  给右值取别名
void test3() {
	double x = 1.5, y = 2.5;

	// 左值引用: 给左值取别名
	int a = 10;
	int& r1 = a;

	/* 左值引用能否给右值取别名？
	 const 左值引用可以*/
	const int& r2 = 20;
	const double r3 = x + y;

	// 右值引用: 给右值取别名
	int&& r5 = 20;
	//double& r6 = x + y;		// 编译不通过
	double&& r6 = x + y;

	/* 右值引用是否可以给左值取别名
	 右值引用可以引用 move 以后的左值*/
	//int&& r7 = a;	// 编译报错
	int&& r7 = std::move(a);	// 右值引用引用 move 以后的左值

	// 总结一下
	// 左值和右值的本质区别是  能否取地址
	// 左值引用 :  给左值取别名    左值引用可以直接给左值取别名
	// 右值引用 :  给右值取别名    右值引用可以直接给右值取别名
	// const 左值引用可以 给右值取别名
	// 右值引用可以 给 move后的左值 取别名， 不能直接给左值取别名
}

// 左值引用的使用场景和价值是什么？
 //适用场景 1. 做输出型参数，减少拷贝，   2. 做返回值
 //价值:  减少拷贝  缺陷: 局部对象做返回值，不能用左值引用返回
string Func1() {
	string str;
	cin >> str;
	// ...
	return str;
}
// Func 函数中的场景只能传值返回
// 传值返回又会遇到编译器的优化
void test4() {
	// 传值返回，编译器先构造一个临时对象，为str的拷贝，再赋值给ret1，这样的行为十分损耗性能
	// 编译器将以上行为  优化为直接构造
	string ret1 = Func1();	// 编译器直接构造一个 ret1 对象
	// 以下场景 编译器无法优化
	string ret2;
	// ... 
	ret2 = Func1();
}

// 以下三个函数构成函数重载 
void func1(int& r) {
	cout << "void func1(int& r)" << endl;
}
void func1(const int& r) {
	cout << "void func1(const int& r)" << endl;
}
void func1(int&& r2) {
	cout << "void func1(int&& r)" << endl;
}
void test5() {
	int a = 0;
	const int b = 20;
	func1(a);	// 这里两个func1都可以调用，但这里不会出现歧义，编译器会去调用最匹配的那个函数
	func1(b);
	func1(a + b);	// a + b 是右值，右值引用版本 最匹配，因此调用右值引用版本
}

#include "string_me.h"


std::string test6_std() {
	std::string str("xxxxxxxxxxxxxxxxxxx");
	// ...
	return std::move(str);
	//return str;
}
m_string::string test6() {
	m_string::string str("xxxxxxxxxxxxxxxxxxx");
	// ...
	return std::move(str);
	//return str;
}
void test7() {
	//m_string::string ret1 = test6();	// 连续的拷贝和构造  优化为直接构造

	//m_string::string ret1 = test6();	

	m_string::string ret2;
	// ...
	ret2 = test6();
}

// 场景一、 自定义类型中深拷贝的类，必须传值返回的场景，移动语义提升性能
void test8() {
	m_string::string ret1 = test6();	// 移动拷贝

	m_string::string ret3("1111111111111111111111");
	m_string::string copy1 = ret3;	// 深拷贝

	move(ret3);	
	m_string::string copy2 = ret3;	// 深拷贝

	m_string::string copy3 = move(ret3);	// 移动拷贝
}
void test9() {
	std::string ret1 = test6_std();	// 移动拷贝
	std::string ret3("111111111");
	std::string copy1 = ret3;	// 深拷贝
	move(ret3);
	std::string copy2 = ret3;	// 深拷贝
	std::string copy3 = move(ret3);	// 移动拷贝
}

// 场景二、
// 容器的插入接口，如果插入对象是右值，可以利用移动构造转移资源给数据结构中的对象。也可以减少。
void test10() {
	list<m_string::string> lt;
	m_string::string s1("111111111111111111111");
	lt.push_back(s1);

	cout << endl;
	m_string::string s2("111111111111111111111");
	lt.push_back(move(s2));

	cout << endl;
	lt.push_back("22222222222222222222222222");
}


//int main() {
//	//test1();
//	//test2();
//	//test5();
//	//test7();
//	//test8();
//	//test9();
//	test10();
//	return 0;
//}