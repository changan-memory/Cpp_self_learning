//#include <iostream>
//using namespace std;
//
//// 继承中的对象模型
//class Base {
//public:
//	int _A;
//protected:
//	int _B;
//private:
//	int _C;
//
//};
//
//// 父类中所有非静态成员属性都会被子类继承下去
//// 父类中私有成员属性 是被编译器隐藏了，因此访问不到，但确实被继承下去了
//class Son : public Base {	//sizeof(Son)    16
//public:
//	int _D;
//};
//
//void test_1() {
//	Son son1;
//	cout << sizeof(son1);
//}
//
//
//
//
//
//
//int main() {
//	test_1();
//	return 0;
//}