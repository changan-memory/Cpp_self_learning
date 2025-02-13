//#include <iostream>
//using namespace std;
//
////���������
//class Date {
//public:
//	Date(int year = 2025, int month = 2, int day = 22) {
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	//�������Ǽ�����������operator�������м�������(Ӧ�ð�����������thisָ�����)
//	//Ҳ����ȫ�����أ������������ظ����㣬����ֱ�ӷ���˽�г�Ա
//	bool operator<(const Date& d) {	//�Զ������ͣ���ô����ã����ڲ����޸ģ�����const
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
//	int _year;
//	int _month;
//	int _day;
//};
//// ���������
//void Test_operator() {
//	Date d1(2025, 6, 20);
//	Date d2(2024, 3, 10);
//
//	//ȫ�ְ汾	//ȫ����������ز��ܷ���private��Ա
//	//d1 < d2;	//�ᱻת���� operator<(d1, d2);
//	//operator<(d1, d2);	//Ҳ����ֱ�ӵ���
//
//	//��Ա�����汾
//	d1 < d2;	//ת���� d1.operator(d2);
//	d1.operator<(d2);	//�����϶��� d1.operator(d2)
//	//�Զ������͵���������أ����������ڵ��ú���
//
//	//�Ƿ���Ҫ�����������Ҫ����Щ������������Ƿ������� 
//	//d1 + d2;	// + û����
//	//d1 - d2;	// - ������
//
//	//������Ҫ��ֵ�����=��Ҫ����
//	d1 = d2;
//	Date d3, d4;
//	d4 = d3 = d1; //d4.operator=(d3.operator=(d1));	//���Ӧ�÷��ص��øú����Ķ���Ҳ����*this
//
//	Date d5(2025, 6, 6);
//	d5 = d1;
//	//��һ���Ѿ����ڵĶ����ʼ����һ������  -----  ���ÿ������캯��
//	Date d6 = d5;
//
//	//�Ѿ����ڵ���������֮�临�ƿ���  -----  ��ֵ��������غ���
//	d1 = d6;
//}
//
//int main() {
//	Date d1(2025, 2, 12);
//	Date d2(2024, 2, 12);
//	cout << (d2 < d1) << endl;
//}

#include <iostream>
using namespace std;

class Stack {
	typedef int DataType;
public:
	Stack(size_t capacity = 10) {
		_array = (DataType*)malloc(capacity * sizeof(DataType));
		if (nullptr == _array) {
			perror("malloc����ռ�ʧ��");
			return;
		}
		_size = 0;
		_capacity = capacity;
	}
	void Push(const DataType& data) {
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	~Stack() {
		if (_array) {
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};
int main() {
	Stack s1;
	s1.Push(1);
	s1.Push(2);
	Stack s2;
	s2 = s1;
	return 0;
}