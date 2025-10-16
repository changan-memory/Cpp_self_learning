#include"Red_Black_Tree.h"
#include"AVL_Tree.h"
#include<vector>

//int main()
//{
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.insert(make_pair(e, e));
//		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
//	}
//
//	return 0;
//}

int main()
{
	const int N = 10000000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand() + i);	// 插入随机数据
		//v.push_back(i);				// 插入有序数据
	}

	RBTree<int, int> rbt;
	for (auto e : v)
	{
		rbt.insert(make_pair(e, e));	
		//cout << "Insert:" << e << "->" << t.isBalance() << endl;
	}
	cout << "红黑树是否平衡:         " << rbt.isBalance() << endl;
	cout << "红黑树的高度:           " <<rbt.Height() << endl;
	cout << "红黑树的旋转次数:       " << rbt._rotateCount << endl;

	cout << endl << endl;

	AVLTree<int, int> avlt;
	for (auto e : v)
	{
		avlt.insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	
	cout << "AVL树是否平衡:          " << avlt.isBalance() << endl;
	cout << "AVL树的高度:            " << avlt.height() << endl;
	cout << "AVL树的旋转次数:        "<< avlt._rotateCount << endl;


	return 0;
}