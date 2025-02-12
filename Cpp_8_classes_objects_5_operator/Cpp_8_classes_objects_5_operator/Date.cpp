#include "Date.h"

Date::Date(int year, int month, int day) {
	_year = year;
	_month = month;
	_day = day;
}

bool Date::operator<(const Date& d) {
	if (this->_year < d._year)
		return true;
	else if (this->_year == d._year && this->_month < d._month)
		return true;
	else if (this->_year == d._year && this->_month == d._month && this->_day < d._day)
		return true;
	else
		return false;
}

bool Date::operator==(const Date& d) {
	return this->_year == d._year 
		&& this->_month == d._month 
		&& this->_day == d._day;
}
//利用逻辑关系复用
bool Date::operator<=(const Date& d) {
	return *this < d || *this == d;
}

bool Date::operator>(const Date& d) {
	return !(*this <= d);
}

bool Date::operator>=(const Date& d) {
	return !(*this < d);
}
bool Date::operator!=(const Date& d) {
	return !(*this == d);
}

//这样写 是+= 会修改当前对象
Date& Date::operator+=(const int day) {
	this->_day += day;	//修改了当前对象，所以实现的是+=
	while(this->_day > GetMonthDay(_year, _month)) {
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13) {
			++_year;
			_month = 1;
		}
	}
	return *this;

	/**this = *this + day;
	return *this;*/
}
//先实现+=,之后+再复用+=更好   比+中复用+=更好
Date Date::operator+(const int day) {
	//拷贝构造一个
	Date temp(*this);	//Date temp = *this;	//两种写法本质上是一样的
	temp += day;
	return temp;

	//Date temp(*this);
	//temp._day += day;	//修改了当前对象，所以实现的是+=
	//while (temp._day > GetMonthDay(temp._year, temp._month)) {
	//	temp._day -= GetMonthDay(temp._year, temp._month);
	//	++temp._month;
	//	if (temp._month == 13) {
	//		++temp._year;
	//		temp._month = 1;
	//	}
	//}
	//return temp;
}

//前置++，返回++之后的值
Date& Date::operator++() {
	*this += 1;
	return *this;
}

//后置++，返回++之前的值	//运算符重载本质是函数，因此可以用函数重载来实现前置++和后置++的同时存在
//增加这个int参数不是为了接收具体的值，仅仅是为了站位，与前置++构成重载
Date Date::operator++(int) {
	Date temp(*this);
	*this += 1;
	return temp;
}

Date& Date::operator-=(const int day) {
	this->_day -= day;
	while (_day <= 0) {
		_day += GetMonthDay(_year, _month-1);
		_month--;
		while (_month <= 0) {
			_year--;
			_month = 12;
		}
	}
	return *this;
}

Date Date::operator-(const int day) {
	Date temp = *this;
	return (temp -= day);
}