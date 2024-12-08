#include <iostream>
using namespace std;

class CPU {
public:
	//抽象计算函数
	virtual void calculate() = 0;	//一般把父类中的函数写为纯虚函数
};
class VideoCard {
public:
	//抽象显示函数
	virtual void display() = 0;	//一般把父类中的函数写为纯虚函数
};
class Memory {
public:
	//抽象存储函数
	virtual void storage() = 0;	//一般把父类中的函数写为纯虚函数
};
class Computer {
public:
	Computer(CPU* cpu, VideoCard* videocard, Memory* memory ) {	//多态  可以传入子类
		this->_cpu = cpu;
		this->_videocard = videocard;
		this->_memory = memory;
	}
	void work() {		//根据传入的指针来调用不同的 类的方法
		this->_cpu->calculate();
		this->_memory->storage();
		this->_videocard->display();
	}
	//可以提供一个析构函数释放 电脑的零件指针
	~Computer() {		
		if (this->_cpu != nullptr) {
			delete this->_cpu;
			this->_cpu = nullptr;
		}
		if (this->_memory != nullptr) {
			delete this->_memory;
			this->_memory = nullptr;
		}
		if (this->_videocard != nullptr) {
			delete this->_videocard;
			this->_videocard = nullptr;
		}
	}
private:
	CPU* _cpu;
	VideoCard* _videocard;
	Memory* _memory;
};
class IntelCPU :public CPU {
public:
	virtual void calculate() {
		cout << "IntelCPU开始计算了" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Intel显卡开始显示了" << endl;
	}
};
class IntelMomory :public Memory {
public:
	virtual void storage() {
		cout << "Intel内存条开始存储了" << endl;
	}
};

class LenovoCPU :public CPU {
public:
	virtual void calculate() {
		cout << "LenovoCPU开始计算了" << endl;
	}
};
class LenovoVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Lenovo显卡开始显示了" << endl;
	}
};
class LenovoMomory :public Memory {
public:
	virtual void storage() {
		cout << "Lenovo内存条开始存储了" << endl;
	}
};

void test1() {
	CPU* intelcpu = new IntelCPU;
	VideoCard* intelvideocard = new IntelVideoCard;
	Memory* intelmemory = new IntelMomory;
	//组装第一台电脑
	Computer* computer1 = new Computer(intelcpu, intelvideocard, intelmemory);
	computer1->work();
	delete computer1;

	cout << "-------------------------" << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMomory);
	computer2->work();
	delete computer2;

	cout << "-------------------------" << endl;
	Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMomory);
	computer3->work();
	delete computer3;
}

int main() {

	test1();
	return 0;
}