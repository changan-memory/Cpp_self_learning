#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//�������
//C++����C���ԣ�ͬʱC++��struct�������� ��(������������)
struct _Stack {
	//��Ա����
	void Init(int defaultCapacity = 4) {
		base = (int*)malloc(sizeof(int) * defaultCapacity);
		if (base == nullptr) {
			perror("malloc failed\n");
			return;
		}
		this->size = 0;
		this->capacity = defaultCapacity;
	}
	void Push() {

	}
	void Destroy() {
		free(this->base);
		this->base = nullptr;
		this->top = this->capacity;
	}
	//��Ա����
	int* base;
	int top;
	int capacity;
	int size;
};
void TestStruct() {
	struct _Stack st1;	//C���Ե�д��
	st1.Init();
	_Stack st2;		//C++��д��
	st2.Init();

	cout << "size: " << st1.size << " capacity: " << st1.capacity << endl;
	cout << "size: " << st2.size << " capacity: " << st2.capacity << endl;
}

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
	TestStruct();
	return 0;
}