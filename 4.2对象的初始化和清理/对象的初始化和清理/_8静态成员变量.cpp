//#include<iostream>
//using namespace std;
//
////��̬��Ա
//// ��̬��Ա����
//class  Person {	//���ڵ� ��̬��Ա  ���ж�����ͬһ������
//public:
//	//���ж��󶼹���һ���ڴ�
//	//����׶ξͷ����ڴ�
//	// ���������������ʼ��
//	static int _A;
//
//private:
//	static int _B;
//
//};
//
//int Person:: _A = 100;
//int Person::_B = 300;
//void test1() {
//	Person p1;
//	cout << p1._A << endl;
//	Person p2;
//	p2._A = 200;
//	cout << p1._A << endl;
//}
//
//void test2() {
//	//��̬��Ա����  ������ĳ�������� �����ж�����ͬһ������
//	//��˾�̬���������ַ��ʷ�ʽ
//
//	//ͨ��������з���
//	Person p;
//	cout << p._A << endl;
//	//ͨ���������з���
//	cout << Person::_A << endl;
//	//��̬��Ա����Ҳ����Ȩ�޵�
//
//	//cout << Person::_B << endl;	//˽�еľ�̬��Ա �ⲿ�����Է���
//}
//
//int main() {
//
//	//test1();
//	test2();
//	return 0;
//}