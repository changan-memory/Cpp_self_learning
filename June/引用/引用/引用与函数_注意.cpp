#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//1. 引用必须初始化
//2. 引用一旦初始化后不可改变
/*int a = 10;
	int& b = a;
	int c = 100;
	b = c;
	cout << a << " " << b << " " << c << endl;*/
// b = c 这是赋值操作，把b a 都改成了 100

//引用做函数参数
void swap_1(int a, int b) {//值传递
	int temp = a;
	a = b;
	b = temp;
}
void swap_2(int* a, int* b) {//地址传递
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap_3(int &a, int &b) {//引用传递   引用  用形参给实参的内存空间起了别名  直接操纵内存
	int temp = a;
	a = b;
	b = temp;
}
//int main() {
//	int a = 10;
//	int b = 20;
//	swap_1(a, b);
//	cout << a << " " << b << endl;
//	swap_2(&a, &b);
//	cout << a << " " << b << endl;
//	swap_3(a, b);
//	cout << a << " " << b << endl;
//	system("pause");
//	return 0;
//}

//引用做函数的返回值     
// 局部变量的 地址/引用 不能返回
int& test() {
	int a = 10;
	return a;
}
int& test_1() {
	static int b = 10;
	return b;
}
//函数可以作为 左值 
//当函数返回一个引用的时候 ，此时的函数可以作为左值
int main() {
	
	int& res = test();
	cout << res << endl;
	cout << res << endl;
	int& ref = test_1();
	cout << ref << endl;
	test_1() = 1000;
	cout << ref << endl;

	system("pause");
	return 0;
}