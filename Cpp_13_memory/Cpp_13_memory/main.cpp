#include<iostream>
using namespace std;

class A {
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
//申请的都是虚拟内存
int main() {
	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间还会调用构造函数和析构函数
	// 一定要 new/delete  malloc/free 匹配使用
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);

	free(p1);
	delete p2;
	cout << endl;
	A* p5 = (A*)malloc(sizeof(A) * 3);
	//调用了构造函数的，用传入的参数初始化
	//没有初始化的，调用默认构造函数
	A* p6 = new A[4]{A(1), A(2), A(3)};	//利用匿名对象进行初始化

	free(p5);
	delete[] p6;
	return 0;
}
