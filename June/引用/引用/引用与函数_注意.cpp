#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//1. ���ñ����ʼ��
//2. ����һ����ʼ���󲻿ɸı�
/*int a = 10;
	int& b = a;
	int c = 100;
	b = c;
	cout << a << " " << b << " " << c << endl;*/
// b = c ���Ǹ�ֵ��������b a ���ĳ��� 100

//��������������
void swap_1(int a, int b) {//ֵ����
	int temp = a;
	a = b;
	b = temp;
}
void swap_2(int* a, int* b) {//��ַ����
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap_3(int &a, int &b) {//���ô���   ����  ���βθ�ʵ�ε��ڴ�ռ����˱���  ֱ�Ӳ����ڴ�
	int temp = a;
	a = b;
	b = temp;
}
//int main() {
//	int a = 10;
//	int b = 20;
//	swap_1(a, b);
//	cout << a << " " << b << endl;
//	swap_2(&a, &b);
//	cout << a << " " << b << endl;
//	swap_3(a, b);
//	cout << a << " " << b << endl;
//	system("pause");
//	return 0;
//}

//�����������ķ���ֵ     
// �ֲ������� ��ַ/���� ���ܷ���
int& test() {
	int a = 10;
	return a;
}
int& test_1() {
	static int b = 10;
	return b;
}
//����������Ϊ ��ֵ 
//����������һ�����õ�ʱ�� ����ʱ�ĺ���������Ϊ��ֵ
int main() {
	
	int& res = test();
	cout << res << endl;
	cout << res << endl;
	int& ref = test_1();
	cout << ref << endl;
	test_1() = 1000;
	cout << ref << endl;

	system("pause");
	return 0;
}