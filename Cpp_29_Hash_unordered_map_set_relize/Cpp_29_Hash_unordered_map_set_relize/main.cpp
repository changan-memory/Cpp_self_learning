#include "HashTable.h"


void testHash1()
{

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
}
int main()
{
	testHash1();
	return 0;
}