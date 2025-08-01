#include <iostream>
using namespace std;

namespace question2 {
	class Person {
	protected:
		string _name; // ����
	public:
		Person(const char* name = "peter")
			: _name(name)
		{
			cout << "Person()" << endl;
		}
		Person(const Person& p)	// ������� ���� ��ֵ�� ���������
			: _name(p._name)
		{
			cout << "Person(const Person& p)" << endl;
		}
		Person& operator=(const Person& p) {
			cout << "Person operator=(const Person& p)" << endl;
			if (this != &p)
				_name = p._name;
			return *this;
		}
		~Person() {
			cout << "~Person()" << endl;
		}
	};
	class Student : public Person {
	public:
		// 1. ���캯��
		// ���ø���Ĺ��캯�� ���ڳ�ʼ���б���õ�
		// ������ �������и�����ǲ��ֳ�Ա��������һ���Զ��������ڴ���
		// �Զ������ͳ�ʼ��������Ĭ�Ϲ��캯��
		// ������ֻ�ܳ�ʼ���Լ����ǲ��ֳ�Ա�������еĸ�����ǲ��ֳ�Ա����������Ĺ��캯������
		// �������û��Ĭ�Ϲ��캯����������������๹�캯���ĳ�ʼ���б�׶���ʽ����
		Student(const char* name = "����", int id = 0)
			: Person(name)	// �ֶ���ʼ�������ǲ��ֳ�Ա���﷨�������ڹ���һ��������������ʼ��
			, _id(id)		// �����ʼ���б��˳��� ������˳��(��ʼ����˳��)����һ��
			//,_name(name)	// ������ʽ �ڳ�ʼ���б��� 
		{
			// �����ʼ���б��г��ֵ�˳��ͳ�ʼ��˳���޹�
			// ��ʼ���б��У��ǰ��ճ�Ա������˳���ʼ���ģ��̳е��࣬�൱���������˻��࣬
			// ����ȳ�ʼ��Person �� �ٳ�ʼ������ĳ�Ա���� _id  
		}

		// 2. �������캯��
		Student(const Student& stu)
			// �����ֶ���ʼ������ĳ�Ա������Ҫ���ø���Ŀ������캯��
			:Person(stu)	// ������� ���� ���� ���������   ��ʽ���ÿ�������
			,_id(stu._id)
			// ������ֶ�д����Ŀ������죬�����Ĭ�Ϲ��죬û��Ĭ�Ϲ��죬�ᱨ��
		{ }
		// 3. �������operator=����Ҫ���û����operator=��ɻ���ĸ���
		// ��Ҫ���ִ�д��
		Student& operator=(const Student& stu) {
			if (this != &stu) {
				Person::operator=(stu);
				//Person& operator=(const Person & p)  p������������и������һ����
				_id = stu._id;
			}
			return *this;
		}
	protected:
		int _id; //ѧ��
	};
}
int main() {
	question2::Student s;
	question2::Student s1(s);

	return 0;
}