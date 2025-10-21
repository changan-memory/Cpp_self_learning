#include "HashTable.h"


void testHash1()
{

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
}
int main()
{
	testHash1();
	return 0;
}