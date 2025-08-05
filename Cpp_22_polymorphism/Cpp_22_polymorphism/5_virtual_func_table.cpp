#include <iostream>
using namespace std;
namespace question4 {
	//���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�
	class Base {
	public:
		// ��ʵ�ֶ�̬ʱ����Ҫ������û��Ҫ�ĺ�������Ϊvirtual
		// ��Ϊ����ֻҪ���麯�������ڶ���ά��һ���麯����
		// ���д�������麯���ĵ�ַ
		// �麯�������Ǵ���ڴ����
		virtual void Func1() {
			cout << "Func1()" << endl;
		}
		virtual void Func2() {
			cout << "Func2()" << endl;
		}
		void Func3() {
			cout << "Func3()" << endl;
		}
	private:
		int _b = 1;
	};
	void test() {
		cout << sizeof(Base) << endl;	// ���Ϊ8
		Base b1;
	}
}

namespace question5 {
	class Person {
	public:
		virtual void BuyTicket() { cout << "��Ʊ����ȫ��" << endl; }
		int _a = 1;
	};
	class Student : public Person {
	public:
		virtual void BuyTicket() { cout << "��Ʊ�������" << endl; }
		int _b = 2;
	};
	void Func(Person& p) {
		// ��̬����  ����ʱ��ָ�������麯�������ҵ��ú����ĵ�ַ
		p.BuyTicket();
	}
	void test() {
		// ���ʵ�� ָ���������  ָ�����������
		// Person& p
		// �� p��˵�������࣬�ͽ��ܸ���  �����࣬��������Ƭ����ָ��
		// ��p��˵�������Ķ��Ǹ���
		// ��ͨ���ã��ڱ���ʱȷ�������ĵ�ַ
		// ��̬����  ����ʱ��ָ�������麯�������ҵ��ú����ĵ�ַ
		Person Mike;
		Func(Mike);
		Student Johnson;
		Func(Johnson);
	}
}

namespace question6 {
	class A {
	public:
		virtual void func(int val = 1) { 
			std::cout << "A->" << val << std::endl; 
		}
		virtual void test() { func(); }
	};
	class B : public A {
	public:
		void func(int val = 0) { std::cout << "B->" << val << std::endl; }
	};
	void ques() {
		B* p = new B;
		p->test();
		return;
	}
}
int main() {
	//question4::test();
	//question5::test();
	question6::ques();
	return 0;
}