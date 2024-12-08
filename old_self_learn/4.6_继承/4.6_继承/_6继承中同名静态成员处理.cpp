#include <iostream>
using namespace std;

class Base {
public:
	static int _A;
	static void func() {
		cout << "Base 下func调用" << endl;
	}
	static void func(int a) {
		cout << "Base 下func (int a )调用" << endl;
	}
};

int Base::_A = 100;

class Son :public Base {
public:
	static int _A;
	static void func() {
		cout << "Son 下func调用" << endl;
	}
};

int Son::_A = 200;

void test1() {
	//静态成员有两种访问方法
	//通过对象访问同名静态成员
	Son s1;
	cout << s1._A << endl;//son下的_A;
	cout << s1.Base::_A << endl;

	//通过类名来访问
	cout << Son::_A << endl;
	cout << Base::_A << endl;
	cout << Son::Base::_A << endl;//通过类名的方式  访问 Base 作用下的 _A
	
}

void test2() {
	//通过对象调用
	Son s;
	s.func();	//直接调用调用的是子类中func
	s.Base::func();

	//通过类名作用
	Son::func();
	Base::func();
	Son::Base::func();	//通过类名的方式 访问父类作用域下的函数
	Son::Base::func(10);

}

int main() {


	//test1();
	test2();

	return 0;
}