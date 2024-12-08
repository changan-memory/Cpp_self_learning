//#include <iostream>
//#include <vector>
//using namespace std;
//
//void printVector(vector<int>& v) {
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i] << " ";
//	cout << endl;
//}
//
//void test() {
//	vector<int> v1;
//	for (int i = 0; i <= 50; i += 10)
//		v1.push_back(i);	//尾插法
//	printVector(v1);
//
//	v1.pop_back();		// 删除最后一个元素
//	printVector(v1);
//
//	// 插入元素
//	v1.insert(v1.begin(), 100);
//	printVector(v1);		// 让 100 成为第一个元素，剩下的元素后移
//	// 插入多个相同的元素
//	v1.insert(v1.begin(), 2, 200);
//	printVector(v1);
//	// erase 提供一个迭代器  或者 两个迭代器构成的区间
//	v1.erase(v1.begin());
//	printVector(v1);
//	cout << " 大小为" << v1.size() << endl;
//
//}
//
//int main() {
//
//	test();
//	return 0;
//}