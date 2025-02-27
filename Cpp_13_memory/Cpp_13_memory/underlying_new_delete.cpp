#include <iostream>
using namespace std;

class A {
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << " A(const A& aa) " << endl;
	}
	~A() {
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
void TestNew_2() {
	//C++希望在出现错误时，抛异常而不是和malloc等一样返回错误编号
	//异常与捕获
	int* p1 = nullptr;
	try {
		do {
			//p1 = (int*)malloc(sizeof(int));
			p1 = new int[1024 * 1024];
			cout << p1 << endl;
		} while (p1);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	// C++要求，申请空间失败了，要抛异常，因此C++申请空间不能直接用malloc
}

void TestNew_1() {
	//operator new/delete
	//operator new/delete  的用法和malloc/free 的用法相同
	int* p1 = (int*)operator new(sizeof(int));
	operator delete(p1);
	int* p2 = new int(1);
	delete p2;

	A* p3 = (A*)operator new(sizeof(A) * 10);
	operator delete(p3);

	A* p4 = new A();
	delete p4;
}

//int main() {
//	//operator new/delete
//	//operator new/delete  的用法和 malloc/free 的用法相同
//	
//	A* p3 = (A*)operator new(sizeof(A));
//	operator delete(p3);
//
//	A* p4 = new A();
//	delete p4;
//	return 0;
//}