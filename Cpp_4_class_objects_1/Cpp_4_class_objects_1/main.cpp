#include <iostream>
using std::cout;
using std::cin;
using std::endl;
//�������
//C++����C���ԣ�ͬʱC++��struct�������� ��(���������������)
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


//��Ķ���
class Stack {
public:
	void Init(int defaultCapacity = 4) {
		base = (int*)malloc(sizeof(int) * defaultCapacity);
		capacity = defaultCapacity;
		top = 0;
	}
	void Push() {
		//.......
	}
	void Pop() {
		//.......
	}
private:
	int* base;
	int top;
	int capacity;
};
//class��struct�����Զ����࣬struct��Ϊ�˼���C���Ե�д����C++�ж����������struct,��C++��ϲ����class
//class�г�Ա�����ͱ���Ĭ����˽�еģ�strutc��Ĭ���ǹ�����


//��������Ͷ������
// ͷ�ļ���д��Ķ�������� ��Ա��Ȩ���޶� ��Ա����������   �Լ���Ա����������
// ��Ӧ��.cpp�ļ��У�д��Ա������ʵ�֣� ֻ������Ҫ�ں�����ǰ���϶�Ӧ��� �������޶�
//��������Ͷ�����룬��Ҫ�ں�����ǰ�棬��������������޶�
//ע�⣺ 1. �����ڽ���ʵ�ֵĺ������ᱻ�����Ϊ���������������Ƿ��Ϊȡ���ڱ�����
//		 2. ���У������Ͷ������ĺ�������������������(�������������Ͷ��岻�ܷ��룬��������Ӳ���)

class Date {
public:
	//���ݾֲ����ȵ�ԭ���� �������β�   ��ֵ��  �������β�,����Գ�Աyear����Ӱ��
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
//private:
	//int year;
	//int month;
	//int day;

	//ͨ������ĳ�Ա��������_������
	int _year;	//���Ƶ�д���������������������Ͷ���������ǣ��Ƿ񿪱ٿռ�
	int _month;
	int _day;
};

//��������������ԣ���װ���̳С���̬
// ��ѧϰ��װ
// C���ԣ����ݺͷ����Ƿ���ģ���װ���ǰ����ݺͷ���д��һ����Ϊ�˸��õĹ������Զž�һЩ�������Ĵ������
// �ֲ��� ȫ���������ռ���(��Ҫָ��)������
// �ֲ����ȫ�����Ӱ���������ڣ� ����������ռ��򲻻�Ӱ����������

//����Ĵ�Сֻ�����Ա�������������Ա����
//��ͬ���󣬵��ó�Ա���������õ���ͬһ����������Щ������ָ�����һ����������

//Ҳ����˵��������ֻ�洢�˳�Ա������û�д洢����ָ��
//�����洢��һ������������
void TestClass() {

	// ��ʵ�����������嶨�������ڵ�����
	// �����ͼֽ��ʵ�������Ķ�������Ƿ���
	
	Date d1;
	//Date::_year = 1;	//��������д��ͼֽ����ס�ˡ�����û�п��ٿտռ䣬���ܴ�����ݡ�
	d1._day = 2;	//Ӧ����������
	cout << sizeof(d1) << endl;		//��СΪ 12������Ĵ�Сֻ�����Ա�������������Ա����
}
//int main() {
//	TestStruct();
//	TestClass();
//	return 0;
//}

class Empty {};
class Data {
	int num;        // 4�ֽ�
	double value;   // 8�ֽ�
	char tag;       // 1�ֽ�
};// 8 + 8 + 1 = 17 �� vs��ʵ�����24���ڴ���룩

int main() {
	cout << sizeof(Empty) << endl;;  // ���1
	cout << sizeof(Data) << endl;;  // ���24
}