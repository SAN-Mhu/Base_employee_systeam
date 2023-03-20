#include"SysManager.h"
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"

using namespace std;


//系统管理类构造函数
SysManager::SysManager()
{
	this->Init_sys();
}

//获得文件内职工个数
int SysManager::get_empNum()
{
	//创建输入流对象
	ifstream ifs;
	//打开文件
	ifs.open(FILENAME, ios::in);
	//判断文件是否打开
	if (!ifs.is_open())
	{
		//cout<<"文件打开失败"<<endl;
		return 0;
	}
	//读取数据
	int id;
	string name;
	int did;

	int data_num=0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		data_num++;
	}
	ifs.close();

	return data_num;
}
//系统初始化
void SysManager::Init_sys()
{
	//创建输入流对象
	ifstream ifs;
	//打开文件
	ifs.open(FILENAME, ios::in);
	//判断文件是否打开
	//1.判断文件是否存在
	if (!ifs.is_open())
	{//文件不存在
		//cout << "文件不存在" << endl;
		this->Is_empty = true;
		this->m_size = 0;
		this->m_Marray = NULL;
		return;
	}
	//判断文件是否为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{//文件为空
		//cout << "文件为空" << endl;
		this->Is_empty = true;
		this->m_size = 0;
		this->m_Marray = NULL;
		return;
	}
	ifs.close();
	//关闭以上打开
	

	//当文件存在且不为空
	//创建输入流对象
	ifstream ifs1;
	//打开文件
	ifs1.open(FILENAME, ios::in);
	
	//获得文件内职工人数
	this->m_size = this->get_empNum();
	//开辟新空间
	this->m_Marray = new Worker * [this->m_size];
	//将文件内的数据拷贝进去
	int n_id;
	string n_name;
	int n_did;
	for (int i = 0; i < this->m_size; i++)
	{
		ifs1 >> n_id;
		ifs1 >> n_name;
		ifs1 >> n_did;
		switch (n_did)
		{
		case 1:
			this->m_Marray[i] = new Employee(n_id, n_name, 1);
			break;
		case 2:
			this->m_Marray[i] = new Manager(n_id, n_name, 2);
			break;
		case 3:
			this->m_Marray[i] = new Boss(n_id, n_name, 3);
			break;
		default:
			break;
		}

	}
	ifs1.close();
	//更新未空标志位
	this->Is_empty = false;
	
	

}
//职工信息保存
void SysManager::save_sys()
{
	//创建输出流对象
	ofstream ofs;
	//打开文件
	ofs.open(FILENAME,ios::out);
	//输入流对象
	for (int i = 0; i < this->m_size; i++)
	{
		ofs << this->m_Marray[i]->m_Id << " "
			<< this->m_Marray[i]->m_Name << " "
			<< this->m_Marray[i]->m_Did << endl;
	}
	//关闭文件
	ofs.close();
}
//菜单显示函数
void SysManager::ShowManu()
{
	cout << "***********************************************************" << endl;
	cout << "************	欢迎使用职工管理系统	***************" << endl;
	cout << "***************	0.退出系统	***************" << endl;
	cout << "***************	1.添加职工信息	***************" << endl;
	cout << "***************	2.显示职工信息	***************" << endl;
	cout << "***************	3.删除职工信息	***************" << endl;
	cout << "***************	4.修改职工信息	***************" << endl;
	cout << "***************	5.查找职工信息	***************" << endl;
	cout << "***************	6.排序职工信息	***************" << endl;
	cout << "***************	7.清空职工信息	***************" << endl;
	cout << "*********************************************************" << endl;
	cout << endl;
}
//按名字检索员工，返回索引号
int SysManager::find_emp(string f_name)
{
	int f_index = -1;
	if (this->Is_empty)//如果系统库无信息，则返回
	{ }
	else
	{
		for (int i = 0; i < this->m_size; i++)
		{
			if (this->m_Marray[i]->m_Name == f_name)
			{
				f_index = i;
				break;
			}
		}
	}
	
	return f_index;

}


