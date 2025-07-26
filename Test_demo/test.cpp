//#include <iostream>
//#include<vector>
//#include <algorithm>
//#include <assert.h>
//using namespace std;
//class Date {
//	//��Ԫ��������   ����ʹ����ĺ���  ���ܷ���Ȩ�޵Ŀ���
//	friend ostream& operator<<(std::ostream& out, const Date& d);
//	friend ostream& operator<<(std::ostream& out, const Date* d);
//public:
//	Date(int year, int month, int day) {
//		//Ҫ�ӹ��촦�����봦���Ƿ�����
//		//����Ҫ���Ƿ����ڣ���˲���ʹ�ó�ʼ���б��ʼ��
//		if (month > 0 && month < 13 && day > 0 && day < GetMonthDay(year, month)) {
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else {
//			cout << "�Ƿ�����" << endl;
//			assert(false);
//		}
//	}
//	int GetMonthDay(int year, int month) const {
//		const static int daysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		//ÿ�ε��ú�������Ҫ��ջ���������飬�ɴཫ����ɾ�̬����
//		//����һ�󣬰��겻���İ���һ��
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
//			return 29;
//		}
//		else {
//			return daysArray[month];
//		}
//	}
//	bool operator<(const Date& d) const {
//		if (this->_year < d._year)
//			return true;
//		else if (this->_year == d._year && this->_month < d._month)
//			return true;
//		else if (this->_year == d._year && this->_month == d._month && this->_day < d._day)
//			return true;
//		else
//			return false;
//	}
//private:
//	int _year = 2025;
//	int _month = 6;
//	int _day = 1;
//};
//
//ostream& operator<<(std::ostream& out, const Date& d) {
//	out << d._year << "��" << d._month << "��" << d._day << "��";
//	return out;
//}
//ostream& operator<<(std::ostream& out, const Date* d) {
//	out << d->_year << "��" << d->_month << "��" << d->_day << "��";
//	return out;
//}
//
//template<class T>
//class Less {
//public:
//	// ��Ҫ����T���������� < �����
//	bool operator()(const T& x, const T& y) const {
//		return x < y;
//	}
//};
//// ��Less��ģ�尴��ָ�뷽ʽ�ػ�
//template<>
//class Less<Date*> {
//public:
//	bool operator()(Date* x, Date* y) const {
//		return *x < *y;
//	}
//};
////int main() {
////	Date d1(2025, 6, 10);
////	Date d2(2025, 6, 6);
////	Date d3(2025, 6, 8);
////	vector<Date> v1;
////	v1.push_back(d1);
////	v1.push_back(d2);
////	v1.push_back(d3);
////	// ����ֱ�����򣬽������������
////	sort(v1.begin(), v1.end(), Less<Date>());
////	for (auto& e : v1)
////		cout << e << " ";
////	cout << endl;
////
////	vector<Date*> v2;
////	v2.push_back(&d1);
////	v2.push_back(&d2);
////	v2.push_back(&d3);
////	// �˴�����Ľ���� vector ��Ԫ�س��ֵ�˳�� ��Ϊvector��Ԫ�صĵ�ַ�ǵ�����
////	// ����ֱ�����򣬽������ ���ڻ��������򣬶�v2�зŵĵ�ַ������
////	// �˴���Ҫ����������У���sort�Ƚ�v2�д�ŵ�ַָ������ڶ���
////	// ������Lessģ�壬sort������ʱʵ�ʱȽϵ���v2��ָ��ĵ�ַ������޷��ﵽԤ��
////	sort(v2.begin(), v2.end(), Less<Date*>());
////	for (auto& e : v2)
////		cout << e << " ";
////	cout << endl;
////	return 0;
////}
#include <iostream>
using namespace std;
class Date {
public:
	Date(int year = 2025, int month = 7, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{ }
	// ��ͨ���������ͨ�汾  const�������const�汾
	// ��ͨ�����const�����ܵ���const�汾
	void showDate() const {
		cout << _year << "��--" << _month << "��--" << _day <<"��"<< endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main() {
	Date d1(6, 6, 6);
	const Date d2(2025, 8, 31);
	d1.showDate();
	d2.showDate();
	return 0;
}