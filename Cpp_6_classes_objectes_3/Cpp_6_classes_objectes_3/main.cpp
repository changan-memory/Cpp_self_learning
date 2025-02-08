#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <assert.h>
//C���� ��ʼ�������پ�������д
//C���� ��Щ����д�����ܷ���
//��Ͷ���
//�������Ĭ�ϳ�Ա���� ��ʼ�� ���� ���� ��ֵ(ǰ�ĸ�) ����Ҫ

//��Щ����������ĳ�Ա����


class Stack {
	typedef int StackDataType;		//����ƥ����Ҫ�� int ����char
private:
	StackDataType* base;
	int top;	//top��ʾջ��Ԫ�ص���һ��λ��
	int capacity;
public:
	//ջ���˹���������������Ͳ������ǳ�ʼ�����ͷ��ڴ���
	//ʹ�ù��캯����ʼ�������캯����������
	
	//���캯��
	/*	1. ��������������ͬ��
		2. �޷���ֵ��Ҳ����Ҫдvoid��
		3. ����ʵ����ʱ �Զ����ö�Ӧ�Ĺ��캯����
		4. ���캯���������ء�
		5. �������û����ʽ���幹�캯������C++���������Զ�����һ���޲ε�Ĭ�Ϲ��캯����һ��
		   �û���ʽ������������������ɡ� 
		6. ���캯�������ٿռ䣬ֻ��ɶ���ĳ�ʼ��			*/

	//���캯�������init, ���캯��������˽�еģ����ⲿ�Ͳ����Զ�������
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

	//�������� ��ɵ��Ƕ�����Դ��������������Destroy,�����������ϵͳ���

	/*1. 1. ������������������ǰ�����ַ� ~��
		 2. �޲���  (��˲�������)  �޷���ֵ���͡�
		 3. һ����  ֻ����һ��������������δ��ʽ���壬ϵͳ���Զ�����Ĭ�ϵ�����������ע�⣺����������������

		 //��������Ҳһ�������������Ͳ����������Զ������ͻ�ȥ����������������

		 4. �ڶ����������ڽ���ʱ��C++����ϵͳ�Զ�������������
				����������ʱ���Զ�����������������ɶ�������Դ����������
		 5. ������������Ϊ���ͷ� �����Ŀռ䣬 ջ���Ŀռ䲻��Ҫ�ͷ� */
	
	//ϵͳ�Զ����ɵ�������������ʲô��  
	//���������Ͳ����������Զ������ͻ�ȥ����������������
	
	//���˹��캯���������������Ͳ������ǳ�ʼ�����ͷ��ڴ��ˣ�����
	~Stack() {
		cout << "~Stack" << endl;
		free(this->base);
		this->base = nullptr;
		this->capacity = 0;
		this->top = 0;
	}

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


//�Զ����ɵĹ��캯��
class Date {
public:
	//�޲ι��캯����ȫȱʡ���캯�����ڵ���ʱ���������
	//�޲εĹ��캯����ȫȱʡ�Ĺ��캯������ΪĬ�Ϲ��캯��������Ĭ�Ϲ��캯��ֻ����һ����
	//ע�⣺�޲ι��캯����ȫȱʡ���캯��������ûд������Ĭ�����ɵĹ��캯������������Ϊ��Ĭ�Ϲ��캯����
	// ������ֻ�ܴ���һ��
	// �ܽᣬ�����ξͿ��Ե��õĺ���������Ĭ�Ϲ��캯��(���������ɵģ�ȫȱʡ�ģ��޲ε�)
	
	
	//���� Ĭ�ϳ�Ա����  �� Ĭ�Ϲ��캯��
	//Ĭ�Ϲ��캯�� ����
	//Ĭ�ϳ�Ա���� �� ���������ɵ�����Ĭ�ϳ�Ա����

	Date(int year = 2, int month = 2, int day = 2) {
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}

	//Date() {		//�﷨�ϣ������غ������Դ��ڣ����ǣ��޲ε���ʱ��������壬��˲��ܴ���
	//	this->_year = 3;
	//	this->_month = 3;
	//	this->_day = 3;
	//}

	/*Date(int year, int month, int day) {	//��ȱʡֵ������ȣ����������û�д��ڵı�Ҫ��
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}*/
	
	void Print() {
		cout << this->_year << "--" << this->_month << "--" << this->_day << endl;
	}
	//�������û����ʽ���幹�캯������C++���������Զ�����һ���޲ε�Ĭ�Ϲ��캯����
	// һ���û���ʽ�������������������


private:
	//��������
	//ע�⣺C++11 ������������ͳ�Ա����ʼ����ȱ�ݣ��ִ��˲���
	// �����������ͳ�Ա������, ��������ʱ���Ը�ȱʡֵ�� 
	// ���������ȱʡֵ�� �Ǹ�����������Ĭ�Ϲ��캯��ʹ��

	int _year = 2025;
	int _month = 1;
	int _day = 1;

	/* C++�����ͷֳ���������(��������)���Զ������͡��������;��������ṩ���������ͣ��磺
	int / char / double ...
	�Զ������;�������ʹ��class / struct / union���Լ����������
	����������Ĭ�ϵĹ��캯��,���������Ͳ����������Զ����������ͻ���� ����  Ĭ�Ϲ��캯��*/

	/*int _year;
	int _month;
	int _day;*/

	//�Զ�������  
	Stack _st;     //vs�ı��������Թ��캯�������˴���
					 // ���Զ�������ʱ��������Զ������͵Ĺ��캯��������ʼ���������ͣ���C++��׼��δ�����涨

	//һ������£� ���������ͳ�Ա����Ҫ�Լ�д���캯���������ñ�����Ĭ�����ɵ�
	//����ȫ�������Զ�������ʱ�� ���Կ����ñ������Լ�����
};
void TestNULLparameter() {
	Date d1;
	Date d2;
	d2.Print();
}
//���캯���ĵ���
void TestCallConstruct() {
	//���캯���ĵ��ú���ͨ������ͬ�����캯���Ƕ���+��ʼ������ ���� �Զ�����
	Date d1;
	//Date d1();	//��������д��������ͺ����������ֲ���
	Date d2(2025, 2025, 2025);		//���캯���ĵ��ã��������Ӳ����б�

	d1.Print();
	d2.Print();

	Date d3;
	//d3.Date(2025, 2025, 2025);
	 //����д�������壬��������д���������Զ����õ����⣬��Σ�����д��DateΪʲô����Init
}
int main() {
	//TestStackClass();
	//TestNULLparameter();
	//TestCallConstruct();
	return 0;
 


//#include <iostream>
//using namespace std;
//
//class Date {
//public:
//	/*Date(int year = 2, int month = 2, int day = 2) {
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}*/
//	void Print() {
//		cout << this->_year << "--" << this->_month << "--" << this->_day << endl;
//	}
//private:
//	int _year = 2025;	
//	int _month = 1;
//	int _day = 1;
//};
//int main() {
//	Date d1;
//	d1.Print();
//	return 0;
//}