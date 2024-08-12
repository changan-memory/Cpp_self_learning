#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

void f(int a){
	cout << "f(int)" << endl;
}
void f(int* a){
	cout << "f(int*)" << endl;
}
class Person {
public:

	void ShowClassName() {
		cout << "this is class name" << endl;
	}
	// 类内的函数访问类内的变量时  会默认在变量名前面加上this  即 this->_age
	// 当用空指针访问
	void ShowClassAge() {
		if (this == NULL)
			return;
		cout << "this is class age" <<_age<< endl;	
	}

	int _age;
};

void test() {
	Person* p = nullptr;	// 指向类的空指针也可以访问成员函数  
	p->ShowClassName();	//一般函数
	p->ShowClassAge();	//该函数中含有 this 指针   不能访问
}
int main() {

	test();
	f(0);
	f(NULL);
	f((int*)NULL);
	f(nullptr);
	return 0;
}