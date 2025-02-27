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
	//C++ϣ���ڳ��ִ���ʱ�����쳣�����Ǻ�malloc��һ�����ش�����
	//�쳣�벶��
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
	// C++Ҫ������ռ�ʧ���ˣ�Ҫ���쳣�����C++����ռ䲻��ֱ����malloc
}

void TestNew_1() {
	//operator new/delete
	//operator new/delete  ���÷���malloc/free ���÷���ͬ
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
//	//operator new/delete  ���÷��� malloc/free ���÷���ͬ
//	
//	A* p3 = (A*)operator new(sizeof(A));
//	operator delete(p3);
//
//	A* p4 = new A();
//	delete p4;
//	return 0;
//}