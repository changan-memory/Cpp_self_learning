#include <iostream>
using namespace std;
//���ּ̳�
// 1. ����Ҫ����
//		�������Ȩ��  ֻ�ܷ��� ������ �� private ������

// 2. ����Ҫ����
// ���������Ե�Ȩ��  ��Ӧ�ķ���Ȩ��


class Base {
public:
	int _A;
protected:
	int _B;
private:
	int _C;
};

class son_1 : public Base {
public:
	void func() {
		//�����̳� 
		this->_A = 100;		//�����еĹ���Ȩ�޳�Ա  �������� ��Ȼ�ǹ���Ȩ��
		this->_B = 100;		// �����еı���Ȩ�޳�Ա  �������� ��Ȼ�Ǳ���Ȩ��
		// this->_C = 10;	// �����е�˽��Ȩ�޳�Ա   ������ʲ���
	}
};

class son_2 : protected Base {
public:
	void func() {
		this->_A = 100;
		this->_B = 1000;
		//this->_C = 100;   //���׵�˽��Ȩ�����ݲ��ɷ���
	}
};

class son_3 : private Base {
public: 
	void func() {
		this->_B = 100;
		this->_A = 10;
	}
};
void test_1() {
	son_1 s1;
	s1._A = 100;	
	//�̳й�����  _B Ϊ����Ȩ�� ���ⲻ�ɷ���
}






int main() {


	return 0;
}