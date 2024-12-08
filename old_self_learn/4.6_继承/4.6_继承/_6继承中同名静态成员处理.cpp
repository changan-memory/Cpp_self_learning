#include <iostream>
using namespace std;

class Base {
public:
	static int _A;
	static void func() {
		cout << "Base ��func����" << endl;
	}
	static void func(int a) {
		cout << "Base ��func (int a )����" << endl;
	}
};

int Base::_A = 100;

class Son :public Base {
public:
	static int _A;
	static void func() {
		cout << "Son ��func����" << endl;
	}
};

int Son::_A = 200;

void test1() {
	//��̬��Ա�����ַ��ʷ���
	//ͨ���������ͬ����̬��Ա
	Son s1;
	cout << s1._A << endl;//son�µ�_A;
	cout << s1.Base::_A << endl;

	//ͨ������������
	cout << Son::_A << endl;
	cout << Base::_A << endl;
	cout << Son::Base::_A << endl;//ͨ�������ķ�ʽ  ���� Base �����µ� _A
	
}

void test2() {
	//ͨ���������
	Son s;
	s.func();	//ֱ�ӵ��õ��õ���������func
	s.Base::func();

	//ͨ����������
	Son::func();
	Base::func();
	Son::Base::func();	//ͨ�������ķ�ʽ ���ʸ����������µĺ���
	Son::Base::func(10);

}

int main() {


	//test1();
	test2();

	return 0;
}