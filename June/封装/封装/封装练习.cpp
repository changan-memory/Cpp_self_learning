#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
class Cube {
private:
	int len = 1;
	int wid = 1;
	int hig = 1;
public://��Ա��������ֱ�ӷ��ʳ�Ա����
	int s() {
		return 2 * (len * wid + len * hig + wid * hig);
	}
	int v() {
		return len * wid * hig;
	}
	void set_len(int a) {
		len = a;
	}
	int get_len() {
		return len;
	}
	void set_wid(int a) {
		wid = a;
	}
	int get_wid(){
		return wid;
	}
	void set_hig(int a) {
		hig = a;
	}
	int get_hig() {
		return hig;
	}
	//���ó�Ա�������ж������������Ƿ����
	void judge(Cube &c2) {//������һ�����������������е���������бȽ�
		if ((len == c2.get_len()) && (wid == c2.get_wid()) && (hig == c2.get_hig())) {
			cout << "���" << endl;
			return;
		}
		cout << "�����" << endl;
	}
};
void judge(Cube c1, Cube c2) {//����ȫ�ֺ����ж������������Ƿ����
	if ((c1.get_len() == c2.get_len()) && (c1.get_wid() == c2.get_wid()) && (c1.get_hig() == c2.get_hig())) {
		cout << "���" << endl;
		return;
	}
	cout << "�����" << endl;

}
int main() {
	Cube c1, c2;
	c1.set_len(3);
	c1.set_wid(4);
	c1.set_hig(4);
	c2.set_len(3);
	c2.set_wid(4);
	c2.set_hig(5);
	cout << "1�����Ϊ" << c1.s() << " ���Ϊ" << c1.v() << endl;
	cout << "�� " << c1.get_len() <<" " << c1.get_wid() << " " << c1.get_hig() << endl;
	cout << "2�����Ϊ" << c2.s() << " ���Ϊ" << c2.v() << endl;
	cout << "�� " << c2.get_len() << " " << c2.get_wid() << " " << c2.get_hig() << endl;
	judge(c1, c2);
	c1.set_len(3);
	c1.set_wid(4);
	c1.set_hig(5);
	c1.judge(c2);

	system("pause");
	return 0;
}