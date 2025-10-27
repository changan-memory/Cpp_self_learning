﻿#include "HashTable.h"


//void testHash1()
//{
//	using namespace open_addr;
//	HashTable<int, int> hash;
//	int a[] = { 1, 111, 4, 7, 15, 25, 44, 9 };
//	for (auto e : a)
//	{
//		hash.insert(make_pair(e, e));
//	}
//
//	// 实现不能修改 key
//	/*auto ret = hash.find(4);
//	ret->_kv.first = 40;
//	ret->_kv.second = 400;*/
//
//	// 求 hashi 的时候 进行了 取模， string 不能取模，要解决 string 不能做 key 的问题
//	//HashTable<string, string, StringHashFunc> dict;
//	HashTable<string, string> dict;
//	dict.insert(make_pair("sort", "排序"));
//	dict.insert(make_pair("left", "左边"));
//	dict.insert(make_pair("right", "右边"));
//	auto ret = dict.find("right");
//	/*ret->_kv.first = "xx";
//	ret->_kv.second = "xx";*/
//
//	string s1("xxx");
//	string s2("xxx");
//
//	DefaultHashFunc<string> hf;
//	cout << hf(s1) << endl;
//	cout << hf(s2) << endl;
//	cout << hf("abcd") << endl;
//	cout << hf("acbd") << endl;
//	cout << hf("abbe") << endl;
//}
//
//void testHash2()
//{
//	using namespace hash_bucket;
//	HashTable<int, int> hash;
//	int a[] = { 1, 111, 4, 7, 15, 25, 44, 9 };
//	for (auto e : a)
//		hash.Insert(make_pair(e, e));
//
//	hash.Insert(make_pair(14, 14));
//	hash.Insert(make_pair(24, 24));
//	hash.Print();
//
//	hash.Insert(make_pair(34, 34));
//	hash.Print();
//
//	// 测试删除
//	hash.Erase(44);
//	hash.Erase(4);
//	hash.Erase(24);
//	hash.Print();
//
//	HashTable<string, string> dict;
//	dict.Insert(make_pair("sort", "排序"));
//	dict.Insert(make_pair("left", "左边"));
//	dict.Insert(make_pair("right", "右边"));
//	dict.Insert(make_pair("sort", "排序"));
//	dict.Insert(make_pair("left", "左边"));
//	dict.Insert(make_pair("right", "右边"));
//	dict.Insert(make_pair("sort", "排序"));
//	dict.Insert(make_pair("left", "左边"));
//	dict.Insert(make_pair("insert", "插入"));
//	dict.Insert(make_pair("string", "字符串"));
//	dict.Insert(make_pair("hello", "你好"));
//	dict.Insert(make_pair("world", "世界"));
//	dict.Insert(make_pair("bucket", "桶"));
//	dict.Insert(make_pair("operate system", "操作系统"));
//	dict.Insert(make_pair("Linux", "Linux 操作系统"));
//	dict.Insert(make_pair("windows", "windows操作系统"));
//	dict.Insert(make_pair("Mac OS", "Mac操作系统"));
//	
//
//	auto dret = dict.Find("left");
//	//dret->_kv.first = "xx";
//	dret->_kv.second = "xxxx";
//	dict.Print();
//
//	return;
//}


//int main()
//{
//	//testHash1();
//	//testHash2();
//	return 0;
//}

// 测试 unordered 系列
#include "UnOrderedMap.h"
#include "UnOrderedSet.h"

void test_un_set()
{
	m_unordered_set::unordered_set<int> us;
	us.insert(3);
	us.insert(1);
	us.insert(3);
	us.insert(4);
	us.insert(5);
	us.insert(0);
}
int main()
{
	test_un_set();
	return 0;
}