//#include <iostream>
//using namespace std;
//
////普通函数会发生隐式类型转换   将传入的实参转化为形参对应的类型
//int add(int a, int b) {
//	return a + b;
//}
//
//template <typename T>
//T add_1(T a, T b) {
//	return a + b;
//}
//
//
//void test1() {
//	int b = 20;
//	int a = 10;
//	cout << add(a, b) << endl;
//
//	char c = 'c';
//	cout << add_1<int>(a, c) << endl;  // 显示制定类型会发生 隐式类型转换
//	//cout << add_1(a, c) << endl;  //自动类型推导不会发生隐式类型转换
//
//}
//
//int main() {
//
//	test1();
//	system("pause");
//	return 0;
//}