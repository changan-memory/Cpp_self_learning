#include<iostream>
using std::endl;
using std::cout;
using std::cin;

//1. 引用 从语法的概念来说，引用 就是 给一个变量起别名
void Test1() {
	int a = 0;
	int num = 100;
	int& b = a;
	int& c = b;
	int& d = c;
	//int& e;		//引用必须初始化
	//int& d = num;	//引用一旦指定，不可修改
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << &d << endl;
}
//利用引用，可以避免指针和多级指针
void Swap(int& a, int& b) {	//交换值
	int temp = a;
	a = b;
	b = temp;
}
void Swap(int*& a, int*& b) {	//交换指针
	int* temp = a;
	a = b;
	b = temp;
}
void Test2() {
	cout << "交换数值" << endl;
	int a = 10, b = 100;
	cout << a << " " << b << endl;
	Swap(a, b);
	cout << a << " " << b << endl;
	cout << "交换指针" << endl;
	int* pa = &a;
	int* pb = &b;
	cout << pa << " " << pb << endl;
	Swap(pa, pb);
	cout << pa << " " << pb << endl;

}
//2. 指针 引用 一节typedef 的联合使用
typedef struct ListNode {
	int data;
	struct ListNode* next;	//C语言必须这么写
	//ListNode* _next;		//C++还可以这么写，C++"把结构体升级成了类", 可以直接用类名作为类型
}ListNode, *LinkList;


//将二级指针化为一级指针的引用
void ListPushBack(ListNode* pphead, int data) {

}
//将和typedef联合后的引用
void ListPushBack(LinkList& phead, int data) {

}
// 3. 在语法层面上，引用没有开辟新的空间，只是给原来的空间 起了别名
void Test3() {
	//1. 一个变量可以有多个引用
	int a = 100;
	int& b = a;
	int& c = a;
	int& d = b;	
	//2. 引用在定义时必须初始化
	//int& x;	//该行会报错

	//3. 引用一旦引用一个实体，再不能引用其他实体 (即引用的指向不能改变)
	int y = 200;
	b = y;	//此处 对 b 和 d 的操作， 是赋值，而不是修改引用
	d = y;
}
// 4. 引用的使用场景
//_1. 做参数(输出型 参数)
//_2. 做参数  (提高效率)    (大对象/深拷贝的引用 可以极大地提高效率)
//提高效率的例子
#include <time.h>
struct A { int a[10000]; };
void TestFunc1(A a) {}
void TestFunc2(A& a) {}
void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}
//C++的引用无法完全替代指针
//_3 引用做返回值

int main() {
	//Test1();
	Test2();
	Test3();
	TestRefAndValue();
	return 0;
}