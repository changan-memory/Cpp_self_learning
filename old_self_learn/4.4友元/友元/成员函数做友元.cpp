#include <iostream>
#include "������Ԫ.h"
using namespace std;

Building::Building() {
	this->liv_room = "����";
	this->_bed_room = "����";
}

Good_Gay::Good_Gay() {
	this->building = new Building;
}

void Good_Gay::visit() {
	cout << "visit���ڷ��� " << this->building->liv_room << endl;
	cout << "visit���ڷ��� " << this->building->_bed_room << endl;
}

void Good_Gay::visit2() {

	cout << "visit2���ڷ���  " << this->building->liv_room << endl;
	cout << "visit2���ڷ���  " <<this->building->liv_room << endl;	//visit 2���ܷ��� bedroom
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