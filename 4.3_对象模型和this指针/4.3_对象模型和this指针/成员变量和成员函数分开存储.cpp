#if 0

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//成员变量和成员函数是分开存储的
class Person {


};

void test() {

	Person p;
	cout << sizeof(p) << endl;
}

int main() {

	test();
	return 0;
}

#endif