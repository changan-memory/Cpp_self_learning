//#include <iostream>
//using namespace std;
//
//#include <vector>
//#include <algorithm>
//
//void print(int val) {
//	cout << val << " ";
//}
//
//// vector  的三种遍历方式
//void test1() {
//	vector<int> v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//
//	//遍历方式1
//	vector<int>::iterator itBegin = v1.begin();
//	vector<int>::iterator itEnd = v1.end();
//	while (itBegin != itEnd) {
//		cout << *itBegin << " ";
//		++itBegin;
//	}
//	cout << endl;
//
//	//遍历方式2
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	// 遍历方式 3
//	for_each(v1.begin(), v1.end(), &print);
//}
//
//
//
//int main(){
//
//	test1();
//
//
//	system("pause");
//	return 0;
//}