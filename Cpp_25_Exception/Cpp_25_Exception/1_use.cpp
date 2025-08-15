#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

namespace use_1 {
	double Division(int a, int b) {
		//当b == 0时抛出异常
		if (b == 0) {
			// 抛出异常后，会立刻跳转到catch部分执行
			// 会立即跳转到距离当前异常抛出函数栈帧 最近的栈帧中捕获异常
			/*
				首先检查throw本身是否在try块内部，如果是再查找匹配的catch语句。如果有匹配的，则
				调到catch的地方进行处理。
				2. 没有匹配的catch则退出当前函数栈，继续在调用函数的栈中进行查找匹配的catch。
				3. 如果到达main函数的栈，依旧没有匹配的，则终止程序。上述这个沿着调用链查找匹配的
				catch子句的过程称为栈展开。所以实际中我们最后都要加一个catch(...)捕获任意类型的异
				常，否则当有异常没捕获，程序就会直接终止。
				4. 找到匹配的catch子句并处理以后，会继续沿着catch子句后面继续执行
			*/
			throw "Division by zero condition!";
			throw 1; // 在一个错误中抛出多个异常，语法允许，但是没有意义
			// 因为上个 throw 被捕获后，会直接跳转到catch处执行catch及其之后的代码
		}
		else
			return ((double)a / (double)b);
	}
	void Func() {
		try {
			int len, time;
			cin >> len >> time;
			cout << Division(len, time) << endl;
		}
		catch (const char* errmsg) {
			cout << "errmsg" << errmsg << endl;
		}
	}
	int main() {
		// 只有包含在 try catch 中才能捕获异常
		try {
			Func();
		}
		// 没有异常时，catch不会被执行
		catch (int errmsg) {
			cout << errmsg << endl;
		}
		// 只有 抛出了异常，才会执行catch的代码
		catch (const char* errmsg) {
			cout << "异常已捕获: " << errmsg << endl;
		}
		catch (...) {
			cout << "unkown exception" << endl;
		}
		cout << "已无异常" << endl;
		return 0;
	}
}

namespace use_2 {
	// throw
// 1. 抛出异常对象后，会生成一个异常对象的拷贝，因为抛出的异常对象可能是一个临时对象，
// 所以会生成一个拷贝对象，这个拷贝的临时对象会在被catch以后销毁。
// 2. catch(...)  抛出了异常，没有被捕获，会直接终止掉整个程序
	double Division(int a, int b) {
		//当b == 0时抛出异常
		if (b == 0) {
			string s("Division by zero condition!");
			throw s;	// 这里抛出 string 类对象，抛出的不是当前局部域的 s
			// 抛出的是 s的拷贝  
			// 这个拷贝的临时对象会在被catch以后销毁。这里的处理类似于函数的传值返回
		}
		else
			return ((double)a / (double)b);
	}
	void Func() {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	int main() {
		// 只有包含在 try catch 中才能捕获异常
		try {
			Func();
		}
		// 没有异常时，catch不会被执行
		catch (int errmsg) {
			cout << errmsg << endl;
		}
		// 只有 抛出了异常，才会执行catch的代码
		catch (const char* errmsg) {
			cout << "异常已捕获: " << errmsg << endl;
		}
		// 整个程序的某个模块出现异常了，其他模块正常，不能因为某个模块抛出的异常没有被捕获
		// 就终止掉整个程序，不能因为小模块的异常没背捕获就终止掉整个程序
		// 因此最后一道防线，catch(...)
		// 可以捕获任意类型的异常，但缺点是,不知道是什么类型的异常
		catch (...) {
			cout << "unknown exception" << endl;
		}
		return 0;
	}
}

//服务器开发中通常使用的异常继承体系
namespace use_3 {
	
	class Exception {
	public:
		Exception(const string& errmsg, int id)
			:_errmsg(errmsg)
			, _id(id)
		{ 
		}
		virtual string what() const {
			return _errmsg;
		}
	protected:
		string _errmsg;
		int _id;
	};

	class SqlException : public Exception {
	public:
		SqlException(const string& errmsg, int id, const string& sql)
			:Exception(errmsg, id)
			, _sql(sql)
		{
		}
		virtual string what() const {
			string str = "SqlException:";
			str += _errmsg;
			str += "->";
			str += _sql;
			return str;
		}
	private:
		const string _sql;
	};

	class CacheException : public Exception {
	public:
		CacheException(const string& errmsg, int id)
			:Exception(errmsg, id)
		{
		}
		virtual string what() const {
			string str = "CacheException:";
			str += _errmsg;
			return str;
		}
	};
	class HttpServerException : public Exception {
	public:
		HttpServerException(const string& errmsg, int id, const string& type)
			:Exception(errmsg, id)
			, _type(type)
		{
		}
		virtual string what() const {
			string str = "HttpServerException:";
			str += _type;
			str += ":";
			str += _errmsg;
			return str;
		}
	private:
		const string _type;
	};

	void SQLMgr() {
		srand(time(0));
		if (rand() % 7 == 0) {
			throw SqlException("权限不足", 100, "select * from name = '张三'");
		}
		//throw "xxxxxx";
	}
	void CacheMgr() {
		srand(time(0));
		if (rand() % 5 == 0) {
			throw CacheException("权限不足", 100);
		}
		else if (rand() % 6 == 0) {
			throw CacheException("数据不存在", 101);
		}
		SQLMgr();
	}
	// 模拟http的错误
	void HttpServer() {
		// ...
		srand(time(0));
		if (rand() % 6 == 0) {
			throw HttpServerException("请求资源不存在", 100, "get");
		}
		else if (rand() % 4 == 0)
		{
			throw HttpServerException("权限不足", 101, "post");
		}
		CacheMgr();
	}
	int main() {
		while (1)
		{
			//this_thread::sleep_for(chrono::seconds(1));
			Sleep(300);
			try {
				HttpServer();
			}
			catch (const Exception& e) // 这里捕获父类对象就可以
			{
				// 利用继承和多态，可以用基类指针或引用
				// 父类的指针或引用，指向谁，就调用谁的异常模块
				cout << e.what() << endl;
			}
			// C++支持抛任意类型的异常，
			catch (...) {
				cout << "Unkown Exception" << endl;
			}
		}
		return 0;
	}
}

// 4. 异常的重新抛出
double Division(int a, int b) {
	// 当b == 0时抛出异常
	if (b == 0) {
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func() {
	/*int* array = new int[10];
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;

	delete[] array;*/
	// 这里可以看到如果发生除0错误抛出异常，会直接跳转到main函数中
	// 下面的array没有得到释放。

	// 解决方法:
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	// 异常的重新抛出
	catch (...) {
		cout << "delete []" << array << endl;
		delete[] array;
		throw;	// 捕获任意类型的异常，捕获之后重新抛出
	}
	// ...
	cout << "delete []" << array << endl;
	delete[] array;
	
}
int main()
{
	try{
		Func();
	}
	catch (const char* errmsg){
		cout << errmsg << endl;
	}
	return 0;
}



