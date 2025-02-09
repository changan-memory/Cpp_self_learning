#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//���������
class Date {
public:
	
	
	Date(int year = 2025, int month = 2, int day = 22) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	void Print() {
		cout << this->_day << "--" << this->_month << "--" << this->_day << endl;
	}

	//�������Ǽ�����������operator�������м�������(Ӧ�ð�����������thisָ�����)
	//����ȫ�����أ�Ҳ��������������(�����㣬ֱ�ӷ���˽�г�Ա)
	bool operator<(const Date& d) {	//�Զ������ͣ���ô����ã����ڲ����޸ģ�����const
		if (this->_year < d._year)
			return true;
		else if (this->_year == d._year && this->_month < d._month)
			return true;
		else if (this->_year == d._year && this->_month == d._month && this->_day < d._day)
			return true;
		else
			return false;
	}
	//��ֵ�����=����
	// d3 = d1;
	//���ǲ�д��������Ҳ��Ĭ������=���أ�
	// �������������ͣ����õ��� ֵ����/ǳ����
	// ���Զ����������ͣ����ø��Ե� ��ֵ���������
	Date& operator=(const Date& d) {	//����(*this)�ı���
		//if (*this != d)	// �����ӱȽϣ������е�󣬽� != ���غ��ǿ���ʵ�ֵģ�����û��Ҫ
		if (this != &d) {		//����Լ����Լ���ֵ�����Բ�����
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;	//���ض���ı���
	}

//private:
	int _year;
	int _month;
	int _day;
};
// ���������
void Test_operator() {
	Date d1(2025, 6, 20);
	Date d2(2024, 3, 10);

	//ȫ�ְ汾
	//d1 < d2;	//�ᱻת���� operator<(d1, d2);
	//operator<(d1, d2);	//Ҳ����ֱ�ӵ���

	//��Ա�����汾
	d1 < d2;	//ת���� d1.operator(d2);
	d1.operator<(d2);	//�����϶��� d1.operator(d2)
	//�Զ������͵���������أ����������ڵ��ú���

	//�Ƿ���Ҫ�����������Ҫ����Щ������������Ƿ������� 
	//d1 + d2;	// + û����
	//d1 - d2;	// - ������

	//������Ҫ��ֵ�����=��Ҫ����
	d1 = d2;
	Date d3, d4;
	d4 = d3 = d1;
	
}
int main() {
	
	Test_operator();
	return 0;
}