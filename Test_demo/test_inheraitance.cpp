
#include <iostream>
using namespace std;

class Base {
public:
	virtual void Func1() {
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2() {
		cout << "Base::Func2()" << endl;
	}
	void Func3() {
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Derive : public Base {
public:
	virtual void Func1() {
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};

void test() {
	Base b_test;
	Derive d_test;
}
int main() {
	Base b_main;
	Derive d_main;
	test();
	return 0;
}