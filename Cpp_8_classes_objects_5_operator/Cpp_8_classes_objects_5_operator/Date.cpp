#include "Date.h"


bool Date::operator<(const Date& d) const {
	if (this->_year < d._year)
		return true;
	else if (this->_year == d._year && this->_month < d._month)
		return true;
	else if (this->_year == d._year && this->_month == d._month && this->_day < d._day)
		return true;
	else
		return false;
}

bool Date::operator==(const Date& d) const {
	return this->_year == d._year 
		&& this->_month == d._month 
		&& this->_day == d._day;
}
//�����߼���ϵ����
bool Date::operator<=(const Date& d) const {
	return *this < d || *this == d;
}

bool Date::operator>(const Date& d) const {
	return !(*this <= d);
}

bool Date::operator>=(const Date& d) const {
	return !(*this < d);
}
bool Date::operator!=(const Date& d) const {
	return !(*this == d);
}

//����д ��+= ���޸ĵ�ǰ����
Date& Date::operator+=(const int day) {
	if (day < 0) {
		return *this -= -day;
	}
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
Date Date::operator+(const int day) const {
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
	if (day < 0) {	//��������Ϊ����������� - ������ -= �����ֻ��Ҫ��-=
		return *this += -day;
	}
	this->_day -= day;
	while (_day <= 0) {
		--_month;	//--֮�󣬿���-��֮����0
		while (_month <= 0) {
			_year--;
			_month = 12;
		}
		//����λ�ſ��Լ�����
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(const int day) const {
	Date temp = *this;	//�˴��� ��������
	temp -= day;
	return temp;
}

//ǰ��--
Date& Date::operator--() {
	*this -= 1;
	return *this;
}
//����Զ������ͣ�Ӧ�ö���ǰ��++ --,Ч�ʸ���
Date Date::operator--(int) {	//ռλ���������ɲ���
	Date temp(*this);
	*this -= 1;
	return temp;
}
// d1 - d2
int Date::operator-(const Date& d) const {
	//Ĭ��this��d��Ĭ�������ֵ������
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

//void Date::operator<<(std::ostream& out) {	//��һ�������� this ���ڶ�������������
//	//���ô�ֵ��out��cout�ı���
//	out << this->_year << "��" << _month << "��" << _day << "��" << endl;
//}

//���س�ȫ�ֺ�����û�취����˽�г�Ա������C++�л�����Ԫ�����
//void operator<<(const ostream& out, const Date& d)	//�����������cout��������ݣ��������const������ô����
ostream& operator<<(std::ostream& out, const Date& d) {
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}

//����ȡ cin ���ܼ�const, ��Ϊ��ȡ��ᣬ�ڲ������״ֵ̬
istream& operator>>(std::istream& in, Date& d) {
	int year = 0, month = 0, day = 0;
	in >> year >> month >> day;
	//����������ݵĺϷ���
	if (month > 0 && month < 13 && day > 0 && day < d.GetMonthDay(year, month)) {
		d._year = year;
		d._month = month;
		d._day = day;
	}
	else {
		cout << "�Ƿ�����" << endl;
		assert(false);
	}
	return in;
}

