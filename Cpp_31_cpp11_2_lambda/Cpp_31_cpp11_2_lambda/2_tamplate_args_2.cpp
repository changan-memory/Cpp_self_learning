// �ɱ�ģ����� --- 2
#include <iostream>
#include <functional>
using namespace std;

class Date {
	Date(int year = 2025, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{ }
private:
	int _year;
	int _month;
	int _day;
};

// ֮ǰ�Ŀɱ�������Ļ�ȡ�����ǰѲ���һ��һ��ȡ������
// �������� һ����ȡ������ȥ���ù��캯��
template<class ...Args>
Date* creat(Args... args) {
	Date* ret = new Date(args...);
	return ret;
}
int main() {
	Date* p1 = creat(2025, 10, 10);
	return 0;
}