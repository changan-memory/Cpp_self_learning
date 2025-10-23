#include <iostream>
using namespace std;

#include "MyMap.h"
#include "MySet.h"

void testSet()
{
	m_set::set<int> mySet;
	mySet.insert(1);
	mySet.insert(2);
	mySet.insert(3);
	mySet.insert(21);
	mySet.insert(37);
	mySet.insert(399);
	mySet.insert(426);
	mySet.insert(50);
	mySet.insert(548);
	mySet.insert(2);
	m_set::set<int>::iterator it = mySet.begin();
	while (it != mySet.end())
	{
		//*it = 10;	// set 不允许修改
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (const auto& key : mySet)
		cout << key << " ";

	cout << endl << endl;;
}


void test_const_map(const m_map::map<int, int>& m)
{
	//auto mit = m.begin();
	m_map::map<int, int>::const_iterator mit = m.begin();
	while (mit != m.end())
	{
		// map 不能修改key，不能修改value
		/*mit->first = 1;
		mit->second = 2;*/

		cout << mit->first << ":" << mit->second << endl;
		++mit;
	}
	cout << endl;
}

void testMap()
{
	m_map::map<int, int> myMap;
	myMap.insert(make_pair(1, 2));
	myMap.insert(make_pair(2, 4));
	myMap.insert(make_pair(3, 6));
	myMap.insert(make_pair(15, 18));
	myMap.insert(make_pair(20, 10));
	myMap.insert(make_pair(8, 9));

	//test_const_map(myMap);

	m_map::map<int, int>::iterator it = myMap.begin();
	while (it != myMap.end())
	{
		// 两种访问方式都可以
		//cout << (*it).first << " ";
		//cout << *it << endl;	// map 中   *it  得到的是一个 pair类型，pair 不支持 流提取
		cout << it->first << ": " << it->second << endl;
		//cout << it->->first << ": " << it->->second << endl;
		// 严格来说是两个箭头， it-> 返回 T 的地址，再用 -> 访问数据
		++it;
	}

	cout << endl;
	for (const auto& kv : myMap)
		cout << kv.first << ": " << kv.second << endl;
}


// 还需手动实现 set 和 map 的 const 属性
// set 不允许 修改 Key, map 不允许修改 Key,但允许修改 V
int main()
{
	//testSet();
	testMap();

	return 0;
}