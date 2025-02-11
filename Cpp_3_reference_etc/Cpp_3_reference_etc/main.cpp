#include<iostream>
#include <assert.h>
using std::endl;
using std::cout;
using std::cin;

//1. 引用 从语法的概念来说，引用 就是 给一个变量起别名
void Test1() {
	int a = 666;
	int num = 100;
	int& b = a;
	int& c = b;
	int& d = c;
	//int& e;		//引用必须初始化
	cout << d << endl;
	d = num;	//引用一旦指定，不可修改   所以这里是  赋值， 是把num的值  赋值给  d   
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << &d << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
}
//利用引用，可以避免指针和多级指针
void Swap(int& a, int& b) {	//交换值   形参是实参的别名
	int temp = a;
	a = b;
	b = temp;
}
void Swap(int*& a, int*& b) {	//交换指针   如果不用引用， 交换指针变量需要用二级指针
	int* temp = a;
	a = b;
	b = temp;
}
void Test2() {
	cout << "交换数值" << endl;
	int a = 10, b = 100;
	cout << a << " " << b << endl;
	Swap(a, b);
	cout << a << " " << b << endl;
	cout << "交换指针" << endl;
	int* pa = &a;
	int* pb = &b;
	cout << pa << " " << pb << endl;
	Swap(pa, pb);
	cout << pa << " " << pb << endl;

}
//2. 指针 引用 一节typedef 的联合使用
typedef struct ListNode {
	int data;
	struct ListNode* next;	//C语言必须这么写
	//ListNode* next;		//C++还可以这么写，C++"把结构体升级成了类", 可以直接用类名作为类型
}ListNode, *LinkList;


//将二级指针化为一级指针的引用
void ListPushBack(ListNode* pphead, int data) {

}
//将和typedef联合后的引用
void ListPushBack(LinkList& phead, int data) {

}
// 3. 在语法层面上，引用没有开辟新的空间，只是给原来的空间 起了别名
void Test3() {
	//1. 一个变量可以有多个引用
	int a = 100;
	int& b = a;
	int& c = a;
	int& d = b;	
	//2. 引用在定义时必须初始化
	//int& x;	//该行会报错

	//3. C++中 引用一旦引用一个实体，再不能引用其他实体 (即引用的指向不能改变)
	//java中没有指针， 引用是可以改指向的
	int y = 200;
	b = y;	//此处 对 b 和 d 的操作， 是赋值，而不是修改引用
	d = y;
}

//1. 引用在定义时必须初始化
//2. 一个变量可以有多个引用
//3. 引用一旦引用一个实体，再不能引用其他实体
//  在语法层面上， 我们认为 引用没有开辟新空间， 只是对同一片内存空间取了多个名字

// 4. 引用的使用场景
//_1. 做参数(输出型 参数)  在函数内部，需要改变实参
//_2. 做参数  (提高效率)    (大对象 / 深拷贝的引用 可以极大地提高效率)
//提高效率的例子
#include <time.h>
#define TEST_NUM 10000
struct A { int a[TEST_NUM]; };		//为什么这段代码  把10000 改成1000 会报错
void TestFunc1(A a) {}
void TestFunc2(A& a) {}
void TestRefAndValue(){
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < TEST_NUM; ++i)
		TestFunc1(a);
	size_t end1 = clock();
	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < TEST_NUM; ++i)
		TestFunc2(a);
	size_t end2 = clock();
	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}
//C++的引用无法完全替代指针
//_3 引用做返回值   十分重要
// 引用做返回值， 可以修改返回值
// 是否生成临时变量，取决于函数的 返回值类型
//int Count() {
//	static int n = 10;
//	n++;
//	return n; //n不会直接返回， 而是会生成一个临时变量(小数据是寄存器， 大数据再说)，再返回
//}
int& Count() {	//引用做返回值就不再会生成临时变量了 
	static int n = 10;
	n++;
	return n;
}//返回的是 n 的引用， 好处是，避免了临时对象的拷贝， 提高了效率

int& ResTestReturn() {	//引用做返回值就不再会生成临时变量了 
	int n = 10;
	n++;
	return n;
}//返回的是 n 的引用， 好处是，避免了临时对象的拷贝， 提高了效率

