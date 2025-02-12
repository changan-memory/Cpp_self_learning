#pragma once
#include <iostream>
using std::endl;
using std::cin;
using std::cout;

class Date {
public:
	Date(int year = 2025, int month = 2, int day = 11);
	void Print() { cout << this->_year << "--" << this->_month << "--" << this->_day << endl;}
	int GetMonthDay(int year, int month) {
		static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		//四年一润，不润，四百年一润
		if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
			return 29;
		}

		return dayArray[month];
	}

	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	bool operator!=(const Date& d);

	Date operator+(const int day);
	Date& operator+=(const int day);


	Date operator-(const int day);
	Date& operator-=(const int day);

private:
	int _year;
	int _month;
	int _day;
};
