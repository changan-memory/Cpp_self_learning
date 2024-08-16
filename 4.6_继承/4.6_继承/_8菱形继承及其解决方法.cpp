//#include <iostream>
//using namespace std;
//
////菱形继承   
//// 可以利用虚继承来解决 菱形继承的问题
//
//// 利用虚继承可以解决 菱形继承的问题
////动物类
//class Animal{
//public:
//	int _age;
//};
//
//
////在继承之前加上 关键字 virtual 解决菱形继承 
//
//// virtual 继承时, 派生类实际上是继承了一个指针 vbptr（virtua; base pointer）
//// 指针指向一个表 表中记录了 继承过来的属性的 偏移量, 通过加上偏移量 来实现数据的独一份
//class Sheep:virtual public Animal{};
//class tuo:virtual public Animal{};
//
//class Sheeptuo: public Sheep, public tuo{};
//
//
//
//void test() {
//	Sheeptuo st;
//	//菱形继承 可以加作用域来区分  访问时也需要加作用域
//
//	//当发生虚继承的时候 数据只有一份
//	st.Sheep::_age = 100;
//	st.tuo::_age = 200;
//	cout << st.Sheep::_age << endl;
//	cout << st.tuo::_age << endl;
//	cout << st._age << endl;
//}
//
//
//
//int main() {
//
//
//	test();
//	return 0;
//}