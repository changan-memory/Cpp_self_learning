#include <iostream>
using namespace std;


class Base1 {
public:
	Base1() {
		this->_A = 100;
	}
	int _A;
};

class Base2 {
public:
	Base2() {
		this->_A = 200;
	}
	int _A;
};
//ʵ�ʿ����в�����ʹ�ö�̳�
//��̳�
// class ����: �̳з�ʽ ����1, �̳з�ʽ ����2
class Son:public Base1, public Base2 {
public:
	
	Son() {
		this->_C = 0;
		this->_D = 0;
	}
	int _C;
	int _D;
};

void test() {
	Son son;
	cout << sizeof(son) << endl;
	//һ������̳ж������ ����������ͬ���ĳ�Ա����ʱ ����ʱ��Ҫ��������
	cout << "Base1 _A  " << son.Base1::_A << endl;
	cout << "Base2 _A  " << son.Base2::_A << endl;
}

int main() {

	test();



	return 0;
}