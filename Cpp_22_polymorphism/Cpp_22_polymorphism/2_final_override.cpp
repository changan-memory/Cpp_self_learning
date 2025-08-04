#include <iostream>
using namespace std;

namespace use_2 {
	class Car {
	public:
		// 1. final: 一般修饰基类的虚函数，表示该虚函数不能再被重写
		virtual void Drive() final
		{ }
	};
	class Benz :public Car {
	public:
		// 父类中virtual是虚函数，子类继承过来的函数也具有虚函数属性
		// 加了final 就不能重写了
		void Drive(int i) { cout << "Benz-舒适" << endl; }
	};
}

namespace use_3 {
	class Car {
	public:
		// 1. final: 一般修饰基类的虚函数，表示该虚函数不能再被重写
		virtual void Drive()	// final
		{}
	};
	class Benz :public Car {
	public:
		//override : 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错
		void Drive() override  { 
			cout << "Benz-舒适" << endl; 
		}
	};
}


//int main() {
//
//	return 0;
//}