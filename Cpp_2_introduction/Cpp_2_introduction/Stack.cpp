#include "Stack.h"

//函数的声明 和定义中  默认参数不能同时出现，即使一样也不可以
void StackInit(struct Stack* pst, int defaultCapacity) {
	pst->base = (int*)malloc(sizeof(int) * defaultCapacity);
	if (pst->capacity == NULL) {
		perror("malloc failed");
		return;
	}
	pst->top = 0;
	pst->capacity = defaultCapacity;
}

void StackPush(struct Stack* pst, int x) {
	printf("void StackPush(struct Stack* pst, int x)\n");
}
void StackPush(struct Stack* pst, double y) {
	printf("void StackPush(struct Stack* pst, double y)\n");
}