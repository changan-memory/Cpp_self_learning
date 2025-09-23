#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <string>
using namespace std;

struct Point {
	//explicit Point(int x, int y)
	Point(int x, int y)
		:_x(x)
		, _y(y)
	{
		cout << "Point(int x, int y)" << endl;
	}
	int _x;
	int _y;
};
// 特性1 统一的列表初始化 {}
// 建议日常定义，不要去掉=，但是我们自己要能看懂列表初始化的这个语法
namespace use_1{
	// 一切皆可用{}初始化，并且可以不写 赋值的 =
	void test1() {
		int x = 1;	// 赋值
		int y(2);	// C++中内置类型也有构造函数
		int z = { 3 };	// 列表初始化
		int w{ 4 };		// 不写 赋值的= 的列表初始化

		int a1[] = {1, 2, 3};
		int a2[] {1, 2, 3};		// C++11
		// 以下写法 本质都会调用构造函数
		Point p0(0, 0);
		Point p1 = { 1, 1 };
		Point p2{2, 2};
	}
	void test2() {
		// C++ 11 更好地支持了这种写法
		int* p1 = new int[3] {1, 2, 3};
		int* p2 = new int[3]{ 2, 4, 6 };

		Point ptr0(0, 0);	// 调用构造函数*1
		// 之前是单参数的构造函数支持隐式类型转换

		// 这里语法的本质是  多参数构造函数的隐式类型转换
		Point ptr1 = { 1, 1 };	 //调用构造函数*1
		Point* ptr2 = new Point[2]{Point(1, 2), Point(3, 4)};	 //调用构造函数*2
		Point* ptr3 = new Point[2]{ptr0, ptr1};		// 这里没有调用构造函数
		// 下面这行这里语法的本质是  支持了 多参数构造函数的隐式类型转换
		Point* ptr4 = new Point[2]{ {2, 2}, {3, 3} };	 //调用构造函数 *2

		Point* ptr5 = new Point[1]{ {1, 1} };	// new 调用构造函数 * 1
		// {1, 8}会生成一个Point的临时对象，临时对象具有常性，需要用常引用
		//Point& rp0 = { 1, 8 };
		const Point& rp = { 1, 8 };
	}
	// 建议日常定义，不要去掉=，但是我们自己要能看懂列表初始化的这个语法
}

// 特性2  std::initializer_list 
namespace use_2 {
	void test1() {
		vector<int> v = { 1, 2, 3 };	// 这里的语法不是 {}列表初始化   调用的是构造函数
		Point p = { 1, 2 };			// 多参数的构造函数支持隐式类型转换
		// 以上两行 是不同的语法  vector可以在后面加多个值，但Point只能有两个参数

		//initializer_list 此类型的对象由编译器从 初始化列表声明 中自动构造，
		// 初始化列表声明是用大括号括起来的逗号分隔的 常量的列表 存储在内存的常量区
		auto il = { 1, 2, 5 };
		cout << typeid(il).name() << endl;
		cout << sizeof(il) << endl;

		/*const int* arr = { 1, 2, 3 };
		int* arr = { 1, 2, 3 };*/
		map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"}};
	}
}

namespace use_3 {
	// auto
	void test_auto() {
		int i = 10;
		auto p = &i;
		auto pf = malloc;	// 函数指针类型 也可以 自动识别
		cout << typeid(p).name() << endl;
		cout << typeid(pf).name() << endl;
		map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"} };
		//map<string, string>::iterator it = dict.begin();
		auto it = dict.begin();
	}

	// decltype

	// 场景一，类内的成员变量是个函数指针，但是不想写函数指针这个类型声明变量
	class A {
	private:
		decltype(malloc) pf_malloc;
	};
	// 场景二
	template<class Func>
	class B {
	private:
		Func _pf;	// 可以传入函数指针
	};
	// 关键字decltype将变量的类型声明为表达式指定的类型
	void test_decltype() {
		auto pf = malloc;	// 函数指针类型 也可以 自动识别
		cout << typeid(pf).name() << endl;
		// 如何定义一个和pf同类型变量
		//typeid(pf).name _ptr;	// typeid().name 只能获取到变量的类型，不能用于声明/定义变量
		
		// auto 定义是必须初始化
		auto pf1 = pf;	//
		// decltype		// decltype 可以先只声明，不进行初始化
		// decltype 可以推导出变量的类型 ，再定义变量，或者作为模板实参
		decltype(pf) _ptr = malloc;
		decltype(malloc) _ptr2;		// 单纯先声明一个变量，不初始化
		// typeid().name   推导出的类型是一个字符串，只能看，不能使用
		// decltype 可以推导出变量的类型 ，再定义变量，或者作为模板实参
		
		// 实例化 B 类  // decltype 作为模板实参时很好用
		B<decltype(pf)> b1;

		// decltype 推理表达式的类型
		const int x = 1;
		double y = 2.2;
		decltype(x * y) ret; // ret的类型是double
		decltype(&x) p; // p的类型是int*
		cout << typeid(ret).name() << endl;
		cout << typeid(p).name() << endl;
	}

	// nullptr 相关
	void Func(int) {
		cout << "Func(int)" << endl;
	}
	void Func(int*){
		cout << "Func(int*)" << endl;
	}
	void test_nullptr() {
		/*
		#ifndef NULL
		#ifdef __cplusplus
		#define NULL 0
		#else
		#define NULL ((void *)0)
		#endif
		#endif
		*/
		int* p = NULL;	// NULL 是宏，预处理阶段 会被替换成0， 不够安全  int* p = 0;
		Func(NULL);		// Func(0)  期望调用int* 版本，却调用了int版本
	}
	// 范围for循环，底层是 迭代器 
}

namespace new_container {
	// std::array
	void test_array() {
		int a1[10];
		std::array<int, 10> a2;
		cout << sizeof(a1) << endl;
		cout << sizeof(a2) << endl;
		//a1[15];		//  本质 是 指针的解引用   有些越界读，原生数组无法检查
		//a2[15];		//  本质 是 operatpr[]函数调用，内部检查了越界  越界读写都能检查出来

		// vector 也可以完成 array的功能，还能初始化，显得arrat很鸡肋
		vector<int> a3(10, 3);
	}
	// std::forward_list
	// 底层实现是  单链表
}
//int main() {
//	//use_1::test1();
//	//use_1::test2();
//	use_2::test1();
//	//use_3::test_auto();
//	//use_3::test_decltype();
//	//use_3::test_nullptr();
//	//new_container::test_array();
//	return 0;
//}