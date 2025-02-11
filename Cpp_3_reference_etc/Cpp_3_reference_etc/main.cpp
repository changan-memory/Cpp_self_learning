#include<iostream>
#include <assert.h>
using std::endl;
using std::cout;
using std::cin;

//1. ���� ���﷨�ĸ�����˵������ ���� ��һ�����������
void Test1() {
	int a = 666;
	int num = 100;
	int& b = a;
	int& c = b;
	int& d = c;
	//int& e;		//���ñ����ʼ��
	cout << d << endl;
	d = num;	//����һ��ָ���������޸�   ����������  ��ֵ�� �ǰ�num��ֵ  ��ֵ��  d   
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << &d << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
}
//�������ã����Ա���ָ��Ͷ༶ָ��
void Swap(int& a, int& b) {	//����ֵ   �β���ʵ�εı���
	int temp = a;
	a = b;
	b = temp;
}
void Swap(int*& a, int*& b) {	//����ָ��   ����������ã� ����ָ�������Ҫ�ö���ָ��
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
	//ListNode* next;		//C++��������ôд��C++"�ѽṹ������������", ����ֱ����������Ϊ����
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

	//3. C++�� ����һ������һ��ʵ�壬�ٲ�����������ʵ�� (�����õ�ָ���ܸı�)
	//java��û��ָ�룬 �����ǿ��Ը�ָ���
	int y = 200;
	b = y;	//�˴� �� b �� d �Ĳ����� �Ǹ�ֵ���������޸�����
	d = y;
}

//1. �����ڶ���ʱ�����ʼ��
//2. һ�����������ж������
//3. ����һ������һ��ʵ�壬�ٲ�����������ʵ��
//  ���﷨�����ϣ� ������Ϊ ����û�п����¿ռ䣬 ֻ�Ƕ�ͬһƬ�ڴ�ռ�ȡ�˶������

// 4. ���õ�ʹ�ó���
//_1. ������(����� ����)  �ں����ڲ�����Ҫ�ı�ʵ��
//_2. ������  (���Ч��)    (����� / ��������� ���Լ�������Ч��)
//���Ч�ʵ�����
#include <time.h>
#define TEST_NUM 10000
struct A { int a[TEST_NUM]; };		//Ϊʲô��δ���  ��10000 �ĳ�1000 �ᱨ��
void TestFunc1(A a) {}
void TestFunc2(A& a) {}
void TestRefAndValue(){
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < TEST_NUM; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < TEST_NUM; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}
//C++�������޷���ȫ���ָ��
//_3 ����������ֵ   ʮ����Ҫ
// ����������ֵ�� �����޸ķ���ֵ
// �Ƿ�������ʱ������ȡ���ں����� ����ֵ����
//int Count() {
//	static int n = 10;
//	n++;
//	return n; //n����ֱ�ӷ��أ� ���ǻ�����һ����ʱ����(С�����ǼĴ����� ��������˵)���ٷ���
//}
int& Count() {	//����������ֵ�Ͳ��ٻ�������ʱ������ 
	static int n = 10;
	n++;
	return n;
}//���ص��� n �����ã� �ô��ǣ���������ʱ����Ŀ����� �����Ч��

int& ResTestReturn() {	//����������ֵ�Ͳ��ٻ�������ʱ������ 
	int n = 10;
	n++;
	return n;
}//���ص��� n �����ã� �ô��ǣ���������ʱ����Ŀ����� �����Ч��

void TestRetRefVal() {
	int& ret = ResTestReturn();	//���ݾֲ���������ã� ʮ��Σ�ա�
	cout << ret << endl;
	//�����ӡRet��ֵ�ǲ�ȷ���ģ����ResTestReturn����������û������ջ֡�����صĽ����������ȷ��
	//							 ���ResTestReturn����������������ջ֡����ôRet��ֵ�����ֵ
	printf("ssssssssssssssssssssssssssss\n");	//����printf������ �²�����ջ֡������ԭ����ջ֡
												//�ٷ���ret�Ͳ��������ֵ
	cout << ret << endl; 
}
//�ܽ�
//1. �����κγ��������������ô���
//2. ���÷��ؽ���ʹ��
//        ���������� �����ڣ����������÷���   �����ڵĻ������������÷���
// �ֲ��������������÷��أ� 
//ȫ�ֱ��� �Լ�  malloc �����Ķ���(�����Ķ������ͷ�֮ǰ���Է�������)

