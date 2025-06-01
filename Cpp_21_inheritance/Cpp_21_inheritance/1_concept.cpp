#include <iostream>
#include <string>
using namespace std;

// 继承就是为了复用， 将已定义的属性，通过继承的方式，来实现代码复用
// 以下 Person 是基类，也叫父类，继承形成的类 交 派生类，或者 子类
class Person {
public:
	void Print() {
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter"; // 姓名
	int _age = 18; // 年龄
};

// 三种访问限定符  public protected  private
// 对应有三种继承方式  public protected private
class Student1 :  Person {	
protected:
	int _stuid = 0;
};
class Student : public Person {
protected:
	int _stuid = 1;
};
class Teacher : public Person {
protected:
	int _jobid = 2;
};
// 一般都使用 public 继承


int main(){
	Student s;
	Teacher t;
	s.Print();
	t.Print();
	return 0;
}