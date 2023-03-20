#pragma once
#include"worker.h"

class Employee:public Worker
{
public:
	//构造函数
	Employee(int id, string name, int did);
	//信息显示函数 
	virtual void ShowInfo();

	//析构函数
	~Employee();
};
