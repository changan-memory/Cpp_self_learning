#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

// ��ĩ�ع鸴ϰ�汾
namespace mm_vector {
	template<typename T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin() { return _start; }
		iterator end() { return _finish; }	// end�����һ��Ԫ�ص���һ��λ��
		const_iterator begin() const { return _start; }
		const_iterator end() const { return _finish; }
		// ָ�� - ָ�� �õ��м��Ԫ�ظ���
		size_t capacity() const {
			return _end_of_storage - _start;
		}
		size_t size() const {
			return _finish - _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	
	public:
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{ }
		// ��n��val����
		vector(size_t n, const T& val = T()){
			resize(n, val);
		}
		// �������캯��
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			/*T* newSpace = new T[v.capacity()];*/
			_start = new T[v.capacity()];
			// ���ǵ���memcpy�ĵط���Ӧ��ʵ��������͵�����
			//memcpy(_start, v._start, sizeof(T) * v.size());
			for (size_t i = 0; i < v.size(); ++i) {
				_start[i] = v[i];
			}
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}
		// �������캯���ĵڶ���д��
		/*vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for (auto& e : v)
				push_back(e);
		}*/
		// = ���� ���
		// v2 = v1
		// ����ʱ����ֵ������ÿ������캯���������Ѿ�ʵ�������  operator= �����
		vector<T>& operator=(vector<T> tmp) {
			swap(tmp);
			return *this;
		}
		// ����vector����
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
			// reserve ��ֻ��push_back�ã���Ҫ����Ƿ���Ҫ����
			if (newSize > capacity()) {
				T* newSpace = new T[newSize];
				size_t oldSize = size();
				if (_start) {
					// ���ǵ���memcpy�ĵط���Ӧ��ʵ��������͵�����
					//memcpy(newSpace, _start, sizeof(T) * oldSize);
					for (size_t i = 0; i < oldSize; ++i) {
						newSpace[i] = _start[i];	// ���Զ������е� = ����ʵ��������͵Ŀ���
						// ��д��Ҳ���������������͵Ŀ����������������ͱ���Ϳ�����=��ֵ
					}
					delete[] _start;
				}
				_start = newSpace;
				//_finish = _start + size();	// ��ʵ�������⣬����д_finish��ֵû��
				// �����size()  _start ָ���¿ռ��ˣ�����ʱ_finish��Ȼָ��ɿռ�
				_finish = _start + oldSize;
				_end_of_storage = _start + newSize;
			}
		}
		// ��resize��ʼ��һ��vector 
		//resize ��ʼ����val������Ĭ��ֵ(ȱʡ����)�������ȷ��ȱʡ����������
		// ��ʱ T() ������һ��T���͵��������� �������T���͵�Ĭ�Ϲ��죬дһ���࣬һ��Ҫ�ṩĬ�Ϲ���
		// ����� int ���������� resize��ô�ܣ�   �����ϲ�����
		// ����ģ���C++���������ͽ�����������Ҳ֧������������Ĭ�Ϲ��캯��
		// ��ʼ�� n ������
		void resize(size_t n, const T& val = T()) {
			// Ҫ��size ��Сʱ��ֱ�� �� _finish
			if (n < size())
				_finish = _start + n;
			// Ҫ��size ���ʱ��������Ŀռ���val��ʼ��
			else {
				reserve(n);		// n С�� capacityʱ��reserveʲô������������ʱ����
				// ��������Ŀռ���val���
				while(_finish != _start + n){
					*_finish = val;
					++_finish;
				}
			}
		}
		void push_back(const T& obj) {
			// �ж��Ƿ���Ҫ����
			if (_finish == _end_of_storage) {
				size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);
				reserve(newCapacity);
			}
			// �����߼�
			*_finish = obj;
			++_finish;
			//insert(end(), obj);
		}
		void pop_back() {
			erase(--end());
		}

		// ���ﱾ���Ͻ�������ڲ��ĵ�����ʧЧ

		// ������ʧЧ���⣺pos��¼���ǵ�ַ��
		// ���vector���ݺ�ԭ�ռ�ᱻ������
		// posָ���ĵ�ַ���Ͳ����¿ռ���pos�ĵ�ַ�ˣ������Ҫ����pos��ֵ
		//void insert(iterator pos, const T& obj) {
		//	// ��֤����λ����ȷ
		//	assert(pos >= _start && pos <= _finish);
		//	// �����߼�
		//	if (_finish == _end_of_storage) {
		//		size_t len = pos - _start;	// ��¼ pos ����� _start ��λ��
		//		size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);
		//		reserve(newCapacity);
		//		// ���ݺ����pos��ֵ����ֹ������ʧЧ
		//		pos = _start + len;
		//	}
		//	// Ų��Ԫ��
		//	iterator end = _finish - 1;
		//	while (end >= pos) {
		//		*(end + 1) = *end;
		//		--end;
		//	}
		//	// ��������
		//	*pos = obj;
		//	++_finish;
		//}

		// ����ڲ����ⲿ������������insertʵ�ַ���
		iterator insert(iterator pos, const T& obj) {
			// ��֤����λ����ȷ
			assert(pos >= _start && pos <= _finish);
			// �����߼�
			if (_finish == _end_of_storage) {
				size_t len = pos - _start;	// ��¼ pos ����� _start ��λ��
				size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);
				reserve(newCapacity);
				// ���ݺ����pos��ֵ����ֹ������ʧЧ
				pos = _start + len;
			}
			// Ų��Ԫ��
			iterator end = _finish - 1;
			while (end >= pos) {
				*(end + 1) = *end;
				--end;
			}
			// ��������
			*pos = obj;
			++_finish;
			return pos;
		}
		// Ϊ�˽��������ʧЧ���⣬erase���ش����pos����һ��λ��
		iterator erase(iterator pos) {
			assert(pos >= _start && pos < _finish);
			//ɾ��
			iterator begin = pos + 1;
			//while (begin < end()) {
			while (begin != _finish) {
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			// Ϊ�˽��������ʧЧ���⣬erase���ش����pos����һ��λ��
			// Ų�����ݺ�pos ���Ǳ�ɾ��Ԫ�غ����һ��Ԫ�ص�λ��
			return pos;	
		}

		//void insert(iterator pos, size_t n, const T& obj) {
		//	// ��֤����λ����ȷ
		//	assert(pos >= _start && pos <= _finish);
		//	// �����߼�
		//	if (_finish + n > _end_of_storage) {
		//		size_t len = pos - _start;	// ��¼ pos ����� _start ��λ��
		//		size_t newCapacity = (capacity() == 0 ? 4 : capacity() + n);
		//		reserve(newCapacity);
		//		// ���ݺ����pos��ֵ����ֹ������ʧЧ
		//		pos = _start + len;
		//	}
		//	// Ų������
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