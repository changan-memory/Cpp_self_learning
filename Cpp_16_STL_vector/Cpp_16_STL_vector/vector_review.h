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
		iterator begin() { return _start; }
		iterator end() { return _finish; }	// end是最后一个元素的下一个位置
		const_iterator begin() const { return _start; }
		const_iterator end() const { return _finish; }
		// 指针 - 指针 得到中间的元素个数
		size_t capacity() const {
			return _end_of_storage - _start;
		}
		size_t size() const {
			return _finish - _start;
		}

	private:
		//与标准库STL中的命名风格保持一致
		//可以用C++11中的 成员变量缺省值 给初始化列表使用 这样在构造函数中，就不用写初始化列表了
		iterator _start = nullptr;		
		iterator _finish = nullptr;	
		iterator _end_of_storage = nullptr;
		/*iterator _start;
		iterator _finish;
		iterator _end_of_storage;*/
	
	public:
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{ }

		// mm_vector::vector<int> v(10, 1);	int int 匹配 size_t int 还是 int int
		// mm_vector::vector<int> v1(10u, 1); unsigned int int 匹配 size_t int 还是 int int
		// mm_vector::vector<string> v2(10, "hello"); int char* 只能匹配 size_t char*
		// 用n个val构造  复用resize 时，三个指针应该初始化
		vector(size_t n, const T& val = T()) {	// 成员变量给了缺省值，可以不写初始化列表
			resize(n, val);
		}
		vector(int n, const T& val = T()) {	//多提供一个 int int 类型的构造
			resize(n, val);
		}
		// 用一个迭代器区间进行初始化
		// 类模板内的成员函数，依然可以再是另一个模板函数
		// [first, last]
		template<typename InputIterator>
		vector(InputIterator first, InputIterator last) {
			while (first != last) {
				push_back(*first);	// vector<int> v(10, 1);  构造时匹配错误，匹配成了迭代器区间初始化
									// 然后 int 不能解引用，因此报错
				++first;
			}
		}

		// 拷贝构造函数
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			/*T* newSpace = new T[v.capacity()];*/
			_start = new T[v.capacity()];
			// 凡是调用memcpy的地方，应该实现深拷贝类型的扩容
			//memcpy(_start, v._start, sizeof(T) * v.size());
			for (size_t i = 0; i < v.size(); ++i) {
				_start[i] = v[i];
			}
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}
		// 拷贝构造函数的第二种写法
		/*vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for (auto& e : v)
				push_back(e);
		}*/
		// = 重载 深拷贝
		// v2 = v1
		// 传参时，传值，会调用拷贝构造函数，我们已经实现了深拷贝  operator= 的深拷贝
		vector<T>& operator=(vector<T> tmp) {
			swap(tmp);
			return *this;
		}
		// 两个vector交换
		void swap(vector<T>& v) {
			std::swap(v._start, _start);
			std::swap(v._finish, _finish);
			std::swap(v._end_of_storage, _end_of_storage);
		}
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
					// 凡是调用memcpy的地方，应该实现深拷贝类型的扩容
					//memcpy(newSpace, _start, sizeof(T) * oldSize);
					for (size_t i = 0; i < oldSize; ++i) {
						newSpace[i] = _start[i];	// 用自定义类中的 = 重载实现深拷贝类型的拷贝
						// 该写法也可以满足内置类型的拷贝的需求，内置类型本身就可以用=赋值
					}
					delete[] _start;
				}
				_start = newSpace;
				//_finish = _start + size();	// 该实现有问题，这样写_finish的值没变
				// 里面的size()  _start 指向新空间了，但此时_finish仍然指向旧空间
				_finish = _start + oldSize;
				_end_of_storage = _start + newSize;
			}
		}
		// 用resize初始化一个vector 
		//resize 初始化，val可以有默认值(缺省参数)，但如何确定缺省参数的类型
		// 此时 T() 本质是一个T类型的匿名对象 ，会调用T类型的默认构造，写一个类，一定要提供默认构造
		// 如果是 int 等内置类型 resize怎么跑？   理论上不能跑
		// 有了模板后，C++对内置类型进行了升级，也支持内置类型有默认构造函数
		// 初始化 n 个数据
		void resize(size_t n, const T& val = T()) {
			// 要求size 变小时，直接 该 _finish
			if (n < size())
				_finish = _start + n;
			// 要求size 变大时，多出来的空间用val初始化
			else {
				reserve(n);		// n 小于 capacity时，reserve什么都不做，大于时扩容
				// 将多出来的空间用val填充
				while(_finish != _start + n){
					*_finish = val;
					++_finish;
				}
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
		void pop_back() {
			erase(--end());
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
		// 为了解决迭代器失效问题，erase返回传入的pos的下一个位置
		iterator erase(iterator pos) {
			assert(pos >= _start && pos < _finish);
			//删除
			iterator begin = pos + 1;
			//while (begin < end()) {
			while (begin != _finish) {
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			// 为了解决迭代器失效问题，erase返回传入的pos的下一个位置
			// 挪动数据后，pos 就是被删除元素后面第一个元素的位置
			return pos;	
		}

		//void insert(iterator pos, size_t n, const T& obj) {
		//	// 保证插入位置正确
		//	assert(pos >= _start && pos <= _finish);
		//	// 扩容逻辑
		//	if (_finish + n > _end_of_storage) {
		//		size_t len = pos - _start;	// 记录 pos 相对于 _start 的位置
		//		size_t newCapacity = (capacity() == 0 ? 4 : capacity() + n);
		//		reserve(newCapacity);
		//		// 扩容后更新pos的值，防止迭代器失效
		//		pos = _start + len;
		//	}
		//	// 挪动数据
		//	memcpy(pos + n, pos, sizeof(T) * n);
		//	size_t len = 0;
		//	while (len < n) {
		//		_start[len] = obj;
		//	}
		//	_finish += n;
		//	
		//}
	};
}