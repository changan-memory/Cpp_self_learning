#include <iostream>
using namespace std;

namespace use_1 {
	// ��̬������
	// 0. ���м̳й�ϵ�������������
	// 1. ����ͨ�������ָ��������õ����麯��
	// 2. �����õĺ����������麯���������������Ի�����麯��������д
	class Person {
	public:
		virtual void buyTicket() const {
			cout << "��ͨ����Ʊ��ȫ��" << endl;
		}
	};
	// �麯����д��ϸ��:
	// �麯����д�������� �麯��+��ͬ������һЩ����
	// 1. ��������д�麯�������Բ��� virtual ,���ǽ������virtual
	// 2. ������� Э��  ����ֵ���Բ�ͬ����Ҫ�󷵻�ֵ�����Ǹ��ӹ�ϵ��ָ��/����
			// �����е��麯�����ظ����ָ��/����  �����е��麯�����ظ����ָ��/����
			// ��������� ��Ҫͬʱ����ָ�� ͬʱ�������ã����ܽ���
	class Student : public Person {
	public:
		//void buyTicket() const {
		virtual void buyTicket() const {
			cout << "ѧ����Ʊ�����" << endl;
		}
	};
	// ��̬����ͬ�Ķ��󣬴���ȥ�����ò�ͬ�ĺ���
	// ��̬���ã�����ָ��Ķ�����ͨ������ú���������ǰ��������� 
	
	// ��̬������
	// 0. ���м̳й�ϵ�������������
	// 1. ����ͨ�������ָ��������õ����麯��
	// 2. �����õĺ����������麯���������������Ի�����麯��������д
	// �麯�� �� ��virtual ���ε����Ա�������麯��ֻ���ǳ�Ա��������ͨ�������ܱ�virtual����
	void func(Person& p) {
		p.buyTicket();
	}
	void test1() {
		Person p;
		Student s;
		func(p);
		func(s);
	}
}

// ������������д
// ����������virtual , �㲻���麯����д
// �㣬��Ϊ ������������������������ destructor ���ͳһ������
// ���������ֲ�ͬ��ʵ����ͬ����˹��� ��д
// ΪʲôҪ��ô���� ��ΪҪ�����ǹ�����д   ΪʲôҪ�����ǹ�����д��
namespace use_2 {
	class Person {
	public:
		//virtual ~Person() { cout << "~Person()" << endl; }
		~Person() { cout << "~Person()" << endl; }
	};
	class Student : public Person {
	public:
		//virtual ~Student() { cout << "~Student()" << endl; }
		~Student() { 
			cout << "~Student()" << endl;
			delete[] _ptr;
		}
	protected:
		int* _ptr = new int[10];
	};
	
	void test1() {
		Person p;
		Student s;	// stu �������������� �����е�
	}
	// ����д���������������ĳ���
	void test2() {
		Person* p = new Person;
		delete p;

		p = new Student;
		delete p;
	}
}
int main() {
	//use_1::test1();
	//use_2::test1();
	use_2::test2();
	return 0;
}