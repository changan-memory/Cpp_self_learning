#pragma once

#include "Red_Black_Tree.h"

namespace m_set
{
	template<class K>
	class set
	{
		// 萃取器
		struct SetKeyOfT
		{
			const K& operator()(const K& key) const
			{
				return key;
			}
		};
		RBTree<K, K, SetKeyOfT> _tree;
	public:
		//typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;
		// set 不允许修改，解决方案: set 的迭代器和const迭代器均为 const_iterator
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;

		const_iterator begin() const
		{
			return _tree.begin();
		}
		const_iterator end() const
		{
			return _tree.end();
		}

		bool insert(const K& key)
		{
			return _tree.insert(key);
		}
	};
}