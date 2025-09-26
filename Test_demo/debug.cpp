#include <iostream>
#include <functional>
#include <stdio.h>

using namespace std;

class Rate {
public:
	Rate(double rate) : _rate(rate)
	{
	}
	double operator()(double money, int year)
	{
		return money * _rate * year;
	}
private:
	double _rate;
};

//int main() {
//	int a = 1, b = 2, c = 3, d = 4;
//	const int e = 6;
//
//	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
//	// ���ò��� �����������б�����ֵ���� c ����
//	cout << &e << endl;
//	auto func1 = [&, c]() {
//		++a;
//		++b;
//		//++c;	// ֵ����� c �����޸�
//		++d;
//		cout << &e << endl;
//		cout << typeid(e).name() << endl;
//		};
//	func1();
//	cout << a << " " << b << " " << c << " " << d << " " << e << endl;
//	return 0;
//}

int main() {
	int x = 0, y = 1, z = 2;
	printf("%d\n", x);
	printf("%d %d\n", x, y);
	printf("%d %d %d\n", x, y, z);
	return 0;
}