
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Building {
	//全局函数  做 类的 友元
	//该行代码的意思是  声明一个全局函数为 该类的友元 
	// 类的友元  可以访问 类的私有属性
	friend void Good_Gay(Building& B);
public:
	Building() {
		this->_bedroom = "卧室";
		this->_living_room = "客厅";
	}
public:
	string _living_room;

private:
	string _bedroom;
};

void Good_Gay(Building& B) {
	cout << "好基友正在访问 ： " << B._living_room << endl;
	cout << "好基友正在访问 ： " << B._bedroom << endl;
}


int main() {
	Building B;
	Good_Gay(B);

	return 0;
}



