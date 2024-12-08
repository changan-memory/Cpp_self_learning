//#include <iostream>
//using namespace std;
//
////1. 如果函数模板和普通函数都可以实现，优先调用普通函数   
////2. 可以通过空模板参数列表来   强制调用函数模板
////3. 函数模板也可以发生重载   函数模板产生了重载，调用时会优先调用  参数 类型匹配更好的 函数模板
////4. 如果函数模板可以产生更好的匹配, 优先调用函数模板
// 
//
//
//
//
//
//void myPrint(int a, int b) {
//	cout << "调用普通函数" << endl;
//}
//
//
//template <typename T>
//void myPrint(T a, T b) {
//	cout << "模板函数调用" << endl;
//}
//
//template <typename T>
//void myPrint(T a, T b, T c) {
//	cout << "模板函数调用" << endl;
//	cout << c << endl;
//}
//
//void test1() {
//	int b = 20;
//	int a = 10;
//	myPrint(a, b);
//
//	//通过空模板参数列表   强制调用模板函数
//	myPrint<>(a, b);
//
//	myPrint<int>(a, b, 'a');	//自动类型推导需要  推导出 一致的结果
//
//
//}
//
//int main() {
//
//	test1();
//	system("pause");
//	return 0;
//}