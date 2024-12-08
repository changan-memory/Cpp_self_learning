//#include <iostream>
//using namespace std;
//#include <vector>
//
//void printVector(vector<int> &v) {
//	for (vector<int> ::iterator it = v.begin(); it != v.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//
//void test1() {
//	//默认构造
//	vector<int> v1;
//	for (int i = 0; i < 10; i++)
//		v1.push_back(i);
//	printVector(v1);
//
//	// 区间构造
//	vector<int> v2(v1.begin(), v1.end());
//	printVector(v2);
//
//	//重复构造
//	vector<int> v3(5, 100);
//	printVector(v3);
//
//	//拷贝构造
//	vector<int> v4(v3);
//	printVector(v4);
//}
//
//
//
//int main() {
//	test1();
//	return 0;
//}
