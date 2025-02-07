#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//��װ�����ñ��˿����ĵط�������Ϊ���У������ñ��˿����ģ�����Ϊ˽��
// public  protected  private

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
public:
	int _c;
};
void TestClassSize() {
	A a1;
	A a2;
	A a3;
	cout << "A size" << sizeof(A) << endl;
	cout << "a1 size" << sizeof(a1) << endl;
	cout << "a2 size" << sizeof(a2) << endl;
	cout << "a3 size" << sizeof(a3) << endl;

	a1._c = 10;		//������ȥ�������� ��Ա���� _c 
	a1.Print_1();	//�����洢�� ���Ա��������, ����ȥ�������ҳ�Ա����
}

//�ڴ�������
//1. ��һ����Ա����ṹ��ƫ����Ϊ0�ĵ�ַ����
//2. ������Ա����Ҫ���뵽ĳ�����֣������������������ĵ�ַ����
//ע�⣺������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ��
//VS��Ĭ�ϵĶ�����Ϊ8
//3. �ṹ���ܴ�СΪ���������������б������������ �� Ĭ�϶������ ȡ��С���Ǹ�������������
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
//û�г�Ա�������࣬����������һ���ֽڣ�����ռλ����ʾ����Ķ������, ���洢��Ч����
void TestEmptyClass() {	
	A1 a1;
	A2 a2;
	cout <<"A1 " << sizeof(A1) << endl;
	cout << "A2 " << sizeof(A2) << endl;
	//��������С��0�Ļ�����ô����ĵ�ַ�Ƕ��٣���СΪ0�Ļ���û�취ȡ��ַ��
	cout << &a1 << endl;
	cout << &a2 << endl;
}

// thisָ��
class Date {
public:
	//this�������βκ�ʵ����ʽ���ݺ�ʹ�ã��������ں����ڲ�ʹ�ã�this��һ���ؼ���
	//this ��������  Date* const this�� const���ε��� this������� this �����޸�
	void Init(int year, int month, int day) {
		/*_year = year;
		_month = month;
		_day = day;
		this = nullptr;*/

		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	void Print() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//��ͬ�Ķ��󣬵���ͬһ������������������ʵ����ݲ�ͬ
	
	//����������󣬻�Գ�Ա�������д��������Ա�������ϲ���this, ���ʱ���ʱ��ʹ��this����
	/*void Print(Date* const this) {
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
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
	d1.Init(2025, 1, 11);
	d2.Init(2024, 2, 22);
	d1.Print();			//��ͬ�Ķ��󣬵���ͬһ������������������ʵ����ݲ�ͬ
	d2.Print();
	//��ͬ�Ķ��󣬵���ͬһ������������������ʵ����ݲ�ͬ��
	//����󣬱��������ڵ��ô�������ö���ĵ�ַ
	/*d1.Print(&d1);
	d2.Print(&d2);*/
}
//Date������ Init �� Print ������Ա������d1��d2���õ���ͬһ��������������û�й��ڲ�ͬ���������
//�ǵ�d1���� Init ����ʱ���ú��������֪��Ӧ������d1���󣬶���������d2�����أ�
//C++��ͨ������thisָ���������⣬����C++��������ÿ�����Ǿ�̬�ĳ�Ա������������һ�����ص�ָ�����
//�ø�ָ��ָ��ǰ����(��������ʱ���øú����Ķ���)���ں����������С���Ա������
//�Ĳ���������ͨ����ָ��ȥ���ʡ�ֻ�������еĲ������û���͸���ģ����û�����Ҫ�����ݣ��������Զ���ɡ�


//˼��thisָ�������� ������  ջ��  ����  ��̬��  ������
//this���βΣ���˺���ͨ�β�һ��������ں�������ʱ��ջ֡�У������ջ��

//thisָ���ں����ڲ���Ҫ�������õ�, vs�ı�������thisָ�봫�������Ż��������ַ����ecx�Ĵ�����
//exc�д洢thisָ���ֵ


//  �Կ�ָ����н�����  ��������ʱ����
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

	//TestThis::Print();	//����д������ͨ��������ú�����thisָ���û�취������
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
	Test_This_1();
	//Test_This_2();
	return 0;
}

//�ײ��ϣ�C��C++��û�������