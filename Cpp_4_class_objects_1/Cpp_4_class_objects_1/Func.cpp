#include "Func.h"

//类的声明和定义分离，需要在函数名前面，加上类的作用域限定
void Stack:: Init(int defaultCapacity) {	//缺省参数一般在 函数声明 给出
	base = (int*)malloc(sizeof(int) * defaultCapacity);
	capacity = defaultCapacity;
	top = 0;
}