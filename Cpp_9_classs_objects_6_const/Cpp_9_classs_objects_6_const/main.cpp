#include <iostream>
using namespace std;

class Date {
public:
	//这两个默认成员函数一般不用重新定义 ，编译器默认会生成。
	//这两个运算符一般不需要自己实现重载，使用编译器生成的默认取地址的重载即可，
	// 只有特殊情况，才需要重载，比如想让别人获取到指定的内容！
	Date* operator&() {
		cout << "Date* operator&()" << endl;
		//return this;
		return nullptr;	//比如不想让别人访问到可修改对象的地址
	}
	//两个函数构成函数重载(参数 this 类型不同)
	//Date* const this 和 const Date* const this
	const Date* operator&() const {
		cout << "const Date* operator&() const" << endl;
		return this;
	}
private:
	int _year = 2025;
	int _month = 2;
	int _day = 17;
};
int main() {
	Date d1;
	const Date d2;	//const类型对象声明时必须初始化，因为只有这一次的初始化机会
	cout << &d1 << endl;
	cout << &d2 << endl;
	return 0;
}

//class Date {
//private:
//	int _year = 2025;
//	int _month = 2;
//	int _day = 17;
//};
//int main() {
//	Date d1;
//	const Date d2;	//const类型对象声明时必须初始化，因为只有这一次的初始化机会
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//	return 0;
//}