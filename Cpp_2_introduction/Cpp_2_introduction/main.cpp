#include <iostream>
using std::cout;
using std::endl;

// 一、
//缺省参数  基本使用
void Func(int a);
void Func(int a = 10) {
	cout << a << endl;
}
void Test1() {
	Func();	//默认输出
	Func(1000);
}
// 2.
void Func2(int a = 10, int b = 100, int c = 1000) {
	cout << a << " " << b << " " << c << endl;
}
void Test2() {	//传参时缺省，使用声明或定义时的默认值
	//全缺省参数
	Func2();
	//半缺省参数    缺省参数在  传参时， 必须从左向右传， 编译器是从左向右依次赋值的，因此不能跳着传
	Func2(100000000);
	Func2(20, 200);
	Func2(100, 200, 300);
}
//定义时参数缺省
// 由于编译器传参时是   从右向左 传的， 因此默认值  应该从右开始向左设置
void Func3(int a, int b = 100, int c = 10000) {
	cout << a << " " << b << " " << c << endl;
}
void Test3() {
	//无缺省值的参数    必须传入
	Func3(666);
	Func3(666, 777);
	Func3(666, 777, 888);
}
//总结缺省参数
//1. 半缺省参数必须从右往左依次来给出，不能间隔着给
//2. 缺省参数不能在函数声明和定义中同时出现
//3. 缺省值必须是常量或者全局变量
//4. C语言不支持（编译器不支持）


//半缺省的应用
#include "Stack.h"

void Test4() {
	struct Stack st1;
	struct Stack st2;
	//场景1  初始化两个栈， 如果已知需要插入10000个元素， 可以给缺省参数传参， 直接开辟10000个空间
	//避免扩容的损耗
	StackInit(&st1, 100000);
	//场景2 我不知道一共要插入多少个数据， 那就根据缺省值来初始化  随着数据量的增多来扩容
	StackInit(&st2);
}
//二、
//函数重载
//函数重载：是函数的一种特殊情况，C++允许在同一作用域中声明几个功能类似的同名函数，这
//些同名函数的形参列表( 参数个数 或 类型 或 类型顺序)不同，常用来处理实现功能类似数据类型不同的问题。

// 重载对函数的返回值没有要求

//1 参数类型不同
int Add(int x, int y) {
	cout << "int x, int y" << endl;
	return x + y;
}
double Add(double x, int y) {
	cout << "double x, int y" << endl;
	return x + y;
}
// 2 参数个数不同
void f() {
	cout << "无参" << endl;
}
void f(int x) {
	cout << "一个参数" << endl;
}

//3 类型的顺序不同
void f1(int a, double b) {
	cout << "int , double" << endl;
}
void f1(double a, int b) {
	cout << "double, int" << endl;
}
//4. 函数重载与函数的缺省值
//属于函数重载
//可以编译通过，但实际调用时， 会报错， 因为当参数为空时， 不知道调用哪个函数
void f2() {
	cout << "无缺省值"<<endl;
}
void f2(int a = 10) {
	cout << "有缺省值" << endl;
}
void Test5() {
	//1. 类型不同
	Add(1, 2);
	Add(1.11, 2);
	//2. 参数个数不同
	f();
	f(1);
	//3. 参数 的类型的顺序不同
	f1(1, 2.2);
	f1(2.2, 1);
	//函数重载与缺省值碰撞
	// 有默认参数 并且 不传参数时， 有二义性， 因此报错
	f2(1);//输出有缺省值
}

void Test6() {
	struct Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 1.1);
}
//函数重载的原理
//为什么C语言不支持函数重载  编译器不支持
//为什么C++支持函数重载   C++的编译器支持 函数名修饰
//函数名修饰规则  C++的编译器会把函数的  可以在Linux下用objdump查看修饰后的函数名
//C语言的编译器不会对函数名有这样的修饰

//就算改了函数名修饰规则， 也不能支持返回值不同的重载  因为会在函数调用时产生歧义
//解释如下， 就算改了函数名修饰规则，调用时， 不知道该调用哪种返回值类型的函数(调用函数不能指定返回值)

//编译 给出承诺   链接  兑现承诺

int main() {
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();
	//Test6();
	return 0;
}