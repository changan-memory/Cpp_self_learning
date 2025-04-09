#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;


namespace m_vector {
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		//迭代器与const迭代器
		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator begin() const { return _start; }
		const_iterator end() const { return _finish; }

		//默认构造函数
		//我们写的逻辑是 构造时暂不开空间
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{ }

		~vector() {
			if (_start) {
				delete[] _start;
				_finish = _start = _end_of_storage = nullptr;
			}
		}
		void reserve(size_t n) {
			// reserve 不是只给push_back使用，因此也要检查
			if (n > capacity()) {
				size_t old_sz = size();
				T* tmp = new T[n];		//开空间,会构造一个vector
				//原空间不为空时拷贝数据
				if (_start) {
					memcpy(tmp, _start, sizeof(T) * old_sz);
					delete[] _start;
				}
				// start指向新空间，指针finish该为 start 加上 
				_start = tmp;
				//_finish = _start + size();	//这是错误写法，size = finsih - start
				_finish = _start + old_sz;	//让finsih指向和原空间一样的size处
				_end_of_storage = _start + n;
			}
		}
		//T可能是任意类型，自定义类型或内置类型，尽量使用引用
		void push_back(const T& obj) {
			////检查容量并扩容
			//if (_finish == _end_of_storage) {
			//	//计算新空间需要的大小  二倍扩容逻辑
			//	size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);	
			//	// 传入二倍扩容后空间的大小
			//	reserve(newCapacity);											//分配空间的大小
			//}
			//// 开好空间后，插入数据，并更新_finish
			//*_finish = obj;
			//++_finish;
			
			//insert(_finish, obj);
			insert(end(), obj);
		}

		iterator insert(iterator pos, const T& ele) {
			//检查pos
			assert(pos >= _start && pos <= _finish);
			//检查容量并扩容

			//扩容后，由于空间更新，pos记录的地址可能不是新开辟空间的地址，此时迭代器失效
			if (_finish == _end_of_storage) {
				//记录下 pos 相对于 _start的偏移地址
				size_t len = pos - _start;

				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);

				//解决迭代器失效问题, 记录下便宜地址，解决的是函数内部迭代器失效的问题
				pos = _start + len;
			}
			//插入逻辑
			iterator end = _finish - 1;
			while (end >= pos) {
				*(end + 1) = *end;
				--end;
			}
			//更新成员变量逻辑
			*pos = ele;
			++_finish;
			return pos;		//返回插入位置的引用，解决外部迭代器失效问题
		}

		void erase(iterator pos) {
			//检查越界
			assert(pos >= _start && pos < _finish);
			//删除逻辑,有数据才能删
			if (_start) {
				iterator begin = pos + 1;
				while (begin != _finish) {
					*(begin - 1) = *begin;
					++begin;
				}
				//更新状态
				--_finish;
			}
		}
		// 指针 - 指针，返回的是两个指针中间的元素个数
		size_t capacity() const { return _end_of_storage - _start; }
		size_t size() const { return _finish - _start; }

		T& operator[](size_t pos) {
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const{
			assert(pos < size());
			return _start[pos];
		}
	private:
		//与标准库STL中的命名风格保持一致
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

}