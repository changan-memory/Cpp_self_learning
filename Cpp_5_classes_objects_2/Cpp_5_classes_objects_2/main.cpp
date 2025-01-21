#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//��ʵ�����������൱��ͼֽ�������൱�ڸ���ͼֽ��������ķ���
class A {
public:
	void Print_1() {
		cout << "_1" << endl;
	}
	void Print_2() {
		cout << "_2" << endl;
	}
private:
	int a;
	char b;
};
void TestClassSize() {
	A a1;
	A a2;
	A a3;
	cout << "A size" << sizeof(A) << endl;
	cout << "a1 size" << sizeof(a1) << endl;
	cout << "a2 size" << sizeof(a2) << endl;
}
//1. ��һ����Ա����ṹ��ƫ����Ϊ0�ĵ�ַ����
//2. ������Ա����Ҫ���뵽ĳ�����֣������������������ĵ�ַ����
//ע�⣺������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ��
//VS��Ĭ�ϵĶ�����Ϊ8
//3. �ṹ���ܴ�СΪ���������������б��������������Ĭ�϶������ȡ��С������������
//4. ���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ������������������������ṹ�����
//���С��������������������Ƕ�׽ṹ��Ķ�����������������

//ΪʲôҪ�ڴ���룿
//��Ӳ��������йأ�CPU��ȡ���ݣ�ֻ�ܶ�4 or 8��������
class A1 {
public:
	void print_() {
		cout << "A1" << endl;
	}
};
class A2 {};
//û�г�Ա�������࣬����������һ���ֽڣ�����ռλ����ʾ����Ķ������
void TestEmptyClass() {	
	cout <<"A1 " << sizeof(A1) << endl;
	cout << "A2 " << sizeof(A2) << endl;
}

// thisָ��
class Date {
public:
	//this�������βκ�ʵ����ʾ���ݣ��������ں����ڲ�����
	void Init(int year, int month, int day) {
		/*_year = year;
		_month = month;
		_day = day;*/
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	void Print() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//��������Գ�Ա�������д��������Ա�������ϲ���this
	/*void Print(Date* const this) {
		cout << _year << "-" << _month << "-" << _day << endl;
	}*/
private:
	int _year;
	int _month;
	int _day;
};
void Test_this() {
	Date d1, d2;
	//���˺����β�thisָ��󣬶����ڵ��ó�Ա����ʱ��Ҳ���ȴ������ĵ�ַ����Щ���Ǳ��������Ĵ���
	//d1.Init(&d1, 2025, 1, 21);s
	d1.Init(2025, 1, 21);
	d1.Print();
	d2.Init(2024, 1, 21);
	d2.Print();
}
//Date������ Init �� Print ������Ա������d1��d2���õ���ͬһ��������������û�й��ڲ�ͬ���������
//�ǵ�d1���� Init ����ʱ���ú��������֪��Ӧ������d1���󣬶���������d2�����أ�
//C++��ͨ������thisָ���������⣬����C++��������ÿ�����Ǿ�̬�ĳ�Ա������������һ�����ص�ָ�����
//�ø�ָ��ָ��ǰ����(��������ʱ���øú����Ķ���)���ں����������С���Ա������
//�Ĳ���������ͨ����ָ��ȥ���ʡ�ֻ�������еĲ������û���͸���ģ����û�����Ҫ�����ݣ���
//�����Զ���ɡ�

//˼��thisָ�������� ������  ջ��  ����  ��̬��  ������
//this���βΣ���˺���ͨ�β�һ��������ں�������ʱ��ջ֡�У�
//thisָ���ں����ڲ���Ҫ�������õ�, vs�ı�������thisָ�봫�������Ż��������ַ����ecx�Ĵ�����
//exc�д洢thisָ���ֵ

//�Կ�ָ������û�������ʱ����
//����thisָ���˼����
class TestThis {
public:
	void Print() {
		cout << "Print" << endl;
	}
	void PrintA() {
		cout << _A << endl;
	}
private:
	int _A;
};
void Test_This_1() {
	TestThis* p = nullptr;
	p->Print();
}
void Test_This_2() {
	TestThis* p = nullptr;
	p->PrintA();
}
//�������������Ľ���ֱ���ʲô  1.����ʱ����   2. ����ʱ����   3. ��������
int main() {
	//TestClassSize();
	//TestEmptyClass();
	//Test_this();
	//Test_This_1();
	Test_This_2();
	return 0;
}