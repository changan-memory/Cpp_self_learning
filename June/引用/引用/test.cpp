#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//���þ��Ƿ�װ��ָ��
int main()
{
	int a = 100;
	int &b = a;
	int *p = &a;
	cout << &b << endl;
	cout << &a << endl;
	cout << &p << endl;
	b = 20;
	cout << a << " " << b << endl;


	system("pause");
	return 0;
}