//#include <iostream>
//#include <vector>
//using namespace std;
//
//void printVector(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//
//void test1() {
//	cout << "����ǰ" << endl;
//	vector<int> v1;
//	for (int i = 0; i < 10; i++)
//		v1.push_back(i);
//	printVector(v1);
//
//	vector<int> v2;
//	for (int i = 10; i > 0; i--)
//		v2.push_back(i);
//	printVector(v2);
//
//	cout << " ������" << endl;
//	v1.swap(v2);
//	printVector(v1);
//	printVector(v2);
//
//}
//// ���� swap ���������ڴ�
//void test2() {
//	vector<int> v1;
//	for (int i = 0; i < 1000000; i++)
//		v1.push_back(i);
//	cout << v1.size() << " " << v1.capacity() << endl;
//
//	v1.resize(3);
//	cout << v1.size() << " " << v1.capacity() << endl;
//
//	// ���� �������� �����ڴ�
//	vector<int>(v1).swap(v1);		// ִ���굱ǰ�к󣬱������������������󣬻����̻����ڴ�
//	cout << v1.size() << " " << v1.capacity() << endl;
//
//}
//
//
//
//int main() {
//
//	//test1();
//	test2();
//	return 0;
//}