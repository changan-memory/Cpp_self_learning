#include <iostream>
using namespace std;

// 设计一个不能被继承的类
// 1. 构造函数私有/析构函数私有 (C++98)
// 2. 用final修饰该类，表示该类是最终类，不能被继承 (C++11)
namespace question1 {
	// 将一个类的构造函数私有后，该类就不能被继承了
	class A {
	public:
		// A也需要创建对象，因此可以提供一个函数，用于创建A的对象
		// 但是调用时，非静态成员函数，需要创建对象才能，才能调用
		// 因此 设计成静态成员函数 可以解决该问题
		static A creatObj() {
			return A();
		}
	private:
		A(){}
	};
	class B : public A {

	};
	void test() {
		A a = A::creatObj();
	}
}

namespace question2 {
	// 将一个类的析构函数私有
	class A {
	public:
	private:
		~A() {}
	};
	class B : public A {

	};
	void test() {
		//B b;	// 无妨创建对象，因为B无法调用析构函数
	}
}
namespace question3 {
	// C++11 final final修饰的类不能被继承
	class A final {
	public:
	private:
		~A() {}
	};
	//class B : public A	// A不能被继承
	//{ };
}
