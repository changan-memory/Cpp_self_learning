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
//		v1.push_back(i);	//β�巨
//	printVector(v1);
//
//	v1.pop_back();		// ɾ�����һ��Ԫ��
//	printVector(v1);
//
//	// ����Ԫ��
//	v1.insert(v1.begin(), 100);
//	printVector(v1);		// �� 100 ��Ϊ��һ��Ԫ�أ�ʣ�µ�Ԫ�غ���
//	// ��������ͬ��Ԫ��
//	v1.insert(v1.begin(), 2, 200);
//	printVector(v1);
//	// erase �ṩһ��������  ���� �������������ɵ�����
//	v1.erase(v1.begin());
//	printVector(v1);
//	cout << " ��СΪ" << v1.size() << endl;
//
//}
//
//int main() {
//
//	test();
//	return 0;
//}