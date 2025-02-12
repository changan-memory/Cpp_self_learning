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
//�����߼���ϵ����
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

//����д ��+= ���޸ĵ�ǰ����
Date& Date::operator+=(const int day) {
	this->_day += day;	//�޸��˵�ǰ��������ʵ�ֵ���+=
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
//��ʵ��+=,֮��+�ٸ���+=����   ��+�и���+=����
Date Date::operator+(const int day) {
	//��������һ��
	Date temp(*this);	//Date temp = *this;	//����д����������һ����
	temp += day;
	return temp;

	//Date temp(*this);
	//temp._day += day;	//�޸��˵�ǰ��������ʵ�ֵ���+=
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

//ǰ��++������++֮���ֵ
Date& Date::operator++() {
	*this += 1;
	return *this;
}

//����++������++֮ǰ��ֵ	//��������ر����Ǻ�������˿����ú���������ʵ��ǰ��++�ͺ���++��ͬʱ����
//�������int��������Ϊ�˽��վ����ֵ��������Ϊ��վλ����ǰ��++��������
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