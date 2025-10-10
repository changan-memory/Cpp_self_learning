#include "AVL_Tree.h"
#include <vector>

// 这两个测试用例不能保证 AVL 树没有问题
void test1()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		// 假设 插入 11 的时候出问题了 需要调试，可以写个if 语句，在if内打断点
		// 方便快速的定位到问题所在处
		if (e == 11)
		{
			int x;
		}
		t.insert(make_pair(e, e));
		cout << "insert: " << e << "-> " << t.isBalance() << endl;
	}
}

// 使用多个随机值再进行测试
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