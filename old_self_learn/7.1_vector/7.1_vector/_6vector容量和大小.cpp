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
//	for (int i = 0; i < 10; i++)
//		v1.push_back(i);
//	printVector(v1);
//
//	if (v1.empty())
//		cout << "v1为空" << endl;
//	else {
//		cout << endl;
//		cout << " v1 不为空" << endl;
//		cout << "v1的容积为" << v1.capacity() << endl;
//		cout << "v1的大小" << v1.size()<< endl;
//	}
//
//	cout << endl;
//	v1.resize(15);
//	printVector(v1);
//	cout << "v1的容积为" << v1.capacity() << endl;
//	cout << "v1的大小" << v1.size() << endl;
//
//	cout << endl;
//	v1.resize(20, 1);
//	printVector(v1);
//	cout << "v1的容积为" << v1.capacity() << endl;
//	cout << "v1的大小" << v1.size() << endl;
//
//}
//
//int main() {
//
//	test1();
//	return 0;
//}