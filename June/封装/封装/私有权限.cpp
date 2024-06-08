#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Person {
public://利用 公开的方法来设置  访问  成员变量的值
	//通过设置 成员方法 的功能来设置 成员变量的 读 写  访问 状态
	void setName(string name) {
		my_name = name;
	}
	void getName() {
		cout << "姓名是" << my_name << endl;
	}
	void setAge(int age) {
		if (age > 150) {
			cout <<"年龄为" << age << "设置错误" << endl;
			return;
		}
		age = age;

	}
	void getAge() {
		cout << "你的学号为" << id << endl;
	}
	void setId(int id) {
		id = id;
	}
	int getId() {
		return id;
	}
private://一般将成员变量设置私有化  
	string my_name = "秦宇翔";
	int age = 18;
	int id = 2023;
};
//int main()
//{
//	Person p1;
//	p1.getName();
//	p1.getAge();
//	p1.getId();
//	p1.setName("薛之谦");
//	p1.getName();
//	system("pause");
//	return 0;
//}