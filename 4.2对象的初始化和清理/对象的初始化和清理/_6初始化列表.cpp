#include <iostream>
using namespace std;

// ��ʼ���б�
class Person {
public:
	//��ͳ��ʼ����ʽ
	/*Person(int a, int b, int c) {
		this->_A = a;
		this->_B = b;
		this->_C = c;
	}*/
	//�����Ӿ�д����
	/*Person() :_A(10), _B(20), _C(30) {

	}*/
	Person(int& a, int& b, int& c) :_A(a), _B(b), _C(c) {

	}
	int _A;
	int _B;
	int _C;
};

void test1() {
	int a = 0, b = 0, c = 0;
	Person p(a, b, c);
	cout << p._A << " " << p._B << " " << p._C << endl;
}




int main() {
	test1();

	return 0;
}