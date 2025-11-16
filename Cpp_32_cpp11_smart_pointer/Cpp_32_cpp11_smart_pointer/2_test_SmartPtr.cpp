#define _CRT_SECURE_NO_WARNINGS 1

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
	std::shared_ptr<A> sp1(new A(1));	// 引用计数 == 1

	std::shared_ptr<A> sp2(sp1);	// 引用计数 == 2

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

// shared_ptr 的循环引用问题
//struct Node
//{
//	A _val;
//	Node* _prev;
//	Node* _next;
//};
//void test_circalRef_Shared_Ptr_1()
//{
//	////Node* n2 = new Node;
//	//// 推荐用 new Node()  的写法，会对节点值进行初始化
//	//Node* n1 = new Node();
//	//Node* n2 = new Node();
//	//// ...
//	//delete n1;
//	//delete n2;
//
//	std::shared_ptr<Node> sp1(new Node());
//	std::shared_ptr<Node> sp2(new Node());
//	//sp1->_next = sp2;	// 通过智能指针 链接链表时，无法链接， 因为类型不匹配
//	//sp2->_prev = sp1;	// 左边时指针类型，右边是智能指针类型 对象
//}

//// 想到的其中一种解决方案，把 prev 和 next 指针 也使用智能指针
//struct Node
//{
//	A _val;
//	std::shared_ptr<Node> _prev;
//	std::shared_ptr<Node> _next;
//};
//void test_circalRef_Shared_Ptr_2()
//{
//	// shared_ptr 的 循环引用 问题
//	// 循环引用问题，两个对象内部，互相持有对方的 shared_ptr 指针
//	std::shared_ptr<Node> sp1(new Node());
//	std::shared_ptr<Node> sp2(new Node());
//	// 把 prev 和 next 指针 也使用智能指针
//	sp1->_next = sp2;
//	sp2->_prev = sp1;
//}

// 使用 werk_ptr 解决循环引用问题
namespace m_weak_ptr_test
{
	struct Node
	{
		A _val;
		m_SmartPtr::weak_ptr<Node> _prev;
		m_SmartPtr::weak_ptr<Node> _next;
		// weak_ptr 不是 RAII 智能指针，专门用来解决 shared_ptr 的循环引用问题
	};
	void test_m_weak_Ptr()
	{
		// shared_ptr 的 循环引用 问题
		// 循环引用问题，两个对象内部，互相持有对方的 shared_ptr 指针
		m_SmartPtr::shared_ptr<Node> sp1(new Node());
		m_SmartPtr::shared_ptr<Node> sp2(new Node());

		cout << sp1.use_count() << endl;
		cout << sp2.use_count() << endl;
		// 把 prev 和 next 指针 使用 weak_ptr
		sp1->_next = sp2;
		sp2->_prev = sp1;

		//  weak_ptr 不是 RAII 智能指针，专门用来解决 shared_ptr 的循环引用问题
		//  weak_ptr 不增加引用计数，可以访问资源，不参与资源的释放
		cout << sp1.use_count() << endl;
		cout << sp2.use_count() << endl;
	}
}

namespace std_weak_ptr_test
{
	struct Node
	{
		/*A _val;
		std::shared_ptr<Node> _prev;
		std::shared_ptr<Node> _next;*/

		A _val;
		std::weak_ptr<Node> _prev;
		std::weak_ptr<Node> _next;
		// weak_ptr 不是 RAII 智能指针，专门用来解决 shared_ptr 的循环引用问题
	};
	void test_weak_Ptr()
	{
		// shared_ptr 的 循环引用 问题
		// 循环引用问题，两个对象内部，互相持有对方的 shared_ptr 指针
		std::shared_ptr<Node> sp1(new Node());
		std::shared_ptr<Node> sp2(new Node());

		cout << sp1.use_count() << endl;
		cout << sp2.use_count() << endl;
		// 把 prev 和 next 指针 使用 weak_ptr
		sp1->_next = sp2;
		sp2->_prev = sp1;

		//  weak_ptr 不是 RAII 智能指针，专门用来解决 shared_ptr 的循环引用问题
		//  weak_ptr 不增加引用计数，可以访问资源，不参与资源的释放
		cout << sp1.use_count() << endl;
		cout << sp2.use_count() << endl;
	}
}

// shared_ptr 定制删除器的问题
template<class T>
struct DeleteArray
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

void test_delete()
{
	//std::shared_ptr<A> sp(new A(1));
	// 我们自己实现的 shared_ptr 中的析构函数是写死的，如果 new[]  会处理错误

	//std::shared_ptr<A> sp1(new A[10]);	
	//std::shared_ptr<A> sp2((A*)malloc(sizeof(A)));

	std::shared_ptr<A> sp1(new A[10], DeleteArray<A>());	// 传匿名仿函数对象
	std::shared_ptr<A> sp2((A*)malloc(sizeof(A)), [](A* ptr) { free(ptr); });	// 传 lambda 表达式
	// 智能指针控制文件的打开和关闭
	std::shared_ptr<FILE> sp3(fopen("SmartPtr.h", "r"), [](FILE* ptr) { fclose(ptr); });
}

int main() {
	//test_circalRef_Shared_Ptr_2();
	//m_weak_ptr_test::test_m_weak_Ptr();


	//test_std_autoPtr();
	//test_autoPtr();

	//test_std_unique_Ptr();

	test_std_shared_Ptr();
	//test_m_shared_Ptr();

	//test_delete();

	return 0;
}