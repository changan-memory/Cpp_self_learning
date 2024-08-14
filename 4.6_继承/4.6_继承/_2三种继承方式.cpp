#include <iostream>
using namespace std;
//三种继承
// 1. 类内要访问
//		看父类的权限  只能访问 父类中 非 private 的属性

// 2. 类外要访问
// 看类内属性的权限  对应的访问权限


class Base {
public:
	int _A;
protected:
	int _B;
private:
	int _C;
};

class son_1 : public Base {
public:
	void func() {
		//公共继承 
		this->_A = 100;		//父类中的公共权限成员  到子类中 依然是公共权限
		this->_B = 100;		// 父类中的保护权限成员  到子类中 依然是保护权限
		// this->_C = 10;	// 父类中的私有权限成员   子类访问不到
	}
};

class son_2 : protected Base {
public:
	void func() {
		this->_A = 100;
		this->_B = 1000;
		//this->_C = 100;   //父亲的私有权限内容不可访问
	}
};

class son_3 : private Base {
public: 
	void func() {
		this->_B = 100;
		this->_A = 10;
	}
};
void test_1() {
	son_1 s1;
	s1._A = 100;	
	//继承过来的  _B 为保护权限 类外不可访问
}






int main() {


	return 0;
}