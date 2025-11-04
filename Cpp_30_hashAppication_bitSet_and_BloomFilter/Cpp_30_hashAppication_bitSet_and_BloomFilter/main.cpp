#include "bitSet.h"
//#include <bitset>


void testBitSet()
{
	m_BitSet::bitset<1000> bs;
	bs.set(1);
	bs.set(10);
	bs.set(100);

	cout << bs.test(1) << endl;
	cout << bs.test(10) << endl;
	cout << bs.test(100) << endl;
	cout << bs.test(999) << endl << endl;

	bs.set(999);
	bs.reset(10);

	cout << bs.test(1) << endl;
	cout << bs.test(10) << endl;
	cout << bs.test(100) << endl;
	cout << bs.test(999) << endl << endl;

	// 解决腾讯的面试题的思路
	// 从文件中读取数字，将40亿个数字都set 一遍之后，再使用 test 判断新来的数字 在不在那 40 亿中
	m_BitSet::bitset<4000000000> bs1;
	bs1.set(0);
	bs1.set(4000000000);

	cout << bs1.test(0) << endl;
	cout << bs1.test(4000000000) << endl;

	return;
}
//位图的应用
// 问题一、给定100亿个整数，设计算法找到只出现一次的整数
void testQuestion1()
{
	int arr[] = {1, 2, 3, 3, 4, 4, 4, 4, 4, 2, 3, 6, 3, 1, 5, 5, 8, 9 };
	m_BitSet::TwoBitSet_1<10> tbt;
	for (auto e : arr)
		tbt.set(e);

	for (auto e : arr)
		if (tbt.is_once(e))
			cout << e << " ";
	cout << endl;
}
// 问题二、给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集
void testQuestion2()
{
	int arr1[] = { 1, 2, 3, 3, 4, 4, 4, 4, 4, 2, 3, 6, 3, 1, 5, 5, 8, 9 };
	int arr2[] = { 1, 3, 5, 5, 8, 9 };
	m_BitSet::bitset<10> b1;
	m_BitSet::bitset<10> b2;

	for (auto e : arr1)
		b1.set(e);
	for (auto e : arr2)
		b2.set(e);
	for (auto e : arr2)
		if (b1.test(e) && b2.test(e))
			cout << e << " ";
	// 以上思路求得的结果，还需要再去重，但不能用 set 去重，因为内存不够
	// 但可以再用 位图去重
}

// 问题二、给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集
void testQuestion2_new()
{
	// 优化版
	int arr1[] = { 1, 2, 3, 3, 4, 4, 4, 4, 4, 2, 3, 6, 3, 1, 5, 5, 8, 9 };
	int arr2[] = { 1, 3, 5, 5, 8, 9 };
	m_BitSet::bitset<10> b1;
	m_BitSet::bitset<10> b2;
	
	// 这两步，放入位图，本质相当于去重
	for (auto e : arr1)
		b1.set(e);
	for (auto e : arr2)
		b2.set(e);
	
	for (size_t i = 0; i < 10; i++)
		if (b1.test(i) && b2.test(i))
			cout << i << " ";
	cout << endl;

}

// 问题三
// 位图应用变形：1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数
void testQuestion3()
{
	int arr1[] = { 1, 2, 3, 3, 4, 4, 4, 4, 4, 2, 3, 6, 3, 1, 5, 5, 8, 9 };
	//int arr1[] = { 1, 2, 3};

	m_BitSet::TwoBitSet_3<18> bt3;
	for (auto e : arr1)
		bt3.set(e);

	for (auto e : arr1)
		if (bt3.less_twice(e))
			cout << e << " ";
	cout << endl;
}

// 问题三 优化 增加一个 位图用去去重，将所有出现次数小于等于 两次 的数 ，都只打印一次
void testQuestion3_new()
{
	// 如果出现负数，需要开最大的空间
	int arr1[] = { 1, 2, 3, 3, 4, 4, 4, 4, 4, 2, 3, 6, 3, 1, 5, 5, 8, 9 };
	//int arr1[] = { 1, 2, 3};

	m_BitSet::TwoBitSet_3<18> bt3;
	for (auto e : arr1)
		bt3.set(e);

	m_BitSet::bitset<18> printed;	// 控制不打印重复的元素
	for (auto e : arr1)
	{
		if (bt3.less_twice(e) && !printed.test(e))
		{
			cout << (int)e << " ";
			printed.set(e);	// 每次打印过后，将其标记位存在，仅打印 出现少于两次且 未打印过的数据
		}
	}	
	cout << endl;
}

#include "bloomFilter.h"

void testBloomFilter()
{
	BloomFilter<11> bf;
	bf.Set("孙悟空");
	bf.Set("猪八戒");
	bf.Set("牛魔王");
	bf.Set("二郎神");

	cout << bf.Test("孙悟空") << endl;;
	cout << bf.Test("猪八戒") << endl;;
	cout << bf.Test("沙悟净") << endl;;
}


// 布隆过滤器 只要舍得开空间，误判率就可以降低到很低
void TestBloomFilter2()
{
	srand(time(0));
	const size_t N = 100000;
	BloomFilter<N * 8> bf;	// N * x x代表平均一个值 占多少个字节

	std::vector<std::string> v1;
	//std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
	std::string url = "猪八戒";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(i));
	}

	for (auto& str : v1)
	{
		bf.Set(str);
	}

	// v2跟v1是相似字符串集（前缀一样），但是不一样
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string urlstr = url;
		urlstr += std::to_string(9999999 + i);
		v2.push_back(urlstr);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.Test(str)) // 误判
		{
			++n2;
		}
	}
	cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

	// 不相似字符串集
	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		//string url = "zhihu.com";
		string url = "孙悟空";
		url += std::to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.Test(str))
		{
			++n3;
		}
	}
	cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
}
int main()
{
	//testBitSet();
	//testQuestion1();	// 问题一
	
	//testQuestion2();	// 问题二
	//testQuestion2_new();	// 问题二 优化版
	
	//testQuestion3();	// 问题三
	//testQuestion3_new();	// 问题三 优化版

	//testBloomFilter();
	TestBloomFilter2();
	return 0;
}