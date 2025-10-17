#pragma once

#include "Red_Black_Tree.h"

namespace m_map
{
	template<class K, class V>
	class map
	{
		// ��ȡ��  �� T �����е� key ȡ����
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