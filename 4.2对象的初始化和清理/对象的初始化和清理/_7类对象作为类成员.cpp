#include <iostream>
#include <string>
using namespace std;

class Phone {
public:
	string _PName;
	Phone(string name) {
		this->_PName = name;
		cout << "Phone �Ĺ��캯������" << endl;
	}
	~Phone() {
		
		cout << "Phone ��������������" << endl;
	}
};

class Person {
public:
	Person(string name, string pname) :_name(name), _phone(pname){
		cout << "Person �Ĺ��캯������" << endl;
	}
	~Person(){
		cout << "Person ��������������" << endl;
	}


	string _name;
	Phone _phone;

};

void test() {
	Person("����", "ƻ��");
}




int main() {

	test();
	return 0;
}