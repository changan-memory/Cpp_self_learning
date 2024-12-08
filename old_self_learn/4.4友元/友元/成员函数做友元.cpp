#include <iostream>
#include "类做友元.h"
using namespace std;

Building::Building() {
	this->liv_room = "客厅";
	this->_bed_room = "卧室";
}

Good_Gay::Good_Gay() {
	this->building = new Building;
}

void Good_Gay::visit() {
	cout << "visit正在访问 " << this->building->liv_room << endl;
	cout << "visit正在访问 " << this->building->_bed_room << endl;
}

void Good_Gay::visit2() {

	cout << "visit2正在访问  " << this->building->liv_room << endl;
	cout << "visit2正在访问  " <<this->building->liv_room << endl;	//visit 2不能访问 bedroom
}

void test() {
	Good_Gay gg;
	gg.visit();
	gg.visit2();
}


int main() {
	test();
	return 0;
}