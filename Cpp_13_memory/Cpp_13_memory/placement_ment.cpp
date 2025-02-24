#include <iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A(){
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};

// 定位new/replacement new
// 这样的功能，在池化技术中很常用，内存池，线程池，连接池，进程池......
// 每次 在堆上申请空间，都要去找堆申请内存(在堆中申请内存是一件很耗时的操作)
// 因此会提前申请一大块内存，在需要的时候取出内存。
// 但，取出的只是内存，没有调用构造函数初始化，因此可以用定位new初始化    new(p1)A;

//int main() {
//	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因此构造函数不会自动调用
//	A* p1 = (A*)malloc(sizeof(A));	
//
//	//对已有的一块空间，显式调用构造函数
//	new(p1)A; // 注意：如果A类的构造函数有参数时，此处需要传参
//
//	//显式调用析构函数
//	p1->~A();
//	free(p1);
//
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//	p2->~A();
//	operator delete(p2);
//
//	return 0;
//}