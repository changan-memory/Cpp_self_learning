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
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool insert(const K& key)
		{
			return _ht.Insert(key);
		}
	};
}