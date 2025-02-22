#include <iostream>
using namespace	std;

//void Swap(int& left, int& right) {
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right) {
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right) {
//	char temp = left;
//	left = right;
//	right = temp;
//}

//现阶段认为 class和typename是一样的

//模板
//函数模板
//编译器根据已有的函数模板，生成具有不同参数函数
//模板参数，模板的意义在于，将类型参数化
template<typename T>	//单个类型参数
void Swap(T& left, T& right) {
	T temp = left;
	left = right;
	right = temp;
}

// 我们调用的函数，实际上是，编译器根据模板生成的具体函数(编译器根据模板，生成了参数是各种类型的函数)
template<typename T1, typename T2>		//多个类型参数   T是一个类型，T1是一个类型，T2是一个类型
T1& Func(const T1& x, const T2& y) {
	cout << x << " " << y << endl;
	return x;
}
//int main() {
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.2;
//	/*Swap(a, b);
//	Swap(c, d);*/
//
//	//标准库中已实现了 交换函数
//	std::swap(a, b);
//	std::swap(c, d);
//
//	int* p1 = &a, * p2 = &b;
//	swap(p1, p2);
//	swap(p1, p2);
//	return 0;
//}


//函数模板的实例化
template<typename T>
T Add(const T& left, const T& right) {
	return left + right;
}

template<typename T>
T* Alloc(int n) {
	return new T[n];
}

//int main() {
//	//函数模板的实例化
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.1;
//	//编译器自动推导 进行函数模板的实例化
//	//通过实参传递的类型，推演T的类型
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//	cout << Add(a1, (int)d1) << endl;	//通过强制类型转换，确保推导的结果一致
//	cout << Add((double)a1, d1) << endl;
//
//	//函数模板的 显式实例化，用指定类型实例化，会发生隐式类型转换
//	cout << Add<int>(a1, d1) << endl;
//	cout << Add<double>(a1, d1) << endl;
//
//	//显式实例化的应用场景
//	//有些函数不能自动类型推导，需要显式指定
//	int* p_int = Alloc<int>(10);
//	double* p_double = Alloc<double>(20);
//
//	return 0;
//}