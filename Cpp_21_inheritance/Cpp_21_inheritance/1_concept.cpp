#include <iostream>
#include <string>
using namespace std;


//// 1. 继承的基本写法 和 成员访问限定符和继承方式的组合 默认继承方式  用的最多的是 public 继承
//// 
//// 继承就是为了复用， 将已定义的属性，通过继承的方式，来实现代码复用
//// 以下 Person 是基类，也叫父类，继承形成的类 交 派生类，或者 子类
//class Person {
//public:
//	void Print() {
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
////protected:
//public:
////private:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};

// 三种访问限定符  public protected  private
// 对应有三种继承方式  public protected private

// 如果子类是 class 继承时不写继承方式，默认是 private 继承
// 如果子类是 struct 继承时不写继承方式，默认是 public 继承
//class Student1 : public Person {
////class Student1 : Person {
//
//public:
//	// 父类的私有成员，子类 所有继承方式 都无法访问
//	void func() {
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	int _stuid = 0;
//};
//
//
//class Student : public Person {
//protected:
////public:
//	int _stuid = 1;
//};
//class Teacher : public Person {
//protected:
//	int _jobid = 2;
//};
//// 一般都使用 public 继承

////int main() {
////	Student s;
////	Teacher t;
////	s.Print();
////	t.Print();
////	return 0;
////}

//// 2. 基类和 派生类 对象 赋值转换
//void test1() {
//	Person p;
//	Student s;
//  int i = 0;
//  double d = i;
//	// 不同类型之间的赋值，都会发生 用 临时变量转换 
//	// 子类给父类 赋值，没有发生隐式类型转换
//	// 这里会发生赋值兼容(也叫切割、切片)，这里 赋值的过程不产生临时对象
//	// 切割 ，把子类中 父类 的那部分，拷贝给父类
//	p = s;		// 子类 可以给父类赋值 但父类不能给子类赋值
//	//s = p;
//
//	// 子类给父类赋值，被称为向上转换
//}
//// 证明 子类 给父类 赋值时，不产生临时对象
//void test2() {
//	int i = 0;
//	//double d = i;	// 隐式类型转换，合法
//	//double& d = i;	// 隐式类型转换，中间会产生临时对象，临时对象具有常性 需要加上 const 
//	const double& d = i;	// 需要加上 const 
//	Student stu;		// 切片
//	Person& rp = stu;	// 这里的 rp 是 子类中父类的那一部分的别名
//	// 子类 可以 赋值给 父类的对象/引用/指针
//	Person* ptr_p = &stu;	// 这里的 指针 指向 子类中父类的那一部分
//
//	rp._name = "张三";
//	ptr_p->_name = "李四";
//}



// 2. 基类和派生类中的作用域问题
// 只要在 不同的作用域 就可以有同名的成员和同名的函数
class Person {
public:
	void func() {
		cout << "Person:func()" << endl;
	}
protected:
	string _name = "小李子";
	int _num = 111;	//身份证号
};

// 隐藏/重定义 的概念: 当子类和父类有同名的成员时，子类的成员隐藏了父类的成员
// 隐藏的成员 包括成员变量和成员函数
// 实际中，不建议 子类和父类写同名的成员变量 和 成员函数
// 子类和父类中的 同名函数也可以同时存在，不指明类域时，优先访问子类的成员函数
// 查找的顺序  函数局部域 > 子类域 > 父类域 > 全局域
// 不能说互相隐藏，只能是子类隐藏父类的，父类不能调用的子类的函数、不能访问子类的成员变量
class Student : public Person {
public:
	void func() {
		cout << "student:func()" << endl;
	}
	void print() {
		int _num = 0;	
		cout << "姓名: " << _name << endl;
		cout << "子类编号: " << _num << endl;	// 函数局部优先
		cout << "子类编号: " << Student::_num << endl;	// 子类的 _num
		// 优先找的顺序 函数局部域 子类域 父类域 全局域
		cout << "父类编号: " << Person::_num << endl;	
	}
protected:
	int _num = 999;		// 学号
};
void test3() {
	Student s;
	s.print();
	s.func();	// 子类中存在func函数时，调用子类中的,否则调用父类中的 没有的话，调用全局的，
				// 都没有的话，报错
	s.Person::func();	// 指定类域，调用父类中的func函数
}

namespace question {
	// 两个func函数构成什么关系
	// a. 隐藏/重定义  b. 重载    c.重写/覆盖    d.编译报错
	// 答案 a (父类子类中，成员函数名相同，就构成隐藏)
	// 不构成重载，因为不是在同一作用域
	// 构成隐藏，父类子类中，成员函数满足函数名相同就构成隐藏
	// 最好不要在继承体系中，定义同名成员
	class Person {
	public:
		void func() {
			cout << "Person:func()" << endl;
		}
	};
	class Student : public Person {
	public:
		void func(int i) {
			cout << "student:func()" << endl;
		}
	};
	void test1() {
		Student s;
		//s.func();//子类中存在该函数 但是需要参数 编译器默认先在子类中查找 如果调用时不传参 报错
		s.func(1);	// 传参后不报错
		s.Person::func();	// 手动指定作用域后，正确
	}
}
//int main() {
//	//test2();
//	//test3();
//	//using namespace question;
//	question::test1();
//	return 0;
//}