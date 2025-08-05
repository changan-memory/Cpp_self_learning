#include <iostream>
using namespace std;

// ��̳У�һ����̳��˶����
namespace question6 {
	class Person {
	public:
		string _name; // ����
		int _age;
	};
	class Student : virtual public Person {
	protected:
		int _num; //ѧ��
	};
	class Teacher : virtual public Person {
	protected:
		int _id; // ְ�����
	};
	// ��̳е��﷨
	class Assistant : public Student, public Teacher {
	protected:
		string _majorCourse; // ���޿γ�
	};
	void test1() {
		// �������ж������޷���ȷ֪�����ʵ�����һ��
		Assistant as;
		as._name = "peter"; // ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
		// ��������: �ᵼ���˷ѿռ�   �����Կ���ͨ��������
		as.Student::_name = "xxx";
		as.Teacher::_name = "yyy";
		as.Person::_name = "zzz";
		// ��̳н������Ķ���������
		as._name = "xxx";
		as._name = "yyy";
		as._name = "zzz";
	}
}
// ��̳У��������μ̳�����������
namespace question5 {
	class Person {
	public:
		string _name; // ����
		int _age;
	};
	class Student : virtual public Person {
	protected:
		int _num; //ѧ��
	};
	class Teacher : virtual public Person {
	protected:
		int _id; // ְ�����
	};
	// ��̳е��﷨
	class Assistant : public Student, public Teacher {
	protected:
		string _majorCourse; // ���޿γ�
	};
	void test1() {
		// �������ж������޷���ȷ֪�����ʵ�����һ��
		Assistant as;
		as._name = "peter"; // ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
		// ��������: �ᵼ���˷ѿռ�   �����Կ���ͨ��������
		as.Student::_name = "xxx";
		as.Teacher::_name = "yyy";
		as.Person::_name = "zzz";
		// ��̳н������Ķ���������
		as._name = "xxx";
		as._name = "yyy";
		as._name = "zzz";
	}
}
//class A {
//public:
//	int _a;
//};
//class B :  public A {
//public:
//	int _b;
//};
//// class C : public A
//class C :  public A {
//public:
//	int _c;
//};
//class D : public B, public C {
//public:
//	int _d;
//};
 //̽�� virtual �̳еĵײ�ԭ��
class A {
public:
	int _a;
};
class B : virtual public A {
public:
	int _b;
};
class C : virtual public A {
public:
	int _c;
};
class D : public B, public C {
public:
	int _d;
};
void test_virtual() {
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	d._a = 0;
	D d1;
	d1.B::_a = 1;
	d1.C::_a = 2;
	d1._b = 3;
	d1._c = 4;
	d1._d = 5;
	d1._a = 0;
	return;
}
void test_virtual2() {
	B b;
	D d;
	B* ptr = &b;
	ptr->_a = 1;

	ptr = &d;
	ptr->_a = 2;
}
int main() {
	//question5::test1();
	// ��̳��� ��ν�� ���μ̳е������
	//test_virtual();
	test_virtual2();
	return 0;
}