//����Ŀ�µ�Դ�ļ�ֻ��һ��һ����
#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
using namespace std;

class Building;
class Good_Gay {
public:
	Good_Gay(); //���캯��
	void visit();	//���ڵĺ���  �����ӿ�
	void visit2();
private:
	Building* building;
};

class Building {
	//friend class Good_Gay;
	friend void Good_Gay::visit();
public:
	Building();

public:
	string liv_room;
private:
	string _bed_room;

};



