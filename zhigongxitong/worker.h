#pragma once
#include <iostream>
using namespace std;
#include<string>

class worker
{
public:

	virtual void showid() = 0;//展示信息

	virtual string workname() = 0;//获取岗位名称

	int m_ID=-1;  //员工编号
	string m_Name;//员工名字
	int work_ID=-1;//部门编号


};