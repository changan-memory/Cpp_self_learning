// 3. ģ����ػ�


#include <iostream>
#include <vector>
#include <list>
using namespace std;


// 3.1 ����ģ����ػ�
// ����ģ�� -- ����ƥ��
template<class T>		// 1
bool Less(T left, T right) {
	return left < right;
}
//// ��׼�ĺ���ģ����ػ�   ��д��
//template<>				// 2
//bool Less<int*>(int* left, int* right) {
//	return *left < *right;
//}

// ����ʵû��Ҫ�����������ػ���
// ��ΪҪ�����ػ��ˣ�������ֱ��дһ���µĺ����������������������أ�template<>û��Ҫд��
bool Less(int* left, int* right) {		// 2
	return *left < *right;
}
// ��������û�н�����⣬��Ϊ��ʱֻ�ܽṹint* ,double*��
// ����ʵ��
template<class T>		// 3
bool Less(T* left, T* right) {
	return *left < *right;
}
void test3() {
	cout << Less(1, 2) << endl;   // ƥ�� 1
	int a = 1, b = 2;
	cout << Less(&a, &b) << endl;	// ƥ�� 2 // �п��� ���봫��ַ���������յ�ַ�Ĵ�С�ȣ���ֵȥ��
	double a1 = 1.1, b1 = 2.2;
	cout << Less(&a, &b) << endl;	 // ƥ�� 3  // �п��� ���봫��ַ���������յ�ַ�Ĵ�С�ȣ���ֵȥ��

}

// 3.2 ��ģ����ػ�

//int main() {
//	
//	test3();
//	return 0;
//}