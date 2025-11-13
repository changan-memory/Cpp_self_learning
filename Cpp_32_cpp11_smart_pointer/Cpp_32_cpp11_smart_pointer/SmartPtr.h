#pragma once

// C++98 auto_ptr

// boost

// C++11 unique_ptr
// C++11 shared_ptr
// C++11 weak_ptr

namespace m_SmartPtr 
{
	// auto_ptr 模拟实现
	template<class T>
	class auto_ptr 
	{
	private:
		T* _ptr; // 指向管理的动态资源（如: new分配的对象）

	public:
		// 1. 构造函数：接收外部new的资源指针，接管所有权
		auto_ptr(T* ptr)
			: _ptr(ptr)
		{ }

		// 2. 析构函数：当auto_ptr对象生命周期结束时，自动释放管理的资源
		~auto_ptr()
		{
			if (_ptr)  // 确保指针非空，避免重复释放
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		// 3. 拷贝构造函数 ---> 采用"所有权转移"策略 ---> 原对象会失去资源所有权，变为悬空指针
		auto_ptr(auto_ptr<T>& sp)
			: _ptr(sp._ptr)     //1.新对象接管原对象的资源
		{
			sp._ptr = nullptr;  //2.原对象指针置空，失去所有权
		}

		// 4. 拷贝赋值运算符 ---> 采用"所有权转移"策略
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			//1.检测自赋值以避免自己赋值给自己导致的错误
			if (this != &ap)
			{
				//第一步：先释放当前资源
				if (_ptr)
				{
					delete _ptr;
					_ptr = nullptr;
				}

				//第二步：再接管新资源
				_ptr = ap._ptr;  //接管ap的资源

				//第三步：最后将原对象指针置空
				ap._ptr = nullptr;  // ap失去所有权
			}

			//2.返回当前对象以支持链式赋值
			return *this;
		}

		// 5. 重载解引用运算符：
		T& operator*() const
		{
			return *_ptr;  // 返回资源的引用
		}
	
		T* operator->() const
		{
			return _ptr;  // 返回资源指针
		}
	};

	// unique_ptr 模拟实现
	template<class T>
	class unique_ptr
	{
	private:
		T* _ptr;  // 指向管理的动态资源

	public:
		explicit unique_ptr(T* ptr) // explicit：禁止隐式转换（避免int*等意外转换为unique_ptr）
			: _ptr(ptr)
		{
		}
		/* 对比分析：unique_ptr和auto_ptr的“构造函数”的区别
		*      1. unique_ptr的构造函数使用了explicit 关键字进行了禁止隐式转换
		*/

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}
		//对比分析：这里的unique_ptr和auto_ptr的“析构函数”实现一样


		// 3. 禁止拷贝：删除“拷贝构造和拷贝赋值”---> 确保资源所有权唯一，避免重复释放
		// 禁止拷贝赋值   禁止拷贝构造			   
		unique_ptr(const unique_ptr<T>& sp) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& sp) = delete;

		// 禁止拷贝构造 和 赋值， 两种实现方式：
		// 1. C++98 构造函数 和 operator= 声明为私有
		// 2. C++11  构造函数 和 operator= 只声明，不实现，同时在函数声明尾部加上 = delete


		T& operator*() {
			return *_ptr;
		}
		//对比分析：这里的unique_ptr和auto_ptr的“重载解引用运算符”实现一样

		T* operator->() {
			return _ptr;
		}
		//对比分析：这里的unique_ptr和auto_ptr的“重载成员访问运算符”实现一样


		// 6. 移动构造函数 ---> 通过右值引用转移所有权
		unique_ptr(unique_ptr<T>&& sp)
			: _ptr(sp._ptr)     //1.新对象接管原对象的资源
		{
			sp._ptr = nullptr;  //2.原对象指针置空，失去所有权
		}
		/* 对比分析：auto_ptr的“拷贝构造函数”和 unique_ptr的“移动构造函数”的唯一区别：函数参数的不同
		*      1. auto_ptr(auto_ptr<T>& sp)
		*      2. unique_ptr：unique_ptr(unique_ptr<T>&& sp)
		*/


		// 7. 移动赋值运算符 ---> 通过右值引用转移所有权
		unique_ptr<T>& operator=(unique_ptr<T>&& sp)
		{
			//1.检测自赋值以避免自己赋值给自己导致的错误
			if (this != &sp)
			{
				//第一步：先释放当前资源
				if (_ptr)
				{
					delete _ptr;
				}

				//第二步：再接管新资源
				_ptr = sp._ptr;  //接管sp的资源

				//第三步：最后将原对象指针置空
				sp._ptr = nullptr;  // sp置空失去所有权

			}
			//2.返回当前对象以支持链式赋值
			return *this;
		}
		/* 对比分析：auto_ptr的“拷贝赋值运算符”和 unique_ptr的“移动赋值运算符”的唯一区别：函数参数的不同
		*      1. auto_ptr：auto_ptr<T>& operator=(auto_ptr<T>& ap)
		*      2. unique_ptr：unique_ptr<T>& operator=(unique_ptr<T>&& sp)
		*/

	};

	// shared_ptr 模拟实现
	template<class T>
	class shared_ptr
	{
	private:
		T* _ptr;  // 指向管理的动态资源

		// 引用计数，期望一个资源伴随着一个 引用计数， static 不能解决
		int* _ptr_refCount;		// 引用计数使用动态的内存， 每个智能指针都保存了 引用计数的地址

	public:

		// 构造的时候，开辟引用计数
		shared_ptr(T* ptr)
			:_ptr(ptr)
			,_ptr_refCount(new int(1))		// new 一个 int 变量，初始化引用计数为 1
		{ }

		// 智能指针 生命周期结束后，对引用计数减减，减减后为 0 时，代表当前是最后一个引用计数
		// 再开始 释放资源
		~shared_ptr()
		{
			if (--(*_ptr_refCount) == 0)
			{
				cout << "~shared_ptr delete: " << typeid(T).name() << " " << _ptr << endl;
				delete _ptr;
				delete _ptr_refCount;
			}
		}

		//// sp3(sp1)
		//shared_ptr(const shared_ptr<T>& sp)
		//	:_ptr(sp._ptr)
		//	,_ptr_refCount(& (++(*sp._ptr_refCount)))
		//{
		//}

		// sp3(sp1)
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _ptr_refCount(sp._ptr_refCount)
		{
			++(*_ptr_refCount);
		}
		
		// 三种情况 sp3 = sp1		// 管理同一个资源的智能指针 互相赋值
		//          sp1 = sp5		// 管理不同的资源的智能指针 互相赋值
		//          sp1 = sp1		// 同一个智能指针对象互相赋值
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			// 分两种情况分别判断
			// 管理同个资源的 智能指针对象之间的赋值
			if (this == &sp || _ptr == sp._ptr)
				return *this;
			//管理不同的资源的智能指针 互相赋值
			else
			{
				// 旧资源的引用计数存在，且 减减后 引用计数为0 就释放资源
				if (_ptr_refCount && --(*_ptr_refCount) == 0)
				{
					delete _ptr;
					delete _ptr_refCount;
				}
				//  减减后 引用计数不为0 ，
				_ptr = sp._ptr;
				_ptr_refCount = sp._ptr_refCount;

				if(_ptr_refCount)
					++(*_ptr_refCount);

				return *this;
			}
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