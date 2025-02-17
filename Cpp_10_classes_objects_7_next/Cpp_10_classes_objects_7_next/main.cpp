#include <iostream>
using namespace std;

class A {
public:
	//�����εĶ���Ĭ�Ϲ��캯�����������޲ι��캯����ȫȱʡ�Ĺ��캯������ô��д�������Զ����ɵĹ��캯��
	A(int a) :_a(a) {

	}
private:
	int _a;
};

class B {
public:
	//�����ʹ�� ��ʼ���б���г�ʼ��

	//��ʼ���б�  �Ƕ���ĳ�Ա�����λ��
	B(int a, int& ref)
		:_ref(ref)	//��ֹ�ֲ�����������
		,_n(1) 
		,_x(2)
		,_obj_a(111)	//��Ĭ�Ϲ��죬�ڳ�ʼ���б�����ʽ����Ĭ�Ϲ���(����Ĭ�Ϲ��캯���������)
	{
		//�ڹ��캯���� �Ǹ�ֵ�����Զ�θ�ֵ�����ǳ�ʼ������Ϊ��ʼ��ֻ����һ��
		//_n = 0;	//�������ڸ�ֵ���ܶ� const ��ʼ��
		//_ref = ref
	}
private:
	//���³�Ա�������� ����
	A _obj_a;		//�Զ�������û��Ĭ�Ϲ��캯���������ڳ�ʼ���б���г�ʼ��

	//����: �����ڶ����ʱ���ʼ��   ��Ա�����ڶ������ʱ�����嶨��
	int& _ref;		//����
	const int _n;	//const

	int _x = 1;	//����� 1 ��ȱʡֵ���Ǹ���ʼ���б�ģ�����������ȱʡֵ������ȱʡֵȡ��ʼ��
	//�������Ͳ��������Զ������ͻ�ȥ����Ĭ�Ϲ���
};


class Stack {
	typedef int DataType;
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
public:
	Stack(size_t capacity = 10) {
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (_array = nullptr) {
			perror("malloc failed\n");
			return;
		}
		_size = 0;
		_capacity = capacity;
	}
	void Push(const DataType& data) {
		//checkCapacity();
		_array[_size] = data;
		_size++;
	}
	~Stack() {
		free(_array);
		_array = nullptr;
		_size = 0;
		_capacity = 0;
	}
};
class MyQueue {
private:
	Stack _pushst;
	Stack _popst;
	int _size = 0;	//ȱʡֵ��������÷�
public:
	MyQueue(){}
	//��ʼ���б��������ǲ�д��Ҳ��ȥ�Զ���һ���ʼ���б���Ϊ��ʼ���б��ǳ�Ա��������ĵط�
	MyQueue(int capacity)
		:_pushst(capacity)
		,_popst(capacity)
	{}
};
//int main() {
//	//�Զ�������
//	//MyQueue q1;		//����Ĭ�Ϲ��캯��
//	//MyQueue q2(100);	//��ʽ���ù��캯��
//	return 0;
//}

class Stack_1 {
private:
	int* _base;
	int _top;
	int _capacity;
public:
	//��ʼ���б��޷������ڹ��캯�����ڸ�ֵ
	//�����Ƿ�д��ʼ���б�������һ���ʼ���б��Ժ󶼽���ʹ�ó�ʼ���б�
	Stack_1(int capacity = 10)
		:_base((int*)malloc(sizeof(int) * capacity))	//������³�ʼ���б��޷���malloc�Ŀռ���м��
		, _top(0)
		, _capacity(capacity) 
		//: _top(0)		// ��Ա���������ڵ������Ĵ��� ���� ��ʼ���б��ʼ����˳��
		//, _capacity(capacity)
		//, _base((int*)malloc(sizeof(int) * _capacity))	//����д ��Ϊ _capacity ����ɳ�ʼ��
		//�������ȳ�ʼ�� _base , ��ʱ_capacity�����ֵ����˻�mallocʧ��
		//���飬��ʼ���б��еĳ�ʼ������ �� ��Ա����������˳�򱣳�һ�£�����
		
	{
		if (nullptr == _base) {
			perror("malloc failed\n");
			return;
		}
		//Ҫ�������ʼ��һ��
		memset(_base, 0, sizeof(int) * capacity);
	}
};
//��ʼ���б��޷�����ĳ��� ---------- ��̬����һ����ά����
class AA {
private:
	int** _base;
	int _row;
	int _col;
public:
	AA(int row = 10, int col = 10)
		:_row(row)
		, _col(col)
	{
		_base = (int**)malloc(sizeof(sizeof(int*) * row));
		if (_base == nullptr) {
			perror("malloc failed\n");
			return;
		}
		for (int i = 0; i < row; ++i) {
			_base[i] = (int*)malloc(sizeof(int) * col);
		}
	}
};

int main() {

	//���Ƕ������嶨�壬��ʼ���б��Ƕ���ĳ�Ա����ĵط�
	int num = 10;
	B bb(10, num);
	//�Զ�������
	//MyQueue q1;		//����Ĭ�Ϲ��캯��
	//MyQueue q2(100);	//��ʽ���ù��캯��

	return 0;
}