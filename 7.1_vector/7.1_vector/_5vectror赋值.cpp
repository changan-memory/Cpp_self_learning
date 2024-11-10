//#include <iostream>
//#include <vector>
//using namespace std;
//
//void printVector(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test1() {
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	printVector(v1);
//
//	// operator
//	vector<int> v2 = v1;
//	printVector(v2);
//
//	//assign n 个 相同元素
//	vector<int> v3;
//	v3.assign(10, 100);
//	printVector(v3);
//
//	// assign 区间内的元素
//	vector<int> v4;
//	v4.assign(v1.begin(), v1.end());
//	printVector(v4);
//
//}
//
//int main() {
//
//	test1();
//	return 0;
//}