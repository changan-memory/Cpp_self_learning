#pragma once
#include <iostream>
//��Ķ���
class Stack {
public:
	void Init(int defaultCapacity = 4);
	//�����ڶ���ĺ�������ֱ�ӽ���������øú�����Ϊ����������
	void Push() {	//���ڶ���ĺ��������ܼӲ��� inline ,���൱�ڼ����� inline 
		//.......
	}
	void Pop() {
		//.......
	}
private:
	int* base;
	int top;
	int capacity;
};