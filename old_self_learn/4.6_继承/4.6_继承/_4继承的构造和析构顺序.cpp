//#include <iostream>
//using namespace std;
//
//// 继承中的对象模型
//class Base {
//public:
//	Base() {
//		cout << "Base的构造函数" << endl;
//	}
//	~Base() {
//		cout << "Base的析构函数" << endl;
//	}
//
//};
//// 继承中的构造和析构顺序为
//// 先构造父类 在构造子类 析构的顺序与构造的顺序相反
//class Son: public Base {
//public:
//	Son() {
//		cout << "son 的构造函数" << endl;
//	}
//	~Son() {
//		cout << "son 的析构函数" << endl;
//	}
//};
//
//void test01() {
//	//Base base;
//	Son s;
//
//}
//int main() {
//
//	test01();
//	return 0;
//}