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

	// 拷贝了对象 也能正确释放
	// auto_ptr 的原理为:
	// 管理权转移，拷贝时，会把 被拷贝对象的资源管理转移给拷贝对象
	// 隐患: 会导致 被拷贝对象悬空，访问就会出问题
	m_SmartPtr::auto_ptr<A> ap3(ap1);

	// 悬空后，再访问被拷问对象 就会崩溃
	//ap1->_a++;
	ap3->_a++;
}
void test_unique_Ptr() {
	// C++11 unique_ptr 禁止拷贝
	unique_ptr<A> uPtr1(new A(1));
	unique_ptr<A> uPtr2(new A(2));

	//unique_ptr<A> uPtr3(uPtr1);	// 报错，不能拷贝
	//up1 = up2;	// 同样也不能赋值
}

void test_shared_Ptr() {
	
	// shared
}
int main() {
	test_autoPtr();

	return 0;
}