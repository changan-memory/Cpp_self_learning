//#include <iostream>
//using namespace std;
//
////1. �������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����   
////2. ����ͨ����ģ������б���   ǿ�Ƶ��ú���ģ��
////3. ����ģ��Ҳ���Է�������   ����ģ����������أ�����ʱ�����ȵ���  ���� ����ƥ����õ� ����ģ��
////4. �������ģ����Բ������õ�ƥ��, ���ȵ��ú���ģ��
// 
//
//
//
//
//
//void myPrint(int a, int b) {
//	cout << "������ͨ����" << endl;
//}
//
//
//template <typename T>
//void myPrint(T a, T b) {
//	cout << "ģ�庯������" << endl;
//}
//
//template <typename T>
//void myPrint(T a, T b, T c) {
//	cout << "ģ�庯������" << endl;
//	cout << c << endl;
//}
//
//void test1() {
//	int b = 20;
//	int a = 10;
//	myPrint(a, b);
//
//	//ͨ����ģ������б�   ǿ�Ƶ���ģ�庯��
//	myPrint<>(a, b);
//
//	myPrint<int>(a, b, 'a');	//�Զ������Ƶ���Ҫ  �Ƶ��� һ�µĽ��
//
//
//}
//
//int main() {
//
//	test1();
//	system("pause");
//	return 0;
//}