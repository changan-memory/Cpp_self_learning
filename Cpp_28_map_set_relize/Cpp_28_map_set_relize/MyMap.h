#pragma once

#include "Red_Black_Tree.h"

namespace m_map
{
	template<class K, class V>
	class map
	{
		// 萃取器  把 T 对象中的 key 取出来
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv) const
			{
				return kv.first;
			}
		};
		RBTree<K, pair<K, V>, MapKeyOfT> _tree;
	public:
		bool insert(const pair<K, V>& kv)
		{
			return _tree.insert(kv);
		}
	};
}