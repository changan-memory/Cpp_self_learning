#pragma once

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;


namespace base
{
	// 闭散列的 开放定址法的哈希表
	namespace open_addr
	{
		// 哈希表中每个位置的状态
		enum STATE
		{
			EXIST,
			EMPTY,
			DELETE
		};

		// 哈希存储的数据
		template<class K, class V>
		struct HashData
		{
			std::pair<K, V> _kv;
			enum STATE _state = EMPTY;
		};

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
				// BKDR 哈希算法
				size_t hash = 0;
				for (auto ch : str) {
					hash *= 131;
					hash += ch;
				}
				return hash;
			}
		};

		// 哈希表的结构
		template<class K, class V, class HashFunc = DefaultHashFunc<K>>		// 默认使用整型的哈希函数
		class HashTable
		{
		private:
			vector<HashData<K, V>> _table;	// vector 存自定义类型，无需实现析构函数
			size_t _n = 0;  // 存储的有效数据的个数   哈希是分散存储的，vector 是连续存储的，因此即使 vector 中有 size,也需要这个 _n

		public:
			HashTable()
			{
				_table.resize(10);
			}
			bool insert(const pair<K, V>& kv)
			{
				if (find(kv.first))
					return false;

				// 插入前需要控制 负载因子 和 扩容
				//if ((static_cast<double> (_n) / static_cast<double>(_table.size())) >= 0.75)
				if (_n * 10 / _table.size() >= 7)		// 牺牲一部分空间换取性能
				{
					size_t newSize = _table.size() * 2;
					// 扩容后映射关系变了，需要重新映射
					// 创建一个新的 哈希表 处理映射关系 和 冲突
					HashTable<K, V, HashFunc> newHashTable;
					newHashTable._table.resize(newSize);
					// 遍历旧表的数据 重新插入，映射到新表   只把 存在的区域 进行映射
					for (size_t i = 0; i < _table.size(); i++)
					{
						if (_table[i]._state == EXIST)
						{
							// 这里再调用 insert 时，已经resize过了，会走下面的线性探测逻辑
							newHashTable.insert(_table[i]._kv);
						}
					}
					_table.swap(newHashTable._table);
				}

				// 线性探测
				HashFunc hs;
				size_t hashi = hs(kv.first) % _table.size();
				// 找到的 hashi 位置，可能 exist delete empty ，
				// 插入时 需要找到 线性探测，只要位置已有数据存在，就向后继续探测
				while (_table[hashi]._state == EXIST)
				{
					++hashi;
					hashi %= _table.size();
				}
				// 循环结束后，找到了  状态为 empty 和 delete 的位置都可以插入
				_table[hashi]._kv = kv;
				_table[hashi]._state = EXIST;
				++_n;
				return true;
			}
			HashData<const K, V>* find(const K& key) const
			{
				// 线性探测
				HashFunc hs;

				size_t hashi = hs(key) % _table.size();
				while (_table[hashi]._state != EMPTY)
				{
					if (_table[hashi]._state == EXIST && _table[hashi]._kv.first == key)
					{
						//return (HashData<const K, V>*) & _table[hashi];
						return (HashData<const K, V>*) & _table[hashi];
					}
					++hashi;
					hashi %= _table.size();
				}
				return nullptr;
			}

			bool Erase(const K& key)
			{
				// 找到了才能删除
				HashData<const K, V>* ret = find(key);
				if (ret)
				{
					ret->_state = DELETE;
					--_n;
					return true;
				}
				return false;
			}
		};
	}


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

		template<class K, class V>
		struct HashNode
		{
			std::pair<K, V> _kv;
			struct HashNode<K, V>* _next;

			HashNode(const pair<K, V>& kv)
				:_kv(kv)
				, _next(nullptr)
			{
			}
		};

		template<class K, class V, class HashFunc = DefaultHashFunc<K>>
		class HashTable
		{
			typedef struct HashNode<K, V> Node;
		private:
			vector<Node*> _table;	// 需要写析构函数，桶中的节点需要手动析构
			size_t _n = 0;

		public:
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

			bool Insert(const pair<K, V>& kv)
			{
				if (Find(kv.first))
					return false;

				HashFunc hf;
				// 扩容逻辑
				// 控制负载因子 为 1 时扩容
				//if (static_cast<double> (_n) / static_cast<double> (_table.size()) >= 1.0)

				// 控制负载因子 到 1 时扩容
				if (_n == _table.size())
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

							// 把每个结点做重新映射
							size_t hashi = hf(curNode->_kv.first) % newSize;	
							// 头插
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
				size_t hashi = hf(kv.first) % _table.size();

				Node* newNode = new Node(kv);
				// 头插
				newNode->_next = _table[hashi];
				_table[hashi] = newNode;
				++_n;
				return true;
			}

			Node* Find(const K& key) const
			{
				HashFunc hf;
				size_t hashi = hf(key) % _table.size();

				Node* curNode = _table[hashi];
				while (curNode)
				{
					if (curNode->_kv.first == key)
						return curNode;
					curNode = curNode->_next;
				}
				return nullptr;
			}

			// 单链表的删除需要更改前一个结点的 next 指针，不适合复用 find
			bool Erase(const K& key)
			{
				HashFunc hf;
				size_t hashi = hf(key) % _table.size();

				Node* curPrev = nullptr;
				Node* curNode = _table[hashi];
				while (curNode)
				{
					if (curNode->_kv.first == key)
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
					printf("[%d]->", (int)i);
					Node* curNode = _table[i];
					while (curNode)
					{
						cout << curNode->_kv.first << ":" << curNode->_kv.second << "->";
						curNode = curNode->_next;
					}
					printf("NULL\n");
				}
				cout << endl;
			}
		};

	}
}