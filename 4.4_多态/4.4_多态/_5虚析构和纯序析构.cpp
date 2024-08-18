//
//#include <iostream>
//#include <string>	//string是一个类
//using namespace std;
//
////虚析构和纯虚析构
////多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
////虚析构和纯虚析构 是为了解决父类指针在释放时无法调用到子类的析构代码
////可以把父类中的析构函数写为虚析构  
//
//
//
//
//class Animal {
//public:
//	Animal() {
//		cout << "Animal 构造函数调用" << endl;
//	}
//	virtual void speak() {
//		cout << "动物在说话" << endl;
//	}
//
//	virtual ~Animal() {
//		cout << "Animal 析构函数调用" << endl;
//	}
//};
//
//class Cat :public Animal {
//public:
//	Cat(string name) {
//		cout << "Cat构造函数调用" << endl;
//		this->_name = new string(name);
//	}
//	virtual void speak() {
//		cout << *this->_name<<"小猫在说话" << endl;
//	}
//	~Cat() {
//		if (this->_name != nullptr) {
//			cout << "Cat的析构函数调用" << endl;
//			delete this->_name;
//			this->_name = nullptr;
//		}
//			
//	}
//	string* _name;
//};
//
//void test1() {
//	Animal* ani = new Cat("Tom");
//	ani->speak();
//	delete ani;
//}
//
//
//
//int main() {
//
//	test1();
//	system("pause");
//	return 0;
//}