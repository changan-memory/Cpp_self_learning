#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>



void Test_NewFunction() {
	//auto自动类型识别， 根据右边表达式的类型自动推导变量的类型
	auto a = 10;
	auto b = 11.11;
	auto c = a;
	auto d = b;
	//可以用法typeid().name来查看类型
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	//auto对于后面的长类型识别非常有用
	std::vector<std::string>::iterator it; //类型这么长可以用auto  省功夫嘛
}

//基于范围的for循环
//使用条件， 遍历数组的范围必须是确定的
void TestFor(){
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;
	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << endl;

	//适用于数组，范围for, 语法糖
	//依次去数组中数据赋值给 ele, 自动迭代， 自动判断结束
	for (auto ele : array)
		cout << ele << " ";
	cout << endl;
	//想修改元素的话，可以用引用
	for (auto& ele : array) {	//可用普通continue,也可用continue;
		ele *= 2;
		cout << ele << " ";
	}
	//不能使用
	/*int* base = (int*)malloc(sizeof(int) * 10);
	for (auto ele : base) {

	}
	1. for循环迭代的范围必须是确定的
	对于数组而言，就是数组中第一个元素和最后一个元素的范围；对于类而言，应该提供
	begin和end的方法，begin和end就是for循环迭代的范围。
	注意：以下代码就有问题，因为for的范围不确定
	void Test(int arrar[]){
		for(auto& ele : array)
			cout<<ele<<endl;
	}
	2. 迭代的对象要实现++和==的操作*/
}


//加入有个函数，要在循环内执行10000次， 那么每次调用函数都会建立栈帧，有建立栈帧的开销
// C语言中通过宏函数，将函数体展开来解决这样的问题
//#define TESTADD(x, y) (10*(x+y))	//宏执行的是文本替换， 不能加分号， 不能加return  不用加形参类型
#define ADD(x, y) (10*((x)+(y)))  //每个变量都可能是表达式，因此，需要加多重括号

//#define 中加 \ 代表多行宏， 告诉编译器这些行是在同一行
#define safe_add(a, b) ({ \
    typeof(a) _a = (a); \
    typeof(b) _b = (b); \
    _a + _b; \
})
//宏函数-----
//优点      不需要建立栈帧， 提高效率
//缺点		复杂，容易出错， 代码的可读性差， 不能调试， 没有类型安全的检查

//C++中引入内联函数，来解决这样的问题
//在普通函数的最前面加上  inline 关键字，该函数就成了内联函数
//适用于 短小的，被频繁调用的函数，长函数就不要使用 inline 函数展开了
//多个 inline 函数展开后，会使可执行程序的体积变大
//inline 对于编译器来说，只是一个建议， 是否称为内联函数，取决于编译器
//1. 比较长的函数
//2. 递归函数    不会被编译器定义为内联函数
//默认debug模式下， 内敛不会生效，否则不方便调试了
inline int Add(int left, int right) {
	return left + right;
}
void Test_inline() {
	for (int i = 0; i < 10000; ++i) {
		cout << Add(i, i + 1) << endl;
	}
}
#include "Func.h"
void Test_Inline() {
	F(2, 3);	//F函数，有声明，有定义,为什么链接时错误  
	//内联函数声明和定义不能分离， 内联函数不需要被call(没有函数地址), 不会进入符号表，链接时就找不到
	//此处调用时，只有声明，因此编译器就要去找函数的定义，但内联函数的定义被展开了，找不到
}

//C++中的空指针
void f(int) {
	cout << "f(int)" << endl;
}
void f(int*) {
	cout << "f(int*)" << endl;
}
void Test_nullptr() {
	f(0);
	f(NULL);
	f(nullptr);	//空指针关键字
	cout << sizeof(nullptr) << endl; //8字节
}
int main() {

	//Test_NewFunction();
	//TestFor();
	//Test_Inline();
	Test_nullptr();
	return 0;
}