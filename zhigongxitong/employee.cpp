#include "employee.h"

employee::employee(int id, string name, int workid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->work_ID = workid;
}
void employee::showid()
{
	cout << "职工编号： " << this->m_ID 
		<< "\t职工姓名： " << this->m_Name
		<< "\t岗位名称: " << this->workname()
		<< "\t你的职责是打工仔"<<endl;
}
string employee::workname()
{
	return "员工";
}
/*employee::~employee()
{
	delete this
}*/