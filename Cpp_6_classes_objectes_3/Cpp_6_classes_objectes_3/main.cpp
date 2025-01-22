#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <assert.h>
//C���Գ�ʼ�������پ�������
//��Ͷ���
//�������Ĭ�ϳ�Ա����

//��Щ����ʽ����ĳ�Ա����


class Stack {
	typedef int StackDataType;		//����ƥ����Ҫ�� int ����char
public:
	//ջ���˹���������������Ͳ������ǳ�ʼ�����ͷ��ڴ���
	//ʹ�ù��캯����ʼ�������캯����������
	
	//���캯��
	/*	1. ��������������ͬ��
		2. �޷���ֵ��
		3. ����ʵ����ʱ�������Զ����ö�Ӧ�Ĺ��캯����
		4. ���캯���������ء�
		5. �������û����ʽ���幹�캯������C++���������Զ�����һ���޲ε�Ĭ�Ϲ��캯����һ��
		   �û���ʽ������������������ɡ� */

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
	/*void Init() {		//���캯�����Դ���Init()����
		this->base = (StackDataType*)malloc(sizeof(StackDataType) * 4);
		if (this->base = NULL) {
			cout << "malloc failed" << endl;
		}
		this->capacity = 4;
		this->top = 0;
	}*/
	void Push(StackDataType ele) {
		assert(this->base);
		if (this->top == this->capacity) {
			StackDataType* newSpace = (StackDataType*)realloc(this->base, 
															sizeof(StackDataType) * 2 * this->capacity);
			if (newSpace == nullptr) {
				std::perror("realloc ʧ��");
				return;
			}
			this->base = newSpace;
			this->capacity *= 2;
		}
		this->base[this->top++] = ele;
	}
	void Pop() {
		assert(this->base);
		this->top--;
	}
	StackDataType Top() {
		return this->base[top-1];
	}

	//��������
	/*1. 1. ������������������ǰ�����ַ� ~��
		 2. �޲����޷���ֵ���͡�
		 3. һ����ֻ����һ��������������δ��ʽ���壬ϵͳ���Զ�����Ĭ�ϵ�����������ע�⣺����������������
		 4. �����������ڽ���ʱ��C++����ϵͳϵͳ�Զ�������������*/
	//���˹��캯���������������Ͳ������ǳ�ʼ�����ͷ��ڴ��ˣ�����
	~Stack() {
		cout << "~Stack" << endl;
		if(this->base){
			free(this->base);
			this->base = nullptr;
			this->capacity = 0;
			this->top = 0;
		}
	}
private:
	StackDataType* base;
	int top;	//top��ʾջ��Ԫ�ص���һ��λ��
	int capacity;
};
void TestStackClass() {
	Stack st;
	st.Push(4);
	cout << st.Top() << endl;
	st.Pop();
	st.Push(3);
	cout << st.Top() << endl;
	st.Pop();
	st.Push(2);
	cout << st.Top() << endl;
	st.Pop();
	st.Push(1);
	cout << st.Top() << endl;
	st.Pop();
}
class Date {
public:
	//�޲ι��캯����ȫȱʡ���캯�����ڵ���ʱ���������
	//�޲εĹ��캯����ȫȱʡ�Ĺ��캯������ΪĬ�Ϲ��캯��������Ĭ�Ϲ��캯��ֻ����һ����
	//ע�⣺�޲ι��캯����ȫȱʡ���캯��������ûд������Ĭ�����ɵĹ��캯������������Ϊ��Ĭ�Ϲ��캯����
	//������ֻ�ܴ���һ��
	
	//���� Ĭ�ϳ�Ա����  �� Ĭ�Ϲ��캯��
	//Ĭ�Ϲ��캯�� ����
	//Ĭ�ϳ�Ա���� �� ���������ɵ�����Ĭ�ϳ�Ա����
	Date(int year = 1, int month = 1, int day =1) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	/*Date() {}*/

	/*Date(int year, int month, int day) {	//��ȱʡֵ������ȣ����������û�д��ڵı�Ҫ��
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}*/
	
	void Print() {
		cout << this->_year << "--" << this->_month << "--" << this->_day << endl;
	}
	//���ǲ�д���캯����������������Ĭ�Ϲ��캯����
	/* C++�����ͷֳ���������(��������)���Զ������͡��������;��������ṩ���������ͣ��磺int / char...
		�Զ������;�������ʹ��class / struct / union���Լ����������
		����������Ĭ�ϵĹ��캯��,���������Ͳ����������Զ����������ͻ��������Ĭ�Ϲ��캯��*/
private:
	//��������
	//ע�⣺C++11 ������������ͳ�Ա����ʼ����ȱ�ݣ��ִ��˲����������������ͳ�Ա������
	// ��������ʱ���Ը�ȱʡֵ�� ȱʡֵ�Ǹ�Ĭ�Ϲ��캯��ʹ��
	int _year = 2025;
	int _month = 1;
	int _day = 1;

	//�Զ�������
	Stack _st;

	//һ������£� ���������ͳ�Ա����Ҫ�Լ�д���캯���������ñ�����Ĭ�����ɵ�
	//����ȫ�������Զ�������ʱ�� ���Կ����ñ������Լ�����
};
void TestNULLparameter() {
	Date d1;
	Date d2;
	d2.Print();
}
void TestCallConstruct() {
	//���캯���ĵ��ú���ͨ������ͬ�����캯���Ƕ���+��ʼ������ ���� �Զ�����
	Date d1;
	//Date d1();	//��������д��������ͺ����������ֲ���
	Date d2(2025, 1, 1);
}
int main() {
	//TestStackClass();
	//TestNULLparameter();
	TestCallConstruct();
	return 0;
}