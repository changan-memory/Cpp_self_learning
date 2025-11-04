#include "HashTable.h"

namespace m_unordered_set
{
	template<class K>
	class unordered_set
	{
	private:
		struct SetKeyOfT
		{
			const K& operator()(const K& key) const
			{
				return key;
			}
		};
		hash_bucket::HashTable<K, K, SetKeyOfT> _ht;

	public:
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::const_iterator const_iterator;

		const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}

		//pair<iterator, bool> insert(const K& key)
		pair<const_iterator, bool> insert(const K& key)
		{
			pair<typename hash_bucket::HashTable<K, K, SetKeyOfT>::iterator, bool> ret = _ht.Insert(key);
			return pair<const_iterator, bool>(ret.first, ret.second);
			
			// 返回的是 pair<iterator, bool>，这里的 iterator 是 哈希表中的 普通 iterator
			 //return _ht.Insert(key);		

			// set 中的 pair<iterator, bool> 本质是 pair<const_iterator, bool>
			// 两个 pair 实例化成了 不同的类型，不能互相转换
		}
		//pair<iterator, bool> insert(const K& key)
		/*pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}*/

		//pair<iterator, bool> insert(const K& key)
		//{
		//	// 这里树的 insert 返回的 iterator 是树里 的 普通iterator
		//	// 但是 set 中 insert 的返回值 pair 中的迭代器 是 const_iterator

		//	// 解决方法，先接收 树里的 普通迭代器，再用 普通迭代器构造 const_迭代器 返回
		//	pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> retPair = _tree.insert(key);

		//	// 下面用 普通迭代器去构造 const 迭代器 并 返回
		//	return pair<const_iterator, bool>(retPair.first, retPair.second);
		//}
	};
}