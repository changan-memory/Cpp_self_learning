#include <iostream>
using namespace	std;

//void Swap(int& left, int& right) {
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right) {
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right) {
//	char temp = left;
//	left = right;
//	right = temp;
//}

//�ֽ׶���Ϊ class��typename��һ����

//ģ��
//����ģ��
//�������������еĺ���ģ�壬���ɾ��в�ͬ��������
//ģ�������ģ����������ڣ������Ͳ�����
template<typename T>	//�������Ͳ���
void Swap(T& left, T& right) {
	T temp = left;
	left = right;
	right = temp;
}

// ���ǵ��õĺ�����ʵ�����ǣ�����������ģ�����ɵľ��庯��(����������ģ�壬�����˲����Ǹ������͵ĺ���)
template<typename T1, typename T2>		//������Ͳ���   T��һ�����ͣ�T1��һ�����ͣ�T2��һ������
T1& Func(const T1& x, const T2& y) {
	cout << x << " " << y << endl;
	return x;
}
//int main() {
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.2;
//	/*Swap(a, b);
//	Swap(c, d);*/
//
//	//��׼������ʵ���� ��������
//	std::swap(a, b);
//	std::swap(c, d);
//
//	int* p1 = &a, * p2 = &b;
//	swap(p1, p2);
//	swap(p1, p2);
//	return 0;
//}


//����ģ���ʵ����
template<typename T>
T Add(const T& left, const T& right) {
	return left + right;
}

template<typename T>
T* Alloc(int n) {
	return new T[n];
}

//int main() {
//	//����ģ���ʵ����
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.1;
//	//�������Զ��Ƶ� ���к���ģ���ʵ����
//	//ͨ��ʵ�δ��ݵ����ͣ�����T������
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//	cout << Add(a1, (int)d1) << endl;	//ͨ��ǿ������ת����ȷ���Ƶ��Ľ��һ��
//	cout << Add((double)a1, d1) << endl;
//
//	//����ģ��� ��ʽʵ��������ָ������ʵ�������ᷢ����ʽ����ת��
//	cout << Add<int>(a1, d1) << endl;
//	cout << Add<double>(a1, d1) << endl;
//
//	//��ʽʵ������Ӧ�ó���
//	//��Щ���������Զ������Ƶ�����Ҫ��ʽָ��
//	int* p_int = Alloc<int>(10);
//	double* p_double = Alloc<double>(20);
//
//	return 0;
//}