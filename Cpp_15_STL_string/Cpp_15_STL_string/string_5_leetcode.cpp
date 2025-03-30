#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
	string num1("123");
	string num2("3");
	cout << typeid(num2[0]).name() << endl;
	cout << typeid(num2[0] - '0').name() << endl;	//一个字符减去字符 '0',会被转换成int类型
	return 0;
}