void TestRetRefVal() {
	int& ret = ResTestReturn();	//传递局部对象的引用， 十分危险。
	cout << ret << endl;
	//这里打印Ret的值是不确定的，如果ResTestReturn函数结束，没有清理栈帧，返回的结果侥幸是正确的
	//							 如果ResTestReturn函数结束，清理了栈帧，那么Ret的值是随机值
	printf("ssssssssssssssssssssssssssss\n");	//调用printf函数， 新产生的栈帧覆盖了原来的栈帧
												//再访问ret就产生了随机值
	cout << ret << endl; 
}
//总结
//1. 基本任何场景都可以用引用传参
//2. 引用返回谨慎使用
//        出了作用域， 对象还在，就能用引用返回   对象不在的话，不能用引用返回
// 局部变量不能用引用返回， 
//全局变量 以及  malloc 出来的对象(堆区的对象，在释放之前可以返回引用)

typedef struct SeqList {
	int base[100];
	int size;
	//C++的玩法  C++把结构体升级成了类， 可以在结构内写函数，以及运算符重载等
	int& at(int pos) {
		assert(pos < 100 && pos >= 0);
		return base[pos];
	}
	int& operator[](int pos) {
		assert(pos >= 0 && pos < 100);
		return base[pos];
	}
}SeqList;	//运算符重载配合了引用，使可以直接读写或者操作顺序表

void TestSeqList_CppVersion() {	// C++的玩法
	SeqList s;
	s[0] = 100;		//运算符重载配合了引用，使可以直接读写或者操作顺序表
	cout << s[0] << endl;
	s[0] += 5;
	cout << s[0] << endl;
}

//常引用  
void TestRef() {
	//引用的过程中权限不能放大
	const int a = 10;
	//int& b = a;

	// 可以，c 赋值给d属于拷贝，d改变不影响c的值
	const int c = 100;
	int d = c;
	//引用的过程中， 权限可以平移或者 缩小
	int x = 1000;
	int& y = x;		//权限平移
	const int& z = x;	//权限缩小  权限缩小后,这个变量只是,用 z 这个别名时，不能修改，用别名x依然可以修改
	x++;
	//++z; //会报错

	const int& m = 10;	//常量引用   给常量取别名
	//int& n = 10;	//这样子不行, 是因为10是常量

	double dd = 11;
	int ii = dd;	//会发生隐式类型转换 类型转换会产生临时变量，临时变脸具有常性，只能做右值

	//类型转换会产生临时变量，临时变脸具有常性  
	//int& rii = dd;	//dd 到 int, 发生了类型转换， 本质上， rii是 常临时变量 的引用  这样的写法扩大了权限
	const int& rii = dd;	//加了const后， 权限相同， 因此编译通过
}
//例子
int func1() {	//返回x的拷贝，会产生临时变量
	static int x = 10;
	return x;
}
int& func2() {	//返回x的别名， 不会产生临时变量
	static int x = 10;
	return x;
}
void func3() {
	//int& x = func1();	//权限放大， 不可以进行
	int x1 = func1();	// 仅拷贝
	const int& y = func1();	//权限平移， 可以进行

	int& ret2 = func2();	//可以，权限的平移   
	const int& ret2_ = func2();		//可以，权限的缩小
	//总结，func返回的是一个变量的别名， 
}

//测试类型转换时会产生临时变量
void TestTypeChange() {
	int i = 10;
	double j = 10.11;
	//一般是小的往大的进行类型提升， 提升的时候不能改变原变量，因此只能产生原变量的副本，即临时变量
	if (j > i)	
		cout << "xxxxxxxxxxxxx" << endl;
}
void TestPointerANDRef(){
	int a = 10;
	//在语法层面，引用不开辟空间， 是一片空间的别名
	int& ra = a;
	ra = 1000;
	//语法层面，指针开辟空间， 存放a的地址
	int* p = &a;
	*p = 100;

	//从底层汇编实现的角度看，引用使用类似指针的方式实现的
}
int main() {
	//Test1();
	//Test2();
	//Test3();
	//TestRefAndValue();
	//Count();
	//TestRetRefVal();
	//TestSeqList_CppVersion();
	//TestRef();
	TestTypeChange();	//测试类型转换时会产生临时变量
	//TestPointerANDRef();
	return 0;
}