#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "m_list.h"
#include "string_me.h"

using namespace std;

void Fun(int& x) { cout << "��ֵ����" << endl; }
void Fun(const int& x) { cout << "const ��ֵ����" << endl; }

void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }

// ģ���е�&&��������ֵ���ã������������ã�����ܽ�����ֵ���ܽ�����ֵ��
// ģ�����������ֻ���ṩ���ܹ� ͬʱ������ֵ���ú���ֵ���õ�������
// �����������͵�Ψһ���þ��������˽��յ����ͣ�����ʹ���ж��˻�������ֵ��
// ����ϣ���ܹ��ڴ��ݹ����б���������ֵ������ֵ������, ����Ҫ����������ѧϰ������ת��

// ʵ������ֵ: ������ֵ����(�����۵�)
// ʵ������ֵ: ������ֵ����
template<typename T>
void PerfectForward(T&& t)
{
	//Fun(t);
	
	// ����ת�����ֶ����ԭ������
	// ����ת��: t����ֵ���ã�������ֵ����
	// ����ת��: t����ֵ���ã�������ֵ����
	Fun(forward<T> (t));
}

//void PerfectForward(int&& t)
//{
//	Fun(t);
//}
void test11() {
	PerfectForward(10); // ��ֵ  int&&

	int a;
	PerfectForward(a);  // ��ֵ  int&
	PerfectForward(std::move(a)); // ��ֵ

	const int b = 8;
	PerfectForward(b); // const ��ֵ
	PerfectForward(std::move(b)); // const ��ֵ
}

void test12() {
	PerfectForward(10); // ��ֵ  int&&

	int a;
	PerfectForward(std::move(a)); // ��ֵ
}

void test13() {
	int a = 19;
	int& r = a;
	int&& rr = std::move(a);

	cout << &r << " "<< ++r << endl;
	cout << &rr << " " << ++rr << endl;
}
void test14() {
	int&& rr = 10;
	rr++;
	cout << rr << " " << &rr << endl;
}
void test15() {
	m_list::list<m_string::string> lt;
	//std::list<m_string::string> lt;
	m_string::string s1("111111111111111111111");
	lt.push_back(s1);

	cout << endl;
	m_string::string s2("111111111111111111111");
 	lt.push_back(move(s2));

	cout << endl;
	lt.push_back("22222222222222222222222222");
}
//int main() {
//	//test11();
//	//test12();
//	//test13();
//	//test14();
//	test15();
//
//	return 0;
//}