#include <iostream>

#include <set>  // key 的搜索模型
#include <map>  // key/value 的搜索模型
using namespace std;

void test1_set(){
	// set 会进行去重
	set<int> s1;
	s1.insert(3);
	s1.insert(2);
	s1.insert(4);
	s1.insert(5);
	s1.insert(1);
	s1.insert(3);	// 碰到相同的元素时，不插入
	set<int>::iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// 范围for遍历
	for (auto e : s1) {
		cout << e << " ";
	}
	cout << endl;

	// 删除指定位置
	auto pos = s1.find(3);	 // 类内的 find 自平衡的二叉搜索树查找 O(logN)  
	if(pos != s1.end())
		s1.erase(pos);
	//auto pos = find(s1.begin(), s1.end(), 3);	// 算法库中的 find 暴力查找 O(N)
	// 删除指定的值
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