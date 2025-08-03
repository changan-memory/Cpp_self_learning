#include <iostream>
#include <string>

using namespace std;
//// 2. 基类和派生类中的作用域问题
//// 只要在 不同的作用域 就可以有同名的成员和同名的函数
//class Person {
//public:
//	void func() {
//		cout << "Person:func()" << endl;
//	}
//protected:
//	string _name = "小李子";
//	int _num = 111;	//身份证号
//};
//
//// 隐藏/重定义 的概念: 当子类和父类有同名的成员时，子类的成员隐藏了父类的成员
//// 隐藏/重定义的成员 包括成员变量和成员函数
//// 实际中，不建议 子类和父类写同名的成员变量 和 成员函数
//// 子类和父类中的 同名函数也可以同时存在，不指明类域时，优先访问子类的成员函数
//// 查找的顺序  函数局部域 > 子类域 > 父类域 > 全局域
//// 不能说互相隐藏，只能是子类隐藏父类的，父类不能调用的子类的函数、不能访问子类的成员变量
//class Student : public Person {
//public:
//	void func() {
//		cout << "student:func()" << endl;
//	}
//	void print() {
//		cout << "num: " << _num << endl;	// 先访问子类中的成员
//		// 子类中，访问父类中的同名成员时，需要指定作用域
//		cout << "Person::num: " << Person::_num << endl;
//	}
//protected:
//	int _num = 999;		// 学号
//};
//int main() {
//	Student s;
//	// 子类中存在func函数时，调用子类中的,否则调用父类中的 再没有的话，调用全局的，
//	s.func();
//	// 都没有的话，报错
//	s.Person::func();	// 指定类域，调用父类中的func函数
//	return 0;
//}
//
////void print() {
////	int _num = 0;
////	cout << "姓名: " << _name << endl;
////	cout << "子类编号: " << _num << endl;	// 函数局部优先
////	cout << "子类编号: " << Student::_num << endl;	// 子类的 _num
////	// 优先找的顺序 函数局部域 子类域 父类域 全局域
////	cout << "父类编号: " << Person::_num << endl;
////}
//
////两个func函数构成什么关系
////a. 隐藏/重定义  b. 重载    c.重写/覆盖    d.编译报错
////答案 a (父类子类中，成员函数名相同，就构成隐藏)
////不构成重载，因为不是在同一作用域
////构成隐藏，父类子类中，成员函数满足函数名相同就构成隐藏
////最好不要在继承体系中，定义同名成员
