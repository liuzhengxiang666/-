#pragma once
#include <iostream>
using namespace  std;
#include "worker.h"
#include <fstream>



class workerManager
{
public:
	void exitout();
	void  add_emp();//添加用户
	void save();//保存文件
	int get_num();//获取职工人员数量
	void showallperson();//显示员工信息
	int isexsit(int);//检测是否存在放回数组的索引位置
	void restart();//初始化
	workerManager();
	void show_menu();
	~workerManager();
	void deleteperson();//删除成员
	void changepenson();//修改成员
	void searchperson();//查找人员
	void sortperson();//排序
	void clearfile();

	int m_nums;//员工人数
	worker* * m_arrys;  //  worker指针型
	bool m_Fileemty;//true 时文件为空
};

