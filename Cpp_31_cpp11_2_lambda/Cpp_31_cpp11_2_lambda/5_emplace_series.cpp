#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include "string_me.h"
using namespace std;

void test11() {
	// 使用 push_back
	std::list<std::pair<int, char>> mylist;
	mylist.push_back(make_pair(40, 'd'));
	mylist.push_back({ 50, 'e' });
	for (auto e : mylist)
		cout << e.first << ":" << e.second << endl;
}

// 有兴趣的，给list实现 emplace_back

class Date {
public:
	Date(int year = 2025, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "构造" << endl;
	}
	// 拷贝构造
	Date(const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_day(d._day)
	{
		cout << "拷贝构造" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

// emplace 和 push_back 插入深拷贝的类对比
void test12() {
	// 下面我们试一下带有拷贝构造和移动构造的m_string::string，再试试呢
	// 我们会发现其实差别也不到，emplace_back是直接构造了，push_back
	// 是先构造，再移动构造，其实也还好。
	std::list< std::pair<int, m_string::string> > mylist;

	mylist.emplace_back(10, "sort");
	mylist.emplace_back(make_pair(20, "sort"));
	cout << endl;

	mylist.push_back(make_pair(30, "sort"));
	cout << endl;

	mylist.push_back({ 40, "sort" });
}

// emplace 和 push_back 插入浅拷贝的类对比
void test13() {
	std::list<Date> mylist;

	// 参数包，一路往下传，直接构造或者拷贝构造 节点中的 Date类对象
	mylist.emplace_back(2025, 10, 1);	// emplace 可以传Date类对象 和参数包
	cout << endl;

	mylist.push_back(Date(2025, 10, 1));	// push_back 只能传 Date 类对象
	cout << endl;
}

int main() {
	//test11();
	//test12();
	test13();
	return 0;
}