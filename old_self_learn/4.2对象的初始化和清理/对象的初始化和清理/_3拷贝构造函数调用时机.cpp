//
//#include <iostream>
//using namespace std;
//
//
//class Person {
//public:
//	Person() {
//		cout << "Ĭ�Ϲ��캯������" << endl;
//		this->_age = 0;
//	}
//	Person(int age) {
//		cout << "�вι��캯������" << endl;
//		this->_age = age;
//	}
//	Person(const Person& p) {
//
//		cout << "�������캯������" << endl;
//		this->_age = p._age;
//	}
//	~Person() {
//		cout << "������������" << endl;
//	}
//
//private:
//	int _age;
//};
//
////�������캯���ĵ���ʱ��
//
////1 ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//void test01() {
//	Person p1(20);
//	Person p2(p1);
//}
//
////2 ֵ���ݵķ�ʽ������������ֵ
//
//void dowork(Person p) {
//
//}
//
//void test02() {
//	Person p;
//	dowork(p);
//}
////  ֵ��ʽ���ؾֲ�����
//Person doWork2()
//{
//	Person p1;
//	cout << &p1 << endl;
//	return p1;
//}
//
//void test03()
//{
//	Person p3 = doWork2();
//	cout << (int*)&p3 << endl;
//}
//
//void test04() {
//	test03();
//}
//int main() {
//	//test01();
//	//test02();
//	test04();
//	return 0;
//}