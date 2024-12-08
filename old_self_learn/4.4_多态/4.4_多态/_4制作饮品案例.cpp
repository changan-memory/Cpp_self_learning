//#include <iostream>
//using namespace std;
//
//class AbstractDrinking {
//public:
//	//ÖóË®
//	virtual void Boil() = 0;
//	//³åÅÝ
//	virtual void Brew() = 0;
//	//µ¹Èë±­ÖÐ
//	virtual void PourCup() = 0;
//	//¼ÓÈë¸¨ÁÏ
//	virtual void AddSth() = 0;
//	//ÖÆ×÷
//	void make() {
//		this->Boil();
//		this->Brew();
//		this->PourCup();
//		this->AddSth();
//	}
//};
//
//class Coffee :public AbstractDrinking {
//	virtual void Boil() {
//		cout << "ÖóÅ©·òÉ½ÈªË®" << endl;
//	}
//	virtual void Brew() {
//		cout << "³å¿§·È·Û" << endl;
//	}
//	virtual void PourCup() {
//		cout << "µ¼Èë¿§·È±­" << endl;
//	}
//	virtual void AddSth() {
//		cout << "¼ÓÈëÅ£ÄÌ" << endl;
//	}
//};
//
//class Tea :public AbstractDrinking {
//	virtual void Boil() {
//		cout << "Öó¿óÈªË®" << endl;
//	}
//	virtual void Brew() {
//		cout << "³å²èÒ¶" << endl;
//	}
//	virtual void PourCup() {
//		cout << "µ¹Èë²è±­" << endl;
//	}
//	virtual void AddSth() {
//		cout << "¼ÓÈëèÛè½" << endl;
//	}
//};
//
//void dowork(AbstractDrinking* abs) {
//	abs->make();
//	delete abs;
//	abs = nullptr;
//}
//
//void test1() {
//	dowork(new Coffee);
//	cout << "------------------" << endl;
//	dowork(new Tea);
//}
//
//int main() {
//
//	test1();
//
//	return 0;
//}