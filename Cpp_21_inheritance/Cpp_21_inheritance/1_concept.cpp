#include <iostream>
#include <string>
using namespace std;

// �̳о���Ϊ�˸��ã� ���Ѷ�������ԣ�ͨ���̳еķ�ʽ����ʵ�ִ��븴��
// ���� Person �ǻ��࣬Ҳ�и��࣬�̳��γɵ��� �� �����࣬���� ����
class Person {
public:
	void Print() {
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter"; // ����
	int _age = 18; // ����
};

// ���ַ����޶���  public protected  private
// ��Ӧ�����ּ̳з�ʽ  public protected private
class Student1 :  Person {	
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


int main(){
	Student s;
	Teacher t;
	s.Print();
	t.Print();
	return 0;
}