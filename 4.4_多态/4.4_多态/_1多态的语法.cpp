//#include <iostream>
//using namespace std;
////多态
//// 1 静态多态 
//	// 函数重载和运算符重载 属于静态多态， 复用函数名
//// 2 动态多态
//	// 派生类和虚函数 实现运行时多态
//
////区别
//	// 静态多态的 函数地址早绑定 —— 编译阶段确定函数的地址
//	// 动态多态的 函数地址晚绑定 —— 运行阶段确定函数地址
//class Animal {
//public:
//	//Speak函数就是虚函数
//	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
//	virtual void speak() {
//		cout << "动物在叫" << endl;
//	}
//
//};
//
//class Cat:public Animal {
//	void speak() {
//		cout << "猫在叫" << endl;
//	}
//};
//
//class Dog :public Animal {
//public:
//	void speak() {
//		cout << "小狗在叫" << endl;
//	}
//};
//
//// 动态多态需要满足的条件
//// 1. 有继承关系
//// 2. 子类重写了 父类的虚函数 (重写  函数名相同 形参列表相同 返回值相同 函数体不同)
//
////我们希望传入什么对象，那么就调用什么对象的函数
////如果函数地址在编译阶段就能确定，那么静态联编
////如果函数地址在运行阶段才能确定，就是动态联编
//
//
////动态多态的使用
//// 父类的指针或者引用 指向 子类对象
//void doSpeak(Animal& animal) {		// Animal& animal = cat (这里的cat 是父类的类型) C++中允许父子之间的类型转换
//	animal.speak();		// 当父类的speak函数为虚函数时， speak 函数需要 
//}
//
//void test1() {
//	Cat cat;
//	doSpeak(cat);	//传入dog 或者传入 cat 是想让猫或者狗叫 但其实结果是 animal 在叫
//	Dog dog;
//	doSpeak(dog);
//}
//
//void test2() {
//	cout << sizeof(Animal) << endl;
//}
//int main() {
//
//	test1();
//	test2();
//	system("pause");
//	return 0;
//}