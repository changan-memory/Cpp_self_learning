//#include <iostream>
//using namespace std;
//
////ͨ���Լ�д��Ա������ ʵ����������������Ժ󷵻��µĶ���
////�Ӻ����������
//class Person {
//public:
//	//��Ա����ʵ�� + ����
//	/*Person operator+(Person& p) {
//		Person temp;
//		temp._A = this->_A + p._A;
//		temp._B = this->_B + p._B;
//		return temp;
//	}*/
//
//	int _A;
//	int _B;
//};
////ȫ�ֺ������� + 
//// ��������غ������� ��������
//Person operator+(Person& p1, Person& p2) {
//	Person temp;
//	temp._A = p1._A + p2._A;
//	temp._B = p1._B + p2._B;
//	return temp;
//}
//void test1() {
//	Person p1;
//	p1._A = 10;
//	p1._B = 20;
//
//	Person p2;
//	p2._A = 20;
//	p2._B = 30;
//	//ʵ�����ǵ��ú��� Person p3 = p2.operator+(p2);   ����ʹ����operatorָ�����ֻд +
//	//Person p3 = p1 + p2;
//	Person p3 = operator+(p1, p2);
//	cout << p3._A << " " << p3._B << endl;
//	//��������� �󲻻�ʧȥԭ���Ĺ���   
//	//���õ��������� ��������ʱ ���ᷢ������
//	cout << 1 + 3 << endl;
//}
//
//
//int main() {
//
//	test1();
//	return 0;
//}