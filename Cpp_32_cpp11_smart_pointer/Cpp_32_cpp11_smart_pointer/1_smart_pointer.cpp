#include <iostream>
#include <string>

using namespace std;

//// 1. 手动 new 和 delete 遇到 异常 时出现的问题
//int div() {
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//
//	return a / b;
//}
//
//void Func() {
//	// 1、如果p1这里new 抛异常会如何？
//	// 2、如果p2这里new 抛异常会如何？
//	// 3、如果div调用这里又会抛异常会如何？
//	int* p1 = new int;
//	int* p2 = new int;
//
//	div();
//
//	delete p1;
//	delete p2;
//}
//
//int main() {
//	try {
//		Func();
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}


int div() {
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");

	return a / b;
}


// 为了解决以上问题，C++设计了智能指针
template<class T>
class SmartPtr 
{
private:
	T* _ptr;
public:
	// 构造函数 保存指针，析构函数释放指针
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr() 
	{
		cout << "delete: " << _ptr << endl;
		delete _ptr;
	}
	T& operator*() 
	{
		return *_ptr;
	}
	T* operator->() 
	{
		return _ptr;
	}

};
void f()
{
	// RAII 本质是借助一个对象的生命周期，来控制这个对象的释放
	// 资源交给对象管理，对象生命周期内，资源有效，对象生命周期到了，释放资源
	// 1、RAII管控资源释放
	// 2、像指针一样 支持访问资源
	// 3. 指针的拷贝问题
	SmartPtr<pair<string, string>> sp1(new pair<string, string>("1111", "22222"));
	//div();
	SmartPtr<pair<string, string>> sp2(new pair<string, string>);
	SmartPtr<pair<string, string>> sp3(new pair<string, string>);
	SmartPtr<string> sp4(new string("xxxxx"));

	cout << *sp4 << endl;
	cout << sp1->first << endl;
	cout << sp1->second << endl;
	div();

	//delete p1;
	//cout << "delete:" << p1 << endl;
}

//int main() {
//	try {
//		f();
//	}
//	catch (const exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//// 智能指针更麻烦的场景
//int main() {
//	SmartPtr<string> sp1(new string("xxxxx"));
//	SmartPtr<string> sp2(new string("yyyyy"));
//	
//	// 默认生成的 浅拷贝赋值
//	sp1 = sp2;
//	return 0;
//	
//	// 问题
//  // 1. 同一块空间析构零次
//  // 2. 有一块空间没有被析构，导致内存泄漏
//}

 //为什么不能设计成深拷贝
 //  1. 只能指针模拟的是原生指针的行为，原生指针进行的是 值拷贝
 //                      原生指针之间的赋值，是指向同一块空间
 //  2. 由于是模板实现，如果要深拷贝，各种自定义类型的，在不确定类型的情况下，无法实现 深拷贝