#include <iostream>
#include <string>
using namespace std;

class A {
public:
	A(int a = 0)
		:_a(a)
	{ 
		cout << "A(int a)" << endl;
	}
	~A() {
		cout << "~A()" << endl;
	}
private:
	int _a;
};
class Solution {
public:
	Solution(int x, int y) {
		cout << " Solution(int x, int y)" << endl;
	}
	Solution() {
		cout << " Solution()" << endl;
	}
public:
	int Sum_solution(int n) {
		cout << "Sum_solution()" << endl;
		return n;
	}
};
void push_back(const string& str) {
	cout << "str: " << str << endl;
}
void Test_push_back() {
	string str("1111111");	//创建对象，再push
	push_back(str);

	push_back(string("1111111"));	//push一个匿名对象, 匿名对象具有常性，传参要用const引用

	push_back("1111111");	//隐式类型转换后，再push   临时变量也具有常性，传参要用const引用
}
int main() {
	A aa1(1);	//有名对象 -- 生命周期在当前函数作用域
	A(2);		//匿名对象 -- 生命周期在当前行，即用即销毁

	Solution s1;
	s1.Sum_solution(10);	//创建有名对象，并调用函数

	Solution(10, 20).Sum_solution(20);	//用自己实现的构造函数创建匿名对象
	Solution().Sum_solution(20);	//用默认构造函数创建匿名对象

	//A& ra = A(1);		//匿名对象具有常性
	const A& ra = A(1);		//const引用，延长匿名对象的生命周期，生命周期在当前函数作用域

	return 0;
}