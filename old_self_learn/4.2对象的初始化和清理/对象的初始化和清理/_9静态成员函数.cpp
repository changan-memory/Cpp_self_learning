#include <iostream>
using namespace std;

//��̬��Ա����
// ���ж��󶼹��� һ������
// ��̬�ĺ���  ֻ�ܷ��� ��̬�ĳ�Ա����

class Person {

public:
	static void func() {	//��̬��Ա�������Է��ʾ�̬��Ա����
		cout << "��̬��Ա��������" << endl;
		_A = 200;
		//_B = 100;   ��̬��Ա�������ܷ��� �Ǿ�̬��Ա����
		// �޷����� �ı��ĸ������ _B
	}

	static int _A;
	int _B;
};

int Person::_A = 0;

void test1() {
	Person p;
	p.func();

	Person::func();// ������ʲ��� ˽��Ȩ�޵� ��̬��Ա����
}





int main() {

	test1();

	return 0;
}