// 2. ������ģ�������Ӧ�ó���֮һ   std::array

#include <iostream>
#include <array>
#include <vector>
using namespace std;

void testArray() {
	// C++11������һ��array   ֧��ģ��ľ�̬����
	//int a[8];
	array<int, 10> a;
	a[0] = 0;
	for (auto e : a)
		cout << e << " ";
	cout << endl;

	// array��Խ��ļ��ʮ���ϸ�Խ���д���ܼ��
	// C������ͨ���飬����Խ��������ٲ���Խ��д���Լ�����
	//a[10];

	//��Ȼarray��Խ��ļ��ʮ���ϸ�Խ���д���ܼ�顣����Ϊʲô��ʹ��vector��
	// ���ܳ�ʼ�������ܼ���дԽ�磬ʵ�־�̬����Ļ����Ҳ����ݾ�����
	vector<int> v(10, 0);
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	//v[10];
	// ��֮ std::arrayȷʵ����
}
//int main() {
//	testArray();
//	return 0;
//}