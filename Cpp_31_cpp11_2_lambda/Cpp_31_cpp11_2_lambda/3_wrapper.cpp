// 包装器与可变模板参数
#include <iostream>
#include <functional>
using namespace std;

// ret = func(x);
//上面func可能是什么呢？那么func可能是函数名？函数指针？函数对象(仿函数对象)？也有可能
//是lamber表达式对象？所以这些都是可调用的类型！如此丰富的类型，可能会导致模板的效率低下！
//为什么呢？我们继续往下看

template<class F, class T>
T useF(F f, T x) {
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;
	return f(x);
}
double f(double i) {
	return i / 2;
}
struct Functor {
	double operator()(double d) {
		return d / 3;
	}
};

int main() {
	// 函数名
	cout << useF(f, 11.11) << endl;

	// 函数对象
	cout << useF(Functor(), 11.11) << endl;

	// lamber表达式
	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;

	return 0;
}