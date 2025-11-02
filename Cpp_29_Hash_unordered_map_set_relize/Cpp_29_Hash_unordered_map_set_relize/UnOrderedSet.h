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

		/*pair<iterator, bool> insert(const K& key)
		{
			pair<typename hash_bucket::HTIterator<> bool>
			return _ht.Insert(key);
		}*/
	};
}