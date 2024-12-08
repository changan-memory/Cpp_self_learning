//#include <iostream>
//using namespace std;
//
////通过自己写成员函数， 实现两个对象相加属性后返回新的对象
////加好运算符重载
//class Person {
//public:
//	//成员函数实现 + 重载
//	/*Person operator+(Person& p) {
//		Person temp;
//		temp._A = this->_A + p._A;
//		temp._B = this->_B + p._B;
//		return temp;
//	}*/
//
//	int _A;
//	int _B;
//};
////全局函数重载 + 
//// 运算符重载函数可以 发生重载
//Person operator+(Person& p1, Person& p2) {
//	Person temp;
//	temp._A = p1._A + p2._A;
//	temp._B = p1._B + p2._B;
//	return temp;
//}
//void test1() {
//	Person p1;
//	p1._A = 10;
//	p1._B = 20;
//
//	Person p2;
//	p2._A = 20;
//	p2._B = 30;
//	//实质上是调用函数 Person p3 = p2.operator+(p2);   但是使用了operator指令，可以只写 +
//	//Person p3 = p1 + p2;
//	Person p3 = operator+(p1, p2);
//	cout << p3._A << " " << p3._B << endl;
//	//运算符重载 后不会失去原来的功能   
//	//内置的数据类型 不会运算时 不会发生重载
//	cout << 1 + 3 << endl;
//}
//
//
//int main() {
//
//	test1();
//	return 0;
//}