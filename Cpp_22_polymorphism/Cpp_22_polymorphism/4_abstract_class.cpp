#include <iostream>
using namespace std;

//���麯���ĺ���д�� = 0 �����������Ϊ���麯�����������麯��������������ࣨҲ�нӿ��ࣩ
// �����಻��ʵ����������������̳к�Ҳ����ʵ����������
// ������ Ԣ�� ���������ʵ������û�ж�Ӧ��ʵ��
// ֻ����д���麯�������������ʵ����������
// ���麯���淶�������������д�����ⴿ�麯�������ֳ��˽ӿڼ̳�

//���麯���淶�������������д
// ���麯���൱�ڴӻ������涨�����������д�麯��
class Car {
public:
	virtual void Drive() = 0;
};
class Benz : public Car{
public:
	virtual void Drive() override {
		cout << "Benz--����" << endl;
	}
};
class BMW : public Car {
public:
	virtual void Drive() override {
		cout << "BMW--�ٿ�" << endl;
	}
};
void Func(Car* car) {
	car->Drive();
}
int main() {
	Func(new Benz);
	Func(new BMW);
	return 0;
}