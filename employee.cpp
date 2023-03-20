#include"employee.h"

using namespace std;

//构造函数
Employee::Employee(int id,string name,int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Did = did;
}

void Employee::ShowInfo()
{
	cout << "职工编号：" << this->m_Id << "     "
		<< "姓名：" << this->m_Name << "     "
		<< "岗位：" << "员工" << "     "
		<< "岗位职责：" << "完成经理安排的任务" << endl;
}

