#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include "string_me.h"
using namespace std;

void test11() {
	// ʹ�� push_back
	std::list<std::pair<int, char>> mylist;
	mylist.push_back(make_pair(40, 'd'));
	mylist.push_back({ 50, 'e' });
	for (auto e : mylist)
		cout << e.first << ":" << e.second << endl;
}

// ����Ȥ�ģ���listʵ�� emplace_back

class Date {
public:
	Date(int year = 2025, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "����" << endl;
	}
	// ��������
	Date(const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_day(d._day)
	{
		cout << "��������" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

// emplace �� push_back �����������Ա�
void test12() {
	// ����������һ�´��п���������ƶ������m_string::string����������
	// ���ǻᷢ����ʵ���Ҳ������emplace_back��ֱ�ӹ����ˣ�push_back
	// ���ȹ��죬���ƶ����죬��ʵҲ���á�
	std::list< std::pair<int, m_string::string> > mylist;

	mylist.emplace_back(10, "sort");
	mylist.emplace_back(make_pair(20, "sort"));
	cout << endl;

	mylist.push_back(make_pair(30, "sort"));
	cout << endl;

	mylist.push_back({ 40, "sort" });
}

// emplace �� push_back ����ǳ��������Ա�
void test13() {
	std::list<Date> mylist;

	// ��������һ·���´���ֱ�ӹ�����߿������� �ڵ��е� Date�����
	mylist.emplace_back(2025, 10, 1);	// emplace ���Դ�Date����� �Ͳ�����
	cout << endl;

	mylist.push_back(Date(2025, 10, 1));	// push_back ֻ�ܴ� Date �����
	cout << endl;
}

int main() {
	//test11();
	//test12();
	test13();
	return 0;
}