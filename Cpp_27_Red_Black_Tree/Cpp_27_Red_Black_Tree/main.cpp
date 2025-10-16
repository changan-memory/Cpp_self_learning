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
		v.push_back(rand() + i);	// �����������
		//v.push_back(i);				// ������������
	}

	RBTree<int, int> rbt;
	for (auto e : v)
	{
		rbt.insert(make_pair(e, e));	
		//cout << "Insert:" << e << "->" << t.isBalance() << endl;
	}
	cout << "������Ƿ�ƽ��:         " << rbt.isBalance() << endl;
	cout << "������ĸ߶�:           " <<rbt.Height() << endl;
	cout << "���������ת����:       " << rbt._rotateCount << endl;

	cout << endl << endl;

	AVLTree<int, int> avlt;
	for (auto e : v)
	{
		avlt.insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	
	cout << "AVL���Ƿ�ƽ��:          " << avlt.isBalance() << endl;
	cout << "AVL���ĸ߶�:            " << avlt.height() << endl;
	cout << "AVL������ת����:        "<< avlt._rotateCount << endl;


	return 0;
}