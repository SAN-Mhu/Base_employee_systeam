#pragma once
#include<iostream>
#include<string>
#include"worker.h"
#include<fstream>

#define FILENAME "emp_data.txt"

//创建一个管理类
class SysManager
{
public:
	//系统管理类构造函数
	SysManager();
	
	//系统初始化
	void Init_sys();
	//获得文件内职工个数
	int get_empNum();
	//系统职工信息保存文件
	void save_sys();
	//菜单显示函数
	void ShowManu();
	//按名字检索员工，返回索引号
	int find_emp(string f_name);


	//0.退出系统
	void exitSystem();
	//1.添加员工
	void add_emp();
	//2.显示员工信息
	void show_emp();
	//3.删除离职员工
	void delete_emp();
	//4.修改职工信息
	void alter_rmp();
	//5.查询职工信息
	void Serach_info();
	//6.排序职工信息
	void sort_emp();
	//7.清空职工信息
	void clear_emp();

	
	//系统管理类析构函数
	~SysManager();

public:
	int m_size;
	Worker** m_Marray;
	//判断系统内职工是否为空
	bool Is_empty;

};
