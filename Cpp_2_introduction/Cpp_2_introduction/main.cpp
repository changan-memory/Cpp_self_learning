#include <iostream>
using std::cout;
using std::endl;

//缺省参数  基本使用
void Func(int a = 10) {
	cout << a << endl;
}
void Test1() {
	Func();	//默认输出
	Func(1000);
}
// 2.
void Func2(int a = 10, int b = 100, int c = 1000) {
	cout << a << " " << b << " " << c << endl;
}
void Test2() {	//传参时缺省，使用声明或定义时的默认值
	//全缺省参数
	Func2();
	//半缺省参数    缺省参数在  传参时， 必须从左向右传， 编译器是从左向右依次赋值的，因此不能跳着传
	Func2(100000000);
	Func2(20, 200);
	Func2(100, 200, 300);
}
//定义时参数缺省
// 由于编译器传参时是   从右向左 传的， 因此默认值  应该从右开始向左设置
void Func3(int a, int b = 100, int c = 10000) {
	cout << a << " " << b << " " << c << endl;
}
void Test3() {
	//无缺省值的参数    必须传入
	Func3(666);
	Func3(666, 777);
	Func3(666, 777, 888);
}
//总结缺省参数
//1. 半缺省参数必须从右往左依次来给出，不能间隔着给
//2. 缺省参数不能在函数声明和定义中同时出现
//3. 缺省值必须是常量或者全局变量
//4. C语言不支持（编译器不支持）


//半缺省的应用
struct Stack {
	int* base;
	int top;
	int capacity;
};
void StackInit(struct Stack* pst, int defaultCapacity = 4) {
	pst->base = (int*)malloc(sizeof(int) * defaultCapacity);
	if (pst->capacity == NULL) {
		perror("malloc failed");
		return;
	}
	pst->top = 0;
	pst->capacity = defaultCapacity;
}
void Test4() {
	struct Stack st1;
	struct Stack st2;
	//场景1  初始化两个栈， 如果已知需要插入10000个元素， 可以给缺省参数传参， 直接开辟10000个空间
	//避免扩容的损耗
	StackInit(&st1, 100000);
	//场景2 我不知道一共要插入多少个数据， 那就根据缺省值来初始化  随着数据量的增多来扩容
	StackInit(&st2);
}
int main() {
	//Test1();
	//Test2();
	//Test3();
	Test4();
	return 0;
}