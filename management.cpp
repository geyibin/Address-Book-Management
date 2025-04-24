#include "management.h"
/*
* 添加成员的信息包括：
* 姓名
* 手机号
* 性别
* 年龄
* 居住地址
*/
void addmember(struct Addressbooks* stu)
{

	cout << "添加联系人" << endl;
	//先判断通讯录是不是满了
	if (stu->m_Size == MAX)
	{
		cout << "当前通讯录已经满了" << endl;
		return;
	}
	else//添加联系人
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		stu->personArray[stu->m_Size].name = name;

		string phenoNumber;
		cout << "请输入手机号：" << endl;
		cin >> phenoNumber;
		stu->personArray[stu->m_Size].phoneNumber = phenoNumber;

		int sex;//定义性别1为男2为女
		cout << "请输入性别，1为男性，2为女性" << endl;
		cin >> sex;
		while (sex != 1 && sex != 2)
		{
			cout << "非法输入，请重新输入：" << endl;
			cin >> sex;
		}
		stu->personArray[stu->m_Size].sex = sex;

		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		stu->personArray[stu->m_Size].age = age;

		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		stu->personArray[stu->m_Size].residentialAddress = address;
	}
	cout << "添加成员成功" << endl;
	stu->m_Size += 1;
	cout << stu->m_Size;


}
void exitcontacts()//退出通讯录
{
	cout << "退出通讯录" << endl;
}
/*
* 展示通讯录成员的信息包括：
* 姓名
* 手机号
* 性别
* 年龄
* 居住地址
*/
void displayMember(struct Addressbooks* stu)
{
	cout << "展示联系人" << endl;
	for (int i = 0;i < stu->m_Size;i++)
	{
		cout << "联系人: " << i << '\t' << ':' << endl;
		cout << "姓名: " << stu->personArray[i].name << '\t' << endl;
		cout << "年龄: " << stu->personArray[i].age << '\t' << endl;
		cout << "性别: " << stu->personArray[i].sex << '\t' << endl;
		cout << "手机号: " << stu->personArray[i].phoneNumber << '\t' << endl;
		cout << "家庭住址: " << stu->personArray[i].residentialAddress << '\t' << endl;

	}
}
//1. 检测联系人是否存在
/*
* 参数1 通讯录
* 参数2 对比姓名
* 如果存在检测人返回检测人编号，否则返回值为-1
*/
int isExit(struct Addressbooks* abs, string name)
{
	for (int i = 0;i < abs->m_Size;i++)
	{
		if (abs->personArray[i].name == name)
		{
			return i;

		}
	}
	return -1;
}
/*
* 删除指定联系人
*/
void delateMember(struct Addressbooks* stu)
{
	string name;
	cout << "请输入要删除的联系人" << endl;
	cin >> name;
	int flag = isExit(stu, name);
	if (isExit(stu, name) != -1)
	{
		for (int i = flag;i < stu->m_Size;i++)
		{
			stu->personArray[i] = stu->personArray[i + 1];
		}
		stu->m_Size--;
		cout << "删除成功" << endl;
	}
	else cout << "未找到该联系人" << endl;
}
/*
* 修改联系人
*/
void modifyMember(Addressbooks* stu)
{
	cout << "修改联系人" << endl;
	string name;
	cout << "请输入要修改的联系人姓名:" << endl;
	cin >> name;
	int exsitFlag = 1;
	int flag = isExit(stu, name);
	while (exsitFlag)
	{
		if (flag != -1)
		{
			int changeNumber;
			cout << "请选择要修改的信息编号" << endl;
			cout << "1.姓名 2.手机号 3.性别  4.手机号" << endl;
			cin >> changeNumber;
			switch (changeNumber)
			{
			case 1:
			{
				string changeName;
				cout << "请输入修改后的姓名：" << endl;
				cin >> changeName;
				stu->personArray[flag].name = changeName;
				break;
			};
			case 2:
			{
				string changePhenoNumber;
				cout << "请输入修改后的手机号码" << endl;
				cin >> changePhenoNumber;
				stu->personArray[flag].name = changePhenoNumber;
				break;
			}
			case 3:
			{
				int sex;
				while (1)
				{
					cout << "请输入修改后的性别(1为男，2为女）：" << endl;
					cin >> sex;
					if (sex != 1 && sex != 2)
					{
						cout << "非法输入，请重新输入性别：" << endl;
						continue;
					}
					else
					{
						stu->personArray[flag].sex = sex;
						break;
					}
				}
				break;
			}
			case 4:
			{
				string changePhenoNumber;
				cout << "请输入修改后的手机号" << endl;
				cin >> changePhenoNumber;
				stu->personArray[flag].phoneNumber = changePhenoNumber;
				break;
			}
			default:break;
			}
			cout << "是否继续修改？" << "输入1继续修改，输入任意键退出" << endl;
			cin >> exsitFlag;
		}
		else
		{
			cout << "联系人不存在，请确定联系人是否输入正确" << endl;
			break;
		}
	}

}
/*
* 搜索联系人，以联系人姓名作为索引
*/
void searchMember(struct Addressbooks* stu)
{
	string name;
	cout << "请输入想搜索的联系人" << endl;
	cin >> name;
	int flag;
	int i;
	flag = isExit(stu, name);
	while (1)
	{
		int found = -1;  // 用于标记是否找到了联系人
		for (i = 0; i < stu->m_Size; i++)
		{
			if (name == stu->personArray[i].name)
			{
				found = i;
				cout << "找到联系人：" << stu->personArray[i].name << endl;
				cout << "姓名：" << '\t' << stu->personArray[i].name << endl;
				cout << "手机号：" << '\t' << stu->personArray[i].phoneNumber << endl;
				cout << "性别：" << '\t' << stu->personArray[i].sex << endl;
				cout << "年龄：" << '\t' << stu->personArray[i].age << endl;
				cout << "居住地址：" << '\t' << stu->personArray[i].residentialAddress << endl;
				break;
			}
		}

		if (found == -1)
		{
			string sympal;
			cout << "您查找的联系人不存在，请确认姓名。" << endl;
			cout << "是否继续查询？输入 1 继续，否则输入任意键退出：";
			cin >> sympal;
			if (sympal == "1")
			{
				cout << "请输入联系人姓名：";
				cin >> name; // 重新输入要查询的名字
				continue; // 跳回 while 循环开头
			}
			else
			{
				break; // 退出循环
			}
		}
		else
		{
			break; // 找到了联系人，退出循环
		}
	}


}
void clearContacts(struct Addressbooks* stu)
{
	cout << "清空联系人" << endl;
	stu->m_Size = 0;
	cout << "已经清空联系人" << endl;
}