#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
#define PI 3.14159
//class Circle {
//public:
//	//����
//	int r;
//	//��Ϊ
//	double cal_long() {
//		return 2 * PI * r;
//	}
//};
class Stu {//���е����Ժ���Ϊ��ͳһ��Ϊ��Ա

public://����  Ҳ��Ϊ��Ա����   ��Ա����
	string m_name;
	long m_id;
	/*void fuzhi(){
		cout << "����������" << endl;
		cin >> name;
		cout << "������ѧ��" << endl;
		cin >> id;
	}
	void print(){
		cout << "����Ϊ " << name << endl;
		cout << "ѧ��Ϊ " << id << endl;
	}*/
	//���е���Ϊ  Ҳ�г�Ա����  ��Ա����
	void setname(string name) {
		m_name = name;
	}
	void setid(long id) {
		m_id = id;
	}//����ͨ����Ա��������Ա������ֵ
	void showstu() {
		cout << "����Ϊ " << m_name << endl;
		cout << "ѧ��Ϊ " << m_id << endl;
	}
};
//int main(){
//
//	/*Stu s;
//	s.fuzhi();
//	s.print();*/
//	Stu s1;
//	s1.setname("������");
//	s1.setid(2023);
//	s1.showstu();
//	system("pause");
//	return 0;
//}