//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//构造函数与析构函数

// 构造函数    用于初始化对象
// 1. 即使没有返回值 也不写 void 
// 2. 构造函数名和类名相同，可以有参数，因此可以发生重载
// 3. 构造函数在对象创建后 系统自动调用，只调用一次

// 析构函数		用于清理对象的数据
// 1. 没有返回值 也不写 void 
// 2. 构造函数名和类名相同，需要再函数名前加上 ~, 不可以发生重载
// 3. 析构函数在对象销毁前  系统自动调用, 只调用一次
//class Person {
//public:
//	Person() {
//		cout << "这是构造函数调用" << endl;
//	}
//	~Person() {
//		cout << "这是析构函数调用" << endl;
//	}
//	 
//};

//void test() {
//	Person p;
//}
//int main() {
//
//	//Person p;
//
//	test();
//	system("pause");
//	return 0;
//}