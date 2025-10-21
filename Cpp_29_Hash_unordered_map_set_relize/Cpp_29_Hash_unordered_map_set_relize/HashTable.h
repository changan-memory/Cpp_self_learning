#pragma once

#include <iostream>
#include <vector>
using namespace std;


// 开放定址法的哈希表
// 哈希表中每个位置的状态
enum STATE
{
	EXIST,
	EMPTY,
	DELETE
};

// 哈希存储的数据
template<class K, class V>
struct HashData
{
	std::pair<K, V> _kv;
	enum STATE _state = EMPTY;
};

// 哈希表的结构
template<class K, class V>
class HashTable
{
private:
	vector<HashData<K, V>> _table;
	size_t _n = 0;  // 存储的有效数据的个数   哈希是分散存储的，vector 是连续存储的，因此即使 vector 中有 size,也需要这个 _n

public:
	HashTable()
	{
		_table.resize(10);
	}

	HashData<const K, V>* find(const K& key) const
	{
		// 线性探测
		size_t hashi = key % _table.size();
		while (_table[hashi]._state != EMPTY)
		{
			if (_table[hashi]._state == EXIST
				&& _table[hashi]._kv.first == key)
			{
				//return (HashData<const K, V>*) & _table[hashi];
				return (static_cast<HashData<const K, V>*> ( & _table[hashi]));
			}
			++hashi;
			hashi %= _table.size();
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		// 找到了才能删除
		HashData<const K, V>* ret = find(key);
		if (ret)
		{
			ret->_state = DELETE;
			--_n;
			return true;
		}
		return false;
	}

	bool insert(const pair<K, V>& kv)
	{
		// 插入前需要控制 负载因子 和 扩容
		//if ((static_cast<double> (_n) / static_cast<double>(_table.size())) >= 7)
		if(_n * 10 / _table.size() >= 7)		// 牺牲一部分空间换取性能
		{
			size_t newSize = _table.size() * 2;
			// 扩容后映射关系变了，需要重新映射
			// 创建一个新的 vector 处理映射关系 和 冲突
			HashTable<K, V> newHT;
			newHT._table.resize(newSize);
			// 遍历旧表的数据 重新插入，映射到新表   只把 存在的区域 拷贝
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i]._state == EXIST)
				{
					// 这里再调用 insert 时，已经resize过了，会走下面的线性探测逻辑
					newHT.insert(_table[i]._kv);
				}
			}
			_table.swap(newHT._table);
		}

		// 线性探测
		size_t hashi = kv.first % _table.size();
		// 找到的 hashi 位置，可能 exist delete empty ，
		// 插入时 需要找到 线性探测，只要位置已有数据存在，就向后继续探测
		while (_table[hashi]._state == EXIST)
		{
			++hashi;
			hashi %= _table.size();
		}
		// 循环结束后，找到了  状态为 empty 和 delete 的位置都可以插入
		_table[hashi]._kv = kv;
		_table[hashi]._state = EXIST;
		++_n;
		return true;
	}
};