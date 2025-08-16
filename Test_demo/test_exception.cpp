#include <iostream>
using namespace std;

int main() {
	// decltype 推理表达式的类型
	const int x = 1;
	double y = 2.2;
	decltype(x * y) ret;		// ret的类型是double
	decltype(&x) p;				// p的类型是int*
	cout << typeid(ret).name() << endl;
	cout << typeid(p).name() << endl;
	return 0;
}