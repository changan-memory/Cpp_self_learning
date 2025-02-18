#include <iostream>
using namespace std;

//设计一个程序，统计当前正在使用的某个对象有多少个
class A {
public:
	A()
		//:_scount(0)	//静态成员变量 不能用初始化列表 初始化
		//初始化列表只是 对象中的成员变量定义的地方
	{ 
		++_scount;
	}
	A(const A& t) { 
		++_scount;
	}
	~A() { 
		--_scount; 
	}
	void Func1() {
		//非静态成员函数可以调用静态成员函数
		GetACount();
	}
	void Func() {

	}
	//静态成员函数 -- 没有this指针，指定类域和访问限定符就可以访问
	//一般 静态成员变量和静态成员函数是配套出现的
	static int GetACount() {
		//静态成员函数，不能访问类内的非静态成员变量，因为没有this指针(对象的地址)
		// 静态函数不能调用非静态成员函数，非静态成员函数调用需要传递this指针，但static函数没有this指针
		//Func2();
		return _scount;
	}
	int GetACount(int) {
		return _scount;
	}
private:
	// 成员变量 ----- 属于每一个类对象， 存储在对象里面
	int _a1 = 1;	//成员变量给缺省值，会自动走初始化列表
	int _a2 = 2;

	// 静态成员变量 ----- 属于类，类的每个对象共享，存储在静态区, 生命周期是全局的，不能用初始化列表初始化
//public:
	static int _scount;		//此处只是该成员变量的声明
	//类内的静态成员，相当于用类去封装全局变量
};
//全局位置，类外定义   类的 static 成员，类内声明，类外初始化  static 成员定义时不受访问限定符的限制
int A::_scount = 0;

//静态成员函数的妙用
//设计一个类，在类外只能在 栈 上创建对象
//设计一个类，在类外只能在 堆 上创建对象
class Obj {
public:
	//调用这些静态成员函数，需要创建对象(堆区或栈区)，因此我们可以让他们成为静态成员函数
	//通过类作用域限定符来调用函数获取对象
	static Obj GetStackObj() {
		Obj o;
		return o;
	}
	static Obj* GetHeapObj() {
		Obj* o = new Obj;
		return o;
	}
private:
	Obj(){}
private:
	int _a1 = 1;
	int _a2 = 2;
};
int main() {

	//cout << __LINE__ <<" " << A::_scount << endl;	//如果_scount是public的，那么可以通过类作用域限定符来访问
	cout << __LINE__ <<" " << A::GetACount() << endl;	//静态成员通过类域就可以访问

	//这三种方式都会调用构造函数，我们将构造函数私有化后，就无法再类外创建 堆/栈 上的对象了
	/*static OBj o1;
	OBj o2;
	Obj* o3 = new Obj;*/

	//但我们可以提供对外的接口
	Obj obj_1 = Obj::GetStackObj();
	Obj* p_obj = Obj::GetHeapObj();
	return 0;
}
