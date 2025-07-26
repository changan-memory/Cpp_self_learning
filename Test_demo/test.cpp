//#include <iostream>
//#include<vector>
//#include <algorithm>
//#include <assert.h>
//using namespace std;
//class Date {
//	//友元函数声明   可以使类外的函数  不受访问权限的控制
//	friend ostream& operator<<(std::ostream& out, const Date& d);
//	friend ostream& operator<<(std::ostream& out, const Date* d);
//public:
//	Date(int year, int month, int day) {
//		//要从构造处和输入处检查非法日期
//		//由于要检查非法日期，因此不便使用初始化列表初始化
//		if (month > 0 && month < 13 && day > 0 && day < GetMonthDay(year, month)) {
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else {
//			cout << "非法日期" << endl;
//			assert(false);
//		}
//	}
//	int GetMonthDay(int year, int month) const {
//		const static int daysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		//每次调用函数都需要在栈区创建数组，干脆将他变成静态数组
//		//四年一润，百年不润，四百年一润
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
//			return 29;
//		}
//		else {
//			return daysArray[month];
//		}
//	}
//	bool operator<(const Date& d) const {
//		if (this->_year < d._year)
//			return true;
//		else if (this->_year == d._year && this->_month < d._month)
//			return true;
//		else if (this->_year == d._year && this->_month == d._month && this->_day < d._day)
//			return true;
//		else
//			return false;
//	}
//private:
//	int _year = 2025;
//	int _month = 6;
//	int _day = 1;
//};
//
//ostream& operator<<(std::ostream& out, const Date& d) {
//	out << d._year << "年" << d._month << "月" << d._day << "日";
//	return out;
//}
//ostream& operator<<(std::ostream& out, const Date* d) {
//	out << d->_year << "年" << d->_month << "月" << d->_day << "日";
//	return out;
//}
//
//template<class T>
//class Less {
//public:
//	// 需要满足T类内重载了 < 运算符
//	bool operator()(const T& x, const T& y) const {
//		return x < y;
//	}
//};
//// 对Less类模板按照指针方式特化
//template<>
//class Less<Date*> {
//public:
//	bool operator()(Date* x, Date* y) const {
//		return *x < *y;
//	}
//};
////int main() {
////	Date d1(2025, 6, 10);
////	Date d2(2025, 6, 6);
////	Date d3(2025, 6, 8);
////	vector<Date> v1;
////	v1.push_back(d1);
////	v1.push_back(d2);
////	v1.push_back(d3);
////	// 可以直接排序，结果是日期升序
////	sort(v1.begin(), v1.end(), Less<Date>());
////	for (auto& e : v1)
////		cout << e << " ";
////	cout << endl;
////
////	vector<Date*> v2;
////	v2.push_back(&d1);
////	v2.push_back(&d2);
////	v2.push_back(&d3);
////	// 此处排序的结果是 vector 中元素出现的顺序 因为vector中元素的地址是递增的
////	// 可以直接排序，结果错误 日期还不是升序，而v2中放的地址是升序
////	// 此处需要在排序过程中，让sort比较v2中存放地址指向的日期对象
////	// 但是走Less模板，sort在排序时实际比较的是v2中指针的地址，因此无法达到预期
////	sort(v2.begin(), v2.end(), Less<Date*>());
////	for (auto& e : v2)
////		cout << e << " ";
////	cout << endl;
////	return 0;
////}
#include <iostream>
using namespace std;
class Date {
public:
	Date(int year = 2025, int month = 7, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{ }
	// 普通对象调用普通版本  const对象调用const版本
	// 普通对象和const对象都能调用const版本
	void showDate() const {
		cout << _year << "年--" << _month << "月--" << _day <<"日"<< endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main() {
	Date d1(6, 6, 6);
	const Date d2(2025, 8, 31);
	d1.showDate();
	d2.showDate();
	return 0;
}