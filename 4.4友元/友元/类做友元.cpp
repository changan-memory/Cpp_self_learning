
#include "������Ԫ.h"

 Building::Building() {
	 this->liv_room = "����";
	 this->_bed_room = "����";
}
 Good_Gay::Good_Gay() {
	 this->building = new Building;
 }

 void Good_Gay::visit() {
	 cout << "�������ڷ��� ��" << this->building->liv_room << endl;
	 cout << "�������ڷ��� ��" << this->building->_bed_room << endl;
 }

 void test_1() {
	 Good_Gay gg;
	 gg.visit();
 }
int main() {

	test_1();
	return 0;
}
