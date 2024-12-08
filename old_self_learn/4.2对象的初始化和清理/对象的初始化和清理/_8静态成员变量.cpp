//#include<iostream>
//using namespace std;
//
////静态成员
//// 静态成员变量
//class  Person {	//类内的 静态成员  所有对象共享同一份数据
//public:
//	//所有对象都共享一段内存
//	//编译阶段就分配内存
//	// 类内声明，类外初始化
//	static int _A;
//
//private:
//	static int _B;
//
//};
//
//int Person:: _A = 100;
//int Person::_B = 300;
//void test1() {
//	Person p1;
//	cout << p1._A << endl;
//	Person p2;
//	p2._A = 200;
//	cout << p1._A << endl;
//}
//
//void test2() {
//	//静态成员变量  不属于某个对象上 ，所有对象共享同一份数据
//	//因此静态对象有两种访问方式
//
//	//通过对象进行访问
//	Person p;
//	cout << p._A << endl;
//	//通过类名进行访问
//	cout << Person::_A << endl;
//	//静态成员变量也是有权限的
//
//	//cout << Person::_B << endl;	//私有的静态成员 外部不可以访问
//}
//
//int main() {
//
//	//test1();
//	test2();
//	return 0;
//}