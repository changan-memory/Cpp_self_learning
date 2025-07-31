#include <iostream>
#include <string>
using namespace std;


// 1. 继承的基本写法 和 成员访问限定符和继承方式的组合 默认继承方式  用的最多的是 public 继承
// 
// 继承就是为了复用， 将已定义的属性，通过继承的方式，来实现代码复用
// 以下 Person 是基类，也叫父类，继承形成的类 交 派生类，或者 子类
class Person {
public:
	void Print() {
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
//private:
	string _name = "peter"; // 姓名
	int _age = 18; // 年龄
};

// 三种访问限定符  public protected  private
// 对应有三种继承方式  public protected private

// 如果子类是 class 继承时不写继承方式，默认是 private 继承
// 如果子类是 struct 继承时不写继承方式，默认是 public 继承
//class Student1 : public Person {
class Student1 : Person {

public:
	// 父类的私有成员，子类 所有继承方式 都无法访问
	void func() {
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
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


//int main() {
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//	return 0;
//}

// 2. 基类和 派生类 对象 赋值转换
int main() {
	Person p;
	Student s;
	// 不同类型之间的赋值，都会发生 用 临时变量转换 
	// 子类给父类 赋值，这里会发生赋值兼容(也叫切割、切片)，这里 赋值的过程不产生临时对象
	p = s;		// 子类 可以给父类赋值 但父类不能给子类赋值
	//s = p;
}