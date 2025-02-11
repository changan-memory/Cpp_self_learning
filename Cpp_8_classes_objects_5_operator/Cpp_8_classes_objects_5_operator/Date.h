#pragma once
#include <iostream>
using std::endl;
using std::cin;
using std::cout;

class Date {
public:
	Date(int year = 2025, int month = 2, int day = 11) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	void Print() {
		cout << this->_day << "--" << this->_month << "--" << this->_day << endl;
	}

	bool operator<(const Date& d) {	
		if (this->_year < d._year)
			return true;
		else if (this->_year == d._year && this->_month < d._month)
			return true;
		else if (this->_year == d._year && this->_month == d._month && this->_day < d._day)
			return true;
		else
			return false;
	}
	Date& operator=(const Date& d) {	
		if (this != &d) {
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}

	Date(const Date& d) {
		cout << "Date(const Date& d) " << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

private:
	int _year;
	int _month;
	int _day;
};
