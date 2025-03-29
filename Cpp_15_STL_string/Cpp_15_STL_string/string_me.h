#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cstring>
using namespace std;

namespace m_string {
	class string {
	public:
		//STL�еĵ�������������ָ�룬Ҳ���ܲ���ָ��
		//string�ĵ�������������char*
		typedef char* iterator;
		typedef const char* const_iterator;
		
		//��ͨ����ĵ�����
		iterator begin() {		
			//return &_str[0];
			return _str;	//�������ǵ�һ��Ԫ�صĵ�ַ
		}
		iterator end() {
			//return &_str[_size];
			return _str+_size;
		}
		//const���������
		const_iterator begin() const {
			return _str;	
		}
		const_iterator end() const {
			return _str + _size;
		}

		//���캯��
		//string(const char* str)	//��ʼ���б��ǰ��ճ�Ա���������������Ĵ�����г�ʼ����
		//	:_size(strlen(str))
		//	,_capacity(_size)
		//	,_str(new char[_capacity+1])
		//{
		//	strcpy(_str, str);	//���˵����˳�ʼ���б��˳������׳���
		//}
		
		//��c_str����
		//������ʹ�ó�ʼ���б��ʼ��������Щ���ܳ�ʼ���б���ɲ��ˡ�
		// ���������� ��ʼ���б�/�������� ��ʼ������ν���Զ������;����ڳ�ʼ���б�
		//string(const char* str = '\0')
		//string(const char* str = nullptr)
		//string(const char* str = "\0")	//���д�����ý�β������"\0"
		//�ַ����Ľ���λ�ñ�����\0
		string(const char* str = "") {	//��c�����ַ������й��죬Ĭ����\0Ϊ������
			_size = strlen(str);
			_capacity = _size;	//capacity��ʾ���Դ�ŵ��µ��ַ�����
			_str = new char[_capacity + 1];		//���ռ�+1  Ҫ���'\0'
			//strcpy(_str, str);	//��������,�����м京��\0���ַ�������Bug
			//strcpyĬ�ϻ� ����\0�� ���ʹ��memcpy����Ҫ���������ֽ���+1����\0��λ��
			memcpy(_str, str, _size + 1);	
		}
		//���޲ι���ͨ��ȱʡ�����ϲ�
		//string() {	//����Ĭ�Ϲ���  �޲ε� ȫȱʡ��  ���ǲ�д�������Լ����ɵ�
		//	_str = new char[1];
		//	_size = 0;
		//	_capacity = 0;
		//	_str[0] = '\0';
		//}

		//��������  Ҫʵ���������һ���µĿռ䣬�������ݣ�����ʼ��
		string(const string& str) {
			_str = new char[str._capacity + 1];
			//strcpy(_str, str._str);
			memcpy(_str, str._str, str._size + 1);
			_size = str._size;
			_capacity = str._capacity;
		}

		//������string�Ĺ��캯�����ִ�д��������д���������м京��\0�ַ�����������
		/*string(const string& s) 
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(s.c_str());
			swap(tmp);
		}*/
		
		// ��ͳд��
		//	s1 = s3
		//string& operator=(const string& str) {
		//	if (this != &str) {
		//		char* newSpace = new char[str._capacity + 1];	//���ռ�
		//		memcpy(newSpace, str._str, str._size + 1);		//������
		//		delete[] _str;			//�ͷ�ԭ�ռ�
		//		_str = newSpace;

		//		_size = str._size;
		//		_capacity = str._capacity;
		//	}
		//	return *this;
		//}

		//��ֵ���ִ�д��
		//string& operator=(const string& str) {
		//	if (this != &str) {
		//		string tmp(str);		//����tmp����������ҲҪ���٣�������������ʱ��˳���
		//		// s1 ��Ҫtmp�Ŀռ�
		//		std::swap(_str, tmp._str);		//����ֱ�ӽ����������󣬷�����������ֵ
		//		std::swap(_size, tmp._size);
		//		std::swap(_capacity, tmp._capacity);

		//		//����ֱ��
		//		//swap(tmp);
		//	}
		//	return *this;
		//}

