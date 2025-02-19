#include <iostream>
using namespace std;

void Test_new(){
	//C
	int* p1 = (int*)malloc(sizeof(int));
	free(p1);
	//Cpp
	int* p2 = new int;
	delete p2;

	//开 10个int的 数组
	//C
	int* p3 = (int*)malloc(sizeof(int) * 10);
	//Cpp	申请存放10个int的一块空间
	int* p4 = new int[10];	//数组不能初始化
	delete[] p4;
	//申请一个 int ,初始化为 10
	int* p5 = new int(10);
	delete p5;
	// new 数组时初始化
	int* p6 = new int[10] {1, 2, 3};
	delete[] p6;
}

int main() {
	
	Test_new();
	return 0;
}