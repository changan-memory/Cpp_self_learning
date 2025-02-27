#include <iostream>
using namespace std;
#include <assert.h>

void Test_new(){
	// 两种方式都是开空间，但不初始化
	// malloc free是函数，new delete 是操作符
	//C
	int* p1 = (int*)malloc(sizeof(int));
	free(p1);
	//Cpp	// new + 类型
	int* p2 = new int;
	delete p2;

	//开 10个int的 数组
	//C
	int* p3 = (int*)malloc(sizeof(int) * 10);

	//Cpp	申请存放10个int的一块空间
	int* p4 = new int[10];	//数组不能初始化
	delete[] p4;
	//申请一个 int ,初始化为 10
	int* p5 = new int(10);	//圆括号 是初始化
	delete p5;
	// new 数组时初始化
	//int* p6 = new int[10](0);		//数组不能用()来初始化
	int* p6 = new int[10] {1, 2, 3};
	delete[] p6;
}
struct ListNode {
	int _data;
	struct ListNode* _next;
	ListNode(int data = 0)
		:_data(data)
		,_next(nullptr)
	{ }
};
struct ListNode* BuyNode(int data) {
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	//检查
	assert(newNode);
	newNode->_data = data;
	newNode->_next = NULL;
	return newNode;
}
void TestList() {
	//C语言的写法
	struct ListNode* n1 = BuyNode(1);
	struct ListNode* n2 = BuyNode(2);
	struct ListNode* n3 = BuyNode(3);

	//C++的写法，使用new时可以调用构造函数
	struct ListNode* nn1 = new ListNode(1);
	struct ListNode* nn2 = new ListNode(2);
	struct ListNode* nn3 = new ListNode(3);
	return;
}
void Test_new_1() {
	//开一个int
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;

	//申请存放10个int的一块空间
	int* p3 = (int*)malloc(sizeof(int) * 10);
	int* p4 = new int[10];	//int* p4 = new int[10](0);		//数组不能用()来初始化
	//申请一个 int ,初始化为 10
	int* p5 = new int(10);	//圆括号 

	// new 数组时初始化
	int* p6 = new int[10] {1, 2, 3};

	free(p1);
	delete p2;
	free(p3);
	delete[] p4;
	delete p5;
	delete[] p6;
}
//int main() {
//	Test_new_1();
//	return 0;
//}






//class MyClass {
//public:
//	MyClass(int init_value)
//		: _value1(init_value)   // 类中的声明顺序决定初始化顺序
//		, _value2(_value1)  // _value2先声明，会先用 _value1 初始化 _value2
//		// 此时 _value1 还未完成初始化，是随机值
//	{
//	}
//	void Print() const {
//		cout << "_value1: " << _value1
//			<< "  _value2: " << _value2 << endl;
//	}
//private:
//	int _value2;
//	int _value1;
//};
//int main() {
//	MyClass obj(5);
//	obj.Print();  // 输出：_value1: 5  _value2: 随机值
//	return 0;
//}