		// ��������string���������
		void swap(string& str) {		
			std::swap(_str, str._str);		//����ֱ�ӽ�����������
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}
		// s1 = s3
		string& operator=(string tmp) {		//ֱ�����ú������������s3������������,�β��Զ�����
			this->swap(tmp);			// ��s3�Ŀ�����s1 Ҳ���� *this ����
			return *this;		// ����*this, Ҳ���� s1
		}
		//��������
		~string() {
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		//����c_str			const ����thisָ��ָ��Ķ��󣬿�������ͨ�����const���󶼿��Ե�
		//�����ڲ��޸Ķ��󣬽������const
		const char* c_str() const { 
			return _str; 
		}

		//����_size
		size_t size() const {
			return _size;
		}

		//[]����		//const�����const�汾[]    ��ͨ�������ͨ�汾[]
		char& operator[](size_t pos) {	//�������ã���д�汾
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const {	//ֻ���汾
			assert(pos < _size);
			return _str[pos];
		}

		//������reserve��ʵ������
		//������������Ļ���memcpy�����
		void reserve(size_t request_size) {	//request_sizeָ����Ҫ��ŵ��ַ��ĸ���
			if (request_size > _capacity) {	//����Ŀռ����_capacityʱ��������
				char* newSpace = new char[request_size + 1];	//�࿪һ���ռ���\0
				//strcpy(newSpace, _str);		//new���������
				memcpy(newSpace, _str, _size + 1);
				delete[] _str;
				_str = newSpace;
				_capacity = request_size;
			}
		}
		//+=�ı�����push_back�����ʵ��push_back
		void push_back(char ch) {
			//�ȿ�������
			if (_size == _capacity) {
				//��������,����ֹ�չ�����ַ���
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size++] = ch;	//���ַ�
			_str[_size] = '\0';	//����\0
		}
		void append(const char* str) {
			size_t len = strlen(str);
			if (_size + len > _capacity) {
				//�������ݵ�_size + len
				reserve(_size + len);
			}
			//strcpy(_str + _size, str);
			memcpy(_str + _size, str, len + 1);
			_size += len;	//�����_sizeҪ�ı�
		}
		string& operator+=(char ch) {
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str) {
			append(str);
			return *this;
		}

		void insert(size_t pos, size_t n, char ch) {
			assert(pos <= _size);	//_sizeλ�����ַ�����ĩβ���������ַ�����ĩβ����
			//����
			if (_size + n > _capacity)
				reserve(_size + n);
			//Ų������
			//�������posΪ0ʱ��end����-1��end��size_t,-1�������ε����ֵ����һֱ����ѭ��
			//size_t end = _size;	
			//int end = _size;	
			//while (end >= (int)pos) {	//��������� �������������Ͳ�һ��ʱ�����������
			//						// һ���Ƿ�ΧС����Χ��Ľ�������
			//	_str[end + n] = _str[end];
			//	--end;
			//}
			size_t end = _size;
			while (end >= pos && end != npos) {
				_str[end + n] = _str[end];
				--end;
			}
			for (size_t i = 0; i < n; ++i) {
				_str[pos + i] = ch;
			}
			_size += n;
			_str[_size] = '\0';		//����ַ���������־
		}
		void insert(size_t pos, const char* str) {
			assert(pos <= _size);	//_sizeλ�����ַ�����ĩβ���������ַ�����ĩβ����
			size_t len = strlen(str);
			//����
			if (_size + len > _capacity)
				reserve(_size + len);

			size_t end = _size;
			while (end >= pos && end != npos) {
				_str[end + len] = _str[end];
				--end;
			}
			for (size_t i = 0; i < len; ++i)
				_str[pos + i] = str[i];

			_size += len;
			_str[_size] = '\0';		//����ַ���������־
		}
		//��posλ�ÿ�ʼɾ��ɾ��len���ַ���������Ĭ��ɾ��
		void erase(size_t pos, size_t len = npos) {
			assert(pos);
			if (len == npos || pos + len > _size) {		//�����ֶ���ɾ������
				_str[pos] = '\0';
				_size = pos;
				_str[_size] = '\0';
			}
			else {
				size_t end = pos + len;
				while (end < _size) {	//end = '\0'ʱ�����԰�'\0'ҲŲ����
					_str[pos++] = _str[end++];
					//++end;
				}
				_size -= len;
				_str[_size] = '\0';
			}
		}
		//�����ַ�
		size_t find(char ch, size_t pos = 0) const {
			assert(pos < _size);
			for (size_t i = pos; i < _size; ++i) {
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0) const {
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, str);	//���ԴӲ�ͬ��λ�ÿ�ʼ����
			if (ptr)
				return ptr - _str;
			else
				return npos;
		}

		string substr(size_t pos = 0, size_t len = npos) const {
			assert(pos < _size);
			size_t n = len;
			if (len == npos || (pos + len) > _size)
				n = _size - pos;

			string tmp;
			tmp.reserve(n);
			for (size_t i = pos; i < pos + n; ++i) {
				tmp += _str[i];
			}
			return tmp;	//���������򣬶������٣�Ҫ��ֵ����
		}

		void resize(size_t newSize, char ch = '\0') {
			if (newSize < _size) {
				_size = newSize;
				_str[_size] = '\0';
			}
			else {
				//reserve���ж�newSize��_capacity�Ĵ�С���������ݣ�С�ڲ�������
				reserve(newSize);
				//���ݺ���г�ʼ��
				for (size_t i = _size; i < newSize; ++i)
					_str[i] = ch;
				_size = newSize;
				_str[_size] = '\0';
			}
		}
		//�������
		void clear() {
			_str[0] = '\0';
			_size = 0;
		}

		// hello hello false
		// helloxxx hello false
		// hello helloxxx true
		bool operator<(const string& str) const {
			size_t i1 = 0, i2 = 0;
			//�ȱȽ�ͬ���ĳ���
			while (i1 < _size && i2 < str._size) {
				if (_str[i1] < str._str[i2])
					return true;
				else if (_str[i1] > str._str[i2])
					return false;
				else {
					++i1;
					++i2;
				}
			}
			//������ i1 == _size �� i2 == str._size
			// i1 == _size && i2 != str_sizeʱ������str���滹���ַ�����˵������ĸ���
			return i1 == _size && i2 != str._size;
		}
		//���ÿ�ķ�ʽ
		//bool operator<(const string& str) const {
		//	int ret = memcmp(_str, str._str, _size < str._size ? _size : str._size);
		//	return ret == 0 ? _size < str._size : ret < 0;
		//	//return ret < 0 ? true : false;   ����ʽ
		//}
		bool operator==(const string& str) const {
			return _size == str._size			//�����ַ�����ȣ��䳤��һ�����
				&& memcmp(_str, str._str, _size) == 0;		//�ٱȽ��������Ƿ����
		}
		bool operator<=(const string& str) const {
			return *this < str || *this == str;
		}
		bool operator>(const string& str) const {
			return !(*this <= str);
		}
		bool operator>=(const string& str) const {
			return (*this < str);
		}
		bool operator!=(const string& str) const {
			return !(*this == str);
		}
	private:
		size_t _size;
		size_t _capacity;	//_capacityһ�㲻����\0
		char* _str;
		//static::size_t npos = -1;	//��̬��Ա�������ܸ�ȱʡֵ��ȱʡֵ�Ǹ���ʼ���б��õ�
		//������ô�ã����ǲ�����
	public:
		const static size_t npos;	//���龲̬��Ա�����������Ͷ������
	};
	const size_t string::npos = -1;
}

// ��Ա�����ĵ�һ��������this
// ����ϣ����һ�����������������Ҫ���س�ȫ�ֵ�
ostream& operator<<(ostream& out, const m_string:: string& s) {
	//ostream����һ���£����˷����������ostream�������򷵻�ֵʱҪ������
	for (int i = 0; i < s.size(); ++i)
		out << s[i];
	/*for (auto& e : s)
		out << e;*/
	return out;
}

//����ȡ���ܼ� const
istream& operator>>(istream& in, m_string::string& s) {
	/*char ch;
	in >> ch;*/
	//s.clear();	//ÿ�ζ�ȡҪ�����,��ֹ �����������ʱ�������ص�
	char ch = in.get();
	char buff[128];

	//��� ��һ����Ч��������ǰ�Ŀո�ͻ���
	while (ch == ' ' || ch == '\n') {
		ch = in.get();
	}
	int i = 0;
	while (ch != ' ' && ch != '\n'){	//����д���������ַ����еĿո����,��Ϊ
										//����ѡ�� ʹ�� \n ���� ' '��Ϊ�ַ����ķָ���
		//s += ch;		//+=����������ַ����ǳ���ʱ���᲻������,����buff�������ݵĴ���
		buff[i++] = ch;
		if (i == 127) {
			buff[i] = '\0';
			s += buff;
			i = 0;
		}
		//in >> ch;
		ch = in.get();
	}
	if (i != 0) {
		buff[i] = '\0';
		s += buff;
	}
	return in;
}