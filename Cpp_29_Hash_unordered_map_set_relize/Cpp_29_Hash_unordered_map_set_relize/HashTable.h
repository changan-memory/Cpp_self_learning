#pragma once

#include <iostream>
#include <vector>
#include <stdio.h>
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

	// 实现迭代器
	// 为了方便操作，存了一个哈希表的指针
	template<class K, class T, class Ptr, class Ref, class KeyOfT, class HashFunc>
	struct HTIterator
	{
		typedef struct HashNode<T> Node;
		typedef struct HTIterator<K, T, Ptr, Ref, KeyOfT, HashFunc> Self;

		typedef struct HTIterator<K, T, T*, T&, KeyOfT, HashFunc> Iterator;

		Node* _node;
		// 当前哈希表的指针
		//HashTable<K, T, KeyOfT, HashFunc>* _pht;
		const HashTable<K, T, KeyOfT, HashFunc>* _pht;

		HTIterator(Node* node, const HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			,_pht(pht)
		{ }


		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(_node->_data);
		}

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
		// 单向迭代器，不支持--

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
			_table.resize(10, nullptr);
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
				size_t newSize = _table.size() * 2;
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
			return std::make_pair(newNode, true);
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