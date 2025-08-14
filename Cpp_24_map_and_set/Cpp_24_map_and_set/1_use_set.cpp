#include <iostream>

#include <set>  // key 的搜索模型
//#include <map>  // key/value 的搜索模型
using namespace std;

// set容器，里面的数据 达到的效果是 去重 + 顺便排序
// multiset 里面的数据，允许键值重复，
// set 的iterator 都是 const_iterator  因此 set的 iterator 都是 const_iterator
// set 的键值不允许修改
namespace test_set {
	void test1_set() {
		// set 会进行去重
		set<int> s1;
		s1.insert(3);
		s1.insert(2);
		s1.insert(4);
		s1.insert(5);
		s1.insert(1);
		s1.insert(3);	// 碰到相同的元素时，不插入
		set<int>::iterator it = s1.begin();
		// 使用迭代器顺序遍历时，默认走的是中序遍历，因此结果是升序的
		while (it != s1.end()) {
			cout << *it << " ";
			++it;
		}
		cout << endl;
		// 范围for遍历
		for (auto e : s1) {
			cout << e << " ";
		}
		cout << endl;

		// 删除指定位置
		auto pos = s1.find(3);	 // 类内的 find 自平衡的二叉搜索树查找 O(logN)  
		if (pos != s1.end())
			s1.erase(pos);
		//auto pos = find(s1.begin(), s1.end(), 3);	// 算法库中的 find 暴力查找 O(N)
		// 删除指定的值
		s1.erase(1);
		for (auto e : s1) {
			cout << e << " ";
		}
		cout << endl;
		if (s1.count(5)) {
			cout << "找到了" << endl;
		}
	}
	void test2_set() {
		// 找边界
		std::set<int> myset;
		std::set<int>::iterator itlow, itup;

		for (int i = 1; i < 10; i++) myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90
		std::cout << "myset contains:";
		for (auto e : myset) {
			cout << e << " ";
		}
		cout << endl;
		// 找传入值的边界
		// 给的区间 [30, 60] 都会删掉
		itlow = myset.lower_bound(30);                //   找 >= 30 的那个值  itlow是30的位置
		itup = myset.upper_bound(60);                 //   找 > 60 的那个值   itup是70的位置
		// 这么设计是为了配合erase 的左闭右开
		cout << *itlow << " " << *itup << endl;
		// 删除的是 [itlow, itup)
		myset.erase(itlow, itup);                     // 10 20 70 80 90

		std::cout << "myset contains:";
		for (auto e : myset) {
			cout << e << " ";
		}
		cout << endl;
	}
	void test3_set() {
		std::set<int> myset;

		for (int i = 1; i <= 5; i++) myset.insert(i * 10);   // myset: 10 20 30 40 50

		//std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
		auto ret = myset.equal_range(30);
		// ret 的类型是 pair<iterator, itrator> 
		// equal_range(30) 返回的是 30 的左闭右开的区间 [30, 40) 
		std::cout << "the lower bound points to: " << *ret.first << '\n';
		std::cout << "the upper bound points to: " << *ret.second << '\n';
	}
}
// set容器，里面的数据 达到的效果是 去重 + 顺便排序
// multiset 里面的数据，允许键值重复，
// count 和 equal_range 都是为 multiset设计的
namespace test_multiset {
	void test1_multiset() {
		multiset<int> mset;		// multiset 允许键值冗余
		mset.insert(3);
		mset.insert(5);
		mset.insert(8);
		mset.insert(7);
		mset.insert(7);
		mset.insert(9);
		mset.insert(7);
		for (auto e : mset) {
			cout << e << " ";
		}
		cout << endl;
		cout << "count of number 7 is:" << mset.count(7) << endl;
		// 删除容器中所有的7
		//std::pair<std::multiset<int>::const_iterator, std::multiset<int>::const_iterator> ret = mset.equal_range(7);
		auto ret = mset.equal_range(7);
		// ret 被推导为了 pair<std::set<int>::iterator,std::set<int>::iterator>
		// 主要原因在于 std::multiset在其底层实现上通常复用 std::set的迭代器类型
		// 编译器（特别是 MSVC）在内部类型定义中使用了别名
		cout << *ret.first << endl;
		cout << *ret.second << endl;
		// equal_range(7)  的返回值 ret 内有一个迭代器区间，
		// 分别指向第一个7的位置和 最后一个7的下一个位置(查找时是升序排列的，因此多个7是挨着的)
		mset.erase(ret.first, ret.second);
		for (auto e : mset) {
			cout << e << " ";
		}
		cout << endl;
	}
	void test2_multiset() {
		multiset<int> mset;		// multiset 允许键值冗余
		mset.insert(3);
		mset.insert(5);
		mset.insert(8);
		mset.insert(7);
		mset.insert(7);
		mset.insert(9);
		mset.insert(7);
		for (auto e : mset) {
			cout << e << " ";
		}
		cout << endl;
		// 有多个7时，find返回的是 中序遍历时 的第一个7 的位置
		// 如果没找到，返回的是一个空区间
		// 假设7每找到，返回
		auto pos = mset.find(7);
		while (pos != mset.end()) {
			cout << *pos << " ";
			pos++;
		}
		cout << endl;
		for (auto e : mset) {
			cout << e << " ";
		}
		cout << endl;
	}
}
//int main() {
//	//test_set::test2_set();
//	//test_set::test3_set();
//	//test_multiset::test1_multiset();
//	test_multiset::test2_multiset();
//	return 0;
//}