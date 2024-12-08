//
//#include <iostream>
//using namespace std;
//
//
//class Person {
//public:
//	Person() {
//		cout << "默认构造函数调用" << endl;
//		this->_age = 0;
//	}
//	Person(int age) {
//		cout << "有参构造函数调用" << endl;
//		this->_age = age;
//	}
//	Person(const Person& p) {
//
//		cout << "拷贝构造函数调用" << endl;
//		this->_age = p._age;
//	}
//	~Person() {
//		cout << "析构函数调用" << endl;
//	}
//
//private:
//	int _age;
//};
//
////拷贝构造函数的调用时机
//
////1 使用一个已经创建完毕的对象来初始化一个新对象
//void test01() {
//	Person p1(20);
//	Person p2(p1);
//}
//
////2 值传递的方式给函数参数传值
//
//void dowork(Person p) {
//
//}
//
//void test02() {
//	Person p;
//	dowork(p);
//}
////  值方式返回局部对象
//Person doWork2()
//{
//	Person p1;
//	cout << &p1 << endl;
//	return p1;
//}
//
//void test03()
//{
//	Person p3 = doWork2();
//	cout << (int*)&p3 << endl;
//}
//
//void test04() {
//	test03();
//}
//int main() {
//	//test01();
//	//test02();
//	test04();
//	return 0;
//}