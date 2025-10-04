// 可变模板参数 --- 2
#include <iostream>
#include <functional>
using namespace std;

//class Date {
//public:
//	Date(int year = 2025, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{ }
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// 之前的可变参数包的获取，都是把参数一个一个取出来的
//// 但是我想 一次性取出来参数包中的参数，去调用某个类的构造函数
//template<class ...Args>
//Date* Create(Args... args) {
//	Date* ret = new Date(args...);
//	return ret;
//}

//int main() {
//	Date* p0 = Create();
//	Date* p1 = Create(2025);
//	Date* p2 = Create(2025, 9);
//	Date* p3 = Create(2025, 10, 10);
//
//	Date d(2023);
//	Date* p4 = Create(d);	// 可变模板参数 用一个已有对象构造
//
//	return 0;
//}