//0.退出系统
void SysManager::exitSystem()
{
	cout << "欢迎您下次使用！" << endl;
	system("./pause.sh");
	exit(0);//退出系统

}
//1.添加员工
void SysManager::add_emp()
{

	int add_size;
	cout << "请输入要添加员工的数量：" << endl;
	cin >> add_size;

	//开辟一个新空间存放员工信息
	int newSize = this->m_size + add_size;
	Worker** newspace = new Worker * [newSize];
	//将原来的数据拷贝到新空间内
	for (int i = 0; i < this->m_size; i++)
	{
		newspace[i] = this->m_Marray[i];
	}

	int n_id;
	string n_name;
	int n_did;
	Worker * n_emp=NULL;
	for (int i = 0; i < add_size; i++)
	{
		
		cout << "请输入第" << i + 1 << "个职工的职工编号:" << endl;
		cin >> n_id;
		cout << "请输入第" << i + 1 << "个职工的姓名:" << endl;
		cin >> n_name;
		do
		{
			cout << "请选择第" << i + 1 << "个职工的岗位:" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> n_did;
			if (3 < n_did || n_did < 1)
				cout << "无效岗位，请重新输入！" << endl;

		} while (3<n_did || n_did<1);
		switch (n_did)
		{
		case 1:
			n_emp = new Employee(n_id, n_name,1);
			break;
		case 2:
			n_emp = new Manager(n_id, n_name, 2);
			break;
		case 3:
			n_emp = new Boss(n_id, n_name, 3);
			break;
		default:
			break;
		}
		//将新成员加入系统
		newspace[this->m_size + i] = n_emp;
	}
	//更改系统人数
	this->m_size = newSize;
	//更改数组指向
	this->m_Marray = newspace;
	//标志位更新
	this->Is_empty = false;
	this->save_sys();

	n_emp = NULL;
	newspace = NULL;
	cout << "添加成功！" << endl;

}
//2.显示员工信息
void SysManager::show_emp()
{
	if (this->Is_empty)
	{
		cout << "系统内暂无职工信息！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_size; i++)
		{
			//调用信息显示函数
			this->m_Marray[i]->ShowInfo();
		}
		cout << "职工信息显示完成！" << endl;
	}
}
//3.删除离职员工
void SysManager::delete_emp()
{
	if (this->Is_empty)
	{
		cout << "当前数据为空，无法删除" << endl;
		return;
	}
	
	string tager_name;
	cout << "请输入要删除的职工姓名：" << endl;
	cin >> tager_name;

	//查找目标职工索引号
	int tager_index = this->find_emp(tager_name);
	if(tager_index != -1)
	{
		//释放目标空间
		delete this->m_Marray[tager_index];
		this->m_Marray[tager_index] = NULL;
		//后面的数据往前覆盖
		for (int i = tager_index; i < this->m_size - 1; i++)
			this->m_Marray[i] = this->m_Marray[i + 1];
		if (this->m_size != 1 && ((this->m_size - 1) == tager_index))
		{
			//将最后一个对象释放
			delete this->m_Marray[this->m_size - 1];
			this->m_Marray[this->m_size - 1] = NULL;
		}

		//更新人数
		this->m_size --;
		//判断是否更新标志位
		if (!this->m_size)
			this->Is_empty = true;
		//更新系统库文件
		this->save_sys();
		cout << "职工已删除！" << endl;
	}
	else
	{
		cout << "该员工不存在！" << endl;
	}
}
//4.修改职工信息
void SysManager::alter_rmp()
{
	if (this->Is_empty)
	{
		cout << "当前职工为空，无法修改" << endl;
		return;
	}

	string tager_name;
	cout << "请输入要修改的职工姓名" << endl;
	cin >> tager_name;
	int a_index = this->find_emp(tager_name);
	if (a_index == -1)
	{
		cout << "查无此人，无法修改！" << endl;
		return;
	}

	//释放原有对象
	delete this->m_Marray[a_index];
	this->m_Marray[a_index] = NULL;

	int n_id;
	string n_name;
	int n_did;
	cout << "请输入修改后的职工编号：" << endl;
	cin >> n_id;
	cout << "请输入修改后的职工姓名：" << endl;
	cin >> n_name;
	do
	{
		cout << "请选择修改后的职工岗位:" << endl;
		cout << "1.普通员工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
		cin >> n_did;
		if (3 < n_did || n_did < 1)
			cout << "无效岗位，请重新输入！" << endl;

	} while (3 < n_did || n_did < 1);
	switch (n_did)
	{
	case 1:
		this->m_Marray[a_index] = new Employee(n_id, n_name, 1);
		break;
	case 2:
		this->m_Marray[a_index] = new Manager(n_id, n_name, 2);
		break;
	case 3:
		this->m_Marray[a_index] = new Boss(n_id, n_name, 3);
		break;
	default:
		break;
	}
	cout << "修改成功！" << endl;
	//保存更改到数据文件
	this->save_sys();

}
//5.查询职工信息
void SysManager::Serach_info()
{
	if (this->Is_empty)
	{
		cout << "当前职工为空，无法查找" << endl;
		return;
	}

	string tager_name;
	cout << "请输入要查找的职工姓名" << endl;
	cin >> tager_name;
	int a_index = this->find_emp(tager_name);
	if (a_index == -1)
	{
		cout << "查无此人" << endl;
		return;
	}
	else 
	{
		cout << "查找成功" << endl;
		this->m_Marray[a_index]->ShowInfo();
	}

}
//6.排序职工信息
void SysManager::sort_emp()
{
	if (this->Is_empty)
	{
		cout << "当前列表为空,无法排序" << endl;
		return;
	}
	Worker* temp = NULL;;
	for(int i=0;i<this->m_size-1;i++)
		for (int j = i; j < this->m_size; j++)
		{
			if (this->m_Marray[i]->m_Id > this->m_Marray[j]->m_Id)
			{//交换指向
				temp = this->m_Marray[i];
				this->m_Marray[i] = this->m_Marray[j];
				this->m_Marray[j] = temp;
			}
		}
	cout << "排序完成！" << endl;
	//保存结果到系统文件
	this->save_sys();

}
//7.清空职工信息
void SysManager::clear_emp()
{
	if (this->Is_empty)
	{
		cout << "当前系统已经为空！" << endl;
		return;
	}
	//开始清空
	for (int i = 0; i < this->m_size; i++)
	{
		delete this->m_Marray[i];
		this->m_Marray[i] = NULL;
	}
	delete[] this->m_Marray;
	this->m_Marray = NULL;
	this->m_size=0;
	this->Is_empty = true;

	cout << "已清空职工信息" << endl;
}

//系统管理类析构函数
SysManager::~SysManager()
{
	cout << "sysManager构造函数调用析构函数调用！" << endl;
	if (this->m_Marray != NULL)
	{
		for (int i = 0; i < this->m_size; i++)
		{
			delete this->m_Marray[i];
			m_Marray[i] = NULL;
		}

		delete[] this->m_Marray;
		this->m_Marray = NULL;
		this->m_size = 0;
	}
}
