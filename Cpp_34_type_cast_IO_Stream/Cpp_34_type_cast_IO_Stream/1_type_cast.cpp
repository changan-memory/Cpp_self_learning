#include <iostream>
#include <vector>
#include <string>
using namespace std;

// C�����е�����ת��
// �������ܹ���������ʽ������ת������ʽ����ת������ʽ����ת��
// 1. ��ʽ����ת�����������ڱ���׶��Զ����У���ת��ת������ת�ͱ���ʧ��
// 2. ��ʽ����ת������Ҫ�û��Լ�����
void test1() {
	int i = 1;

	// ���ͼ���������� ����  ��ʽת��
	// ��ʽ����ת��  �������Ƶ����� ���Խ�����ʽ����ת��   int char double size_t
	double d = i;
	printf("%d, %.2f\n", i, d);

	int* p = &i;
	// ��ʾ��ǿ������ת��     ָ�������Ҳ�ܻ���ת��
	int address = (int)p;
	printf("%p, %d\n", p, address);

	/*vector<int> v;
	string s;
	v = (vector<int>) s;*/
}

class A {
public:
	A(int a)
	//explicit A(int a)
		:_a(a)
	{ cout << "�������Ĺ��캯��֧����ʽ����ת��\n" << endl; }
private:
	int _a;
};
// �������Ĺ��캯��֧����ʽ����ת��
void test2() {
	int x = 10;
	A a1 = x;	// ���ι���
	A a2(x);
}
// �Զ�������֮��Ļ���ת��
class B {
public:
	B(const A& a)
	{ cout << "�Զ������ͼ���ĳ�ֹ���ʱ��Ҳ���Ի���ת����ȡ����������\n" << endl; }
private:
};
void test3() {
	int x = 10;
	A a1(x);

	B b1(a1);
	B b2 = a1;
}
// int �� size_t ��ʽ����ת���Ŀ�
// ������ʵ�� vector �� insert ��ʱ�� int �� size_t ��ʽ����ת���Ŀ�
void test4() {

}


//
void test5() {
	const int N = 10;	// N ���ǳ����� N�г�����
	int n = 20;

	int arr1[N];	// N�����Ǳ�������ΪN���Լ�ӱ��޸�
	//int arr2[n];	// n �Ǳ��������ܶ���䳤����
}

// ����ת���Ŀӣ�������ȥ�� const ���ԣ���Σ�յ�
void test6() {
	const int N = 10;	// N ���ǳ����� N�г�����

	int* p = (int*)&N;
	(*p)++;
	cout << N << " " << *p << endl;
}
// const ���ֵ� �������������


// C++�е�����ת�� static_cast
void test11() {
	double d = 13.94;
	int x = static_cast<int> (d);
	cout << x << endl;

	int* p = &x;
	//int address = static_cast<int> (p);
}

// C++�е�����ת�� reinterpret_cast
void test12() {
	int x = 10;
	int* p = &x;
	
	// ��������͵�ת��
	int address = reinterpret_cast<int> (p);
	cout << x << endl;
	cout << p << endl;
	cout << address << endl;
}

// C++�е�����ת�� const_cast
void test13() {
	// ȥ�� const ��ת��
	volatile const int N = 10;
	// ʹ���� const_cast ,����ת�����з��յģ�����ʹ������Ҫ���� volatile
	int* p = const_cast<int*> (&N);	
	(*p)++;
	cout << *p << " " << N << endl;
}

namespace dynamic {
	// C++�е�����ת�� dynamic_cast
	class A {
	public:
		virtual void f() {}
		int _x = 0;
	};

	class B : public A {
	public:
		int _y = 1;
	};
	void func1(A* pa) {
		//B* pb = (B*)pa;
		B* pb = dynamic_cast<B*>(pa);
		if (pb) {
			cout << "ת���ɹ�" << endl;
			pb->_x++;
			pb->_y++;
		}
		else {
			cout << "ת��ʧ��" << endl;
		}
		
	}
	void func2(A* pa) {
		// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
		B* pb1 = static_cast<B*>(pa);
		B* pb2 = dynamic_cast<B*>(pa);
		cout << "pb1:" << pb1 << endl;
		cout << "pb2:" << pb2 << endl;
	}
	void test14() {
		A a;
		B b;
		func1(&a);
		func1(&b);
	}
	void test15() {
		A a;
		B b;
		func2(&a);
		func2(&b);
	}
}

int main() {
	//test1();
	//test2();
	//test3();

	//test5();
	//test6();

	//test11();
	//test12();
	//test13();

	dynamic::test14();
	//dynamic::test15();
	return 0;
}