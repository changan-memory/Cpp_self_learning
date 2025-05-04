#include <iostream>
#include <list>
using namespace std;

void testAccess() {
	std::list<int> lt;
	lt.push_back(11);
	lt.push_back(12);
	lt.push_back(22);
	lt.push_back(32);
	lt.push_back(46);
	lt.push_back(58);
	for (auto e : lt)
		cout << e << " ";
	cout << endl;

	//insert(v.begin()+4, 10)
	//lt.insert(lt.begin() + 4, 10);	//list�����õ����� + 4 ��Ϊ list�Ŀռ䲻��������
	auto it = lt.begin();	//������ɾ�������ֵ��ֻ���ֶ�������
	for (int i = 0; i < 4; ++i)
		++it;
	lt.insert(it, 100);
	for (auto e : lt)
		cout << e << " ";
	cout << endl;

	//��������û��3 ��3��ǰ�����һ��ֵ

}

int main() {
	
	testAccess();
	return 0;
}