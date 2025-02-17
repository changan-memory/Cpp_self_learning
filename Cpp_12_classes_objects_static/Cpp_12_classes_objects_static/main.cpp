#include <iostream>
using namespace std;

//设计一个程序，统计当前正在使用的某个对象有多少个
class A {
public:
	A() { 
		++_scount;
	}
	A(const A& t) { 
		++_scount;
	}
	~A() { 
		--_scount; 
	}
	//静态成员函数 -- 没有this指针，指定类域和访问限定符就可以访问
	static int GetACount() {
		//静态成员函数，不能访问类内的非静态成员变量
		return _scount;
	}
private:
	// 成员变量 -- 属于每一个类对象， 存储在对象里面
	int _a1 = 1;
	int _a2 = 2;

	// 静态成员变量 -- 属于类，类的每个对象共享，存储在静态区, 不能用初始化列表初始化
//public:
	static int _scount;
};
//全局位置，类外定义
int A::_scount = 0;

int main() {

	//cout << __LINE__ <<" " << A::_scount << endl;	//如果_scount是public的，那么可以通过类作用域限定符来访问
	cout << __LINE__ <<" " << A::GetACount() << endl;	

	return 0;
}
