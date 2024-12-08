//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	Base() {
//		this->_A = 200;
//	}
//	void func() {
//		cout << "父类中的func调用" << endl;
//	}
//	void func(int a) {
//		cout << "父类中的func int a 调用" << endl;
//	}
//	int _A;
//};
//
//class Son :public Base {
//public:
//	Son() {
//		this->_A = 2000;
//	}
//	void func() {
//		cout << "子类中的func调用" << endl;
//	}
//	
//	int _A;
//};
//
//void test() {
//	Son s1;
//	//父类和子类中的同名成员 在子类中 直接调用 调用子类中的成员
//	cout << "Son中的 A_ " << s1._A << endl;
//	//想调用父类中的成员  需要加上作用域
//	cout << "Base中的 A_ " << s1.Base::_A << endl;
//
//	//同上
//	s1.func();	//直接调用,调用子类中的func
//	s1.Base::func();	//调用时加上作用域 可调用父类中的func
//	s1.Base::func(100);
//
//}
////1. 子类对象可以直接访问到子类中同名成员
////2. 子类对象加作用域可以访问到父类同名成员
////3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，
//// 加作用域可以访问到父类中同名函数
//
//
//
//int main() {
//	test();
//
//	return 0;
//}
//
