#include <iostream>

#include <set>  // key ������ģ��
#include <map>  // key/value ������ģ��
using namespace std;

void test1_set(){
	// set �����ȥ��
	set<int> s1;
	s1.insert(3);
	s1.insert(2);
	s1.insert(4);
	s1.insert(5);
	s1.insert(1);
	s1.insert(3);	// ������ͬ��Ԫ��ʱ��������
	set<int>::iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// ��Χfor����
	for (auto e : s1) {
		cout << e << " ";
	}
	cout << endl;

	// ɾ��ָ��λ��
	auto pos = s1.find(3);	 // ���ڵ� find ��ƽ��Ķ������������� O(logN)  
	if(pos != s1.end())
		s1.erase(pos);
	//auto pos = find(s1.begin(), s1.end(), 3);	// �㷨���е� find �������� O(N)
	// ɾ��ָ����ֵ
	s1.erase(1);
	for (auto e : s1) {
		cout << e << " ";
	}
	cout << endl;
}
void test2_set() {
	// 
}
int main() {
	test1_set();
	return 0;
}