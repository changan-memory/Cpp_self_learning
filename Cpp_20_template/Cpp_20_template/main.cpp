#include <iostream>
#include <vector>
#include <list>
using namespace std;

//只要是传类型，就可以用模板，模板不仅仅是类型参数化，还有更多的用法和功能，比如适配器

// 模板中 typename 和 class 的区别
// 场景1  遍历容器 假设有一个vector需要遍历
//void Print(const vector<int>& v) {
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

// 实现一个泛型的Print
//template<class Container>		// 该场景下
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