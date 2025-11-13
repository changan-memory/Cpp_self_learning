#include <iostream>
#include <string>
#include <memory>
#include <utility>

using namespace std;

#include "SmartPtr.h"

class A {
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a = 0) " << endl;
	}
	~A() 
	{
		cout << "~A " <<  endl;
	}

	int _a;
};


// 一般实践中，明确规定不允许使用 auto_ptr
void test_std_autoPtr() 
{
	// C++98
	std::auto_ptr<A> ap1(new A(1));
	std::auto_ptr<A> ap2(new A(2));

	// 拷贝了对象 也能正确释放
	// auto_ptr 的原理为:
	// 管理权转移，拷贝构造时，会把 被拷贝对象的资源管理权  转移给拷贝对象
	//   隐患: 会导致 被拷贝对象悬空，访问就会出问题
	std::auto_ptr<A> ap3(ap1);

	// 悬空后，再访问被拷问对象 就会崩溃, 因此 使用 auto_ptr 时，不能访问被拷贝的对象
	ap1->_a++;
	ap3->_a++;
}

void test_autoPtr() {
	// C++98
	m_SmartPtr::auto_ptr<A> ap1(new A(1));
	m_SmartPtr::auto_ptr<A> ap2(new A(2));

	// 拷贝了对象 也能正确释放
	// auto_ptr 的原理为:
	// 管理权转移，拷贝时，会把 被拷贝对象的资源管理转移给拷贝对象
	// 隐患: 会导致 被拷贝对象悬空，访问就会出问题
	m_SmartPtr::auto_ptr<A> ap3(ap1);

	// 悬空后，再访问被拷贝对象 就会崩溃
	ap1->_a++;
	ap3->_a++;
}
void test_std_unique_Ptr() {
	// C++11 中的 unique_ptr 的解决方案 
	//			 unique_ptr 直接 禁止拷贝
	std::unique_ptr<A> uPtr1(new A(1));
	std::unique_ptr<A> uPtr2(new A(2));

	//std::unique_ptr<A> uPtr3(uPtr1);	// 报错，不能拷贝
	//uPtr2 = uPtr1;	// 同样也不能赋值

	unique_ptr<A> uPtr4 = std::move(uPtr1);
}


// 单纯的禁止拷贝是不可行的，有些场景需要拷贝, 可借助 shared_ptr 完成拷贝
void test_std_shared_Ptr() {
	
	// shared_ptr
	std::shared_ptr<A> sp1(new A(1));

	std::shared_ptr<A> sp2(sp1);

	sp1->_a++;
	sp2->_a++;

	cout << sp1->_a << endl;
	cout << sp2->_a << endl;
}

void test_m_shared_Ptr() {

	// shared_ptr
	m_SmartPtr::shared_ptr<A> sp1(new A(1));

	m_SmartPtr::shared_ptr<A> sp2(new A(2));

	m_SmartPtr::shared_ptr<A> sp3(sp1);

	sp1->_a++;
	sp2->_a++;

	cout << sp1->_a << endl;
	cout << sp2->_a << endl;

	m_SmartPtr::shared_ptr<A> sp4(sp2);
	m_SmartPtr::shared_ptr<A> sp5(sp4);

	sp3 = sp1;
	sp1 = sp5;
	sp1 = sp1;

}
int main()
{
	//test_std_autoPtr();
	//test_autoPtr();

	test_std_unique_Ptr();

	//test_std_shared_Ptr();
	//test_m_shared_Ptr();

	return 0;
}