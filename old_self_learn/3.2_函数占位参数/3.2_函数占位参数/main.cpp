#include <iostream>
using namespace std;

// C++中，函数可以有 占位参数，调用此类函数式，必须给 占位参数 传值
//函数占位参数 ，占位参数也可以有默认参数
void func(int a, int = 10) {
	cout << "this is func" << endl;
}

int main() {

	func(10, 10); //占位参数必须填补

	system("pause");

	return 0;
}