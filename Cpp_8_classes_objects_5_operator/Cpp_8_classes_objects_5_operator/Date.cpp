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
	return this->_year == d._year && this->_month == d._month && this->_day == d._day;
}

bool Date::operator>(const Date& d) {
	return !(*this < d || *this == d);
}

bool Date::operator>=(const Date& d) {
	return !(*this < d);
}

bool Date::operator<=(const Date& d) {
	return !(*this > d);
}

bool Date::operator!=(const Date& d) {
	return !(*this == d);
}

//这样写 是+= 会修改当前对象
Date& Date::operator+=(const int day) {
	this->_day += day;
	while(this->_day > GetMonthDay(_year, _month)) {
		_day -= GetMonthDay(_year, _month);
		_month++;
		while (_month > 12) {
			_year++;
			_month -= 12;
		}
	}
	return *this;
}

Date Date::operator+(const int day) {
	Date temp = *this;
	;
	return (temp += day);
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