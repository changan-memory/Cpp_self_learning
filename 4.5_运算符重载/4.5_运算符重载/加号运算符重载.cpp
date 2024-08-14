#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Person {
public:
	/*Person operator+ (Person& p) {
		Person temp;
		temp._A = this->_A + p._A;
		temp._B = this->_B + p._B;
		return temp;
	}*/

	int _A;
	int _B;
};

Person operator+(Person& p1, Person& p2) {
	Person temp;
	temp._A = p1._A + p2._B;
	temp._B = p1._B + p2._B;
	return temp;
}



void test_1() {
	Person p1;
	p1._A = 10;
	p1._B = 10;

	Person p2;
	p2._A = 10;
	p2._B = 10;

	//Person p3 = operator+(p1, p2);
	Person p3 = p1 + p2;

	//成员函数 重载本质调用
	//Person p3 = p1.operator+ (p2);

	//全局函数 重载本质调用
	//Person p3 = operator+ (p1, p2);



	cout << p3._A << "   " << p3._B << endl;
}
int main() {

	test_1();
	return 0;
}