//#include <iostream>
//#include <string>
//
//using namespace std;
//class Person {
//protected:
//	string _name; // ����
//public:
//	// �����Ĭ�Ϲ���
//	Person(const char* name = "peter")
//	//Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)	// ������� ���� ��ֵ�� ���������
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p) {
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person() {
//		cout << "~Person()" << endl;
//	}
//};
//// ƽʱֻ��public�̳�
//class Student : public Person {
//public:
//	Student(const char* name = "����", int id = 0)
//		:_id(id)
//		,Person(name)
//	{ }
//	Student(const Student& s)
//		:Person(s)
//		,_id(s._id)
//	{}
//	Student& operator=(const Student& stu) {
//		if (this != &stu) {
//			Person::operator=(stu);
//			//operator=(stu);
//		}
//		return *this;
//	}
//	~Student() {
//		// ���ں����̬��Ƶ�ԭ�����ุ�������������ĺ����������⴦����
//		// �������������ֱ�ͳһ�������destructor
//		// ���ڸ������к���ͬ������˴��������أ����ʸ��������������Ҫָ��������
//		//Person::~Person();
//	}
//protected:
//	int _id; //ѧ��
//};
//
//int main() {
//	Student s;
//	Student s1(s);
//	Student s2("����", 1);
//	s = s2;
//	return 0;
//}

//// ��̬ʾ��
//#include <iostream>
//using namespace std;
//// ��̬ʾ��
//class Person {
//public:
//    virtual void BuyTicket() {
//        cout << "������Ʊ - ȫ��" << endl;
//    }
//};
//class Student : public Person {
//public:
//    virtual void BuyTicket() override {
//        cout << "ѧ����Ʊ - ���" << endl;
//    }
//};
//void Func(Person& p) {
//    p.BuyTicket(); // ��̬������
//}
//
//class A {};
//
//class B : public A {};
//// ���෵�ض����ָ�������
//class Base {
//public:
//    virtual Base* create() { return new Base(); }
//};
//// ���෵�ض����ָ�������
//class Derived : public Base {
//public:
//    virtual Derived* create() override { return new Derived(); }
//};
//int main() {
//    Person p;
//    Student s;
//    Func(p);
//    Func(s);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Person {
//public:
//	string _name; // ����
//	int _age;
//};
//class Student : public Person {
//protected:
//	int _num; //ѧ��
//};
//class Teacher : public Person {
//protected:
//	int _id; // ְ�����
//};
//// ��̳е��﷨
//class Assistant : public Student, public Teacher {
//protected:
//	string _majorCourse; // ���޿γ�
//};
//int main() {
//	Assistant a;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Person {
//public:
//	string _name; // ����
//	int _age;
//};
//class Student : virtual public Person {
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person {
//protected:
//	int _id; // ְ�����
//};
//// ��̳е��﷨
//class Assistant : public Student, public Teacher {
//protected:
//	string _majorCourse; // ���޿γ�
//};
//int main() {
//	Assistant a;
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//	a._name = "zzz";
//	a.Person::_name = "www";
//	return 0;
//}

//void test1() {
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant as;
//	as._name = "peter"; // ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ������������
//	// �����������������޷����
//	// ��������: �ᵼ���˷ѿռ�   �����Կ���ͨ��������
//	as.Student::_name = "xxx";
//	as.Teacher::_name = "yyy";
//	as.Person::_name = "zzz";
//	// ��̳н������Ķ���������
//	as._name = "xxx";
//	as._name = "yyy";
//	as._name = "zzz";
//}

//#include <iostream>
//using namespace std;
//class Base1 { public: int _b1; }; class Base2 { public: int _b2; };
//class Derive : public Base1, public Base2 { public: int _d; };
//// ����ģ��
//// �������ڴ��е��Ų���˭�ȼ̳У�˭���������Ų�
//int main() {
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	printf("%p\n", p1);
//	printf("%p\n", p2);
//	printf("%p\n", p3);
//	return 0;
//}
#include <iostream>
using namespace std;
class A {
public:
	A(const char* s) { cout << s << endl; }
	~A() {}
};
class B :virtual public A {
public:
	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};
class C :virtual public A {
public:
	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};
// B C���̳�A��A�����ȱ�������
class D :public B, public C {	
public:
	D(const char* s1, const char* s2, const char* s3, const char* s4)
		:B(s1, s2)
		,C(s1, s3)
		,A(s1)
	{
		cout << s4 << endl;
	}
};
// D����ֻ��һ��A, A�Ĺ��캯��ֻ�����1��
// ��������̳У�A�Ȳ���BҲ����C��
int main() {
	D* p = new D("class A", "class B", "class C", "class D");
	//A B C D // ��
	delete p;
	return 0;
}
