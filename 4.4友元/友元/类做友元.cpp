
#include "类做友元.h"

 Building::Building() {
	 this->liv_room = "客厅";
	 this->_bed_room = "卧室";
}
 Good_Gay::Good_Gay() {
	 this->building = new Building;
 }

 void Good_Gay::visit() {
	 cout << "基友正在访问 ：" << this->building->liv_room << endl;
	 cout << "基友正在访问 ：" << this->building->_bed_room << endl;
 }

 void test_1() {
	 Good_Gay gg;
	 gg.visit();
 }
int main() {

	test_1();
	return 0;
}
