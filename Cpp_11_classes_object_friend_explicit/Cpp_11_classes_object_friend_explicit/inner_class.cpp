#include <iostream>
using namespace std;
class A{
private:
	static int k;
	int h;
public:
	//类型受到访问限定符的限制
	class B {	// B天生就是A的友元  内部类是外部类的友元
	public:
		void foo(const A& a){
			cout << k << endl; 
			cout << a.h << endl;//OK
		}
	};
};
int A::k = 1;


//int main() {
//	cout << sizeof(A) << endl;	//大小为4，因为A中没有B的对象
//	A aa1;
//	A::B bb1;	//访问B类需要 通过A类去访问
//	return 0;
//}