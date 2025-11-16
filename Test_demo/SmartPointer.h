#pragma once
#include <iostream>
#include <assert.h>
#include <utility>
#include <functional>

using namespace std;

// 智能指针
// 1. 满足 RAII   资源获取即初始化       本质是借助一个对象的生命周期，来控制这个对象的释放
//					 资源交给对象管理，对象生命周期内，资源有效，对象生命周期到了，释放资源
// 2. 像指针一样，可以访问管理的资源
// 3. 指针的拷贝问题

namespace myPointer
{
	// auto_ptr 拷贝时所有权转移
	template<class T>
	class auto_ptr
	{
	private:
		T* _ptr = nullptr;

	public:
		// 构造
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{ }

		// 析构
		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		// 拷贝构造
		// ap2(ap1);
		auto_ptr(auto_ptr<T>& ap)
		{
			_ptr = ap._ptr;		// 接管资源
			ap._ptr = nullptr;	// 原指针失去所有权
		}
		// 赋值运算符重载
		// 1. 自赋值检查  2. 析构当前对象  3. 接管被赋值对象的资源
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
					delete _ptr;

				_ptr = ap._ptr;		// 接管资源
				ap._ptr = nullptr;	// 原指针失去所有权
			}
			return *this;
		}

		// operator* 和 operator->
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	};

	// unique_ptr 禁止拷贝，支持移动构造和移动赋值
	template<class T>
	class unique_ptr
	{
	private:
		T* _ptr = nullptr;

	public:
		explicit unique_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{ }

		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		// 禁止拷贝构造 和 拷贝赋值
		unique_ptr(const unique_ptr<T>& up) = delete;	// 禁止拷贝构造
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;	 // 禁止拷贝赋值

		// 移动构造和移动赋值
		unique_ptr(unique_ptr<T>&& up) noexcept
			:_ptr(up._ptr)
		{
			up._ptr = nullptr;
		}

		unique_ptr<T>& operator=(unique_ptr<T>&& up) noexcept
		{
			if (this != &up)
			{
				if (_ptr)	// 释放当前资源
					delete _ptr;

				_ptr = up._ptr;		// 接管资源
				up._ptr = nullptr;
			}
			return *this;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	};

	//// 共享所有权 以及 引用计数 的 shared_ptr 实现
	template<class T>
	class shared_ptr
	{
	private:
		T* _ptr = nullptr;
		int* _ptr_refCount;		// 引用计数
		std::function<void(T*)> _del;	// 删除器，参数一定为T*  返回值一定为 void 

	public:
		// 默认构造
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _ptr_refCount(new int(1))
			, _del([](T*)->void { delete _ptr; })
		{
		}

		//  普通构造
		shared_ptr(T* ptr = nullptr, std::function<void(T*)> del)
			:_ptr(ptr)
			,_ptr_refCount(new int(1))
			,_del(del)
		{
		}

		void release()
		{
			if (--(*_ptr_refCount) == 0)
			{
				delete _ptr;
				delete _ptr_refCount;

				_ptr = nullptr;
				_ptr_refCount = nullptr;
			}
		}

		~shared_ptr()
		{
			if (_ptr_refCount && (--(*_ptr_refCount) == 0))
			{
				delete _ptr;
				delete _ptr_refCount;
				_ptr = _ptr_refCount = nullptr;
			}
		}
		
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			,_ptr_refCount(++(*sp._ptr_refCount))
		{
		}

		// 三种情况
		// 1. 管理同一个资源的 智能指针互相赋值
		// 2. 相同智能指针对象之间的赋值
		// 3. 管理不同资源的 智能指针互相赋值
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			// 1 和 2
			if (this == &sp || _ptr == sp._ptr)
				return *this;
			else
			{
				// 管理不同资源的 智能指针互相赋值
				// 引用计数 -- 后为0

				if (_ptr_refCount && --(*_ptr_refCount) == 0)
				{
					--(*_ptr_refCount);
					delete _ptr;
					delete _ptr_refCount;
				}

				// 引用计数 -- 后不为0
				_ptr = sp._ptr;		// 接管资源
				_ptr_refCount = sp._ptr_refCount;
				if (_ptr_refCount)
					++(*_ptr_refCount);

				return *this;
			}
			return *this;
		}

		T* get() const noexcept
		{
			return _ptr;
		}
		int use_count() const noexcept
		{
			return *_ptr_refCount;
		}
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	};
}
