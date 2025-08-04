//#include <iostream>
//#include <string>
//
//using namespace std;
//class Person {
//protected:
//	string _name; // 姓名
//public:
//	// 父类的默认构造
//	Person(const char* name = "peter")
//	//Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)	// 子类对象 可以 赋值给 父类的引用
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p) {
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person() {
//		cout << "~Person()" << endl;
//	}
//};
//// 平时只用public继承
//class Student : public Person {
//public:
//	Student(const char* name = "张三", int id = 0)
//		:_id(id)
//		,Person(name)
//	{ }
//	Student(const Student& s)
//		:Person(s)
//		,_id(s._id)
//	{}
//	Student& operator=(const Student& stu) {
//		if (this != &stu) {
//			Person::operator=(stu);
//			//operator=(stu);
//		}
//		return *this;
//	}
//	~Student() {
//		// 由于后面多态设计的原因，子类父类中析构函数的函数名被特殊处理了
//		// 析构函数的名字被统一处理成立destructor
//		// 由于父子类中函数同名，因此触发了隐藏，访问父类的析构函数需要指定作用域
//		//Person::~Person();
//	}
//protected:
//	int _id; //学号
//};
//
//int main() {
//	Student s;
//	Student s1(s);
//	Student s2("李四", 1);
//	s = s2;
//	return 0;
//}

//// 多态示例
//#include <iostream>
//using namespace std;
//// 多态示例
//class Person {
//public:
//    virtual void BuyTicket() {
//        cout << "成人买票 - 全价" << endl;
//    }
//};
//class Student : public Person {
//public:
//    virtual void BuyTicket() override {
//        cout << "学生买票 - 半价" << endl;
//    }
//};
//void Func(Person& p) {
//    p.BuyTicket(); // 多态发生点
//}
//
//class A {};
//
//class B : public A {};
//// 基类返回对象的指针或引用
//class Base {
//public:
//    virtual Base* create() { return new Base(); }
//};
//// 基类返回对象的指针或引用
//class Derived : public Base {
//public:
//    virtual Derived* create() override { return new Derived(); }
//};
//int main() {
//    Person p;
//    Student s;
//    Func(p);
//    Func(s);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class Person {
//public:
//	string _name; // 姓名
//	int _age;
//};
//class Student : public Person {
//protected:
//	int _num; //学号
//};
//class Teacher : public Person {
//protected:
//	int _id; // 职工编号
//};
//// 多继承的语法
//class Assistant : public Student, public Teacher {
//protected:
//	string _majorCourse; // 主修课程
//};
//int main() {
//	Assistant a;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//class Person {
//public:
//	string _name; // 姓名
//	int _age;
//};
//class Student : virtual public Person {
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person {
//protected:
//	int _id; // 职工编号
//};
//// 多继承的语法
//class Assistant : public Student, public Teacher {
//protected:
//	string _majorCourse; // 主修课程
//};
//int main() {
//	Assistant a;
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//	a._name = "zzz";
//	a.Person::_name = "www";
//	return 0;
//}

//void test1() {
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant as;
//	as._name = "peter"; // 需要显示指定访问哪个父类的成员可以解决二义性问题
//	// 但是数据冗余问题无法解决
//	// 数据冗余: 会导致浪费空间   二义性可以通过类域解决
//	as.Student::_name = "xxx";
//	as.Teacher::_name = "yyy";
//	as.Person::_name = "zzz";
//	// 虚继承解决这里的二义性问题
//	as._name = "xxx";
//	as._name = "yyy";
//	as._name = "zzz";
//}

//#include <iostream>
//using namespace std;
//class Base1 { public: int _b1; }; class Base2 { public: int _b2; };
//class Derive : public Base1, public Base2 { public: int _d; };
//// 对象模型
//// 对象在内存中的排布，谁先继承，谁就在上面排布
//int main() {
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	printf("%p\n", p1);
//	printf("%p\n", p2);
//	printf("%p\n", p3);
//	return 0;
//}
#include <iostream>
using namespace std;
class A {
public:
	A(const char* s) { cout << s << endl; }
	~A() {}
};
class B :virtual public A {
public:
	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};
class C :virtual public A {
public:
	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};
// B C都继承A，A是最先被声明的
class D :public B, public C {	
public:
	D(const char* s1, const char* s2, const char* s3, const char* s4)
		:B(s1, s2)
		,C(s1, s3)
		,A(s1)
	{
		cout << s4 << endl;
	}
};
// D里面只有一份A, A的构造函数只会调用1次
// 菱形虚拟继承，A既不在B也不在C中
int main() {
	D* p = new D("class A", "class B", "class C", "class D");
	//A B C D // 答案
	delete p;
	return 0;
}
