#include <iostream>
#include <string>
using namespace std;

class Phone {
public:
	string _PName;
	Phone(string name) {
		this->_PName = name;
		cout << "Phone 的构造函数调用" << endl;
	}
	~Phone() {
		
		cout << "Phone 的析构函数调用" << endl;
	}
};

class Person {
public:
	Person(string name, string pname) :_name(name), _phone(pname){
		cout << "Person 的构造函数调用" << endl;
	}
	~Person(){
		cout << "Person 的析构函数调用" << endl;
	}


	string _name;
	Phone _phone;

};

void test() {
	Person("张三", "苹果");
}




int main() {

	test();
	return 0;
}