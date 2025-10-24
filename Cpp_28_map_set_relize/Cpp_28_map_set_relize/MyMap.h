#pragma once

#include "Red_Black_Tree.h"

namespace m_map
{
	template<class K, class V>
	class map
	{
	private:
		// ��ȡ��  �� T �����е� key ȡ����
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv) const
			{
				return kv.first;
			}

		};
		// map Ҫ��ʵ��ֻ���޸� key �����޸� value
		// �������壬pair �����޸ģ� pair �е� K �����޸�
		RBTree<K, pair<const K, V>, MapKeyOfT> _tree;
	public:
		// ���� set ʵ�� const �������ķ���ʵ�ֵĻ����ᵼ�� map �� value Ҳ�����޸�
		/*typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::const_iterator const_iterator;*/

		// key �����޸ģ� value ���޸�
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