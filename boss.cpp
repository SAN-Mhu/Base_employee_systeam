#include"boss.h"

using namespace std;

//构造函数
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

void Boss::ShowInfo()
{
	cout << "职工编号：" << this->m_Id << "     "
		<< "姓名：" << this->m_Name << "     "
		<< "岗位：" << "老板" << "     "
		<< "岗位职责：" << "管理公司" << endl;
}
