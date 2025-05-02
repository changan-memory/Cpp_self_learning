#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
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

		// 指针 - 指针，返回的是两个指针中间的元素个数
		size_t capacity() const { return _end_of_storage - _start; }
		size_t size() const { return _finish - _start; }

		//[]重载
		T& operator[](size_t pos) {
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const {
			assert(pos < size());
			return _start[pos];
		}

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
				_start = _finish = _end_of_storage = nullptr;
			}
		}
		void reserve(size_t n) {
			// reserve 不是只给push_back使用，因此也要检查传入数据的合法性
			// 大于时 再扩容
			if (n > capacity()) {
				size_t old_sz = size();
				T* tmp = new T[n];		//开空间, 异地扩容  会构造一个vector
				// 原空间不为空时拷贝数据
				if (_start) {
					memcpy(tmp, _start, sizeof(T) * old_sz);
					delete[] _start;
				}
				// start指向新空间，指针finish该为 start 加上 
				_start = tmp;
				// _finish = _start + size(); //这是错误写法，等价于 _finsih = _start + _finish - _start
				// 初始时，_finsih 为 nullptr 因此 会出现finsih为空指针

				_finish = _start + old_sz;	// 让finsih指向和原空间一样的size处
				_end_of_storage = _start + n;
			}
		}
		
		//resize 初始化，val可以有默认值(缺省参数)，但如何确定缺省参数的类型
		// 此时 T() 本质是一个T类型的匿名对象 ，会调用T类型的默认构造，写一个类，一定要提供默认构造
		// 如果是 int 等内置类型 resize怎么跑？   理论上不能跑
		// 有了模板后，C++对内置类型进行了升级，也支持内置类型有默认构造函数
		void resize(size_t n, const T& val = T()) {
			//判断要求的情况
			if (n < size())		//改变大小
				_finish = _start + n;
			else {
				reserve(n);
				while (_finish != _start + n) {
					*_finish = val;
					++_finish;
				}
			}
		}

		//T可能是任意类型，自定义类型或内置类型，尽量使用引用
		void push_back(const T& obj) {
			//检查容量并扩容
			if (_finish == _end_of_storage) {
				//计算新空间需要的大小  二倍扩容逻辑
				size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);	
				// 传入二倍扩容后空间的大小
				reserve(newCapacity);			//分配空间的大小
			}
			// 开好空间后，插入数据，并更新_finish
			*_finish = obj;
			++_finish;
			
			//insert(_finish, obj);
			//insert(end(), obj);
		}
		void pop_back() {
			erase(--end());
		}

		////迭代器失效的引入
		//void insert(iterator pos, const T& obj) {
		//	assert(pos >= 0 && pos <= _finish);
		//	//扩容逻辑
		//	if (_finish == _end_of_storage) {
		//		size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);
		//		reserve(newCapacity);			//分配空间的大小
		//	}
		//	iterator end = _finish - 1;
		//	while (end > pos) {
		//		*(end + 1) = *end;
		//		--end;
		//	}
		//	*pos = obj;
		//	++_finish;
		//}

		//使用指针的优势，pos不可能为0 ，会解决string那里插入的问题
		//空指针就是 不被使用的地址，专门用于初始化
		iterator insert(iterator pos, const T& obj) {
			assert(pos >= _start && pos <= _finish);	//检查pos ； ==finsih时 为尾插
			//检查容量并扩容
			//扩容后，由于空间的异地库容和释放，pos记录的地址可能不是新开辟空间的地址，此时迭代器失效
			// 原有的指针都会失效
			if (_finish == _end_of_storage) {
				//记录下 pos 相对于 _start的偏移地址，用相对偏移量计算pos指针
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
			*pos = obj;
			++_finish;
			return pos;		//返回插入位置的指针，解决外部迭代器失效问题
		}
		// 返回 pos 迭代器，防止迭代器失效问题
		iterator erase(iterator pos) {
			assert(pos >= _start && pos < _finish);		//检查越界,两重限制，保证了一定有数据
			//删除逻辑,有数据才能删
			iterator begin = pos + 1;
			//while (begin != _finish) {
			while (begin < _finish) {
				*(begin - 1) = *begin;
				++begin;
			}
			//更新状态
			--_finish;
			return pos;
		}

	private:
		//与标准库STL中的命名风格保持一致
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}