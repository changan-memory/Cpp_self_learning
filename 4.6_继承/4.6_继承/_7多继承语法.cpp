#include <iostream>
using namespace std;


class Base1 {
public:
	Base1() {
		this->_A = 100;
	}
	int _A;
};

class Base2 {
public:
	Base2() {
		this->_A = 200;
	}
	int _A;
};
//实际开发中不建议使用多继承
//多继承
// class 子类: 继承方式 父类1, 继承方式 父类2
class Son:public Base1, public Base2 {
public:
	
	Son() {
		this->_C = 0;
		this->_D = 0;
	}
	int _C;
	int _D;
};

void test() {
	Son son;
	cout << sizeof(son) << endl;
	//一个子类继承多个父类 当父类中有同名的成员变量时 访问时需要加作用域
	cout << "Base1 _A  " << son.Base1::_A << endl;
	cout << "Base2 _A  " << son.Base2::_A << endl;
}

int main() {

	test();



	return 0;
}