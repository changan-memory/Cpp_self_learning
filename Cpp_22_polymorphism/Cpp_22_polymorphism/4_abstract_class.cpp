#include <iostream>
using namespace std;

//在虚函数的后面写上 = 0 ，则这个函数为纯虚函数。包含纯虚函数的类叫做抽象类（也叫接口类）
// 抽象类不能实例化出对象。派生类继承后也不能实例化出对象
// 抽象类 寓意 这个类在现实世界中没有对应的实体
// 只有重写纯虚函数，派生类才能实例化出对象。
// 纯虚函数规范了派生类必须重写，另外纯虚函数更体现出了接口继承

//纯虚函数规范了派生类必须重写
// 纯虚函数相当于从基类层面规定派生类必须重写虚函数
class Car {
public:
	virtual void Drive() = 0;
};
class Benz : public Car{
public:
	virtual void Drive() override {
		cout << "Benz--舒适" << endl;
	}
};
class BMW : public Car {
public:
	virtual void Drive() override {
		cout << "BMW--操控" << endl;
	}
};
void Func(Car* car) {
	car->Drive();
}
int main() {
	Func(new Benz);
	Func(new BMW);
	return 0;
}