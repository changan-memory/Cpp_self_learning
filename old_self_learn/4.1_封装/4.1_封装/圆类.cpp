#include <iostream>
using namespace std;

class Point {
public:
	void Set_x(int x) {
		_x = x;
	}
	void Set_y(int y) {
		_y = y;
	}
	int get_x() {
		return _x;
	}
	int get_y() {
		return _y;
	}

private:
	int _x;
	int _y;
};

class Circle {
public:
	int judge_location(Point p) {
		if (((p.get_x() - center.get_x()) * (p.get_x() - center.get_x()) + (p.get_y() - center.get_y()) * (p.get_y() - center.get_y())) > r * r)
			return 1;
		if (((p.get_x() - center.get_x()) * (p.get_x() - center.get_x()) + (p.get_y() - center.get_y()) * (p.get_y() - center.get_y())) == r * r)
			return 0;
		else return -1;
	}


private:
	int r;
	Point center;
};



int main() {

	system("pause");
	return 0;
}