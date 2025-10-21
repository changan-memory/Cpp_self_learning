#include "HashTable.h"


void testHash1()
{
	using namespace open_addr;
	HashTable<int, int> hash;
	int a[] = { 1, 111, 4, 7, 15, 25, 44, 9 };
	for (auto e : a)
	{
		hash.insert(make_pair(e, e));
	}

	// 实现不能修改 key
	/*auto ret = hash.find(4);
	ret->_kv.first = 40;
	ret->_kv.second = 400;*/

	// 求 hashi 的时候 进行了 取模， string 不能取模，要解决 string 不能做 key 的问题
	//HashTable<string, string, StringHashFunc> dict;
	HashTable<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("right", "右边"));
	auto ret = dict.find("right");
	/*ret->_kv.first = "xx";
	ret->_kv.second = "xx";*/

	string s1("xxx");
	string s2("xxx");

	DefaultHashFunc<string> hf;
	cout << hf(s1) << endl;
	cout << hf(s2) << endl;
	cout << hf("abcd") << endl;
	cout << hf("acbd") << endl;
	cout << hf("abbe") << endl;
}
int main()
{
	testHash1();
	return 0;
}