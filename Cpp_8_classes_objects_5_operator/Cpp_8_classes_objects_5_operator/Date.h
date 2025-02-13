#ifndef __DATE_H
#define __DATE_H

#include <assert.h>
#include <iostream>

#endif



using namespace std;

//实现一个日期类，表示日期的话，全是内置类型成员
// 拷贝构造不需要写，赋值重载不需要写，析构也不需要写
class Date {
	//友元函数声明   可以使类外的函数  不受访问权限的控制
	friend ostream& operator<<(std::ostream& out, const Date& d);
	friend istream& operator>>(std::istream& in, Date& d);

public:
	Date(int year = 2025, int month = 2, int day = 11) {
		//要从构造处和输入处检查非法日期
		if (month > 0 && month < 13 && day > 0 && day < GetMonthDay(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout<<"非法日期"<<endl;
			assert(false);
		}
	}
	void Print() { 
		cout << _year << "--" << _month << "--" << _day << endl;
	}
	//获取某年中某个月的天数
	int GetMonthDay(int year, int month) {
		//局部静态
		static int daysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		//每次调用函数都需要在栈区创建数组，干脆将他变成静态数组
		//四年一润，百年不润，四百年一润
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
			return 29;
		}
		else {
			return daysArray[month];
		}
		//如果要用引用返回，29是常量，需要着重考虑
		//内置类型没必要用引用返回，引用的底层也需要开指针，差距不大
	}

	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	bool operator!=(const Date& d);

	// d1 + 100
	Date operator+(const int day);
	Date& operator+=(const int day);	//有返回值，是为了满足+=的连续赋值
	Date& operator++();		//前置++	编译器规则，前置++重载时，直接重载
	Date operator++(int);	//后置++	后置++重载时，要加一个参数用于占位


	Date& operator-=(const int day);
	Date operator-(const int day);
	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d);	//实现两个日期的相减

	//流插入不能写成成员函数？
	//因为Date对象默认占用第一个参数，就是做了左操作数
	//写出来就一定是下面这样子，不符合使用习惯
	// d1 << cout;		// d1.operator<<(cout);  //第一个参数是左操作数，第二个参数是右操作数
	// cout << d1;	要让cout成为第一个参数，把<<重载成全局的
	//void operator<<(std::ostream& out);
private:
	int _year;
	int _month;
	int _day;
};
