#include <iostream>
#include <string>
using namespace std;
//// 友元不能继承的测试代码
//class Student;
//class Person {
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//// public 继承
//class Student : public Person {
//protected:
//	int _stuNum; // 学号
//};
//// 友元函数
//void Display(const Person& p, const Student& s) {
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//int main() {
//	Person p;
//	Student s;
//	Display(p, s);
//	return 0;
//}

class Person {
public:
    void Print() {
        cout << "name: " << _name << endl;
        cout << "age: " << _age << endl;
    }
protected:
    string _name = "peter";
    int _age = 18;
};

class Student : public Person {
protected:
    int _stuid; // 学号
};

class Teacher : public Person {
protected:
    int _jobid; // 工号
};
int main() {
    Student s;
    Teacher t;
    s.Print();
    t.Print();
    return 0;
}