#include "Func.h"

//��������Ͷ�����룬��Ҫ�ں�����ǰ�棬��������������޶�
void Stack:: Init(int defaultCapacity) {	//ȱʡ����һ���� �������� ����
	base = (int*)malloc(sizeof(int) * defaultCapacity);
	capacity = defaultCapacity;
	top = 0;
}