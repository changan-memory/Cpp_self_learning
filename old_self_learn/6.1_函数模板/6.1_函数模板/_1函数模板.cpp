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
//
//int main() {
//	int a = 10, b = 20;
//	double c = 30.001, d = 40.001;
//	cout << a << " " << b << endl;
//	cout << c << " " << d << endl;
//
//	//ʹ��ģ������ַ�ʽ
//	//�Զ������Ƶ�
//	swap(a, b);
//	//��ʾ�ƶ�����
//	swap<double>(c, d);
//	cout << a << " " << b << endl;
//	cout << c << " " << d << endl;
//	system("pause");
//	return 0;
//}