#include <iostream>
using namespace std;

class A {
private:
	int _a;
public:
	A(int a = 0)
		:_a(a){
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a){
		cout << "A(const A & a)" << endl;
	}
	A& operator=(const A& a) {
		cout << " A& operator=(const A & a)" << endl;
		if (this != &a) {
			_a = a._a;
		}
		return *this;
	}
	~A() {
		cout << "~A()" << endl;
	}
};
//只要加了const，类型就不一样
//两个函数可以构成重载，但不能同时存在
void Func1(A aa) {

}
void Func2(const A& aa) {

}
A Func3() {
	A aa;
	return aa;	//传值返回，会调用拷贝构造函数
}
A& Func4() {
	static A aa;
	return aa;	//传值返回，会调用拷贝构造函数
}
void TestFunc() {
	//A a1;
	//Func1(a1);	//调用不明确，两个函数都可以传参
	//Func2(a1);

	Func3();
	Func4();
}

A Func5() {
	A aa;
	return aa;	//传值返回，会调用拷贝构造函数，返回的是临时变量的拷贝
}
void Test2() {
	//A& ref_a = Func5();	//返回的是临时变量，临时变量具有常性，需要用常引用
	const A& ref_a = Func5();
}
//int main() {
//	//TestFunc();
//	Test2();
//
//	return 0;
//}