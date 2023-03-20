#include"manager.h"

using namespace std;

//构造函数
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

void Manager::ShowInfo()
{
	cout << "职工编号：" << this->m_Id << "     "
		<< "姓名：" << this->m_Name << "     "
		<< "岗位：" << "经理" << "     "
		<< "岗位职责：" << "完成老板安排的任务,安排好下属的工作" << endl;
}

