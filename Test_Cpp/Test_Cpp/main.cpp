#include <iostream>
#include <assert.h>

using namespace std;
class Stack {
	typedef int StackDataType;
private:
	StackDataType* base;
	int top;	//top��ʾջ��Ԫ�ص���һ��λ��
	int capacity;
public:
	//���캯��
	Stack(int defaultCapacity = 4) {	//������Ҫ���ַ�ʽ�ĳ�ʼ������˹��캯����������
		cout << "Stack defaultCapacity = 4" << endl;
		this->base = (StackDataType*)malloc(sizeof(StackDataType) * defaultCapacity);
		if (this->base == nullptr) {
			cout << "malloc failed" << endl;
		}
		this->capacity = defaultCapacity;
		this->top = 0;
	}
	Stack(StackDataType* array, int num) {	//���ذ汾�������е�������г�ʼ��
		cout << "Stack(array, num)" << endl;
		this->base = (StackDataType*)malloc(sizeof(StackDataType) * num);
		if (this->base == nullptr) {
			cout << "malloc failed" << endl;
		}
		assert(this->base);
		memcpy(this->base, array, sizeof(StackDataType) * num);
		this->capacity = num;
		this->top = 0;
	}
	//�����������Ժ���ܡ�
	~Stack() {
		cout << "~Stack" << endl;
		free(this->base);
		this->base = nullptr;
		this->capacity = 0;
		this->top = 0;
	}
};

//int main() {
//	Stack st1;
//	Stack st2(4);
//	int arr[] = { 1, 2,3,4,6,6,7 };
//	Stack st3(arr, sizeof(arr) / sizeof(arr[0]));
//	return 0;
//}


//�Զ����ɵĹ��캯��
//class Date {
//public:
//	Date(int year = 2, int month = 2, int day = 2) {
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//
//	//Date() {		//�﷨�ϣ������غ������Դ��ڣ����ǣ��޲ε���ʱ��������壬��˲��ܴ���
//	//	this->_year = 3;
//	//	this->_month = 3;
//	//	this->_day = 3;
//	//}
//
//	/*Date(int year, int month, int day) {	//��ȱʡֵ������ȣ����������û�д��ڵı�Ҫ��
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main() {
//
//	//���캯���ĵ��ú���ͨ������ͬ�����캯���Ƕ���+��ʼ������ ���� �Զ�����
//	Date d1;
//	//Date d1();	//��������д��������ͺ����������ֲ���
//	Date d2(2025, 2025, 2025);		//���캯���ĵ��ã��������Ӳ����б�
//
//	Date d3;
//	//d3.Date(2025, 2025, 2025);
//	 //����д�������壬��������д���������Զ����õ����⣬��Σ�����д��DateΪʲô����Init
//}

class Time {
public:
	~Time() {
		cout << "~Time()" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date {
private:
	// ��������(��������)
	int _year;
	int _month;
	int _day;
	// �Զ�������
	Time _time;
};

int main() {
	Date d;
	return 0;
}





