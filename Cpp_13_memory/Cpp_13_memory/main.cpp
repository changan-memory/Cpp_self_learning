#include <iostream>
using namespace std;

void Test_new(){
	//C
	int* p1 = (int*)malloc(sizeof(int));
	free(p1);
	//Cpp
	int* p2 = new int;
	delete p2;

	//�� 10��int�� ����
	//C
	int* p3 = (int*)malloc(sizeof(int) * 10);
	//Cpp	������10��int��һ��ռ�
	int* p4 = new int[10];	//���鲻�ܳ�ʼ��
	delete[] p4;
	//����һ�� int ,��ʼ��Ϊ 10
	int* p5 = new int(10);
	delete p5;
	// new ����ʱ��ʼ��
	int* p6 = new int[10] {1, 2, 3};
	delete[] p6;
}

int main() {
	
	Test_new();
	return 0;
}