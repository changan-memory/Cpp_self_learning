#include <iostream>
using namespace std;

int main() {
	// decltype ������ʽ������
	const int x = 1;
	double y = 2.2;
	decltype(x * y) ret;		// ret��������double
	decltype(&x) p;				// p��������int*
	cout << typeid(ret).name() << endl;
	cout << typeid(p).name() << endl;
	return 0;
}