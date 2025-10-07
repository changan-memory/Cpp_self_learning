#include <iostream>
#include <string>
#include <memory>

using namespace std;

#include "SmartPtr.h"

class A {
public:
	A(int a = 0)
		:_a(a)
	{
		//cout << " A(int a = 0) " << endl;
	}
	~A() {
		//cout << this << "  ~A " << endl; 
	}

	int _a;
};

void test_autoPtr() {
	// C++98
	m_SmartPtr::auto_ptr<A> ap1(new A(1));
	m_SmartPtr::auto_ptr<A> ap2(new A(2));

	// �����˶��� Ҳ����ȷ�ͷ�
	// auto_ptr ��ԭ��Ϊ:
	// ����Ȩת�ƣ�����ʱ����� �������������Դ����ת�Ƹ���������
	// ����: �ᵼ�� �������������գ����ʾͻ������
	m_SmartPtr::auto_ptr<A> ap3(ap1);

	// ���պ��ٷ��ʱ����ʶ��� �ͻ����
	//ap1->_a++;
	ap3->_a++;
}
void test_unique_Ptr() {
	// C++11 unique_ptr ��ֹ����
	unique_ptr<A> uPtr1(new A(1));
	unique_ptr<A> uPtr2(new A(2));

	//unique_ptr<A> uPtr3(uPtr1);	// �������ܿ���
	//up1 = up2;	// ͬ��Ҳ���ܸ�ֵ
}

void test_shared_Ptr() {
	
	// shared
}
int main() {
	test_autoPtr();

	return 0;
}