#include<iostream>
using std::endl;
using std::cout;
using std::cin;

//1. ���� ���﷨�ĸ�����˵������ ���� ��һ�����������
void Test1() {
	int a = 0;
	int num = 100;
	int& b = a;
	int& c = b;
	int& d = c;
	//int& e;		//���ñ����ʼ��
	//int& d = num;	//����һ��ָ���������޸�
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << &d << endl;
}
//�������ã����Ա���ָ��Ͷ༶ָ��
void Swap(int& a, int& b) {	//����ֵ
	int temp = a;
	a = b;
	b = temp;
}
void Swap(int*& a, int*& b) {	//����ָ��
	int* temp = a;
	a = b;
	b = temp;
}
void Test2() {
	cout << "������ֵ" << endl;
	int a = 10, b = 100;
	cout << a << " " << b << endl;
	Swap(a, b);
	cout << a << " " << b << endl;
	cout << "����ָ��" << endl;
	int* pa = &a;
	int* pb = &b;
	cout << pa << " " << pb << endl;
	Swap(pa, pb);
	cout << pa << " " << pb << endl;

}
//2. ָ�� ���� һ��typedef ������ʹ��
typedef struct ListNode {
	int data;
	struct ListNode* next;	//C���Ա�����ôд
	//ListNode* _next;		//C++��������ôд��C++"�ѽṹ������������", ����ֱ����������Ϊ����
}ListNode, *LinkList;


//������ָ�뻯Ϊһ��ָ�������
void ListPushBack(ListNode* pphead, int data) {

}
//����typedef���Ϻ������
void ListPushBack(LinkList& phead, int data) {

}
// 3. ���﷨�����ϣ�����û�п����µĿռ䣬ֻ�Ǹ�ԭ���Ŀռ� ���˱���
void Test3() {
	//1. һ�����������ж������
	int a = 100;
	int& b = a;
	int& c = a;
	int& d = b;	
	//2. �����ڶ���ʱ�����ʼ��
	//int& x;	//���лᱨ��

	//3. ����һ������һ��ʵ�壬�ٲ�����������ʵ�� (�����õ�ָ���ܸı�)
	int y = 200;
	b = y;	//�˴� �� b �� d �Ĳ����� �Ǹ�ֵ���������޸�����
	d = y;
}
// 4. ���õ�ʹ�ó���
//_1. ������(����� ����)
//_2. ������  (���Ч��)    (�����/��������� ���Լ�������Ч��)
//���Ч�ʵ�����
#include <time.h>
struct A { int a[10000]; };
void TestFunc1(A a) {}
void TestFunc2(A& a) {}
void TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}
//C++�������޷���ȫ���ָ��
//_3 ����������ֵ

int main() {
	//Test1();
	Test2();
	Test3();
	TestRefAndValue();
	return 0;
}