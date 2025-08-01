#include <iostream>
using namespace std;

// �̳�����Ԫ
// ��Ԫ��ϵ���ܼ̳�
namespace question3 {
	// ��Ԫ��ϵ���ܼ̳�
	// ��Ԫ��ϵ���ܼ̳У�Ҳ����˵�������Ԫ���� ���ܷ�������˽�кͱ�����Ա
	class Student;
	class Person {
	public:
		friend void Display(const Person& p, const Student& s);
	protected:
		string _name; // ����
	};
	class Student : public Person {
		friend void Display(const Person& p, const Student& s);
	protected:
		int _stuNum; // ѧ��
	};
	void Display(const Person& p, const Student& s) {
		cout << p._name << endl;
		cout << s._stuNum << endl;
	}
	void test1() {
		question3::Person p;
		question3::Student s;
		question3::Display(p, s);
	}
}

// ��̬��Ա�ļ̳�
// ��̬��Ա ͬʱ���ڸ�������е������࣬���������в��ᵥ������һ��
// ��̬��Ա���̳е���ʹ��Ȩ
// ���ඨ����static ��̬��Ա���������̳���ϵ����ֻ��һ�������ĳ�Ա��
// �������������ٸ����࣬��ֻ��һ��static��Աʵ��

namespace question4 {
	
	class Person {
	public:
		Person() { ++_count; }
		string _name; // ����
	public:
		static int _count; // ͳ���˵ĸ�����
	};
	int Person::_count = 0;

	class Student : public Person {
	protected:
		int _stuNum; // ѧ��
	};
	class Graduate : public Student {
	protected:
		string _seminarCourse; // �о���Ŀ
	};
	void test1() {
		Person p;	// ���������ж��� name , ������ name ������������name
		Student s;
		cout << &p._name << endl;
		cout << &s._name << endl;
		// ��̬��Ա �����ö�����ʣ�Ҳ����������ȥ����
		cout << &p._count << endl;
		cout << &s._count << endl;
		cout << &Person::_count << endl;
		cout << &Student::_count << endl;
	}
	void test2() {
		// ����ʹ�� ��̬��Ա����  ȥͳ�� ����ഴ���˶��ٸ��༰��������Ķ���
		// ֻ��Ҫ�ڻ���Ĺ��캯����  ��count++
		Person p1;
		Person p2;
		Student s1;
		Student s2;
		Graduate g1;
		Graduate g2;
		Graduate g3;
		cout << Person::_count << endl;
		cout << Student::_count << endl;
		cout << Graduate::_count << endl;
	}
}
//int main() {
//	//question3::test1();
//	//question4::test1();
//	question4::test2();
//	return 0;
//}