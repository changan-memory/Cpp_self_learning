#pragma once
#include <iostream>
#include <utility>
#include <functional>

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
		//1.指向共享的资源的指针
		//2.引用计数（堆上分配，所有共享对象共享）
		//3.自定义删除器（支持数组/文件句柄等资源）

		T* _ptr;
		int* _pcount;
		std::function<void(T*)> _del;

	public:
		// 实现：“默认构造函数”（支持默认删除器）
		explicit shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)                       //1.管理空资源
			, _pcount(new int(1))              //2.计数在堆上，初始值1
			, _del([](T* ptr) { delete ptr; }) //3.lambda作为默认删除器
		{
		}

		// 实现：“普通构造函数”（带自定义删除器）---> 管理数组（需delete[]）、文件句柄（需fclose）等非普通指针
		shared_ptr(T* ptr, function<void(T*)> del)
			: _ptr(ptr)              //1.管理共享的资源
			, _pcount(new int(1))     //2.计数在堆上，初始值1
			, _del(del)               //3.接收自定义删除器
		{
		}


		// 实现：“释放资源”的核心逻辑：计数-1，为0时彻底释放
		void release()
		{
			if (--(*_pcount) == 0)  //注意细节：调用“释放资源”一定会进行计数-1
			{                       //但是只有计数减为0时，说明是最后一个引用者，才会进行资源释放

				_del(_ptr);		//1.调用删除器释放资源
				delete _pcount;	//2.释放计数空间

				//3.避免野指针
				_ptr = nullptr;       // 将指向“共享资源”的指针置空
				_pcount = nullptr;    // 将指向“计数空间”的指针置空
			}
		}

		// 实现：“析构函数”
		~shared_ptr()
		{
			release();  //调用release释放资源
		}


		// 实现：“拷贝构造函数”
		//注意：每调用一次“拷贝构造函数”就会进行一次“引用计数+1”
		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr),      //1.共享资源
			_pcount(sp._pcount),  //2.共享计数 且 +1
			_del(sp._del)         //3.共享删除器
		{
			(*_pcount)++;         //4.引用计数+1
		} 

		// 实现：“拷贝赋值运算符”：释放当前资源，共享新资源
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//1.检测自赋值以避免自己赋值给自己导致的错误
			if (_ptr != sp._ptr) //若资源不同，才需要释放当前资源
			{
				//1.释放当前资源（计数-1）
				release();

				//2.共享新资源
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_del = sp._del;

				//3.新资源计数+1
				(*_pcount)++;
			}

			//2.返回当前对象以支持链式赋值
			return *this;
		}

		// 实现：“获取原始指针”
		T* get() const
		{
			return _ptr;
		}

		// 实现：“获取当前引用计数”
		int use_count() const
		{
			return *_pcount;
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


	// weak_ptr 模拟实现
	template<class T>
	class weak_ptr
	{
	private:
		T* _ptr;  // 指向管理的动态资源

	public:

		weak_ptr()
			:_ptr(nullptr)
		{
		}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{
		}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();
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
}