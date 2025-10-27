#pragma once
#include "HashTable.h"

namespace m_unordered_map
{
	template<class K, class V>
	class unordered_map
	{
	private:
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv) const
			{
				return kv.first;
			}
		};
		hash_bucket::HashTable<K, std::pair<K, V>, MapKeyOfT> _ht;

	public:
		bool insert(const pair<K, V>& _kv)
		{
			return _ht.Insert(_kv);
		}
	};
}