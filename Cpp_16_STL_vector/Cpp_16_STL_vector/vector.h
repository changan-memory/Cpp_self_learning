#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


namespace m_vector {
	template<class T>
	class vector {
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator cbegin() const { return _start; }
		const_iterator cend() const { return _finish; }

		//Ĭ�Ϲ��캯��
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{ }

		void reserve(size_t n) {
			// reserve ����ֻ��push_backʹ�ã����ҲҪ���
			if (n > capacity()) {
				size_t old_sz = size();
				T* tmp = new T[n];
				//ԭ�ռ䲻Ϊ��ʱ��������
				if (_start) {
					memcpy(tmp, _start, sizeof(T) * old_sz);
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + old_sz;
				_end_of_storage = _start + n;
			}
		}
		void push_back(const T& obj) {
			//�������������
			if (_finish == _end_of_storage) {
				size_t newCapacity = (capacity() == 0 ? 4 : capacity() * 2);	//��ʼ���¿ռ�
				reserve(newCapacity);											//����
			}
			*_finish = obj;
			++_finish;
		}

		// ָ�� - ָ�룬���ص�������ָ���м��Ԫ�ظ���
		size_t capacity() const {
			return _end_of_storage - _start;
		}
		size_t size() const {
			return _finish - _start;
		}
	private:
		//��STL�е�������񱣳�һ��
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}

