#include <iostream>
#include <vector>
#include <list>
using namespace std;

//ֻҪ�Ǵ����ͣ��Ϳ�����ģ�壬ģ�岻���������Ͳ����������и�����÷��͹��ܣ�����������

// ģ���� typename �� class ������
// ����1  �������� ������һ��vector��Ҫ����
//void Print(const vector<int>& v) {
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

// ʵ��һ�����͵�Print
//template<class Container>		// �ó�����
template<typename Container>
//void Print(const vector<int>& v) {
void Print(const Container& con) {
	typename Container::const_iterator it = con.begin();
	// Container::const_iterator
	while (it != con.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
void test1() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	for (auto e : v1)
		cout << e << " ";
	cout << endl;
	Print(v1);
}

int main() {

	test1();
	return 0;
}