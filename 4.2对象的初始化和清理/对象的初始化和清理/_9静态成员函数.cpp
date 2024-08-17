#include <iostream>
using namespace std;

//静态成员函数
// 所有对象都共享 一个函数
// 静态的函数  只能访问 静态的成员变量

class Person {

public:
	static void func() {	//静态成员函数可以访问静态成员变量
		cout << "静态成员函数调用" << endl;
		_A = 200;
		//_B = 100;   静态成员函数不能访问 非静态成员变量
		// 无法区分 改变哪个对象的 _B
	}

	static int _A;
	int _B;
};

int Person::_A = 0;

void test1() {
	Person p;
	p.func();

	Person::func();// 类外访问不到 私有权限的 静态成员函数
}





int main() {

	test1();

	return 0;
}