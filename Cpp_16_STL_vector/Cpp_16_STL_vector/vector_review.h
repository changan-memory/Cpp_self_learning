#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

// 期末回归复习版本
namespace mm_vector {
	template<typename T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin() {
			return _start;
		}
		// end是最后一个元素的下一个位置
		iterator end() {
			return _finish;
		}
		const_iterator begin() const {
			return _start;
		}
		const_iterator end() const {
			return _finish;
		}
		// 指针 - 指针 得到中间的元素个数
		size_t capacity() const {
			return _end_of_storage - _start;
		}
		size_t size() const {
			return _finish - _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	
	public:
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{ }
		~vector() {
			if (_start) {
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}
		T& operator[](size_t pos) {
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const {
			assert(pos < size());
			return _start[pos];
		}

		void reserve(size_t newSize) {
			// reserve 不只给push_back用，需要检查是否需要扩容
			if (newSize > capacity()) {
				T* newSpace = new T[newSize];
				size_t oldSize = size();
				if (_start) {
					memcpy(newSpace, _start, sizeof(T) * oldSize);
					delete[] _start;
				}
				_start = newSpace;
				//_finish = _start + size();	// 该实现有问题，这样写_finish的值没变
				// 里面的size()  _start 指向新空间了，但此时_finish仍然指向旧空间
				_finish = _start + oldSize;
				_end_of_storage = _start + newSize;
			}
		}
		void push_back(const T& obj) {
			// 判断是否需要扩容
			if (_finish == _end_of_storage) {
				size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);
				reserve(newCapacity);
			}
			// 插入逻辑
			*_finish = obj;
			++_finish;
			//insert(end(), obj);
		}

		// 这里本质上解决的是内部的迭代器失效

		// 迭代器失效问题：pos记录的是地址。
		// 如果vector扩容后，原空间会被析构。
		// pos指代的地址，就不是新空间中pos的地址了，因此需要更新pos的值
		//void insert(iterator pos, const T& obj) {
		//	// 保证插入位置正确
		//	assert(pos >= _start && pos <= _finish);
		//	// 扩容逻辑
		//	if (_finish == _end_of_storage) {
		//		size_t len = pos - _start;	// 记录 pos 相对于 _start 的位置
		//		size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);
		//		reserve(newCapacity);
		//		// 扩容后更新pos的值，防止迭代器失效
		//		pos = _start + len;
		//	}
		//	// 挪动元素
		//	iterator end = _finish - 1;
		//	while (end >= pos) {
		//		*(end + 1) = *end;
		//		--end;
		//	}
		//	// 插入数据
		//	*pos = obj;
		//	++_finish;
		//}

		// 解决内部和外部迭代器的最终insert实现方案
		iterator insert(iterator pos, const T& obj) {
			// 保证插入位置正确
			assert(pos >= _start && pos <= _finish);
			// 扩容逻辑
			if (_finish == _end_of_storage) {
				size_t len = pos - _start;	// 记录 pos 相对于 _start 的位置
				size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);
				reserve(newCapacity);
				// 扩容后更新pos的值，防止迭代器失效
				pos = _start + len;
			}
			// 挪动元素
			iterator end = _finish - 1;
			while (end >= pos) {
				*(end + 1) = *end;
				--end;
			}
			// 插入数据
			*pos = obj;
			++_finish;
			return pos;
		}
		

	};
}