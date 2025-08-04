#include <iostream>
#include <string>

using namespace std;
class Person {
protected:
	string _name; // ����
public:
	// �����Ĭ�Ϲ���
	Person(const char* name = "peter")
	//Person(const char* name)
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
// ƽʱֻ��public�̳�
class Student : public Person {
public:
	Student(const char* name = "����", int id = 0)
		:_id(id)
		,Person(name)
	{ }
	Student(const Student& s)
		:Person(s)
		,_id(s._id)
	{}
	Student& operator=(const Student& stu) {
		if (this != &stu) {
			Person::operator=(stu);
			//operator=(stu);
		}
		return *this;
	}
	~Student() {
		// ���ں����̬��Ƶ�ԭ�����ุ�������������ĺ����������⴦����
		// �������������ֱ�ͳһ�������destructor
		// ���ڸ������к���ͬ������˴��������أ����ʸ��������������Ҫָ��������
		//Person::~Person();
	}
protected:
	int _id; //ѧ��
};

int main() {
	Student s;
	Student s1(s);
	Student s2("����", 1);
	s = s2;
	return 0;
}