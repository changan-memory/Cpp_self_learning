#pragma once

#include "Red_Black_Tree.h"

namespace m_map
{
	template<class K, class V>
	class map
	{
	private:
		// 萃取器  把 T 对象中的 key 取出来
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv) const
			{
				return kv.first;
			}

		};
		// map 要求实现只能修改 key 不能修改 value
		// 这样定义，pair 可以修改， pair 中的 K 不能修改
		RBTree<K, pair<const K, V>, MapKeyOfT> _tree;
	public:
		// 按照 set 实现 const 迭代器的方法实现的话，会导致 map 的 value 也不能修改
		/*typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::const_iterator const_iterator;*/

		// key 不能修改， value 能修改
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;

		iterator begin()
		{
			return _tree.begin();
		}
		iterator end()
		{
			return _tree.end();
		}

		const_iterator begin() const
		{
			return _tree.begin();
		}
		const_iterator end() const
		{
			return _tree.end();
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return (ret.first)->second;
		}

		std::pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _tree.insert(kv);
		}
	};
}