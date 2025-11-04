#pragma once

#include <iostream>
#include <vector>
#include <stdio.h>
#include <assert.h>

using namespace std;


//// 闭散列的 开放定址法的哈希表
//namespace open_addr
//{
//	// 哈希表中每个位置的状态
//	enum STATE
//	{
//		EXIST,
//		EMPTY,
//		DELETE
//	};
//
//	// 哈希存储的数据
//	template<class K, class V>
//	struct HashData
//	{
//		std::pair<K, V> _kv;
//		enum STATE _state = EMPTY;
//	};
//
//	// 使用仿函数控制 string 和 其他整型的取模
//	template<class K>
//	struct DefaultHashFunc
//	{
//		size_t operator()(const K& key)
//		{
//			return static_cast<size_t> (key);
//		}
//	};
//
//	//// 方式一: 专门为 string 写一个 哈希函数，使用第一个 char 控制
//	//struct StringHashFunc
//	//{
//	//	size_t operator()(const string& str)
//	//	{
//	//		return static_cast<size_t> (str[0]);
//	//	}
//	//};
//
//	// 为 string 特化一个版本 哈希函数
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
//	// 哈希表的结构
//	template<class K, class V, class HashFunc = DefaultHashFunc<K>>		// 默认使用整型的哈希函数
//	class HashTable
//	{
//	private:
//		vector<HashData<K, V>> _table;	// vector 存自定义类型，无需实现析构函数
//		size_t _n = 0;  // 存储的有效数据的个数   哈希是分散存储的，vector 是连续存储的，因此即使 vector 中有 size,也需要这个 _n
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
//			// 插入前需要控制 负载因子 和 扩容
//			//if ((static_cast<double> (_n) / static_cast<double>(_table.size())) >= 7)
//			if (_n * 10 / _table.size() >= 7)		// 牺牲一部分空间换取性能
//			{
//				size_t newSize = _table.size() * 2;
//				// 扩容后映射关系变了，需要重新映射
//				// 创建一个新的 vector 处理映射关系 和 冲突
//				HashTable<K, V, HashFunc> newHT;
//				newHT._table.resize(newSize);
//				// 遍历旧表的数据 重新插入，映射到新表   只把 存在的区域 拷贝
//				for (size_t i = 0; i < _table.size(); i++)
//				{
//					if (_table[i]._state == EXIST)
//					{
//						// 这里再调用 insert 时，已经resize过了，会走下面的线性探测逻辑
//						newHT.insert(_table[i]._kv);
//					}
//				}
//				_table.swap(newHT._table);
//			}
//
//			// 线性探测
//			HashFunc hs;
//			size_t hashi = hs(kv.first) % _table.size();
//			// 找到的 hashi 位置，可能 exist delete empty ，
//			// 插入时 需要找到 线性探测，只要位置已有数据存在，就向后继续探测
//			while (_table[hashi]._state == EXIST)
//			{
//				++hashi;
//				hashi %= _table.size();
//			}
//			// 循环结束后，找到了  状态为 empty 和 delete 的位置都可以插入
//			_table[hashi]._kv = kv;
//			_table[hashi]._state = EXIST;
//			++_n;
//			return true;
//		}
//		HashData<const K, V>* find(const K& key) const
//		{
//			// 线性探测
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
//			// 找到了才能删除
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
	// 使用仿函数控制 string 和 其他整型的取模
	template<class K>
	struct DefaultHashFunc
	{
		size_t operator()(const K& key)
		{
			return static_cast<size_t> (key);
		}
	};

	//// 方式一: 专门为 string 写一个 哈希函数，使用第一个 char 控制
	//struct StringHashFunc
	//{
	//	size_t operator()(const string& str)
	//	{
	//		return static_cast<size_t> (str[0]);
	//	}
	//};

	// 为 string 特化一个版本 哈希函数

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

	// 提前声明哈希表  告诉编译器， HashTable 类型已有定义
	//template<class K, class T, class KeyOfT, class HashFunc>
	template<class K, class T, class KeyOfT, class HashFunc = DefaultHashFunc<K>>
	class HashTable;

	// 1. 改造哈希表  KeyOfT
	// 2. 封装 map 和 set   MapKeyOfT  SetKeyOfT
	// 3. 普通迭代器     operator++   operator...
	// 4. const 迭代器		通过模板参数控制
	// 5. 实现 key 不能修改的问题
	// 5. insert 返回值        由普通迭代器构造 const 迭代器

	// 实现迭代器
	// 为了方便操作，存了一个哈希表的指针
	template<class K, class T, class Ptr, class Ref, class KeyOfT, class HashFunc>
	struct HTIterator
	{
		typedef struct HashNode<T> Node;
		typedef struct HTIterator<K, T, Ptr, Ref, KeyOfT, HashFunc> Self;

		// 始终为 普通迭代器， 可用于 普通迭代器 构造 const 迭代器
		typedef struct HTIterator<K, T, T*, T&, KeyOfT, HashFunc> Iterator;

		Node* _node;	// 当前结点的指针
	
		//HashTable<K, T, KeyOfT, HashFunc>* _pht;
		// 需要哈希表的指针  是因为  当前桶走完了，需要走到下一个桶

		const HashTable<K, T, KeyOfT, HashFunc>* _pht;	  // 当前哈希表的指针
		
		//HashTable<K, T, KeyOfT, HashFunc>* _pht;	  // 当前哈希表的指针

		HTIterator(Node* node, const HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			,_pht(pht)
		{ }

		// 由 普通 iterator 构造 const iterator
		HTIterator(const Iterator& it)	// 该函数 可以不写
			:_node(it._node)
			, _pht(it._pht)
		{ }

		//HTIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)	// 该函数 可以不写
		//	:_node(node)
		//	, _pht(pht)
		//{ }

		Ref operator*() const
		{
			if (_node == nullptr)
				assert(false);
			return _node->_data;
		}

		Ptr operator->() const
		{
			if (_node == nullptr)
				assert(false);
			return &(_node->_data);
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}
		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}

		// 单向迭代器，不支持--
		Self& operator++()
		{
			// 当前桶没完，就找当前桶的位置
			if (_node->_next)
			{
				_node = _node->_next;
				return *this;
			}
			// 当前桶结束了，就去下一个桶找
			else
			{
				KeyOfT kot;

				HashFunc hf;
				// _table 是 哈希表的 private 成员，迭代器类无法直接访问 
				size_t hashi = hf((kot(_node->_data))) % _pht->_table.size();
				// 从下一个位置开始，查找下一个不为空的 桶
				++hashi;
				while (hashi < _pht->_table.size())
				{
					// 不为空，就是找到了
					if (_pht->_table[hashi])
					{
						_node = _pht->_table[hashi];
						return *this;
					}
					else
						++hashi;
				}
				// 循环内没有返回，代表走到表尾没找到下一个非空桶
				// 返回 nullptr 表示 迭代器的 end()
				_node = nullptr;
				return *this;
			}
		}
		// 后置 ++
		Self operator++(int) 
		{
			Self tmp(*this);
			++(*this);
			return tmp;
		}
	};



	// set -> hash_bucket::HashTable<K, K> _ht;
	// map -> hash_bucket::HashTable<K, std::pair<K, V>> _ht;
	//template<class K, class T, class KeyOfT, class HashFunc = DefaultHashFunc<K>>
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable
	{
		//typedef struct HashNode<K, V> Node;
		typedef struct HashNode<T> Node;

		template<class K, class T, class Ptr, class Ref, class KeyOfT, class HashFunc>
		friend struct HTIterator;

	private:
		vector<Node*> _table;	// 需要写析构函数
		size_t _n = 0;

	public:
		typedef struct HTIterator<K, T, T*, T&, KeyOfT, HashFunc> iterator;
		typedef struct HTIterator<K, T, const T*, const T&, KeyOfT, HashFunc> const_iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* curNode = _table[i];
				if (curNode)
					return iterator(_table[i], this);
			}
			// 没找到，返回空
			return iterator(nullptr, this);
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}

		const_iterator begin() const
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* curNode = _table[i];
				if (curNode)
					return iterator(_table[i], this);
			}
			// 没找到，返回空
			return const_iterator(nullptr, this);
		}
		const_iterator end() const
		{
			return const_iterator(nullptr, this);
		}

		HashTable()
		{
			_table.resize(11, nullptr);
		}
		// 需要手动析构桶中的节点
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
		inline size_t GetNextPrime(size_t prime)
		{
			const int PRIMECOUNT = 28;
			static const size_t primeList[PRIMECOUNT] =
			{
				53ul, 97ul, 193ul, 389ul, 
				769ul, 1543ul, 3079ul, 6151ul, 
				12289ul, 24593ul, 49157ul, 98317ul, 
				196613ul, 393241ul, 786433ul, 1572869ul, 
				3145739ul, 6291469ul, 12582917ul, 25165843ul, 
				50331653ul, 100663319ul, 201326611ul, 402653189ul,
				805306457ul, 1610612741ul, 3221225473ul, 4294967291ul
			};

			size_t i = 0;
			for (; i < PRIMECOUNT; ++i)
			{
				if (primeList[i] > prime)
					return primeList[i];
			}
			return primeList[i];
		}

		/*------------------任务：实现“获取下一个 >=n 的质数的函数”---> “用于哈希表扩容”------------------*/
		inline unsigned long _stl_next_prime(unsigned long n)
		{
			//1.指定素数表的大小
			static const int __stl_num_primes = 28;

			//2.定义素数表覆盖常见哈希表大小
			static const unsigned long _stl_prime_list[__stl_num_primes] =   //注意：这里的素数表的类型是unsigned long 类型
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};

			//3.使用二分查找找到第一个 >=n 的素数
			//3.1：使用一个指针指向素数表中的“第一个素数”
			const unsigned long* first = _stl_prime_list;

			//3.1：使用一个指针指向素数表中的“最后一素数的下一位置”
			const unsigned long* last = _stl_prime_list + __stl_num_primes;

			//3.3：使用lower_bound()接口函数求出第一个 >=n 的素数
			const unsigned long* pos = lower_bound(first, last, n);

			//3.4：适合作为哈希表容量的质数
			return pos == last ? *(last - 1) : *pos;

			/*
			*  说明遍历完质数表，所有预定义的质数都比 n 小
			*  此时返回最大的质数 *(last - 1)，因为 last 是数组末尾的下一个位置，last - 1 指向最后一个有效质数
			*/
		}


		pair<iterator, bool> Insert(const T& data)
		{
			KeyOfT kot;
			iterator it = Find(kot(data));

			if (it != end())
				return std::make_pair(it, false);

			HashFunc hf;

			// 扩容逻辑
			// 控制负载因子 为 1 时扩容
			if (static_cast<double> (_n) / static_cast<double> (_table.size()) >= 1.0)
			{
				size_t newSize = GetNextPrime(_table.size());
				//size_t newSize = _table.size() * 2;
				vector<Node*> newTable;;
				newTable.resize(newSize, nullptr);

				// 遍历每个桶，将每个桶中的节点都拿过来
				for (size_t i = 0; i < _table.size(); ++i)
				{
					Node* curNode = _table[i];
					while (curNode)
					{
						Node* curNext = curNode->_next;
						//size_t hashi = i % newSize;	// 自己写的时候写错的点
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
			// 挂结点的逻辑
			size_t hashi = hf(kot(data)) % _table.size();

			Node* newNode = new Node(data);
			// 头插
			newNode->_next = _table[hashi];
			_table[hashi] = newNode;
			++_n;
			return std::make_pair(iterator(newNode, this), true);
			//return pair<iterator, bool>(newNode, true);
		}

		iterator Find(const K& key) const
		{
			KeyOfT kot;

			HashFunc hf;
			size_t hashi = hf(key) % _table.size();
			
			Node* curNode = _table[hashi];
			while (curNode)
			{
				if (kot(curNode->_data) == key)
					return iterator(curNode, this);
				curNode = curNode->_next;
			}
			return iterator(nullptr, this);
		}

		// 单链表的删除需要更改前一个结点的 next 指针，不适合复用 find
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
					if (curPrev == nullptr) // 头删
						_table[hashi] = curNode->_next;	
					else  // 非头删
						curPrev->_next = curNode->_next;

					delete curNode;
					--_n;
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