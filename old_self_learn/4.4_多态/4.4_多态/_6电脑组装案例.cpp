#include <iostream>
using namespace std;

class CPU {
public:
	//������㺯��
	virtual void calculate() = 0;	//һ��Ѹ����еĺ���дΪ���麯��
};
class VideoCard {
public:
	//������ʾ����
	virtual void display() = 0;	//һ��Ѹ����еĺ���дΪ���麯��
};
class Memory {
public:
	//����洢����
	virtual void storage() = 0;	//һ��Ѹ����еĺ���дΪ���麯��
};
class Computer {
public:
	Computer(CPU* cpu, VideoCard* videocard, Memory* memory ) {	//��̬  ���Դ�������
		this->_cpu = cpu;
		this->_videocard = videocard;
		this->_memory = memory;
	}
	void work() {		//���ݴ����ָ�������ò�ͬ�� ��ķ���
		this->_cpu->calculate();
		this->_memory->storage();
		this->_videocard->display();
	}
	//�����ṩһ�����������ͷ� ���Ե����ָ��
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
		cout << "IntelCPU��ʼ������" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Intel�Կ���ʼ��ʾ��" << endl;
	}
};
class IntelMomory :public Memory {
public:
	virtual void storage() {
		cout << "Intel�ڴ�����ʼ�洢��" << endl;
	}
};

class LenovoCPU :public CPU {
public:
	virtual void calculate() {
		cout << "LenovoCPU��ʼ������" << endl;
	}
};
class LenovoVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Lenovo�Կ���ʼ��ʾ��" << endl;
	}
};
class LenovoMomory :public Memory {
public:
	virtual void storage() {
		cout << "Lenovo�ڴ�����ʼ�洢��" << endl;
	}
};

void test1() {
	CPU* intelcpu = new IntelCPU;
	VideoCard* intelvideocard = new IntelVideoCard;
	Memory* intelmemory = new IntelMomory;
	//��װ��һ̨����
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