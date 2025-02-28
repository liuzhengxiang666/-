#include "workerManager.h"
#include "employee.h"
#include "manage.h"
#include "boss.h"
#define Filename "emtest.txt"

workerManager::workerManager()
{
	ifstream ifs;
	ifs.open(Filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		this->m_Fileemty = true;
		this->m_arrys = nullptr;
		this->m_nums = 0;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文档为空" << endl;
		this->m_Fileemty = true;
		this->m_arrys = nullptr;
		this->m_nums = 0;
		ifs.close();
		return;

	}
	this->m_nums = this->get_num();//获取文件中的人数,打开成功且文件不为空的情况下

	this->m_arrys = new worker * [m_nums];//开辟了并返回一个指向worker类型的指针大小为文件中已有的大小
	restart();//初始化文件的成员，放到数组中，调用了多态双指针



}
void workerManager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void workerManager::add_emp()
{
	int num = 0;
	cout << "请输入需要添加的员工数量：" << endl;
	cin >> num;
	if (num > 0)
	{
		int newsize = num + this->m_nums;
		worker** newarry = new worker * [newsize];//在堆区开辟新空间
		if (this->m_arrys != nullptr)
		{
			for (int i = 0; i < m_nums; i++)//原来的先加进去
			{
				newarry[i] = this->m_arrys[i];
			}
		}
		for (int i = 0; i < num; i++)//后来的再加
		{
			int id01;
			string name01;
			int wk01;
			cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
			cin >> id01;
			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name01;


			cout << "请输入第" << i + 1 << "个新职工的岗位名称" << endl;
			cout << "1.打工仔" << endl;
			cout << "2.项目经理" << endl;
			cout << "3.老板" << endl;

			cin >> wk01;

			worker* wr = nullptr;

			switch (wk01)
			{
			case 1:
				wr = new employee(id01,name01, wk01);
				break;
			case 2:
				wr = new manage(id01, name01, wk01);
				break;
			case 3:
				wr = new boss(id01, name01, wk01);
				break;
			default:
				break;


			}
			newarry[this->m_nums + i] = wr;
		


		}
		delete[] this->m_arrys;
		this->m_arrys = newarry;   //数据
		this->m_nums = newsize;  //更新人员数量
		this->m_Fileemty = false; //文件为不空了
		cout << "成功添加" << num << "个新成员" << endl;


	}
	else
	{
		cout << "输入失败" << endl;
	}
	system("pause");
	system("cls");

}

workerManager::~workerManager()
{
	delete this->m_arrys;
	this->m_arrys = nullptr;

}
void workerManager::exitout()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(1);

}
void workerManager::save()//保存文件的功能
{
	ofstream ofs;
	ofs.open(Filename, ios::out);
	if (!ofs.is_open())
	{
		cout << "打开失败请重试" << endl;
		return;
	}
	for (int i = 0; i < this->m_nums; i++)
	{
		ofs << this->m_arrys[i]->m_ID << " "
			<< this->m_arrys[i]->m_Name << " "
			<< this->m_arrys[i]->work_ID << endl;
	}
	ofs.close();

}

