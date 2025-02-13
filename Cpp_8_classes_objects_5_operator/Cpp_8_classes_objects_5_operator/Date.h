#pragma once
#include <iostream>
using std::endl;
using std::cin;
using std::cout;

//ʵ��һ�������࣬��ʾ���ڵĻ���ȫ���������ͳ�Ա
// �������첻��Ҫд����ֵ���ز���Ҫд������Ҳ����Ҫд
class Date {
public:
	Date(int year = 2025, int month = 2, int day = 11);
	void Print() { 
		cout << _year << "--" << _month << "--" << _day << endl;
	}
	//��ȡĳ����ĳ���µ�����
	int GetMonthDay(int year, int month) {
		//�ֲ���̬
		static int daysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		//ÿ�ε��ú�������Ҫ��ջ���������飬�ɴཫ����ɾ�̬����
		//����һ�󣬰��겻���İ���һ��
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
			return 29;
		}
		else {
			return daysArray[month];
		}
		//���Ҫ�����÷��أ�29�ǳ�������Ҫ���ؿ���
		//��������û��Ҫ�����÷��أ����õĵײ�Ҳ��Ҫ��ָ�룬��಻��
	}

	bool operator<(const Date& d);
	bool operator==(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	bool operator!=(const Date& d);

	// d1 + 100
	Date operator+(const int day);
	Date& operator+=(const int day);	//�з���ֵ����Ϊ������+=��������ֵ
	Date& operator++();		//ǰ��++	����������ǰ��++����ʱ��ֱ������
	Date operator++(int);	//����++	����++����ʱ��Ҫ��һ����������ռλ


	Date& operator-=(const int day);
	Date operator-(const int day);
	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d);	//ʵ���������ڵ����

	void operator<<(std::ostream& out);
private:
	int _year;
	int _month;
	int _day;
};
