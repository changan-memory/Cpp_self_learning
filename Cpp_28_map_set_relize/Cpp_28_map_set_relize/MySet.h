#pragma once

#include "Red_Black_Tree.h"

namespace m_set
{
	template<class K>
	class set
	{
		// ��ȡ��
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
		// set �������޸ģ��������: set �ĵ�������const��������Ϊ const_iterator
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;

		// �����д����set �У������ iterator ʵ���� const_iterator
		/*iterator begin() const
		{
			return _tree.begin();
		}
		iterator end() const
		{
			return _tree.end();
		}*/

		// set �� iterator ���� const_iterator����˿���ֻ�ṩ const �汾�ĵ�����
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
			//�������� insert ���ص� iterator ������ �� ��ͨiterator
			// ���� set �� insert �ķ���ֵ pair�еĵ����� �� const_iterator
			
			// ����������Ƚ��� ����� ��ͨ������������ ��ͨ���������� const_������
			pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> ret = _tree.insert(key);

			// ������ ��ͨ������ȥ��ʼ�� const ������
			return pair<const_iterator, bool>(ret.first, ret.second);
		}
	};
}