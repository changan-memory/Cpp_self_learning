// �ɱ�ģ����� --- 2
#include <iostream>
#include <functional>
using namespace std;

//class Date {
//public:
//	Date(int year = 2025, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{ }
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// ֮ǰ�Ŀɱ�������Ļ�ȡ�����ǰѲ���һ��һ��ȡ������
//// �������� һ����ȡ�����������еĲ�����ȥ����ĳ����Ĺ��캯��
//template<class ...Args>
//Date* Create(Args... args) {
//	Date* ret = new Date(args...);
//	return ret;
//}

//int main() {
//	Date* p0 = Create();
//	Date* p1 = Create(2025);
//	Date* p2 = Create(2025, 9);
//	Date* p3 = Create(2025, 10, 10);
//
//	Date d(2023);
//	Date* p4 = Create(d);	// �ɱ�ģ����� ��һ�����ж�����
//
//	return 0;
//}