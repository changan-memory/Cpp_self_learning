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
	// ���ڵĺ����������ڵı���ʱ  ��Ĭ���ڱ�����ǰ�����this  �� this->_age
	// ���ÿ�ָ�����
	void ShowClassAge() {
		if (this == NULL)
			return;
		cout << "this is class age" <<_age<< endl;	
	}

	int _age;
};

void test() {
	Person* p = nullptr;	// ָ����Ŀ�ָ��Ҳ���Է��ʳ�Ա����  
	p->ShowClassName();	//һ�㺯��
	p->ShowClassAge();	//�ú����к��� this ָ��   ���ܷ���
}
int main() {

	test();
	f(0);
	f(NULL);
	f((int*)NULL);
	f(nullptr);
	return 0;
}