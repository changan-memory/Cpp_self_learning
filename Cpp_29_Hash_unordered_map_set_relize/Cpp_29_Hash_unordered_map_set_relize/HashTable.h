#pragma once

#include <iostream>
#include <vector>
using namespace std;


// ���Ŷ�ַ���Ĺ�ϣ��
// ��ϣ����ÿ��λ�õ�״̬
enum STATE
{
	EXIST,
	EMPTY,
	DELETE
};

// ��ϣ�洢������
template<class K, class V>
struct HashData
{
	std::pair<K, V> _kv;
	enum STATE _state = EMPTY;
};

// ��ϣ��Ľṹ
template<class K, class V>
class HashTable
{
private:
	vector<HashData<K, V>> _table;
	size_t _n = 0;  // �洢����Ч���ݵĸ���   ��ϣ�Ƿ�ɢ�洢�ģ�vector �������洢�ģ���˼�ʹ vector ���� size,Ҳ��Ҫ��� _n

public:
	HashTable()
	{
		_table.resize(10);
	}

	HashData<const K, V>* find(const K& key) const
	{
		// ����̽��
		size_t hashi = key % _table.size();
		while (_table[hashi]._state != EMPTY)
		{
			if (_table[hashi]._state == EXIST
				&& _table[hashi]._kv.first == key)
			{
				//return (HashData<const K, V>*) & _table[hashi];
				return (static_cast<HashData<const K, V>*> ( & _table[hashi]));
			}
			++hashi;
			hashi %= _table.size();
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		// �ҵ��˲���ɾ��
		HashData<const K, V>* ret = find(key);
		if (ret)
		{
			ret->_state = DELETE;
			--_n;
			return true;
		}
		return false;
	}

	bool insert(const pair<K, V>& kv)
	{
		// ����ǰ��Ҫ���� �������� �� ����
		//if ((static_cast<double> (_n) / static_cast<double>(_table.size())) >= 7)
		if(_n * 10 / _table.size() >= 7)		// ����һ���ֿռ任ȡ����
		{
			size_t newSize = _table.size() * 2;
			// ���ݺ�ӳ���ϵ���ˣ���Ҫ����ӳ��
			// ����һ���µ� vector ����ӳ���ϵ �� ��ͻ
			HashTable<K, V> newHT;
			newHT._table.resize(newSize);
			// �����ɱ������ ���²��룬ӳ�䵽�±�   ֻ�� ���ڵ����� ����
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i]._state == EXIST)
				{
					// �����ٵ��� insert ʱ���Ѿ�resize���ˣ��������������̽���߼�
					newHT.insert(_table[i]._kv);
				}
			}
			_table.swap(newHT._table);
		}

		// ����̽��
		size_t hashi = kv.first % _table.size();
		// �ҵ��� hashi λ�ã����� exist delete empty ��
		// ����ʱ ��Ҫ�ҵ� ����̽�⣬ֻҪλ���������ݴ��ڣ���������̽��
		while (_table[hashi]._state == EXIST)
		{
			++hashi;
			hashi %= _table.size();
		}
		// ѭ���������ҵ���  ״̬Ϊ empty �� delete ��λ�ö����Բ���
		_table[hashi]._kv = kv;
		_table[hashi]._state = EXIST;
		++_n;
		return true;
	}
};