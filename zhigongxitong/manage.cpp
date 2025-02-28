#include "manage.h"

manage::manage(int id, string name, int workid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->work_ID = workid;
}
void manage::showid()
{
	cout << "职工编号： " << this->m_ID
		<< "\t职工姓名： " << this->m_Name
		<< "\t岗位名称:  " << this->workname()
		<< "\t你的职责是给老板当牛马" << endl;
}
string manage::workname()
{
	return "经理";
}