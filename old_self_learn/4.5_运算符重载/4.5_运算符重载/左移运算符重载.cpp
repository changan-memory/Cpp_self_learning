#include <iostream>
using namespace std;
//左移 运算符重载
class Person {
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	//通常不会利用成员函数重载 << 左移运算符  因为 无法实现 cout<<p  无法实现cout在左侧
	/*void operator<<() {	//因为本质是对象调用成员函数

	}*/
	Person(int a, int b) {
		this->_A = a;
		this->_B = b;
	}
private:

	int _A;
	int _B;
};

//要用 全局函数重载 <<  运算符		
//将 该全局函数 设置为 类的友元， 可以实现访问类内的私有成员
ostream& operator<<(ostream& cout, Person& p) {
	cout << p._A << " " << p._B << endl;
	return cout;
}

void test1() {
	Person p1(10, 20);//成员变量设置为私有 后，无法再外部进行赋值, 使用构造函数进行赋值
	

	//cout << p1._A << endl;
	cout << p1 << endl;
}



int main() {

	test1();


	return 0;
}