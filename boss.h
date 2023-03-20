#pragma once
#include"worker.h"

class Boss :public Worker
{
public:
	//构造函数
	Boss(int id, string name, int did);
	//信息显示函数 
	virtual void ShowInfo();

	//析构函数
	~Boss();
}; 

