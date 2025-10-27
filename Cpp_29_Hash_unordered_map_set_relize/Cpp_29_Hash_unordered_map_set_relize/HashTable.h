#pragma once

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;


//// ��ɢ�е� ���Ŷ�ַ���Ĺ�ϣ��
//namespace open_addr
//{
//	// ��ϣ����ÿ��λ�õ�״̬
//	enum STATE
//	{
//		EXIST,
//		EMPTY,
//		DELETE
//	};
//
//	// ��ϣ�洢������
//	template<class K, class V>
//	struct HashData
//	{
//		std::pair<K, V> _kv;
//		enum STATE _state = EMPTY;
//	};
//
//	// ʹ�÷º������� string �� �������͵�ȡģ
//	template<class K>
//	struct DefaultHashFunc
//	{
//		size_t operator()(const K& key)
//		{
//			return static_cast<size_t> (key);
//		}
//	};
//
//	//// ��ʽһ: ר��Ϊ string дһ�� ��ϣ������ʹ�õ�һ�� char ����
//	//struct StringHashFunc
//	//{
//	//	size_t operator()(const string& str)
//	//	{
//	//		return static_cast<size_t> (str[0]);
//	//	}
//	//};
//
//	// Ϊ string �ػ�һ���汾 ��ϣ����
//
//	template <>
//	struct DefaultHashFunc<string>
//	{
//		size_t operator()(const string& str)
//		{
//			// BKDR
//			size_t hash = 0;
//			for (auto ch : str) {
//				hash *= 131;
//				hash += ch;
//			}
//			return hash;
//		}
//	};
//
//	// ��ϣ��Ľṹ
//	template<class K, class V, class HashFunc = DefaultHashFunc<K>>		// Ĭ��ʹ�����͵Ĺ�ϣ����
//	class HashTable
//	{
//	private:
//		vector<HashData<K, V>> _table;	// vector ���Զ������ͣ�����ʵ����������
//		size_t _n = 0;  // �洢����Ч���ݵĸ���   ��ϣ�Ƿ�ɢ�洢�ģ�vector �������洢�ģ���˼�ʹ vector ���� size,Ҳ��Ҫ��� _n
//
//	public:
//		HashTable()
//		{
//			_table.resize(10);
//		}
//		bool insert(const pair<K, V>& kv)
//		{
//			if (find(kv.first))
//				return false;
//
//			// ����ǰ��Ҫ���� �������� �� ����
//			//if ((static_cast<double> (_n) / static_cast<double>(_table.size())) >= 7)
//			if (_n * 10 / _table.size() >= 7)		// ����һ���ֿռ任ȡ����
//			{
//				size_t newSize = _table.size() * 2;
//				// ���ݺ�ӳ���ϵ���ˣ���Ҫ����ӳ��
//				// ����һ���µ� vector ����ӳ���ϵ �� ��ͻ
//				HashTable<K, V, HashFunc> newHT;
//				newHT._table.resize(newSize);
//				// �����ɱ������ ���²��룬ӳ�䵽�±�   ֻ�� ���ڵ����� ����
//				for (size_t i = 0; i < _table.size(); i++)
//				{
//					if (_table[i]._state == EXIST)
//					{
//						// �����ٵ��� insert ʱ���Ѿ�resize���ˣ��������������̽���߼�
//						newHT.insert(_table[i]._kv);
//					}
//				}
//				_table.swap(newHT._table);
//			}
//
//			// ����̽��
//			HashFunc hs;
//			size_t hashi = hs(kv.first) % _table.size();
//			// �ҵ��� hashi λ�ã����� exist delete empty ��
//			// ����ʱ ��Ҫ�ҵ� ����̽�⣬ֻҪλ���������ݴ��ڣ���������̽��
//			while (_table[hashi]._state == EXIST)
//			{
//				++hashi;
//				hashi %= _table.size();
//			}
//			// ѭ���������ҵ���  ״̬Ϊ empty �� delete ��λ�ö����Բ���
//			_table[hashi]._kv = kv;
//			_table[hashi]._state = EXIST;
//			++_n;
//			return true;
//		}
//		HashData<const K, V>* find(const K& key) const
//		{
//			// ����̽��
//			HashFunc hs;
//
//			size_t hashi = hs(key) % _table.size();
//			while (_table[hashi]._state != EMPTY)
//			{
//				if (_table[hashi]._state == EXIST
//					&& _table[hashi]._kv.first == key)
//				{
//					//return (HashData<const K, V>*) & _table[hashi];
//					return (HashData<const K, V>*) & _table[hashi];
//				}
//				++hashi;
//				hashi %= _table.size();
//			}
//			return nullptr;
//		}
//
//		bool Erase(const K& key)
//		{
//			// �ҵ��˲���ɾ��
//			HashData<const K, V>* ret = find(key);
//			if (ret)
//			{
//				ret->_state = DELETE;
//				--_n;
//				return true;
//			}
//			return false;
//		}
//	};
//}


namespace hash_bucket
{
	// ʹ�÷º������� string �� �������͵�ȡģ
	template<class K>
	struct DefaultHashFunc
	{
		size_t operator()(const K& key)
		{
			return static_cast<size_t> (key);
		}
	};

	//// ��ʽһ: ר��Ϊ string дһ�� ��ϣ������ʹ�õ�һ�� char ����
	//struct StringHashFunc
	//{
	//	size_t operator()(const string& str)
	//	{
	//		return static_cast<size_t> (str[0]);
	//	}
	//};

	// Ϊ string �ػ�һ���汾 ��ϣ����

