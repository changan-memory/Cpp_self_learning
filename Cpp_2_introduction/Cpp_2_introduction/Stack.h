#pragma once
#include <iostream>
struct Stack {
	int* base;
	int top;
	int capacity;
};
//���������� �Ͷ�����  Ĭ�ϲ�������ͬʱ���֣���ʹһ��Ҳ������
// �������ˣ����岻�ܸ�
void StackInit(struct Stack* pst, int defaultCapacity = 4);
void StackPush(struct Stack* pst, int x);
void StackPush(struct Stack* pst, double y);