//#include <iostream>
//using namespace std;
////�����ǳ����
//class Person {
//public:
//	Person() {
//		cout << "Person���޲ι��캯������" << endl;
//		this->_age = 0;
//		this->height = nullptr;
//	}
//	Person(int a, int height) {
//		this->_age = a;
//		this->height = new int(height);
//		cout << "Person���вι��캯������" << endl;
//	}
//	//C++���캯�� ��������
//	
//	//������ �ж���������ʱ��������Ҫ�Լ���дһ��������캯�� Ĭ�Ϲ��캯��ֻ��ǳ����
//	//���  �ڶ������¿���һ���ڴ� �����п���
//	Person(const Person& p) {
//		cout << "Person �Ŀ������캯������" << endl;
//		this->_age = p._age;
//		this->height = new int(*p.height);
//	}
//
//	~Person() {
//		//��������������  ͨ�����ڶ�������������ͷ�
//		if (this->height != nullptr) {
//			delete this->height;
//			this->height = nullptr;
//		}
//		cout << "Person��������������" << endl;
//	}
//	
//	int _age;
//	int* height;
//
//};
//
//void test() {
//	Person p1(10, 20);
//	Person p2(p1);
//	cout << p1._age << endl;
//	cout << p2._age << endl;
//}
//
//
//
//int main() {
//	test();
//	return 0;
//}