#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// ��ֵ
// ��ֵһ������ȡ��ַ��һ����Ը�ֵ
void test1() {
	int a = 10;
	int b = a;
	const int c = 30;	// ��const���ε���ֵ  ��Ȼ����ֵ
	const int* d = &c;
	// ���µ� p , b,  c,  *p ������ֵ
	int* p = new int(10);
	int q = 1;
	const int x = 2;


	"xxxxxx";  // �ñ��ʽ�ĺ����� ���ַ�����Ԫ�صĵ�ַ
	const char* px = "xxxxxx"; // �ñ��ʽ�ĺ����ǣ��� "xxxxxx" ��Ԫ�صĵ�ַ��ֵ�� px
	p[2];
	cout << &"xxxxx" << endl;	// ����ȡ��ַ�� ��ֵ
	cout << &px[2] << endl;		// ����ȡ��ַ�� ��ֵ



	// ���¼����Ƕ�������ֵ����ֵ����
	int*& rp = p;
	int& rb = b;
	const int& rc = c;
	int& pvalue = *p;
}
// ��ֵ
int fmin(int a, int b) {
	return a < b ? a : b;
}
void test2() {
	// ����Ϊ��������ֵ
	double x = 1.1, y = 2.2;
	// ���¼������ǳ�������ֵ
	10;
	x + y;
	fmin(x, y);	// �������ֵָ�� �� ������ֵ����ʱ�����ص� ���������� �Ǹ���ʱ����
	// ��ֵ����ȡ��ַ
	/*cout << &10 << endl;
	cout << &(x + y) << endl;
	cout << &fmin(1, 2) << endl;*/
}

 //��ֵ���� ��ֵ����
 //������ȡ����
 //��ֵ���� :  ����ֵȡ����
 //��ֵ���� :  ����ֵȡ����
void test3() {
	double x = 1.5, y = 2.5;

	// ��ֵ����: ����ֵȡ����
	int a = 10;
	int& r1 = a;

	/* ��ֵ�����ܷ����ֵȡ������
	 const ��ֵ���ÿ���*/
	const int& r2 = 20;
	const double r3 = x + y;

	// ��ֵ����: ����ֵȡ����
	int&& r5 = 20;
	//double& r6 = x + y;		// ���벻ͨ��
	double&& r6 = x + y;

	/* ��ֵ�����Ƿ���Ը���ֵȡ����
	 ��ֵ���ÿ������� move �Ժ����ֵ*/
	//int&& r7 = a;	// ���뱨��
	int&& r7 = std::move(a);	// ��ֵ�������� move �Ժ����ֵ

	// �ܽ�һ��
	// ��ֵ����ֵ�ı���������  �ܷ�ȡ��ַ
	// ��ֵ���� :  ����ֵȡ����    ��ֵ���ÿ���ֱ�Ӹ���ֵȡ����
	// ��ֵ���� :  ����ֵȡ����    ��ֵ���ÿ���ֱ�Ӹ���ֵȡ����
	// const ��ֵ���ÿ��� ����ֵȡ����
	// ��ֵ���ÿ��� �� move�����ֵ ȡ������ ����ֱ�Ӹ���ֵȡ����
}

// ��ֵ���õ�ʹ�ó����ͼ�ֵ��ʲô��
 //���ó��� 1. ������Ͳ��������ٿ�����   2. ������ֵ
 //��ֵ:  ���ٿ���  ȱ��: �ֲ�����������ֵ����������ֵ���÷���
string Func1() {
	string str;
	cin >> str;
	// ...
	return str;
}
// Func �����еĳ���ֻ�ܴ�ֵ����
// ��ֵ�����ֻ��������������Ż�
void test4() {
	// ��ֵ���أ��������ȹ���һ����ʱ����Ϊstr�Ŀ������ٸ�ֵ��ret1����������Ϊʮ���������
	// ��������������Ϊ  �Ż�Ϊֱ�ӹ���
	string ret1 = Func1();	// ������ֱ�ӹ���һ�� ret1 ����
	// ���³��� �������޷��Ż�
	string ret2;
	// ... 
	ret2 = Func1();
}

// ���������������ɺ������� 
void func1(int& r) {
	cout << "void func1(int& r)" << endl;
}
void func1(const int& r) {
	cout << "void func1(const int& r)" << endl;
}
void func1(int&& r2) {
	cout << "void func1(int&& r)" << endl;
}
void test5() {
	int a = 0;
	const int b = 20;
	func1(a);	// ��������func1�����Ե��ã������ﲻ��������壬��������ȥ������ƥ����Ǹ�����
	func1(b);
	func1(a + b);	// a + b ����ֵ����ֵ���ð汾 ��ƥ�䣬��˵�����ֵ���ð汾
}

#include "string_me.h"

m_string::string test6() {
	m_string::string str("xxxxxxxxxxxxxxxxxxx");
	// ...
	return std::move(str);
	//return str;
}
std::string test6_std() {
	std::string str("xxxxxxxxxxxxxxxxxxx");
	// ...
	return std::move(str);
	//return str;
}
void test7() {
	//m_string::string ret1 = test6();	// �����Ŀ����͹���  �Ż�Ϊֱ�ӹ���

	m_string::string ret1 = test6();	

	//m_string::string ret2;
	//// ...
	//ret2 = test6();
}

// ����һ�� �Զ���������������࣬���봫ֵ���صĳ������ƶ�������������
void test8() {
	m_string::string ret1 = test6();	// �ƶ�����
	m_string::string ret3("1111111111111111111111");
	m_string::string copy1 = ret3;	// ���
	move(ret3);	
	m_string::string copy2 = ret3;	// ���
	m_string::string copy3 = move(ret3);	// �ƶ�����
}
void test9() {
	std::string ret1 = test6_std();	// �ƶ�����
	std::string ret3("111111111");
	std::string copy1 = ret3;	// ���
	move(ret3);
	std::string copy2 = ret3;	// ���
	std::string copy3 = move(ret3);	// �ƶ�����
}

// ��������
// �����Ĳ���ӿڣ���������������ֵ�����������ƶ�����ת����Դ�����ݽṹ�еĶ���Ҳ���Լ��١�
void test10() {
	list<m_string::string> lt;
	m_string::string s1("111111111111111111111");
	lt.push_back(s1);

	cout << endl;
	m_string::string s2("111111111111111111111");
	lt.push_back(move(s2));

	cout << endl;
	lt.push_back("22222222222222222222222222");
}
int main() {
	//test1();
	//test2();
	//test5();
	//test7();
	//test8();
	//test9();
	test10();
	return 0;
}