#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;

void testType() {
	string num1("123");
	string num2("3");
	cout << typeid(num2[0]).name() << endl;
	cout << typeid(num2[0] - '0').name() << endl;	//一个字符减去字符 '0',会被转换成int类型
	int i = 5;
	cout << typeid(('0' + i)).name() << endl;
	cout << (i + '0') << endl;
}

void test2() {
	string str("hello");
	str.resize(10);
	cout << str << endl;
	for (size_t i = 0; i < str.size(); ++i) {
		cout << str[i] << endl;
		cout << str.at(i) << endl;
	}
}
void test3() {
	string str = "Hello";
	str += " World";     // "Hello World"
	str.append(3, '!');  // "Hello World!!!"

	str.insert(5, " C++"); // "Hello C++ World!!!"
	str.erase(5, 4);      // "Hello World!!!"
	cout << str.c_str() << endl;// "Hello World!!!"
}
int main() {
	string str = "Hello World !!!";
	string sub1 = str.substr(0);
	string sub2 = str.substr(6);
	string sub3 = str.substr(6, 5);
	cout << sub1 << endl;
	cout << sub2 << endl;
	cout << sub3 << endl;
	return 0;
}