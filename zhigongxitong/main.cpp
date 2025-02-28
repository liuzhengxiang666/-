
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manage.h"
#include "boss.h"

//void test01()
//{
//	worker* wk = nullptr;
//	wk =new employee(19, "刘彦希", 0);
//	wk->showid();
//	delete wk;
//	wk = new manage(20, "刘余甲",1);
//	wk->showid();
//	delete wk;
//	wk = new boss(18, "刘政翔", 2);
//	wk->showid();
//	delete wk;
//
//
//
//}




int main()
{
	//test01();
	workerManager wm;
	int choice = 0;
	while (true)
	{
		wm.show_menu();
		cout << "请输入功能数字" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitout();
			break;
		case 1://添加职工
			wm.add_emp();
			wm.save();
			break;
		case 2: //显示职工
			wm.showallperson();
			break;
		case 3: //删除职工
			wm.deleteperson();
			break;
		case 4://修改职工
			wm.changepenson();
			break;
		case 5://查找职工
			wm.searchperson();
			break;
		case 6://排序职工
			wm.sortperson();
			break;
		case 7: //清空文件
			wm.clearfile();
			break;
		default:
			system("cls");
			break;

		}

	}

	system("pause");
	return 0;
}