#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
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
		string(const char* str = "") {
			_size = strlen(str);
			_capacity = _size;	//capacity��ʾ���Դ�ŵ��µ��ַ�����
			_str = new char[_capacity + 1];		//���ռ�+1  Ҫ���'\0'
			strcpy(_str, str);	//��������
		}
		//���޲ι���ͨ��ȱʡ�����ϲ�
		//string() {	//����Ĭ�Ϲ���  �޲ε� ȫȱʡ��  ���ǲ�д�������Լ����ɵ�
		//	_str = new char[1];
		//	_size = 0;
		//	_capacity = 0;
		//	_str[0] = '\0';
		//}

		//��������  ��ʵ�����
		string(const string& str) {
			_str = new char[str._capacity + 1];
			strcpy(_str, str._str);
			_size = str._size;
			_capacity = str._capacity;
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
				strcpy(newSpace, _str);		//new���������
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
			strcpy(_str + _size, str);
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