
#include <iostream>
using namespace std;

int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}
//0. C++中，函数的参数可以有默认值
//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
//3. 在函数的声明和实现中，只能有一个 有默认参数
//4. 传入的参数会覆盖默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

int main() {

	cout << "ret = " << func(20, 20) << endl;
	cout << "ret = " << func(100) << endl;

	system("pause");

	return 0;
}