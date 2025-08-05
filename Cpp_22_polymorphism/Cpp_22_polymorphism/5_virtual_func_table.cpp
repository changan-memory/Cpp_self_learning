#include <iostream>
using namespace std;
namespace question4 {
	//这里常考一道笔试题：sizeof(Base)是多少？
	class Base {
	public:
		// 不实现多态时，不要把类中没必要的函数声明为virtual
		// 因为类中只要有虚函数，类内都会维护一个虚函数表
		// 表中存放所有虚函数的地址
		// 虚函数本身是存放在代码段
		virtual void Func1() {
			cout << "Func1()" << endl;
		}
		virtual void Func2() {
			cout << "Func2()" << endl;
		}
		void Func3() {
			cout << "Func3()" << endl;
		}
	private:
		int _b = 1;
	};
	void test() {
		cout << sizeof(Base) << endl;	// 结果为8
		Base b1;
	}
}

namespace question5 {
	class Person {
	public:
		virtual void BuyTicket() { cout << "买票——全价" << endl; }
		int _a = 1;
	};
	class Student : public Person {
	public:
		virtual void BuyTicket() { cout << "买票——半价" << endl; }
		int _b = 2;
	};
	void Func(Person& p) {
		// 多态调用  运行时到指向对象的虚函数表中找调用函数的地址
		p.BuyTicket();
	}
	void test() {
		// 如何实现 指向父类调父类  指向子类调子类
		// Person& p
		// 对 p来说，传父类，就接受父类  传子类，将子类切片后再指向
		// 对p来说，看到的都是父类
		// 普通调用，在编译时确定函数的地址
		// 多态调用  运行时到指向对象的虚函数表中找调用函数的地址
		Person Mike;
		Func(Mike);
		Student Johnson;
		Func(Johnson);
	}
}

namespace question6 {
	class A {
	public:
		virtual void func(int val = 1) { 
			std::cout << "A->" << val << std::endl; 
		}
		virtual void test() { func(); }
	};
	class B : public A {
	public:
		void func(int val = 0) { std::cout << "B->" << val << std::endl; }
	};
	void ques() {
		B* p = new B;
		p->test();
		return;
	}
}
int main() {
	//question4::test();
	//question5::test();
	question6::ques();
	return 0;
}