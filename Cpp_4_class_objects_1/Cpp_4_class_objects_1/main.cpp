#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//�������
//C++��struct����������
struct _Stack {
	void Init(int defaultCapacity = 4) {
		base = (int*)malloc(sizeof(int) * defaultCapacity);
	}
	int* base;
	int top;
	int capacity;
};

////��Ķ���
//class Stack {
//public:
//	void Init(int defaultCapacity = 4) {
//		base = (int*)malloc(sizeof(int) * defaultCapacity);
//		capacity = defaultCapacity;
//		top = 0;
//	}
//	void Push() {
//		//.......
//	}
//	void Pop() {
//		//.......
//	}
//private:
//	int* base;
//	int top;
//	int capacity;
//};

//��������Ͷ������
// ͷ�ļ���д��Ķ�������� ��Ա��Ȩ���޶� ��Ա����������   �Լ���Ա����������
// ��Ӧ��.cpp�ļ��У�д��Ա������ʵ�֣� ֻ������Ҫ�ں�����ǰ���϶�Ӧ��� �������޶�
//��������Ͷ�����룬��Ҫ�ں�����ǰ�棬��������������޶�
//ע�⣺ 1. �����ڽ���ʵ�ֵĺ������ᱻ�����Ϊ���������������Ƿ��Ϊȡ���ڱ�����
//		 2. ���У������Ͷ������ĺ�������������������(�������������Ͷ��岻�ܷ��룬��������Ӳ���)

class Date {
public:
	//���ݾֲ����ȵ�ԭ���Ǻ������βθ�ֵ�����ڵĳ�Ա
	//������д����������
	void setDate(int year, int month, int day) {
		/*year = year;
		month = month;
		day = day;*/
		_year = year;
		_month = month;
		_day = day;
	}
	void getDate() {
		cout << _day << endl;
	}
private:
	//int year;
	//int month;
	//int day;

	//ͨ������ĳ�Ա��������_������
	int _year;	//���������������Ͷ���������ǣ��Ƿ񿪱ٿռ�
	int _month;
	int _day;
};

//��������������ԣ���װ���̳С���̬
// ��ѧϰ��װ
// C���ԣ����ݺͷ����Ƿ����
// �ֲ��� ȫ�������������ռ��� 
// �ֲ����ȫ�����Ӱ���������ڣ� ����������ռ��򲻻�Ӱ����������

//����Ĵ�Сֻ�����Ա�������������Ա����

//Ҳ����˵��������ֻ�洢�˳�Ա������û�д洢����ָ��
//�����洢��һ������������
void TestClass() {
	// ��ʵ��������
	Date d1;
	cout << sizeof(d1) << endl;		//��СΪ 12
}
int main() {
	
	TestClass();

	return 0;
}