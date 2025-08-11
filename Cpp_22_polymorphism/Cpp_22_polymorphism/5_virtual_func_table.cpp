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
		// 类中的虚函数，会
		// Person& p
		// 对 p来说，传父类，就接受父类  传子类，将子类切片后，指向的还是父类
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

namespace question7 {
	class Base {
	public:
		virtual void Func1() {
			cout << "Base::Func1()" << endl;
		}
		virtual void Func2() {
			cout << "Base::Func2()" << endl;
		}
		void Func3() {
			cout << "Base::Func3()" << endl;
		}
	private:
		int _b = 1;
	};
	class Derive : public Base {
	public:
		virtual void Func1() {
			cout << "Derive::Func1()" << endl;
		}
	private:
		int _d = 2;
	};
	void test_address() {
		int a = 1;
		printf("栈区: %p\n", &a);
		static int x = 2;
		printf("静态区: %p\n", &x);
		int* p = new int;
		printf("堆区: %p\n", p);
		const char* str = "hello world";
		printf("常量区: %p\n", str);
		// 打印虚表的地址 ，32位环境中，一个对象内存的前四个字节，存放的是虚表指针
		Base b;
		Derive d;
		printf("Base的虚表地址: %p\n", (void*)(*((int*)&b)));
		printf("Derive的虚表地址: %p\n", (void*)(*((int*)&d)));
	}
}
//int main() {
//	//question4::test();
//	//question5::test();
//	//question6::ques();
//	question7::test_address();
//	return 0;
//}

// 继承  是函数的 实现 继承，子类可以直接复用基类中的函数
// 多态  是函数的 接口 继承，子类需要重写父类中的虚函数，重写实现

