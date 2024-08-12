//此项目下的源文件只能一个一个跑
#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
using namespace std;

class Building;
class Good_Gay {
public:
	Good_Gay(); //构造函数
	void visit();	//类内的函数  公共接口
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



