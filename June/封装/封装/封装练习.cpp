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
public://成员函数可以直接访问成员变量
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
	//利用成员函数来判断两个立方体是否相等
	void judge(Cube &c2) {//传入另一个立方体与类内已有的立方体进行比较
		if ((len == c2.get_len()) && (wid == c2.get_wid()) && (hig == c2.get_hig())) {
			cout << "相等" << endl;
			return;
		}
		cout << "不相等" << endl;
	}
};
void judge(Cube c1, Cube c2) {//利用全局函数判断两个长方体是否相等
	if ((c1.get_len() == c2.get_len()) && (c1.get_wid() == c2.get_wid()) && (c1.get_hig() == c2.get_hig())) {
		cout << "相等" << endl;
		return;
	}
	cout << "不相等" << endl;

}
int main() {
	Cube c1, c2;
	c1.set_len(3);
	c1.set_wid(4);
	c1.set_hig(4);
	c2.set_len(3);
	c2.set_wid(4);
	c2.set_hig(5);
	cout << "1的面积为" << c1.s() << " 体积为" << c1.v() << endl;
	cout << "长 " << c1.get_len() <<" " << c1.get_wid() << " " << c1.get_hig() << endl;
	cout << "2的面积为" << c2.s() << " 体积为" << c2.v() << endl;
	cout << "长 " << c2.get_len() << " " << c2.get_wid() << " " << c2.get_hig() << endl;
	judge(c1, c2);
	c1.set_len(3);
	c1.set_wid(4);
	c1.set_hig(5);
	c1.judge(c2);

	system("pause");
	return 0;
}