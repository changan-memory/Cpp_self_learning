#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

class Person {
public:
	//���ֿɶ���д
	string get_name() {
		return _name;
	}
	void set_name(string name) {
		_name = name;
		
	}
	int get_age() {
		return _age;
	}
	void set_idol(string idol) {	//ֻд״̬
		_idol = idol;
	}
private:
	string _name = "����";	//�ɶ���д
	int _age = 18;	//ֻ��
	string _idol; //ֻд
};

//int main() {
//	Person p1;
//	cout << p1.get_name() << endl;
//	p1.set_name("����");
//	cout << p1.get_name() << endl;
//
//	return 0;
//}