int workerManager::get_num()
{
	int num01 = 0;
	ifstream ifs;
	ifs.open(Filename, ios::in);
	int id;
	string name;
	int workid;
	while (ifs >> id && ifs >> name && ifs >> workid)
	{
		num01++;
	}
	ifs.close();
	return num01;

}
void workerManager::showallperson()
{
	if (this->m_Fileemty)
	{
		cout << "文档不存在或为空" << endl;
		system("pause");
		system("cls");

	}
	else
	{
		for (int i = 0; i < m_nums; i++)
		{
			this->m_arrys[i]->showid();
		}
	}
	system("pause");
	system("cls");



}
int workerManager::isexsit(int id)
{
    int index = -1;

	for (int i = 0; i < m_nums; i++)
	{
		if (this->m_arrys[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void workerManager::restart()  //初始化
{
	ifstream ifs;
	ifs.open(Filename, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* wk = nullptr;
		switch (did)
		{
		case 1:
			wk = new employee(id, name, did);
			break;
		case 2:
			wk = new manage(id, name, did);
			break;
		case 3:
			wk = new boss(id, name, did);
			break;
		}
		this->m_arrys[index] = wk;
		index++;
	}

}
void workerManager::deleteperson()
{
	if (this->m_Fileemty)
	{
		cout << "文件不存在或打不开" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int id;
		cout << "请输入需要删除的员工编码" << endl;
		cin >> id;
		int index = this->isexsit(id);
		if (index != -1)
		{
			for (int i = index; i < m_nums - 1; i++)
			{
				this->m_arrys[i] = this->m_arrys[i + 1];
			}
			m_nums--;
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout<<"员工编号不存在" << endl;
		}


	}
	system("pause");
	system("cls");
}
void workerManager::changepenson() 
{
	if (m_Fileemty)
	{
		cout << "文件不存在或者为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	int id;
	cout << "请输入想要修改的员工编号" << endl;
	cin >> id;
	int id01;
	string name01;
	int did01;
	int index = this->isexsit(id);
	if (index != -1)
	{
		cout << "请输入修改后的员工编号: " << endl;
		cin >> id01;
		cout << "请输入修改后的员工姓名: " << endl;
		cin >> name01;
		cout << "请输入修改职工的岗位名称" << endl;
		cout << "1.----------打工仔" << endl;
		cout << "2.--------项目经理" << endl;
		cout << "3.------------老板" << endl;
		cin >> did01;
		worker* wk=nullptr;
		switch (did01)
		{
		case 1:
			wk = new employee(id01, name01, did01);
		case 2:
			wk = new manage(id01, name01, did01);
		case 3:
			wk = new boss(id01, name01, did01);


		default:
			break;
		}
		this->m_arrys[index] =  wk;
		this->save();
		cout << "修改成功！" << endl;

	}
	else
	{
		cout << "查无此人修改失败" << endl;
	}
	system("pause");
	system("cls");

}
void workerManager::searchperson()
{
	if (this->m_Fileemty)
	{
		cout << "文件不存在或者无法打开" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int select;
		cout << "请输入查找类型" << endl;
		cout << "\t 1.按名字查找" << endl;
		cout << "\t 2.按编号查找" << endl;
		cin >> select;
		switch (select)
		{
		    case 1:
			{
				string name;
				cout << "请输入需要查找的员工名字" << endl;
				cin >> name;
				bool flag = false;
				for (int i = 0; i < m_nums; i++)
				{
					if (this->m_arrys[i]->m_Name == name)
					{
						cout << "查找成功,职工编号为："
							<< m_arrys[i]->m_ID
							<< " 号的信息如下：" << endl;
						this->m_arrys[i]->showid();
						flag = true;

					}
				}
				if (!flag)
				{
					cout << "查找失败，没有此人" << endl;
				}
				break;
			}
		
		
			
		
		    case 2:
			{
				int id;
				cout << "请输入查找员工的id" << endl;
				cin >> id;
				int index = this->isexsit(id);
				if (index != -1)
				{
					cout << "查找成功信息如下： " << endl;
					this->m_arrys[index]->showid();
				}
				else
				{
					cout << "没有这个编号的人" << endl;
				}
				break;
			}
		
			
		

		default:
			break;
		}
	}
	system("pause");
	system("cls");
}
void workerManager::sortperson()
{
	if (this->m_Fileemty)
	{
		cout << "文件打不开或者不存在" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int select;
		cout << "请输入想要的排序方式" << endl;
		cout << "\t 1.升序" << endl;
		cout << "\t 2.降序" << endl;
		cin >> select;
		for (int i = 0; i < m_nums; i++)
		{
			int k = i;
			for (int j = i+1; j < m_nums; j++)
			{
				if (select == 1)//升序，因为每次定第一位，所以要找最小的跟未排序的序列放在第一位
				{
					if (this->m_arrys[k]->m_ID > this->m_arrys[j]->m_ID)
					{
						k = j;
					}
				}
				else//同理找最大的那位放到第一个位置
				{
					if (this->m_arrys[k]->m_ID < this->m_arrys[j]->m_ID)
					{
						k = j;
					}
				}
			}
			worker* temp = m_arrys[k];
			m_arrys[k] = m_arrys[i];
			m_arrys[i] = temp;
		}
		cout << "排序成功！ 排序后的结果为：" << endl;
		this->save();
		this->showallperson();

		system("pause");
		system("cls");

	
	}
}
void workerManager::clearfile()
{
	int choice;
	cout << "请再次确认是否清空文件" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
	cin >> choice;
	if (choice==1)
	{
		ofstream ofs;
		ofs.open(Filename, ios::trunc);
		ofs.close();
		if (this->m_arrys != nullptr)
		{
			for (int i = 0; i < m_nums; i++)
			{
				if (this->m_arrys[i] != nullptr)
				{
					delete this->m_arrys[i];
					this->m_arrys[i] = nullptr;
				}
			}
			m_nums = 0;
			delete[] this->m_arrys;
			this->m_arrys[0] = nullptr;
			this->m_Fileemty = true;
			this->save();
		}
		system("pause");
		system("cls");
	}
	else
	{
		cout << "取消成功" << endl;
		system("pause");
		system("cls");
	}
}