#pragma once

#include "Red_Black_Tree.h"

namespace m_set
{
	template<class K>
	class set
	{
		// ÝÍÈ¡Æ÷
		struct SetKeyOfT
		{
			const K& operator()(const K& key) const
			{
				return key;
			}
		};
		RBTree<K, K, SetKeyOfT> _tree;
	public:
		bool insert(const K& key)
		{
			return _tree.insert(key);
		}
	};
}