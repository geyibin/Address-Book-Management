
#include <iostream>
#include <string>
#include "management.h"
#define addNewmember 1
#define displayContacts 2
#define searchContacts 4
#define modifyContacts 5
#define deleteContacts 3
#define clearContracts 6
#define exitContacts 0
using namespace std;
string function[7] = {
	"1.添加联系人",
	"2.显示联系人",
	"3.删除联系人",
	"4.查找联系人",
	"5.修改联系人",
	"6.清空联系人",
	"0.退出通讯录"
};
//菜单封装函数
void menuSettoFunction(int choice)
{
	int i = 0;


	Addressbooks abs;
	if (i == 0)
	{
		abs.m_Size = 0;
		i++;
	}
	/*
	* 0:退出
	* 1 添加联系人
	* 2 显示联系
	* 3 删除联系人
	* 4 查找联系人
	* 5 修改联系人
	* 6 清空联系人
	*/
	switch (choice)
	{
	case 0:exitcontacts();
		cout << "欢迎下次使用" << endl;
		system("pause");
		break;
	case 1:addmember(&abs);break;//利用地址传递可以用形参修饰实参
	case 2:displayMember(&abs);break;
	case 3:delateMember(&abs);break;
	case 4:searchMember(&abs);break;
	case 5:modifyMember(&abs);break;
	case 6:clearContacts(&abs);break;
	default:break;
	}
}
int main()
{


	//输入菜单选项部分
	int selection;
	while (1)
	{
		//显示菜单部分
		for (int i = 0;i < 15;i++)
		{
			cout << "**";
		}//画30颗星星
		cout << endl;
		for (int i = 0;i < 7;i++)
		{
			for (int j = 0;j < 9;j++)
			{
				cout << "*";
			}
			cout << function[i];
			for (int j = 0;j < 9;j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		cout << "请选择通讯录功能" << endl;
		cin >> selection;
		if (selection < 8 && selection >= 0)
		{
			menuSettoFunction(selection);
		}
		else
		{
			cout << "输入指令无效，请重新输入" << endl;
			continue;
		}


	}


	system("pause");
	return 0;
}
