#include<iostream>
#include<string>
#include"SysManager.h"

using namespace std;

void Penter()
{
	//创建一个系统管理类对象
	SysManager sm;
	while(true)
	{
		sm.ShowManu();	//显示菜单
		int opt = 0;				//选择变量
		cout << "请选择您要进行的操作：" << endl;
		cin >> opt;

		switch (opt)
		{
		case 0://退出职工系统
			sm.exitSystem();
			break; 
		case 1://添加职工信息
			sm.add_emp();
			break;
		case 2://显示职工信息
			sm.show_emp();
			break;
		case 3://删除职工信息
			sm.delete_emp();
			break;
		case 4://修改职工信息
			sm.alter_rmp();
			break;
		case 5://查询职工信息
			sm.Serach_info();
			break;
		case 6://排序职工信息
			sm.sort_emp();
			break;
		case 7://清空职工信息
			sm.clear_emp();
			break;
		default:
			break;
		}

		system("./pause.sh");
		system("./cls.sh");
	}
	
}

int main()
{
	Penter();

	return 0;
}
