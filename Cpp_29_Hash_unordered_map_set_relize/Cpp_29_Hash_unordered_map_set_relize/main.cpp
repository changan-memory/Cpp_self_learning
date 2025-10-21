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

	// ʵ�ֲ����޸� key
	/*auto ret = hash.find(4);
	ret->_kv.first = 40;
	ret->_kv.second = 400;*/

	// �� hashi ��ʱ�� ������ ȡģ�� string ����ȡģ��Ҫ��� string ������ key ������
	//HashTable<string, string, StringHashFunc> dict;
	HashTable<string, string> dict;
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("left", "���"));
	dict.insert(make_pair("right", "�ұ�"));
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