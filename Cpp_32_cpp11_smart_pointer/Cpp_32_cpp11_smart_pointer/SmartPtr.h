#pragma once

namespace m_SmartPtr {
	// auto_ptr 模拟实现
	template<class T>
	class auto_ptr {
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
				//1.显示释放的地址
				cout << "delete:" << _ptr << endl;

				//2.释放动态资源
				delete _ptr;

				//3.指针置空避免野指针
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
		T& operator*()
		{
			return *_ptr;  // 返回资源的引用
		}
		//注意：模拟原始指针的*操作，允许通过auto_ptr访问“资源本身”


		// 6. 重载成员访问运算符
		T* operator->()
		{
			return _ptr;  // 返回资源指针
		}
		//注意：模拟原始指针的->操作，允许通过auto_ptr访问“资源的成员”
	};

	// unique_ptr 模拟实现
	template<class T>
	class unique_ptr {
	private:
		T* _ptr;  // 指向管理的动态资源

	public:
		// 1. 构造函数
		explicit unique_ptr(T* ptr) // explicit：禁止隐式转换（避免int*等意外转换为unique_ptr）
			: _ptr(ptr)
		{
		}
		/* 对比分析：unique_ptr和auto_ptr的“构造函数”的区别
		*      1. unique_ptr的构造函数使用了explicit 关键字进行了禁止隐式转换
		*/

		// 2. 析构函数
		~unique_ptr() {
			if (_ptr)
			{
				//1.
				cout << "delete:" << _ptr << endl;

				//2.
				delete _ptr;

				//3.
				_ptr = nullptr;
			}
		}
		//对比分析：这里的unique_ptr和auto_ptr的“析构函数”实现一样


		// 3. 禁止拷贝：删除“拷贝构造和拷贝赋值”---> 确保资源所有权唯一，避免重复释放
		//3.1：禁止拷贝构造
		unique_ptr(const unique_ptr<T>& sp) = delete;
		//3.2：禁止拷贝赋值
		unique_ptr<T>& operator=(const unique_ptr<T>& sp) = delete;


		// 4. 重载解引用运算符
		T& operator*() {
			return *_ptr;
		}
		//对比分析：这里的unique_ptr和auto_ptr的“重载解引用运算符”实现一样


		// 5. 重载成员访问运算符
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


}