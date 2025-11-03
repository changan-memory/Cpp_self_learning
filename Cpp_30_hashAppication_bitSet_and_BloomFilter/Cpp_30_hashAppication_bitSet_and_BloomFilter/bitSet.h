#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace m_BitSet
{
	template<size_t N>
	class bitset
	{
	private:
		std::vector<int> _arr;
		// 我们无法单独定义 占一个比特位的 类型

	public:
		// 构造函数开空间
		bitset()
		{
			_arr.resize(N / sizeof(size_t) + 1, 0);
		}

		// 将 特定位 处理为1，其余位保持不变
		void set(size_t num)
		{
			/*int i = num / 32;
			int j = num % 32;
			_arr[i] |= (1 << j);*/

			// 下面是 以上 代码的 的更安全、更健壮的写法
			int i = num / (sizeof(size_t) * 8);
			int j = num % (sizeof(size_t) * 8);
			_arr[i] |= (static_cast<size_t>(1) << j);	
		}

		// 将 特定位 处理为0，其余位保持不变
		void reset(size_t num)
		{
			int i = num / (sizeof(size_t) * 8);
			int j = num % (sizeof(size_t) * 8);
			_arr[i] &= ~(static_cast<size_t>(1) << j);
		}

		// 判断 这个位 在不在
		bool test(size_t num)
		{
			int i = num / (sizeof(size_t) * 8);
			int j = num % (sizeof(size_t) * 8);

			return (_arr[i] & (static_cast<size_t> (1) << j)) != 0;
		}
	};

	// 问题一、给定100亿个整数，设计算法找到只出现一次的整数
	// 使用两个位图解决该问题
	template<size_t N>
	class TwoBitSet_1
	{
	private:
		bitset<N> _bt1;
		bitset<N> _bt2;
	public:
		// 成员为两个自定义类型，无需写构造函数
		// 实现思路: 仅使用一个位图时，每个数据只有一个标记位，方便标记在不在
		//			   使用一个位图后，每个数据都有两个位，可以表示四种状态
		//             00 : 出现零次 , 01 : 出现一次   ,   10   11  出现两次及以上
		void set(size_t num)
		{
			if (!_bt1.test(num) && !_bt2.test(num))	// 00 -> 01   读到的数据出现0次，变为 1 次
			{
				_bt1.reset(num);	// 0
				_bt2.set(num);		// 1
			}
			else if (!_bt1.test(num) && _bt2.test(num))	// 01 -> 10  读到的数据已出现1次，变为2次
			{
				_bt1.set(num);
				_bt2.reset(num);
			}
			// 本身已经出现了两次及以上，不做处理
			//else if (_bt1.test(num) && !_bt2.test(num))	// 10 -> 11  读到的数据已出现2次，变为3次
			//{
			//	_bt1.set(num);
			//	_bt2.set(num);
			//}
			//else
			//	;
		}
		bool is_once(size_t num)
		{
			return !_bt1.test(num) && _bt2.test(num);
		}
	};

	// 问题三、位图应用变形: 1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数
	// 使用两个位图解决该问题
	template<size_t N>
	class TwoBitSet_3
	{
	private:
		bitset<N> _bt1;
		bitset<N> _bt2;
	public:
		void set(size_t num)
		{
			if (!_bt1.test(num) && !_bt2.test(num))	// 00 -> 01   读到的数据出现0次，变为 1 次
			{
				_bt1.reset(num);	// 0
				_bt2.set(num);		// 1
			}
			else if (!_bt1.test(num) && _bt2.test(num))	// 01 -> 10  读到的数据已出现1次，变为2次
			{
				_bt1.set(num);
				_bt2.reset(num);
			}
			// 出现了大于两次 
			else if (_bt1.test(num) && !_bt2.test(num))	// 10 -> 11  读到的数据已出现2次，变为3次
			{
				_bt1.set(num);
				_bt2.set(num);
			}
			// 超过三次的不做处理
			else
				;
		}
		bool less_twice(size_t num)
		{
			// 1 次 或 2 次
			return (!_bt1.test(num) && _bt2.test(num)) || (_bt1.test(num) && !_bt2.test(num));
		}
	};
}

