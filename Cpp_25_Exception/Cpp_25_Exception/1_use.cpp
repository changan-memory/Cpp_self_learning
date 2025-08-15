#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

namespace use_1 {
	double Division(int a, int b) {
		//��b == 0ʱ�׳��쳣
		if (b == 0) {
			// �׳��쳣�󣬻�������ת��catch����ִ��
			// ��������ת�����뵱ǰ�쳣�׳�����ջ֡ �����ջ֡�в����쳣
			/*
				���ȼ��throw�����Ƿ���try���ڲ���������ٲ���ƥ���catch��䡣�����ƥ��ģ���
				����catch�ĵط����д���
				2. û��ƥ���catch���˳���ǰ����ջ�������ڵ��ú�����ջ�н��в���ƥ���catch��
				3. �������main������ջ������û��ƥ��ģ�����ֹ��������������ŵ���������ƥ���
				catch�Ӿ�Ĺ��̳�Ϊջչ��������ʵ�����������Ҫ��һ��catch(...)�����������͵���
				�����������쳣û���񣬳���ͻ�ֱ����ֹ��
				4. �ҵ�ƥ���catch�Ӿ䲢�����Ժ󣬻��������catch�Ӿ�������ִ��
			*/
			throw "Division by zero condition!";
			throw 1; // ��һ���������׳�����쳣���﷨��������û������
			// ��Ϊ�ϸ� throw ������󣬻�ֱ����ת��catch��ִ��catch����֮��Ĵ���
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
		// ֻ�а����� try catch �в��ܲ����쳣
		try {
			Func();
		}
		// û���쳣ʱ��catch���ᱻִ��
		catch (int errmsg) {
			cout << errmsg << endl;
		}
		// ֻ�� �׳����쳣���Ż�ִ��catch�Ĵ���
		catch (const char* errmsg) {
			cout << "�쳣�Ѳ���: " << errmsg << endl;
		}
		catch (...) {
			cout << "unkown exception" << endl;
		}
		cout << "�����쳣" << endl;
		return 0;
	}
}

namespace use_2 {
	// throw
// 1. �׳��쳣����󣬻�����һ���쳣����Ŀ�������Ϊ�׳����쳣���������һ����ʱ����
// ���Ի�����һ���������������������ʱ������ڱ�catch�Ժ����١�
// 2. catch(...)  �׳����쳣��û�б����񣬻�ֱ����ֹ����������
	double Division(int a, int b) {
		//��b == 0ʱ�׳��쳣
		if (b == 0) {
			string s("Division by zero condition!");
			throw s;	// �����׳� string ������׳��Ĳ��ǵ�ǰ�ֲ���� s
			// �׳����� s�Ŀ���  
			// �����������ʱ������ڱ�catch�Ժ����١�����Ĵ��������ں����Ĵ�ֵ����
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
		// ֻ�а����� try catch �в��ܲ����쳣
		try {
			Func();
		}
		// û���쳣ʱ��catch���ᱻִ��
		catch (int errmsg) {
			cout << errmsg << endl;
		}
		// ֻ�� �׳����쳣���Ż�ִ��catch�Ĵ���
		catch (const char* errmsg) {
			cout << "�쳣�Ѳ���: " << errmsg << endl;
		}
		// ���������ĳ��ģ������쳣�ˣ�����ģ��������������Ϊĳ��ģ���׳����쳣û�б�����
		// ����ֹ���������򣬲�����ΪСģ����쳣û���������ֹ����������
		// ������һ�����ߣ�catch(...)
		// ���Բ����������͵��쳣����ȱ����,��֪����ʲô���͵��쳣
		catch (...) {
			cout << "unknown exception" << endl;
		}
		return 0;
	}
}

//������������ͨ��ʹ�õ��쳣�̳���ϵ
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
			throw SqlException("Ȩ�޲���", 100, "select * from name = '����'");
		}
		//throw "xxxxxx";
	}
	void CacheMgr() {
		srand(time(0));
		if (rand() % 5 == 0) {
			throw CacheException("Ȩ�޲���", 100);
		}
		else if (rand() % 6 == 0) {
			throw CacheException("���ݲ�����", 101);
		}
		SQLMgr();
	}
	// ģ��http�Ĵ���
	void HttpServer() {
		// ...
		srand(time(0));
		if (rand() % 6 == 0) {
			throw HttpServerException("������Դ������", 100, "get");
		}
		else if (rand() % 4 == 0)
		{
			throw HttpServerException("Ȩ�޲���", 101, "post");
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
			catch (const Exception& e) // ���ﲶ�������Ϳ���
			{
				// ���ü̳кͶ�̬�������û���ָ�������
				// �����ָ������ã�ָ��˭���͵���˭���쳣ģ��
				cout << e.what() << endl;
			}
			// C++֧�����������͵��쳣��
			catch (...) {
				cout << "Unkown Exception" << endl;
			}
		}
		return 0;
	}
}

// 4. �쳣�������׳�
double Division(int a, int b) {
	// ��b == 0ʱ�׳��쳣
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
	// ������Կ������������0�����׳��쳣����ֱ����ת��main������
	// �����arrayû�еõ��ͷš�

	// �������:
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	// �쳣�������׳�
	catch (...) {
		cout << "delete []" << array << endl;
		delete[] array;
		throw;	// �����������͵��쳣������֮�������׳�
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



