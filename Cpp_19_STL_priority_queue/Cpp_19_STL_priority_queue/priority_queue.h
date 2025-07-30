#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace m_priority_queue {

	template<typename T, typename Conatiner = vector<T>>
	class priority_queue {
	public:
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last) {

		}
	private:
		Conatiner _con;
	};
}