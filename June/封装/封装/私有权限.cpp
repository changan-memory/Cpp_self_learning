#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Person {
public://���� �����ķ���������  ����  ��Ա������ֵ
	//ͨ������ ��Ա���� �Ĺ��������� ��Ա������ �� д  ���� ״̬
	void setName(string name) {
		my_name = name;
	}
	void getName() {
		cout << "������" << my_name << endl;
	}
	void setAge(int age) {
		if (age > 150) {
			cout <<"����Ϊ" << age << "���ô���" << endl;
			return;
		}
		age = age;

	}
	void getAge() {
		cout << "���ѧ��Ϊ" << id << endl;
	}
	void setId(int id) {
		id = id;
	}
	int getId() {
		return id;
	}
private://һ�㽫��Ա��������˽�л�  
	string my_name = "������";
	int age = 18;
	int id = 2023;
};
//int main()
//{
//	Person p1;
//	p1.getName();
//	p1.getAge();
//	p1.getId();
//	p1.setName("Ѧ֮ǫ");
//	p1.getName();
//	system("pause");
//	return 0;
//}