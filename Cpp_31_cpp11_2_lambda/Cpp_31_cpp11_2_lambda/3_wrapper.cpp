// 包装器与可变模板参数
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

// ret = func(x);
//上面func可能是什么呢？那么func可能是函数名？函数指针？函数对象(仿函数对象)？也有可能
//是lamber表达式对象？所以这些都是可调用的类型！如此丰富的类型，可能会导致模板的效率低下！
//为什么呢？我们继续往下看

template<class F, class T>
T useF(F f, T x) {
	static int count = 0;
	cout << "count: " << ++count << " ";
	cout << "count: " << &count << endl;
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

void test1() {
	// 函数名
	cout << useF(f, 11.11) << endl;

	// 函数对象
	cout << useF(Functor(), 11.11) << endl;

	// lambda 表达式
	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;

	function<double(double)> f1 = f;
	function<double(double)> f3 = Functor();
	function<double(double)> f2 = [](double d)->double { return d / 4; };
}

void test2() {
	// 函数名
	cout << useF(f, 11.11) << endl;

	// 函数对象
	cout << useF(Functor(), 11.11) << endl;

	// lambda 表达式
	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;

	std::function<double(double)> f1 = f;
	std::function<double(double)> f2 = Functor();
	std::function<double(double)> f3 = [](double d)->double { return d / 4; };
}

void test3() {
	std::function<double(double)> f1 = f;
	std::function<double(double)> f2 = Functor();
	std::function<double(double)> f3 = [](double d)->double { return d / 4; };
	// 可调用对象存储在容器中，解决了类型问题
	std::vector<std::function<double(double)>> v1 = { f1, f2, f3 };	
	std::vector<std::function<double(double)>> v2 = 
	{ 
		f, Functor(), [](double d)->double { return d / 4; }
	};
	double n = 3.4;
	for (auto& e : v2) {
		cout << e(n++) << endl;
	}
}

void test4() {
	std::function<double(double)> func1 = f;	// 函数指针
	std::function<double(double)> func2 = Functor();	// 仿函数
	std::function<double(double)> func3 = [](double d)->double { return d / 4; };	// Lambda

	// 统一传入包装器进行调用
	cout << useF(func1, 11.11) << endl;
	cout << useF(func2, 11.11) << endl;
	cout << useF(func3, 11.11) << endl;
}
//int main() {
//	//test3();
//	test4();
//	return 0;
//}