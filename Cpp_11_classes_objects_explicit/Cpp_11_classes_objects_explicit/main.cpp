#include <iostream>
using namespace std;

class A {
private:
	int _a;
public:
	//构造函数不仅可以构造与初始化对象，对于接收单个参数的构造函数，还具有类型转换的作用
	// 用explicit修饰构造函数，将会禁止构造函数的隐式转换。
	//explicit A(int a)	//加了 explicit 关键字后，就不允许类似 A aa2 = 2 的隐式类型转换了
	//	: _a(a)
	//{
	//	cout << "A(int a)" << endl;
	//}
	A(int a)
		: _a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa) 
		: _a(aa._a)
	{
		cout << " A(const A& aa) " << endl;
	}
};
int main() {
	A aa1(1);	//构造函数
	A aa2 = 2;		//隐式类型转换，整形转换成自定义类型
	// 2构造一个A的临时对象，临时对象再拷贝构造aa2  -> 编译器会把两次构造优化成 用2直接构造
	// A temp = 2  //2先调用A的构造函数生成临时变量temp  ->  A aa2 = temp  //temp再用构造函数去拷贝构造

    //error C2440: “初始化”: 无法从“int”转换为“A &”
	//A& refa = 2;
	const A& refa = 2;
	return 0;
}