//#include <iostream>
//using namespace std;
//
////由于 我们通常调用重写了的 派生类的函数，因此基类中虚函数的实现毫无意义
//// 因此我们可以把  基类中的虚函数 改为纯虚函数
//
//// 纯虚函数和抽象类
//class Base {
//public:
//	//纯虚函数  这个类只要有一个纯虚函数，就被称为抽象类
//	// 抽象类 特点
//	//  1、无法实例化对象
//	//	2、派生类 必须 重写 基类中的纯虚函数， 否则也属于抽象类
//	virtual void func() = 0;
//};
//
//// 写虚函数/纯虚函数 的意义就是为了利用多态  想让子类重写父类中的纯虚函数
//
//class Son :public Base {
//public:
//	virtual void func() {
//		cout << "子类func调用" << endl;
//	}
//};
//
//void test() {
//	Base* base = new Son;
//	base->func();
//}
//
//int main() {
//
//	test();
//	return 0;
//}