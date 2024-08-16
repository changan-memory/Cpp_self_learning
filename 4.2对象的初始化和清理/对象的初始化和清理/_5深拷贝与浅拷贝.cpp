//#include <iostream>
//using namespace std;
////深拷贝与浅拷贝
//class Person {
//public:
//	Person() {
//		cout << "Person的无参构造函数调用" << endl;
//		this->_age = 0;
//		this->height = nullptr;
//	}
//	Person(int a, int height) {
//		this->_age = a;
//		this->height = new int(height);
//		cout << "Person的有参构造函数调用" << endl;
//	}
//	//C++构造函数 可以重载
//	
//	//当类中 有堆区的数据时，我们需要自己再写一个深拷贝构造函数 默认构造函数只能浅拷贝
//	//深拷贝  在堆区重新开辟一块内存 来进行拷贝
//	Person(const Person& p) {
//		cout << "Person 的拷贝构造函数调用" << endl;
//		this->_age = p._age;
//		this->height = new int(*p.height);
//	}
//
//	~Person() {
//		//析构函数的作用  通常把在堆区申请的数据释放
//		if (this->height != nullptr) {
//			delete this->height;
//			this->height = nullptr;
//		}
//		cout << "Person的析构函数调用" << endl;
//	}
//	
//	int _age;
//	int* height;
//
//};
//
//void test() {
//	Person p1(10, 20);
//	Person p2(p1);
//	cout << p1._age << endl;
//	cout << p2._age << endl;
//}
//
//
//
//int main() {
//	test();
//	return 0;
//}