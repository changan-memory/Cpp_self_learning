#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


namespace m_vector {
	template<class T>
	class vector {
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator cbegin() const { return _start; }
		const_iterator cend() const { return _finish; }

		//默认构造函数
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{ }

		void reserve(size_t n) {
			// reserve 不是只给push_back使用，因此也要检查
			if (n > capacity()) {
				size_t old_sz = size();
				T* tmp = new T[n];
				//原空间不为空时拷贝数据
				if (_start) {
					memcpy(tmp, _start, sizeof(T) * old_sz);
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + old_sz;
				_end_of_storage = _start + n;
			}
		}
		void push_back(const T& obj) {
			//检查容量并扩容
			if (_finish == _end_of_storage) {
				size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);	//初始化新空间
				reserve(newCapacity);											//扩容
			}
			*_finish = obj;
			++_finish;
		}

		// 指针 - 指针，返回的是两个指针中间的元素个数
		size_t capacity() const {
			return _end_of_storage - _start;
		}
		size_t size() const {
			return _finish - _start;
		}
	private:
		//与STL中的命名风格保持一致
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}

