#pragma once
#include <iostream>
struct Stack {
	int* base;
	int top;
	int capacity;
};
//函数的声明 和定义中  默认参数不能同时出现，即使一样也不可以
// 声明给了，定义不能给
void StackInit(struct Stack* pst, int defaultCapacity = 4);