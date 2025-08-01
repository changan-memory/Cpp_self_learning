#include <iostream>
using namespace std;

// 继承与友元
// 友元关系不能继承
namespace question3 {
	// 友元关系不能继承
	// 友元关系不能继承，也就是说基类的友元函数 不能访问子类私有和保护成员
	class Student;
	class Person {
	public:
		friend void Display(const Person& p, const Student& s);
	protected:
		string _name; // 姓名
	};
	class Student : public Person {
		friend void Display(const Person& p, const Student& s);
	protected:
		int _stuNum; // 学号
	};
	void Display(const Person& p, const Student& s) {
		cout << p._name << endl;
		cout << s._stuNum << endl;
	}
	void test1() {
		question3::Person p;
		question3::Student s;
		question3::Display(p, s);
	}
}

// 静态成员的继承
// 静态成员 同时属于父类和所有的派生类，在派生类中不会单独拷贝一份
// 静态成员，继承的是使用权
// 基类定义了static 静态成员，则整个继承体系里面只有一个这样的成员。
// 无论派生出多少个子类，都只有一个static成员实例

namespace question4 {
	
	class Person {
	public:
		Person() { ++_count; }
		string _name; // 姓名
	public:
		static int _count; // 统计人的个数。
	};
	int Person::_count = 0;

	class Student : public Person {
	protected:
		int _stuNum; // 学号
	};
	class Graduate : public Student {
	protected:
		string _seminarCourse; // 研究科目
	};
	void test1() {
		Person p;	// 两个对象中都有 name , 这两个 name 是两个独立的name
		Student s;
		cout << &p._name << endl;
		cout << &s._name << endl;
		// 静态成员 可以用对象访问，也可以用类名去访问
		cout << &p._count << endl;
		cout << &s._count << endl;
		cout << &Person::_count << endl;
		cout << &Student::_count << endl;
	}
	void test2() {
		// 可以使用 静态成员变量  去统计 这个类创建了多少个类及其派生类的对象
		// 只需要在基类的构造函数中  将count++
		Person p1;
		Person p2;
		Student s1;
		Student s2;
		Graduate g1;
		Graduate g2;
		Graduate g3;
		cout << Person::_count << endl;
		cout << Student::_count << endl;
		cout << Graduate::_count << endl;
	}
}
//int main() {
//	//question3::test1();
//	//question4::test1();
//	question4::test2();
//	return 0;
//}