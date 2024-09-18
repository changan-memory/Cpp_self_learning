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
//
//int main() {
//	int a = 10, b = 20;
//	double c = 30.001, d = 40.001;
//	cout << a << " " << b << endl;
//	cout << c << " " << d << endl;
//
//	//使用模板的两种方式
//	//自动类型推导
//	swap(a, b);
//	//显示制定类型
//	swap<double>(c, d);
//	cout << a << " " << b << endl;
//	cout << c << " " << d << endl;
//	system("pause");
//	return 0;
//}