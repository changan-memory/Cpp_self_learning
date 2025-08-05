#include <iostream>
using namespace std;

namespace use_1 {
	// 多态的条件
	// 0. 具有继承关系的子类和派生类
	// 1. 必须通过基类的指针或者引用调用虚函数
	// 2. 被调用的函数必须是虚函数，且派生类必须对基类的虚函数进行重写
	class Person {
	public:
		virtual void buyTicket() const {
			cout << "普通人买票，全价" << endl;
		}
	};
	// 虚函数重写的细节:
	// 虚函数重写的条件是 虚函数+三同，但有一些例外
	// 1. 派生类重写虚函数，可以不加 virtual ,但是建议加上virtual
	// 2. 特殊情况 协变  返回值可以不同，但要求返回值必须是父子关系的指针/引用
			// 父类中的虚函数返回父类的指针/引用  子类中的虚函数返回父类的指针/引用
			// 父类和子类 需要同时返回指针 同时返回引用，不能交叉
	class Student : public Person {
	public:
		//void buyTicket() const {
		virtual void buyTicket() const {
			cout << "学生买票，半价" << endl;
		}
	};
	// 多态，不同的对象，传过去，调用不同的函数
	// 多态调用，看的指向的对象，普通对象调用函数，看当前对象的类型 
	
	// 多态的条件
	// 0. 具有继承关系的子类和派生类
	// 1. 必须通过基类的指针或者引用调用虚函数
	// 2. 被调用的函数必须是虚函数，且派生类必须对基类的虚函数进行重写
	// 虚函数 即 被virtual 修饰的类成员函数，虚函数只能是成员函数，普通函数不能被virtual修饰
	void func(Person& p) {
		p.buyTicket();
	}
	void test1() {
		Person p;
		Student s;
		func(p);
		func(s);
	}
}

 //析构函数可以时虚函数吗，为什么要是虚函数
 //析构函数的重写
 //析构函数加virtual , 算不算虚函数重写
 //算，因为 类的析构函数，都被处理成了 destructor 这个统一的名字，
 //函数名相同，加了virtual，就是重写
 //看起来名字不同，实际相同，因此构成 重写
 //为什么要这么处理？ 因为要让他们构成重写   为什么要让他们构成重写呢
namespace use_2 {
	class Person {
	public:
		virtual ~Person() { cout << "~Person()" << endl; }
		//~Person() { cout << "~Person()" << endl; }
	};
	class Student : public Person {
	public:
		//virtual ~Student() { cout << "~Student()" << endl; }
		virtual ~Student() { 
			cout << "~Student()" << endl;
			delete[] _ptr;
		}
	protected:
		int* _ptr = new int[10];
	};
	void test1() {
		Person p;
		Student stu;	// stu 先析构，再析构 stu中父类的那部分
	}
	// 不重写析构函数，会出错的场景
	void test2() {
		Person* p = new Person;
		delete p;
		p = new Student;	// delete 由两部分构成 先调用该类型的析构函数，再释放空间
		// 父类的指针 有可能指向父类  也有可能指向子类
		// 通过父类的
					// delete分为两部分 调析构 + 释放空间
		delete p;	// p->destructor() + operator delete(p)
					// 不重写时，
		// 父类的指针 有可能指向父类  也有可能指向子类
		// 我们期望 p->destructor() 为多态调用 而不是普通调用
		// 指向谁，就调用谁的析构函数
	}
}
//int main() {
//	//use_1::test1();
//	//use_2::test1();
//	use_2::test2();
//	return 0;
//}