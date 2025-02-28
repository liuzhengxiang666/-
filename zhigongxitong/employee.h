#pragma once
#include "worker.h"

class employee:public worker
{
public:

	employee(int id,string name,int workid );//构造函数

	virtual void showid();//显示个人信息

	virtual string workname();//岗位名称
	/*~employee();*/


};

