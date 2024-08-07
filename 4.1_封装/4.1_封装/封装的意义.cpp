#include <iostream>
using namespace std;

const double PI = 3.14;

//设计一个圆类，求圆的周长
class Circle {
	
public:
	//属性
	int r;

	//行为
	//或许圆的周长
	double calculate_ZC() {
		return 2 * PI * r;
	}

};

//int main() {
//	Circle c1;
//	c1.r = 10;
//
//	cout << "圆的周长为" << c1.calculate_ZC() << endl;
//	system("pause");
//	return 0;
//}