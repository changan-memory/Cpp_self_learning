#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	Person(string name, int age) {
		this->_age = age;
		this->_name = name;
	}
public:
	string _name;
	int _age;
};



template <typename T>
bool myCompare(T &a, T &b) {	//������Զ����������ͣ�����Ϊ��Щ  �ض�������  �ṩ  ���廯��ģ��
	if (a == b)
		return true;
	return false;
}

//   ����� class ����  �ṩ ���廯ģ�庯��
template<> bool myCompare(Person &p1,  Person &p2) {
	if (p1._age == p2._age && p1._name == p2._name)
		return true;
	return false;
}


void test1() {
	int a = 10;
	int b = 10;
	bool ret = myCompare<int>(a, b);
	if (ret)
		cout << "a == b" << endl;
	else
		cout << "a != b" << endl;
}

void test2() {
	Person p1("Tom", 10);
	Person p2("Tom", 20);
	bool ret = myCompare(p1, p2);
	if (ret)
		cout << "p1 == p2" << endl;
	else
		cout << "p1 != p2" << endl;

}
int main() {

	//test1();
	test2();
	system("pause");
	return 0;
}