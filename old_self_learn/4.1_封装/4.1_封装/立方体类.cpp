#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Cube {
public:
	void set_length(int length) {
		_length = length;
	}
	void set_width(int width) {
		_width = width;
	}
	void set_height(int height) {
		_height = height;
	}
	int get_length() {
		return _length;
	}
	int get_width() {
		return _width;
	}
	int get_height() {
		return _height;
	}
	int get_squel() {
		return 2 * (_length * _width + _length * _height + _width * _height);
	}
	int get_V() {
		return _length * _width * _height;
	}
	bool is_same(Cube& c) {
		if (_length == c.get_length() && _width == c.get_width() && _height == c.get_height())
			return true;
		return false;
	}
private:
	int _length = 0;
	int _width = 0;
	int _height = 0;
};

bool _same(Cube &c1, Cube &c2) {
	if (c1.get_height() == c2.get_height() && c1.get_length() == c2.get_length() && c1.get_width() == c2.get_width())
		return true;
	else
		return false;
}
//int main() {
//	Cube c1;
//	Cube c2;
//	c1.set_height(10);
//	c1.set_length(10);
//	c1.set_width(10); 
//
//	c2.set_height(10);
//	c2.set_length(10);
//	c2.set_width(10);
//	// 实例化的类有各自的属性，成员函数法判断  是把传入的类的属性与自身的属性进行比较
//	cout << _same(c1, c2) << endl;
//	cout << c1.is_same(c2) << endl;
//	
//
//	return 0;
//}