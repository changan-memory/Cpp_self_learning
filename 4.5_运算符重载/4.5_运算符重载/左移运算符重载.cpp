#include <iostream>
using namespace std;
//���� ���������
class Person {
	friend ostream& operator<<(ostream& cout, Person& p);
public:
	//ͨ���������ó�Ա�������� << ���������  ��Ϊ �޷�ʵ�� cout<<p  �޷�ʵ��cout�����
	/*void operator<<() {	//��Ϊ�����Ƕ�����ó�Ա����

	}*/
	Person(int a, int b) {
		this->_A = a;
		this->_B = b;
	}
private:

	int _A;
	int _B;
};

//Ҫ�� ȫ�ֺ������� <<  �����		
//�� ��ȫ�ֺ��� ����Ϊ �����Ԫ�� ����ʵ�ַ������ڵ�˽�г�Ա
ostream& operator<<(ostream& cout, Person& p) {
	cout << p._A << " " << p._B << endl;
	return cout;
}

void test1() {
	Person p1(10, 20);//��Ա��������Ϊ˽�� ���޷����ⲿ���и�ֵ, ʹ�ù��캯�����и�ֵ
	

	//cout << p1._A << endl;
	cout << p1 << endl;
}



int main() {

	test1();


	return 0;
}