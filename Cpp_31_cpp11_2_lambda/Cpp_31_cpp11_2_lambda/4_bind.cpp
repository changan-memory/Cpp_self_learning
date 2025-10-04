#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int Sub(int a, int b) {
	return a - b;
}
void test5() {
	function<int(int, int)> rSub1 = bind(Sub, placeholders::_1, placeholders::_2);
	cout << rSub1(7, 3) << endl;

	function<int(int, int)> rSub2 = bind(Sub, placeholders::_2, placeholders::_1);
	cout << rSub2(7, 3) << endl;
}
double Plus(int a, int b, double rate) {
	return (a + b) * rate;
}
double PPlus(double rate, int a, int b) {
	return (a + b) * rate;
}
double PPPlus(int a, double rate, int b) {
	return (a + b) * rate;
}
void test6() {
	// 缺省参数是写死的，只能有一个值。bind 可以传多个不同值的参数
	function<double(int, int)> plus1 = bind(Plus, placeholders::_1, placeholders::_2, 4.1);
	function<double(int, int)> plus2 = bind(Plus, placeholders::_1, placeholders::_2, 5.1);
	function<double(int, int)> plus3 = bind(Plus, placeholders::_1, placeholders::_2, 6.1);
	cout << plus1(5, 3) << endl;
	cout << plus2(5, 3) << endl;
	cout << plus3(5, 3) << endl;
	cout << endl;

	function<double(int, int)> plus = bind(Plus, placeholders::_1, placeholders::_2, 4.1);
	function<double(int, int)> pplus = bind(PPlus, 4.2, placeholders::_1, placeholders::_2);
	function<double(int, int)> ppplus = bind(PPPlus, placeholders::_1, 4.3, placeholders::_2);

	cout << plus(5, 3) << endl;
	cout << pplus(5, 3) << endl;
	cout << ppplus(5, 3) << endl;
}
class SubClass {
public:
	// 静态成员函数
	static int s_sub(int a, int b) {
		return a - b;
	}
	// 非静态成员函数
	int sub(int a, int b) {
		return a - b;
	}
};
void test7() {
	// 绑定静态函数，可以取地址，也可以不取
	function<int(int, int)> sub1 = bind(SubClass::s_sub, placeholders::_1, placeholders::_2);
	function<int(int, int)> sub2 = bind(&SubClass::s_sub, placeholders::_1, placeholders::_2);
	cout << sub1(5, 3) << " " << sub2(3, 5) << endl;
}
void test8() {
	// 绑定非静态函数，必须取地址，且需要 手动 对this指针传参
	SubClass s;
	// 传对象 传对象的指针都可以调用
	// 通过对象的指针调用 operator()
	function<int(int, int)> sub1 = bind(&SubClass::sub, &s, placeholders::_1, placeholders::_2);
	// 通过对象直接调用 operator()
	function<int(int, int)> sub2 = bind(&SubClass::sub, s, placeholders::_1, placeholders::_2);
	cout << sub1(5, 3) << " " << sub2(3, 5) << endl;

	// 传匿名对象也可以
	// 调用匿名对象的 operator()
	function<int(int, int)> sub3 = bind(&SubClass::sub, SubClass(), placeholders::_1, placeholders::_2);
	cout << sub3(9, 4) << " " << sub3(4, 9) << endl;
	// 以上的底层实现 都是仿函数
	// 本质都调用了 operator()
}
//int main() {
//	//test5();
//	//test6();
//	//test7();
//	test8();
//
//	return 0;
//}