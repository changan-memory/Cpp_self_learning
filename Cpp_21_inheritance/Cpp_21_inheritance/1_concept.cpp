#include <iostream>
#include <string>
using namespace std;


// 1. �̳еĻ���д�� �� ��Ա�����޶����ͼ̳з�ʽ����� Ĭ�ϼ̳з�ʽ  �õ������� public �̳�
// 
// �̳о���Ϊ�˸��ã� ���Ѷ�������ԣ�ͨ���̳еķ�ʽ����ʵ�ִ��븴��
// ���� Person �ǻ��࣬Ҳ�и��࣬�̳��γɵ��� �� �����࣬���� ����
class Person {
public:
	void Print() {
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
//private:
	string _name = "peter"; // ����
	int _age = 18; // ����
};

// ���ַ����޶���  public protected  private
// ��Ӧ�����ּ̳з�ʽ  public protected private

// ��������� class �̳�ʱ��д�̳з�ʽ��Ĭ���� private �̳�
// ��������� struct �̳�ʱ��д�̳з�ʽ��Ĭ���� public �̳�
//class Student1 : public Person {
class Student1 : Person {

public:
	// �����˽�г�Ա������ ���м̳з�ʽ ���޷�����
	void func() {
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	int _stuid = 0;
};


class Student : public Person {
protected:
	int _stuid = 1;
};
class Teacher : public Person {
protected:
	int _jobid = 2;
};
// һ�㶼ʹ�� public �̳�


//int main() {
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//	return 0;
//}

// 2. ����� ������ ���� ��ֵת��
int main() {
	Person p;
	Student s;
	// ��ͬ����֮��ĸ�ֵ�����ᷢ�� �� ��ʱ����ת�� 
	// ��������� ��ֵ������ᷢ����ֵ����(Ҳ���и��Ƭ)������ ��ֵ�Ĺ��̲�������ʱ����
	p = s;		// ���� ���Ը����ำֵ �����಻�ܸ����ำֵ
	//s = p;
}