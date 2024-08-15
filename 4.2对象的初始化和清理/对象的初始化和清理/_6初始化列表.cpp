#include <iostream>
using namespace std;

// 初始化列表
class Person {
public:
	//传统初始化方式
	/*Person(int a, int b, int c) {
		this->_A = a;
		this->_B = b;
		this->_C = c;
	}*/
	//这样子就写死了
	/*Person() :_A(10), _B(20), _C(30) {

	}*/
	Person(int& a, int& b, int& c) :_A(a), _B(b), _C(c) {

	}
	int _A;
	int _B;
	int _C;
};

void test1() {
	int a = 0, b = 0, c = 0;
	Person p(a, b, c);
	cout << p._A << " " << p._B << " " << p._C << endl;
}




int main() {
	test1();

	return 0;
}