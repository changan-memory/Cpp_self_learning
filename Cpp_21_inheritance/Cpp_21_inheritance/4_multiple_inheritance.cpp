#include <iostream>
using namespace std;

// 多继承，一个类继承了多个类
namespace question6 {
	class Person {
	public:
		string _name; // 姓名
		int _age;
	};
	class Student : virtual public Person {
	protected:
		int _num; //学号
	};
	class Teacher : virtual public Person {
	protected:
		int _id; // 职工编号
	};
	// 多继承的语法
	class Assistant : public Student, public Teacher {
	protected:
		string _majorCourse; // 主修课程
	};
	void test1() {
		// 这样会有二义性无法明确知道访问的是哪一个
		Assistant as;
		as._name = "peter"; // 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
		// 数据冗余: 会导致浪费空间   二义性可以通过类域解决
		as.Student::_name = "xxx";
		as.Teacher::_name = "yyy";
		as.Person::_name = "zzz";
		// 虚继承解决这里的二义性问题
		as._name = "xxx";
		as._name = "yyy";
		as._name = "zzz";
	}
}
// 多继承，及其菱形继承引发的问题
namespace question5 {
	class Person {
	public:
		string _name; // 姓名
		int _age;
	};
	class Student : virtual public Person {
	protected:
		int _num; //学号
	};
	class Teacher : virtual public Person {
	protected:
		int _id; // 职工编号
	};
	// 多继承的语法
	class Assistant : public Student, public Teacher {
	protected:
		string _majorCourse; // 主修课程
	};
	void test1() {
		// 这样会有二义性无法明确知道访问的是哪一个
		Assistant as;
		as._name = "peter"; // 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
		// 数据冗余: 会导致浪费空间   二义性可以通过类域解决
		as.Student::_name = "xxx";
		as.Teacher::_name = "yyy";
		as.Person::_name = "zzz";
		// 虚继承解决这里的二义性问题
		as._name = "xxx";
		as._name = "yyy";
		as._name = "zzz";
	}
}
//class A {
//public:
//	int _a;
//};
//// class B : public A
//class B :  public A {
//public:
//	int _b;
//};
//// class C : public A
//class C :  public A {
//public:
//	int _c;
//};
//class D : public B, public C {
//public:
//	int _d;
//};
// 探究 virtual 继承的底层原理
class A {
public:
	int _a;
};
// class B : public A
class B : virtual public A {
public:
	int _b;
};
// class C : public A
class C : virtual public A {
public:
	int _c;
};
class D : public B, public C {
public:
	int _d;
};
void test_virtual() {
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
}
//int main() {
//	//question5::test1();
//	// 虚继承是 如何解决 菱形继承的问题的
//	test_virtual();
//	return 0;
//}