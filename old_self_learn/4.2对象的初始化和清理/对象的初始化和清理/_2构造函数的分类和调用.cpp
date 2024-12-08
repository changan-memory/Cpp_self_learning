//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Person {
//public:
//	//默认构造函数
//	Person() {
//		cout << "无参构造函数调用"<<endl; //也叫默认构造函数
//		_age = 0;
//	}
//	// 有参构造函数
//	Person(int a) {
//		cout << "有参构造函数调用" << endl;
//		_age = a;
//	}
//
//	//拷贝构造函数
//	Person(const Person& p) {	//传入不可修改的引用
//		_age = p._age;
//		cout << "拷贝构造函数调用" << endl;
//
//	}
//	//析构函数
//	~Person() {
//		cout << "析构函数调用" << endl;
//	}
////private:
//	int _age;
//};
//
//void test_1() {
//	//1 、 括号法
//	Person p1;  
//	Person p2(10);
//	Person p3(p2);
//	cout << p1._age << endl;
//	cout << p2._age << endl;
//	cout << p3._age << endl;
//	//注意事项
//	//1、调用默认构造的时候 不要加括号
//	//Perspn p1();   该行代码 编译器默认会认为 这是一个函数声明   不会认为是在创建对象
//
//	// 2、 显示法
//	Person p4 = Person(100);
//	Person p5 = Person(p4);
//
//	
//	//Person (p5);   这是匿名对象  特点： 当前行执行结束后，会立即回收掉匿名对象
//	cout << p4._age << endl;
//	cout << p5._age << endl;
//
//	// 注意
//	// 不要用拷贝构造函数初始化匿名对象  
//
//}
//
//int main() {
//
//
//	test_1();
//
//	
//
//	system("pause");
//	return 0;
//}