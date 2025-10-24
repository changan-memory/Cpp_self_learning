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

		// 库里的写法，set 中，这里的 iterator 实际是 const_iterator
		/*iterator begin() const
		{
			return _tree.begin();
		}
		iterator end() const
		{
			return _tree.end();
		}*/

		// set 的 iterator 都是 const_iterator，因此可以只提供 const 版本的迭代器
		const_iterator begin() const
		{
			return _tree.begin();
		}
		const_iterator end() const
		{
			return _tree.end();
		}

		// set 
		// 
		pair<iterator, bool> insert(const K& key)
		{
			
			//return _tree.insert(key);	
			//这里树的 insert 返回的 iterator 是树里 的 普通iterator
			// 但是 set 的 insert 的返回值 pair中的迭代器 是 const_iterator
			
			// 解决方法，先接收 树里的 普通迭代器，再用 普通迭代器构造 const_迭代器
			pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> ret = _tree.insert(key);

			// 下面用 普通迭代器去初始化 const 迭代器
			return pair<const_iterator, bool>(ret.first, ret.second);
		}
	};
}