typedef struct SeqList {
	int base[100];
	int size;
	//C++���淨  C++�ѽṹ�����������࣬ �����ڽṹ��д�������Լ���������ص�
	int& at(int pos) {
		assert(pos < 100 && pos >= 0);
		return base[pos];
	}
	int& operator[](int pos) {
		assert(pos >= 0 && pos < 100);
		return base[pos];
	}
}SeqList;	//�����������������ã�ʹ����ֱ�Ӷ�д���߲���˳���

void TestSeqList_CppVersion() {	// C++���淨
	SeqList s;
	s[0] = 100;		//�����������������ã�ʹ����ֱ�Ӷ�д���߲���˳���
	cout << s[0] << endl;
	s[0] += 5;
	cout << s[0] << endl;
}

//������  
void TestRef() {
	//���õĹ�����Ȩ�޲��ܷŴ�
	const int a = 10;
	//int& b = a;

	// ���ԣ�c ��ֵ��d���ڿ�����d�ı䲻Ӱ��c��ֵ
	const int c = 100;
	int d = c;
	//���õĹ����У� Ȩ�޿���ƽ�ƻ��� ��С
	int x = 1000;
	int& y = x;		//Ȩ��ƽ��
	const int& z = x;	//Ȩ����С  Ȩ����С��,�������ֻ��,�� z �������ʱ�������޸ģ��ñ���x��Ȼ�����޸�
	x++;
	//++z; //�ᱨ��

	const int& m = 10;	//��������   ������ȡ����
	//int& n = 10;	//�����Ӳ���, ����Ϊ10�ǳ���

	double dd = 11;
	int ii = dd;	//�ᷢ����ʽ����ת�� ����ת���������ʱ��������ʱ�������г��ԣ�ֻ������ֵ

	//����ת���������ʱ��������ʱ�������г���  
	//int& rii = dd;	//dd �� int, ����������ת���� �����ϣ� rii�� ����ʱ���� ������  ������д��������Ȩ��
	const int& rii = dd;	//����const�� Ȩ����ͬ�� ��˱���ͨ��
}
//����
int func1() {	//����x�Ŀ������������ʱ����
	static int x = 10;
	return x;
}
int& func2() {	//����x�ı����� ���������ʱ����
	static int x = 10;
	return x;
}
void func3() {
	//int& x = func1();	//Ȩ�޷Ŵ� �����Խ���
	int x1 = func1();	// ������
	const int& y = func1();	//Ȩ��ƽ�ƣ� ���Խ���

	int& ret2 = func2();	//���ԣ�Ȩ�޵�ƽ��   
	const int& ret2_ = func2();		//���ԣ�Ȩ�޵���С
	//�ܽᣬfunc���ص���һ�������ı����� 
}

//��������ת��ʱ�������ʱ����
void TestTypeChange() {
	int i = 10;
	double j = 10.11;
	//һ����С������Ľ������������� ������ʱ���ܸı�ԭ���������ֻ�ܲ���ԭ�����ĸ���������ʱ����
	if (j > i)	
		cout << "xxxxxxxxxxxxx" << endl;
}
void TestPointerANDRef(){
	int a = 10;
	//���﷨���棬���ò����ٿռ䣬 ��һƬ�ռ�ı���
	int& ra = a;
	ra = 1000;
	//�﷨���棬ָ�뿪�ٿռ䣬 ���a�ĵ�ַ
	int* p = &a;
	*p = 100;

	//�ӵײ���ʵ�ֵĽǶȿ�������ʹ������ָ��ķ�ʽʵ�ֵ�
}
int main() {
	//Test1();
	//Test2();
	//Test3();
	//TestRefAndValue();
	//Count();
	//TestRetRefVal();
	//TestSeqList_CppVersion();
	//TestRef();
	TestTypeChange();	//��������ת��ʱ�������ʱ����
	//TestPointerANDRef();
	return 0;
}