#include <iostream>
#include <string>
using namespace std;


//// 1. �̳еĻ���д�� �� ��Ա�����޶����ͼ̳з�ʽ����� Ĭ�ϼ̳з�ʽ  �õ������� public �̳�
//// 
//// �̳о���Ϊ�˸��ã� ���Ѷ�������ԣ�ͨ���̳еķ�ʽ����ʵ�ִ��븴��
//// ���� Person �ǻ��࣬Ҳ�и��࣬�̳��γɵ��� �� �����࣬���� ����
//class Person {
//public:
//	void Print() {
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected:
//public:
////private:
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};

// ���ַ����޶���  public protected  private
// ��Ӧ�����ּ̳з�ʽ  public protected private

// ��������� class �̳�ʱ��д�̳з�ʽ��Ĭ���� private �̳�
// ��������� struct �̳�ʱ��д�̳з�ʽ��Ĭ���� public �̳�
//class Student1 : public Person {
////class Student1 : Person {
//
//public:
//	// �����˽�г�Ա������ ���м̳з�ʽ ���޷�����
//	void func() {
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	int _stuid = 0;
//};
//
//
//class Student : public Person {
//protected:
////public:
//	int _stuid = 1;
//};
//class Teacher : public Person {
//protected:
//	int _jobid = 2;
//};
//// һ�㶼ʹ�� public �̳�

////int main() {
////	Student s;
////	Teacher t;
////	s.Print();
////	t.Print();
////	return 0;
////}

//// 2. ����� ������ ���� ��ֵת��
//void test1() {
//	Person p;
//	Student s;
//  int i = 0;
//  double d = i;
//	// ��ͬ����֮��ĸ�ֵ�����ᷢ�� �� ��ʱ����ת�� 
//	// ��������� ��ֵ��û�з�����ʽ����ת��
//	// ����ᷢ����ֵ����(Ҳ���и��Ƭ)������ ��ֵ�Ĺ��̲�������ʱ����
//	// �и� ���������� ���� ���ǲ��֣�����������
//	p = s;		// ���� ���Ը����ำֵ �����಻�ܸ����ำֵ
//	//s = p;
//
//	// ��������ำֵ������Ϊ����ת��
//}
//// ֤�� ���� ������ ��ֵʱ����������ʱ����
//void test2() {
//	int i = 0;
//	//double d = i;	// ��ʽ����ת�����Ϸ�
//	//double& d = i;	// ��ʽ����ת�����м�������ʱ������ʱ������г��� ��Ҫ���� const 
//	const double& d = i;	// ��Ҫ���� const 
//	Student stu;		// ��Ƭ
//	Person& rp = stu;	// ����� rp �� �����и������һ���ֵı���
//	// ���� ���� ��ֵ�� ����Ķ���/����/ָ��
//	Person* ptr_p = &stu;	// ����� ָ�� ָ�� �����и������һ����
//
//	rp._name = "����";
//	ptr_p->_name = "����";
//}



// 2. ������������е�����������
// ֻҪ�� ��ͬ�������� �Ϳ�����ͬ���ĳ�Ա��ͬ���ĺ���
class Person {
public:
	void func() {
		cout << "Person:func()" << endl;
	}
protected:
	string _name = "С����";
	int _num = 111;	//���֤��
};

// ����/�ض��� �ĸ���: ������͸�����ͬ���ĳ�Աʱ������ĳ�Ա�����˸���ĳ�Ա
// ���صĳ�Ա ������Ա�����ͳ�Ա����
// ʵ���У������� ����͸���дͬ���ĳ�Ա���� �� ��Ա����
// ����͸����е� ͬ������Ҳ����ͬʱ���ڣ���ָ������ʱ�����ȷ�������ĳ�Ա����
// ���ҵ�˳��  �����ֲ��� > ������ > ������ > ȫ����
// ����˵�������أ�ֻ�����������ظ���ģ����಻�ܵ��õ�����ĺ��������ܷ�������ĳ�Ա����
class Student : public Person {
public:
	void func() {
		cout << "student:func()" << endl;
	}
	void print() {
		int _num = 0;	
		cout << "����: " << _name << endl;
		cout << "������: " << _num << endl;	// �����ֲ�����
		cout << "������: " << Student::_num << endl;	// ����� _num
		// �����ҵ�˳�� �����ֲ��� ������ ������ ȫ����
		cout << "������: " << Person::_num << endl;	
	}
protected:
	int _num = 999;		// ѧ��
};
void test3() {
	Student s;
	s.print();
	s.func();	// �����д���func����ʱ�����������е�,������ø����е� û�еĻ�������ȫ�ֵģ�
				// ��û�еĻ�������
	s.Person::func();	// ָ�����򣬵��ø����е�func����
}

namespace question {
	// ����func��������ʲô��ϵ
	// a. ����/�ض���  b. ����    c.��д/����    d.���뱨��
	// �� a (���������У���Ա��������ͬ���͹�������)
	// ���������أ���Ϊ������ͬһ������
	// �������أ����������У���Ա�������㺯������ͬ�͹�������
	// ��ò�Ҫ�ڼ̳���ϵ�У�����ͬ����Ա
	class Person {
	public:
		void func() {
			cout << "Person:func()" << endl;
		}
	};
	class Student : public Person {
	public:
		void func(int i) {
			cout << "student:func()" << endl;
		}
	};
	void test1() {
		Student s;
		//s.func();//�����д��ڸú��� ������Ҫ���� ������Ĭ�����������в��� �������ʱ������ ����
		s.func(1);	// ���κ󲻱���
		s.Person::func();	// �ֶ�ָ�����������ȷ
	}
}
//int main() {
//	//test2();
//	//test3();
//	//using namespace question;
//	question::test1();
//	return 0;
//}