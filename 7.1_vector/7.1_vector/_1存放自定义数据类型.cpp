//#include <iostream>
//using namespace std;
//#include <vector>
//#include <string>
//
//class Person {
//public:
//	Person(string name, int age) {
//		this->name = name;
//		this->age = age;
//	}
//
//public:
//	string	name;
//	int age;
// };
//
//void test1() {
//	vector<Person> v1;
//	Person p1("����", 15);
//	Person p2("����", 16);
//	Person p3("����", 17);
//	Person p4("����", 18);
//	Person p5("����", 19);
//
//	v1.push_back(p1);
//	v1.push_back(p2);
//	v1.push_back(p3);
//	v1.push_back(p4);
//	v1.push_back(p5);
//
//	for (vector<Person>::iterator temp = v1.begin(); temp != v1.end(); temp++)
//		cout << (*temp).name << " " << (*temp).age << endl;
//}
//
//void test2() {
//	vector<Person*> v1;
//	Person p1("����", 15);
//	Person p2("����", 16);
//	Person p3("����", 17);
//	Person p4("����", 18);
//	Person p5("����", 19);
//
//	v1.push_back(&p1);
//	v1.push_back(&p2);
//	v1.push_back(&p3);
//	v1.push_back(&p4);
//	v1.push_back(&p5);
//
//	for (vector<Person*>::iterator temp = v1.begin(); temp != v1.end(); ++temp)
//		cout << (*temp)->name << " " << (*temp)->age << endl;
//}
//
//// �Ե����������ã� �õ�������Ӧ <> �е���������
//int main() {
//
//	//test1();
//	test2();
//
//	system("pause");
//	return 0;
//}