#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

class Person {
public:
	//名字可读可写
	string get_name() {
		return _name;
	}
	void set_name(string name) {
		_name = name;
		
	}
	int get_age() {
		return _age;
	}
	void set_idol(string idol) {	//只写状态
		_idol = idol;
	}
private:
	string _name = "张三";	//可读可写
	int _age = 18;	//只读
	string _idol; //只写
};

//int main() {
//	Person p1;
//	cout << p1.get_name() << endl;
//	p1.set_name("李四");
//	cout << p1.get_name() << endl;
//
//	return 0;
//}