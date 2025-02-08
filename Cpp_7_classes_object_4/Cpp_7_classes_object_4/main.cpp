#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Stack {
private:
	int* _base;
	int _top;
	int _capacity;
public:
	Stack(int defaultCapacity = 4) {
		this->_base = (int*)malloc(sizeof(int) * defaultCapacity);
		if (this->_base == nullptr) {
			perror("malloc failed\n");
			return;
		}
		this->_capacity = defaultCapacity;
		this->_top = 0;
	}
	//ʵ��һ�����
	/*Stack(const Stack& stack) {
		
	}*/
	~Stack() {
		cout << " ~Stack" << endl;
		free(this->_base);
		this->_base = nullptr;
		this->_capacity = 0;
		this->_top = 0;
	}
};
//��������  ����
class Date {
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 2023, int month = 10, int day = 28) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	//����ʱ�� ����������Ҫ��ֱ�ӿ������Զ�������  ֵ���Σ�������ÿ������캯��
	//�������캯���ǹ��캯����һ��������ʽ��
	//�������캯���Ĳ���ֻ��һ���ұ����������Ͷ�������ã�ʹ�ô�ֵ��ʽ������ֱ�ӱ�����Ϊ����������ݹ���á�
	// ������ָ�� ����������⣬��Ϊ�������͵�ָ�붼���������ͣ�  �������ø���
	//����һ��������Ҫ�ȴ��Σ����Զ������͵Ĵ���  ����  ���ÿ������캯��

	Date(const Date& date) {	//������� const
		//const ��Ϊ�˷�ֹ����д����ֹ����д�����´���
		//date._year = _year;		//����ϸ���濴�����������˷������۱�����������ֵ
		//date._month = _month;
		//date._day = _day;

		this->_year = date._year;
		this->_month = date._month;
		this->_day = date._day;
	}
};
void Func(int i) {
	return;
}
void Func(Date d) {
	return;
}
//Ĭ�Ͽ������캯��
class Date_1 {
private:
	int _year;
	int _month;
	int _day;
public:
	Date_1(int year = 2023, int month = 10, int day = 28) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	//��δ��ʽ���壬������������Ĭ�ϵĿ������캯���� 
	// Ĭ�ϵĿ������캯�������ڴ�洢���ֽ�����ɿ��������ֿ�������ǳ����������ֵ������
	//Ĭ�Ͽ������캯�� ����ʲô��
	//�������ͳ�Ա���  ֵ����/ǳ����     �Զ������ͣ����ø��ԵĹ��캯�������û�п������캯������ֵ����

	/*Date_1(const Date_1& date) {
		this->_year = date._year;
		this->_month = date._month;
		this->_day = date._day;
	}*/
};
int main() {
	//��������Բ�д�������죬Ĭ�����ɵľͿ���
	Date d1(2025, 2, 8);
	Date d2(d1);

	Func(d1);
	Func(10);
	
	//ֵ������������
	Stack st1;
	Stack st2(st1);
	return 0;
}