	template <>
	struct DefaultHashFunc<string>
	{
		size_t operator()(const string& str)
		{
			// BKDR
			size_t hash = 0;
			for (auto ch : str) {
				hash *= 131;
				hash += ch;
			}
			return hash;
		}
	};

	//template<class K, class V>
	template<class T>
	struct HashNode
	{
		T _data;
		struct HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{ }
	};


	// ʵ�ֵ�����
	// Ϊ�˷������������һ����ϣ���ָ��
	template<class K, class T, class KeyOfT, class HashFunc = DefaultHashFunc<K>>
	struct HTIterator
	{
		typedef struct HashNode<T> Node;
		typedef struct HTIterator<K, T, KeyOfT, HashFunc> Self;

		HashTable<K, T, KeyOfT, HashFunc>* _pht;

		Node* _node;

		HTIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			,_pht(pht)
		{ }

		Self operator++()
		{
			// ��ǰͰû�꣬���ҵ�ǰͰ��λ��
			if (_node->_next)
				_node = _node->_next;
			// ��ǰͰ�����ˣ���ȥ��һ��Ͱ��
			else
			{
				KeyOfT kot;
				HashFunc hf;

				size_t hashi = hf((kot(_node->_data))) % _pht->_table.size();
				// ����һ��λ�� �Ҳ�Ϊ�յ� Ͱ
				++hashi;
				while (hashi < _pht->_table.size())
				{
					// ��Ϊ�գ������ҵ���
					if (_pht->_table[hashi])
					{
						_node = _pht->_table[hashi];
						return *this;
					}
					else
						++hashi;
				}
				// ѭ����û�з��أ�����û�ҵ������� nullptr ��ʾ �������� end()
				_node = nullptr;
				return *this;
			}
		}
		Self operator++(int) 
		{
			Self tmp(*this);
			++(*this);
			return tmp;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}
		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}
	};



	// set -> hash_bucket::HashTable<K, K> _ht;
	// map -> hash_bucket::HashTable<K, std::pair<K, V>> _ht;
	template<class K, class T, class KeyOfT, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
	private:
		//typedef struct HashNode<K, V> Node;
		typedef struct HashNode<T> Node;

		vector<Node*> _table;	// ��Ҫд��������
		size_t _n = 0;
	public:
		typedef struct HTIterator<K, T, KeyOfT, HashFunc> iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* curNode = _table[i];
				if (curNode)
					return iterator(_table[i], this);
			}
			// û�ҵ������ؿ�
			return iterator(nullptr, this);
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}

		HashTable()
		{
			_table.resize(10, nullptr);
		}
		// ��Ҫ�ֶ�����Ͱ�еĽڵ�
		~HashTable()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* curNode = _table[i];
				while (curNode)
				{
					Node* curNext = curNode->_next;
					
					delete curNode;
					curNode = curNext;
				}
				_table[i] = nullptr;
			}
		}


		bool Insert(const T& data)
		{
			KeyOfT kot;

			if (Find(kot(data)))
				return false;
			HashFunc hf;

			// �����߼�
			// ���Ƹ������� Ϊ 1 ʱ����
			if (static_cast<double> (_n) / static_cast<double> (_table.size()) >= 1.0)
			{
				size_t newSize = _table.size() * 2;
				vector<Node*> newTable;;
				newTable.resize(newSize, nullptr);

				// ����ÿ��Ͱ����ÿ��Ͱ�еĽڵ㶼�ù���
				for (size_t i = 0; i < _table.size(); ++i)
				{
					Node* curNode = _table[i];
					while (curNode)
					{
						Node* curNext = curNode->_next;
						//size_t hashi = i % newSize;	// �Լ�д��ʱ��д��ĵ�
						size_t hashi = hf(kot(curNode->_data)) % newSize;

						curNode->_next = newTable[hashi];
						newTable[hashi] = curNode;

						//curNode = curNode->_next;
						curNode = curNext;
					}
					_table[i] = nullptr;
				}
				_table.swap(newTable);
			}
			// �ҽ����߼�
			size_t hashi = hf(kot(data)) % _table.size();

			Node* newNode = new Node(data);
			// ͷ��
			newNode->_next = _table[hashi];
			_table[hashi] = newNode;
			++_n;
			return true;
		}

		Node* Find(const K& key) const
		{
			KeyOfT kot;

			HashFunc hf;
			size_t hashi = hf(key) % _table.size();
			
			Node* curNode = _table[hashi];
			while (curNode)
			{
				if (kot(curNode->_data) == key)
					return curNode;
				curNode = curNode->_next;
			}
			return nullptr;
		}

		// �������ɾ����Ҫ����ǰһ������ next ָ�룬���ʺϸ��� find
		bool Erase(const K& key)
		{
			KeyOfT kot;

			HashFunc hf;
			size_t hashi = hf(key) % _table.size();

			Node* curPrev = nullptr;
			Node* curNode = _table[hashi];
			while (curNode)
			{
				if (kot(curNode->_data) == key)
				{
					if (curPrev == nullptr) // ͷɾ
						_table[hashi] = curNode->_next;	
					else  // ��ͷɾ
						curPrev->_next = curNode->_next;

					delete curNode;
					return true;
				}
				curPrev = curNode;
				curNode = curNode->_next;
			}
			return false;
		}
		void Print()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				printf("[%d]->", i);
				Node* curNode = _table[i];
				while (curNode)
				{
					cout << curNode->_data << ":" << curNode->_data << "->";
					curNode = curNode->_next;
				}
				printf("NULL\n");
			}
			cout << endl;
		}
	};

}