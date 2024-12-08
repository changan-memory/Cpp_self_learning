//#include <iostream>
//using namespace std;
//
//template<typename T>	//告诉编译器  要声明一个模板
//void MySwap(T& a, T& b) {		// T 为通用类型，一般用 T 表示
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//void test1() {
//	//自动推导  推导出的数据类型必须一致
//	int a = 10, b = 20;
//	char c = 'q';
//	cout << a << " " << b << endl;
//	//MySwap(a, c);
//	MySwap<int>(a, b);//推导不出 一致的数据类型
//	cout << a << " " << b << endl;
//}
//
//template<typename T>
//void func() {
//	cout << "test  " << endl;
//}
//
////模板不能直接使用，使用时需要明确指出参数的类型
//void test2() {
//	//func();
//	func<int>();	
//}
//int main() {
//	
//	//test1();
//	test2();
//
//	system("pause");
//	return 0;
//}