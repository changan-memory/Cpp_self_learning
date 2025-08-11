#include <iostream>
using namespace std;

class Base {
public:
	virtual void Func1() {
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2() {
		cout << "Base::Func2()" << endl;
	}
private:
	int _b = 1;
};
class Derive : public Base {
public:
	virtual void Func3() {
		cout << "Derive::Func3()" << endl;
	}
private:
	int _d = 2;
};
// FUNC_PTR是函数指针
typedef void (*FUNC_PTR)();
// 打印虚表的函数
//void printVTB(FUNC_PTR table[]) {		// C语言中没有函数传参传数组的写法，传数组，会退化为指针
void printVTB(FUNC_PTR* table) {
	for (size_t i = 0; table[i] != nullptr; ++i) {
		printf("[%d]: %p->", i, table[i]);
		FUNC_PTR fptr = table[i];
		fptr();
	}
	printf("\n");
}

//int main() {
//	Base b;
//	Derive d;
//
//	int ptb1 = *((int*)&b);
//	printVTB((FUNC_PTR*)ptb1);
//	int ptb2 = *((int*)&d);
//	printVTB((FUNC_PTR*)ptb2);
//	return 0;
//}

// 多态
// 静态(编译时)多态: 函数重载
// 动态(运行时)多态: 继承、虚函数重写 的多态
