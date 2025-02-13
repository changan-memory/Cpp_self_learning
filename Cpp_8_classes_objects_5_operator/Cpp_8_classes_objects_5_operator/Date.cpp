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
	if (day < 0) {
		return *this -= -day;
	}
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
	if (day < 0) {	//考虑输入为负数的情况， - 复用了 -= ，因此只需要改-=
		return *this += -day;
	}
	this->_day -= day;
	while (_day <= 0) {
		--_month;	//--之后，可能-完之后变成0
		while (_month <= 0) {
			_year--;
			_month = 12;
		}
		//借完位才可以加天数
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(const int day) {
	Date temp = *this;	//此处是 拷贝构造
	temp -= day;
	return temp;
}

//前置--
Date& Date::operator--() {
	*this -= 1;
	return *this;
}
//因此自定义类型，应该多用前置++ --,效率更高
Date Date::operator--(int) {	//占位参数，构成参数
	Date temp(*this);
	*this -= 1;
	return temp;
}
// d1 - d2
int Date::operator-(const Date& d) {
	//默认this比d大，默认算出的值是正的
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d) {
		max = d;
		min = *this;
		flag = -1;
	}

	int days = 0;
	while (min < max) {
		min++;
		days++;
	}
	return days * flag;
}

void Date::operator<<(std::ostream& out) {

}

