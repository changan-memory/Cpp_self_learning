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
	//lt.insert(lt.begin() + 4, 10);	//list不能用迭代器 + 4 因为 list的空间不是连续的
	auto it = lt.begin();	//向插入或删除第五个值，只能手动往后找
	for (int i = 0; i < 4; ++i)
		++it;
	lt.insert(it, 100);
	for (auto e : lt)
		cout << e << " ";
	cout << endl;

	//找里面有没有3 在3的前面插入一个值

}

int main() {
	
	testAccess();
	return 0;
}