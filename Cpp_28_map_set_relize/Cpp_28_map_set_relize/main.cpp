#include <iostream>
using namespace std;

#include "MyMap.h"
#include "MySet.h"


int main()
{
	m_map::map<int, int> myMap;
	myMap.insert(make_pair(1, 2));
	myMap.insert(make_pair(2, 4));
	myMap.insert(make_pair(3, 6));

	m_set::set<int> mySet;
	mySet.insert(1);
	mySet.insert(2);
	mySet.insert(3);
	return 0;
}