//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//	Base() {
//		this->_A = 200;
//	}
//	void func() {
//		cout << "�����е�func����" << endl;
//	}
//	void func(int a) {
//		cout << "�����е�func int a ����" << endl;
//	}
//	int _A;
//};
//
//class Son :public Base {
//public:
//	Son() {
//		this->_A = 2000;
//	}
//	void func() {
//		cout << "�����е�func����" << endl;
//	}
//	
//	int _A;
//};
//
//void test() {
//	Son s1;
//	//����������е�ͬ����Ա �������� ֱ�ӵ��� ���������еĳ�Ա
//	cout << "Son�е� A_ " << s1._A << endl;
//	//����ø����еĳ�Ա  ��Ҫ����������
//	cout << "Base�е� A_ " << s1.Base::_A << endl;
//
//	//ͬ��
//	s1.func();	//ֱ�ӵ���,���������е�func
//	s1.Base::func();	//����ʱ���������� �ɵ��ø����е�func
//	s1.Base::func(100);
//
//}
////1. ����������ֱ�ӷ��ʵ�������ͬ����Ա
////2. ����������������Է��ʵ�����ͬ����Ա
////3. �������븸��ӵ��ͬ���ĳ�Ա��������������ظ�����ͬ����Ա������
//// ����������Է��ʵ�������ͬ������
//
//
//
//int main() {
//	test();
//
//	return 0;
//}
//
