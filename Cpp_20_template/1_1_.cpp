#include <iostream>
#include <vector>
#include <list>
using namespace std;
// ģ�� ������ ��������
// 1. ���������д�ŵ����ݵ�����  ʵ�������е����͵�ͨ�仯
// 2. ���ƴ�����߼�: ������ģʽ�����벻ͬ����������������ͣ������������ͬ�������͵�����
// ֻҪ�� �����ͣ��Ϳ�����ģ�壬ģ�岻������ ���Ͳ����������и�����÷��͹��ܣ�����������
// ����ͨ�����벻ͬ������   ʵ�ֲ�ͬ�Ĺ���

// 1. 
// ģ���� typename �� class ������
// ����1  �������� ������һ��vector��Ҫ����
void Print(const vector<int>& v) {
	vector<int>::const_iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

// ʹ��T��Щ��������  ��Ϊ����ʹ��  ֻ�ܱ���vector
//template<class T>
//void Print(const vector<T>& v) {
//	vector<T>::const_iterator it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

// ʵ��һ�����͵�Print
//template<class Container>	   // STL�д󲿷��õĶ���class	    // �ó����� 
// ��ģ������У�ʹ��typename��classЧ��һ��
////template<class Container>

// ����� Container ��֪����ʲô������֪����һ������
// �ҿ���֧�����е�����
template<typename Container>			
void Print(const Container& con) {
	// ���� typename ʱ������ǰҪ�Ƚ��дʷ���������ʱģ����� Container ��δʵ������
	// ��������֪�� Container::const_iterator ��ʾ ���е� ��̬��Ա����
	// �������� typedef �����ͣ�����ȷ��
	// ʵ����֮�����ȷ������
	
	// ����ı��� �� ��֪�� Container::const_iterator ��ʾ�������� ���Ƕ���

	//  ����������typename �������typename, Container::const_iterator ����д����
	// const_iterator �����Ǿ�̬��Ա������Ҳ�����Ǳ������ͣ�����typename�������޷��ֱ棬�����Ҫ����
	// ���� typename ʱ�� Container::const_iterator ��һ�ѣ��ȿ��������ͣ�Ҳ�����Ƕ���()
	typename Container::const_iterator it = con.begin();	// ��������֧�� const_iterator const������
	//Container::const_iterator it = con.begin();	// ��������֧�� const_iterator const������
	// ����Container δʵ����ʱ����������ȷ��  Container::const_iterator �����ͻ���static��Ա����
	// typename  ���߱����� ���� Container::const_iterator �����ͣ��ñ�����֪��������д���Ǻ����
	// �������� ��ģ��ʵ��������ȥ Container ������ ����
	// ֻҪ�� ȡ δʵ������ ��ģ���� �����ݣ�������ȷ�� ȡ���� ���� ���� ��Ա����
	
	//auto it = con.begin();	������ʹ�� auto auto���Ƶ��������ʾ��һ��������
	// �� auto �����ܽ�����г������������  ��Ϊ auto ��������ģ������б���
	while (it != con.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

////template<class Container>
//template<typename Container>
//void Print(const Container& con) {
//	Container::const_iterator it = con.begin();	// ��������֧�� const_iterator const������
//	while (it != con.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
void test1() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	for (auto e : v1)
		cout << e << " ";
	cout << endl;
	Print(v1);
	list<double> l1;
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(7);
	l1.push_back(8);
	Print(l1);
}

// ����2 ������ģ�����
// ��ʱ ���ǵ�ģ�����Ҫ ����Ϊ���͵�ģ�������Ҳ���Ƿ�����ģ����� 

// ��ͳ��ʽ ���ú궨��һ����̬ջ
//#define N 20
//template<class T>
//class Stack {
//public:
//	
//private:
//	T _base[N];
//	int _top;
//};
//void test2() {	
//  // �����ջ�޷����Ĵ�С, ����Ҫһ��10���ռ� �� 20 ���ռ��ջ
//	Stack<int> st1;
//	Stack<int> st2;
//}

// ʹ�÷����� ģ���������һ����̬ջ
// ������ģ������� 1 �����ǳ����� 2 ���������μ���� (size_t  char  int  unsigned int)
template<class T, size_t N>
class Stack {
public:
	void func() {
		//N = 20;			//  N �ǳ����������޸�
	}
private:
	T _array[N];
	int _top;
};
void test2() {
	Stack<int, 10> st1;
	Stack<int, 20> st2;
	// ��Щ����������а���ʵ�����������û�е���func����ô�Ͳ����func���м�顣����Ϊ��Ϊ����ʵ����
	st1.func();
}
// ������ģ����� �ʼ����� ����Ϊ�� ������ ��̬����������ʵ��

//int main() {
//
//	test1();
//	//test2();
//	return 0;
//}