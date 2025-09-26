// 可变模板参数 --- 2
#include <iostream>
#include <functional>
using namespace std;

class Date {
	Date(int year = 2025, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{ }
private:
	int _year;
	int _month;
	int _day;
};

// 之前的可变参数包的获取，都是把参数一个一个取出来的
// 但是我想 一次性取出来，去调用构造函数
template<class ...Args>
Date* creat(Args... args) {
	Date* ret = new Date(args...);
	return ret;
}
int main() {
	Date* p1 = creat(2025, 10, 10);
	return 0;
}