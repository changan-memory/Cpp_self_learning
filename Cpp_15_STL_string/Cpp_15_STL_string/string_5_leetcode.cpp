#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
	string num1("123");
	string num2("3");
	cout << typeid(num2[0]).name() << endl;
	cout << typeid(num2[0] - '0').name() << endl;	//һ���ַ���ȥ�ַ� '0',�ᱻת����int����
	int i = 5;
	cout << typeid(('0' + i)).name() << endl;
	cout << (i + '0') << endl;
	return 0;
}