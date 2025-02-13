#include "Date.h"

namespace TestSpace_operator {
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
		//�������ͣ�ת����
		//�������Ǽ�����������operator�������м�������(Ӧ�ð�����������thisָ�����)
		//Ҳ����ȫ�����أ������������ظ����㣬����ֱ�ӷ���˽�г�Ա
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
		//d4 = d3 = d2 // d4.operator=(d3.operator=(d1));	//���Ӧ�÷��ص��øú����Ķ���Ҳ����*this

		//��ֵ�����������Ĭ�ϳ�Ա���������������Լ����ɣ� ����д��ȫ�ֵģ�
		Date& operator=(const Date& d) {	//����(*this)�ı���
			//if (*this != d)	// �����ӱȽϣ������е�󣬽� != ���غ��ǿ���ʵ�ֵģ�����û��Ҫ
			if (this != &d) {		//��ֹ�����ĸ�ֵ d1 = d1   ����Լ����Լ���ֵ�����Բ�����
				this->_year = d._year;
				this->_month = d._month;
				this->_day = d._day;
			}
			return *this;	//���ض���ı���������������*this�������ڻ���
		}

		/*Date(const Date& d) {
			cout << "Date(const Date& d) " << endl;
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}*/

	private:
		int _year;
		int _month;
		int _day;
	};
	// ���������
	void Test_operator() {
		Date d1(2025, 6, 20);
		Date d2(2024, 3, 10);

		//ȫ�ְ汾	//ȫ����������ز��ܷ���private��Ա
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
		d4 = d3 = d1; //d4.operator=(d3.operator=(d1));	//���Ӧ�÷��ص��øú����Ķ���Ҳ����*this

		Date d5(2025, 6, 6);
		d5 = d1;
		
		//���ֿ�������͸�ֵ���������
		//��һ���Ѿ����ڵĶ����ʼ����һ������  -----  ���ÿ������캯��
		Date d6 = d5;	//�ȼ��� Date d6(d5);

		//�Ѿ����ڵ���������֮�临�ƿ���  -----  ��ֵ��������غ���
		d1 = d6;
	}
}

void TestDate() {
	Date d1(2024, 3, 6);
	Date d2(2025, 3, 6);
	d2 += 100;
	d2.Print();
	d2 = d1 + 10000;
	d1.Print();
	d2.Print();

	/*Date d3(2025, 2, 12);
	Date d4 = d3 - 100;
	d3.Print();
	d4.Print();
	d3 -= 100;
	d4.Print();*/
}
void TestDate2() {
	Date d1(2025, 2, 12);
	// ��Ҫ++��ǰ��++����++��Ķ��� ����++����++ǰ�Ķ���
	++d1;	//d1.operator();
	d1.Print();
	d1++;	//d1.operator(0);
	d1.Print();

}
void TestDate3() {
	Date d1(2025, 2, 13);
	d1 -= 50;
	d1.Print();

	Date d2(2025, 2, 13);
	d2 += -10000;
	d2.Print();
}
void TestDate4() {
	Date d1(2025, 2, 13);
	Date ret1 = d1--;
	ret1.Print();
	d1.Print();

	Date d2(2024, 2, 13);
	Date ret2 = --d2;
	ret2.Print();
	d2.Print();
}
void TestDate5() {
	Date d1(2025, 2, 13);
	Date d2(1949, 10, 1);
	cout << d1 - d2 << endl;
	cout << d2 - d1 << endl;
}
void TestDate6() {
	Date d1(2025, 2, 13);
	Date d2(1949, 10, 1);
	//����������� <<  ,���������������� cout ��ostream��һ�������
	//�����벻��д�ɳ�Ա������
	cout << d1 << endl;
}
int main() {

	//TestDate();
	//TestDate2();
	//TestDate3();
	//TestDate4();
	TestDate5();


	/*int i = 1, j = 11;
	Date d1(2025, 2, 13);
	Date d2(2024, 2, 13);

	bool ret1 = d1 < d2;
	bool ret2 = i < j;*/
	return 0;
}