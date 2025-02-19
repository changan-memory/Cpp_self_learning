#include <iostream>
using namespace std;

//设计一个程序，统计当前正在使用的某个对象有多少个
int _scount = 0;
class A {
public:
	A() { ++_scount; }
	A(const A& t) { ++_scount; }
	~A() { --_scount; }
};

A aa0;

namespace test1 {
	A Func(A aa1) {
		cout << __LINE__ << " " << _scount << endl;
		return aa1;
	}
	int main() {
		cout << __LINE__ << " " << _scount << endl;	//1个全局对象
		A aa1;
		static A aa2;
		Func(aa1);
		cout << __LINE__ << ": " << _scount << endl;	//如果Func的函数栈帧还没清理的话，此处是5个

		return 0;
	}
}
void Func() {
	static A aa2;	//局部静态对象，只会创建一次，不在函数栈帧内，在静态区
	cout << __LINE__ << ": " << _scount << endl;	//3

	//全局变量的劣势：任何地方都可以随意改变，不安全
	//_scount++;
}

//int main() {
//	cout << __LINE__ << ": " << _scount << endl;	// 是 1 ，此处还没进入Func函数，static 对象还没创建
//	A aa1;
//	Func();	//3
//	Func(); //3
//	return 0;
//}