//#include <iostream>
//using namespace std;
//
//template<typename T>	//���߱�����  Ҫ����һ��ģ��
//void MySwap(T& a, T& b) {		// T Ϊͨ�����ͣ�һ���� T ��ʾ
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//void test1() {
//	//�Զ��Ƶ�  �Ƶ������������ͱ���һ��
//	int a = 10, b = 20;
//	char c = 'q';
//	cout << a << " " << b << endl;
//	//MySwap(a, c);
//	MySwap<int>(a, b);//�Ƶ����� һ�µ���������
//	cout << a << " " << b << endl;
//}
//
//template<typename T>
//void func() {
//	cout << "test  " << endl;
//}
//
////ģ�岻��ֱ��ʹ�ã�ʹ��ʱ��Ҫ��ȷָ������������
//void test2() {
//	//func();
//	func<int>();	
//}
//int main() {
//	
//	//test1();
//	test2();
//
//	system("pause");
//	return 0;
//}