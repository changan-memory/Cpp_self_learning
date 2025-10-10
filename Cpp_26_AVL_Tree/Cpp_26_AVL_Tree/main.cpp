#include "AVL_Tree.h"
#include <vector>

// �����������������ܱ�֤ AVL ��û������
void test1()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		// ���� ���� 11 ��ʱ��������� ��Ҫ���ԣ�����д��if ��䣬��if�ڴ�ϵ�
		// ������ٵĶ�λ���������ڴ�
		if (e == 11)
		{
			int x;
		}
		t.insert(make_pair(e, e));
		cout << "insert: " << e << "-> " << t.isBalance() << endl;
	}
}

// ʹ�ö�����ֵ�ٽ��в���
void test2()
{
	const int N = 1000000;
	vector<int> v;
	v.reserve(N);

	srand(time(0));

	AVLTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		v.push_back(rand());
	}
	for (auto e : v)
	{
		t.insert(make_pair(e, e));
		//cout << "insert: " << e << "-> " << t.isBalance() << endl;
	}
	cout << t.isBalance() << endl;

}
int main() {
	//test1();
	test2();
	return 0;
}