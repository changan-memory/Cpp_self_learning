//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Person {
//public:
//	//Ĭ�Ϲ��캯��
//	Person() {
//		cout << "�޲ι��캯������"<<endl; //Ҳ��Ĭ�Ϲ��캯��
//		_age = 0;
//	}
//	// �вι��캯��
//	Person(int a) {
//		cout << "�вι��캯������" << endl;
//		_age = a;
//	}
//
//	//�������캯��
//	Person(const Person& p) {	//���벻���޸ĵ�����
//		_age = p._age;
//		cout << "�������캯������" << endl;
//
//	}
//	//��������
//	~Person() {
//		cout << "������������" << endl;
//	}
////private:
//	int _age;
//};
//
//void test_1() {
//	//1 �� ���ŷ�
//	Person p1;  
//	Person p2(10);
//	Person p3(p2);
//	cout << p1._age << endl;
//	cout << p2._age << endl;
//	cout << p3._age << endl;
//	//ע������
//	//1������Ĭ�Ϲ����ʱ�� ��Ҫ������
//	//Perspn p1();   ���д��� ������Ĭ�ϻ���Ϊ ����һ����������   ������Ϊ���ڴ�������
//
//	// 2�� ��ʾ��
//	Person p4 = Person(100);
//	Person p5 = Person(p4);
//
//	
//	//Person (p5);   ������������  �ص㣺 ��ǰ��ִ�н����󣬻��������յ���������
//	cout << p4._age << endl;
//	cout << p5._age << endl;
//
//	// ע��
//	// ��Ҫ�ÿ������캯����ʼ����������  
//
//}
//
//int main() {
//
//
//	test_1();
//
//	
//
//	system("pause");
//	return 0;
//}