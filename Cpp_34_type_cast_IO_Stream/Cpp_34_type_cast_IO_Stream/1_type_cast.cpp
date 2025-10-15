#include <iostream>
#include <vector>
#include <string>
using namespace std;

// C语言中的类型转换
// 语言中总共有两种形式的类型转换：隐式类型转换和显式类型转换
// 1. 隐式类型转化：编译器在编译阶段自动进行，能转就转，不能转就编译失败
// 2. 显式类型转化：需要用户自己处理
void test1() {
	int i = 1;

	// 整型家族基本都能 互相  隐式转换
	// 隐式类型转换  意义相似的类型 可以进行隐式类型转换   int char double size_t
	double d = i;
	printf("%d, %.2f\n", i, d);

	int* p = &i;
	// 显示的强制类型转换     指针和整型也能互相转换
	int address = (int)p;
	printf("%p, %d\n", p, address);

	/*vector<int> v;
	string s;
	v = (vector<int>) s;*/
}

class A {
public:
	A(int a)
	//explicit A(int a)
		:_a(a)
	{ cout << "单参数的构造函数支持隐式类型转换\n" << endl; }
private:
	int _a;
};
// 单参数的构造函数支持隐式类型转换
void test2() {
	int x = 10;
	A a1 = x;	// 两次构造
	A a2(x);
}
// 自定义类型之间的互相转换
class B {
public:
	B(const A& a)
	{ cout << "自定义类型间有某种关联时，也可以互相转换，取决于类的设计\n" << endl; }
private:
};
void test3() {
	int x = 10;
	A a1(x);

	B b1(a1);
	B b2 = a1;
}
// int 和 size_t 隐式类型转换的坑
// 比如在实现 vector 的 insert 的时候， int 和 size_t 隐式类型转换的坑
void test4() {

}


//
void test5() {
	const int N = 10;	// N 不是常量， N叫常变量
	int n = 20;

	int arr1[N];	// N本质是变量，因为N可以间接被修改
	//int arr2[n];	// n 是变量，不能定义变长数组
}

// 类型转换的坑，常变量去掉 const 属性，是危险的
void test6() {
	const int N = 10;	// N 不是常量， N叫常变量

	int* p = (int*)&N;
	(*p)++;
	cout << N << " " << *p << endl;
}
// const 部分的 看重铸自身根基


// C++中的类型转换 static_cast
void test11() {
	double d = 13.94;
	int x = static_cast<int> (d);
	cout << x << endl;

	int* p = &x;
	//int address = static_cast<int> (p);
}

// C++中的类型转换 reinterpret_cast
void test12() {
	int x = 10;
	int* p = &x;
	
	// 不相关类型的转换
	int address = reinterpret_cast<int> (p);
	cout << x << endl;
	cout << p << endl;
	cout << address << endl;
}

// C++中的类型转换 const_cast
void test13() {
	// 去掉 const 的转换
	volatile const int N = 10;
	// 使用了 const_cast ,这样转换是有风险的，提醒使用者需要加上 volatile
	int* p = const_cast<int*> (&N);	
	(*p)++;
	cout << *p << " " << N << endl;
}

namespace dynamic {
	// C++中的类型转换 dynamic_cast
	class A {
	public:
		virtual void f() {}
		int _x = 0;
	};

	class B : public A {
	public:
		int _y = 1;
	};
	void func1(A* pa) {
		//B* pb = (B*)pa;
		B* pb = dynamic_cast<B*>(pa);
		if (pb) {
			cout << "转换成功" << endl;
			pb->_x++;
			pb->_y++;
		}
		else {
			cout << "转换失败" << endl;
		}
		
	}
	void func2(A* pa) {
		// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
		B* pb1 = static_cast<B*>(pa);
		B* pb2 = dynamic_cast<B*>(pa);
		cout << "pb1:" << pb1 << endl;
		cout << "pb2:" << pb2 << endl;
	}
	void test14() {
		A a;
		B b;
		func1(&a);
		func1(&b);
	}
	void test15() {
		A a;
		B b;
		func2(&a);
		func2(&b);
	}
}

int main() {
	//test1();
	//test2();
	//test3();

	//test5();
	//test6();

	//test11();
	//test12();
	//test13();

	dynamic::test14();
	//dynamic::test15();
	return 0;
}