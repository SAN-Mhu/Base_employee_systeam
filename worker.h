#pragma once
#include<iostream>
#include<string>

using namespace std;

class Worker
{
public:
	virtual void ShowInfo()=0;
public:
	int m_Id;
	string m_Name;
	int m_Did;
};

