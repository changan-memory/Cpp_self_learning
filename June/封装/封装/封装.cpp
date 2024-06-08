#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
#define PI 3.14159
//class Circle {
//public:
//	//属性
//	int r;
//	//行为
//	double cal_long() {
//		return 2 * PI * r;
//	}
//};
class Stu {//类中的属性和行为，统一称为成员

public://属性  也称为成员属性   成员变量
	string m_name;
	long m_id;
	/*void fuzhi(){
		cout << "请输入姓名" << endl;
		cin >> name;
		cout << "请输入学号" << endl;
		cin >> id;
	}
	void print(){
		cout << "姓名为 " << name << endl;
		cout << "学号为 " << id << endl;
	}*/
	//类中的行为  也叫成员函数  成员方法
	void setname(string name) {
		m_name = name;
	}
	void setid(long id) {
		m_id = id;
	}//可以通过成员方法给成员变量赋值
	void showstu() {
		cout << "姓名为 " << m_name << endl;
		cout << "学号为 " << m_id << endl;
	}
};
//int main(){
//
//	/*Stu s;
//	s.fuzhi();
//	s.print();*/
//	Stu s1;
//	s1.setname("秦宇翔");
//	s1.setid(2023);
//	s1.showstu();
//	system("pause");
//	return 0;
//}