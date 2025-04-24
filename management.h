

#ifndef MANAGEMENT_H   // 如果没有定义 MANAGEMENT_H
#define MANAGEMENT_H   // 那就定义它
#include <iostream>
using namespace std;
#define MAX 1000
void addmember(struct Addressbooks* stu);//添加成员
void exitcontacts();//退出通讯录
void displayMember(struct Addressbooks* stu);//显示通讯录成员
void delateMember(struct Addressbooks* stu);//删除成员
void searchMember(struct Addressbooks* stu);//搜索通讯录成员
void modifyMember(struct Addressbooks* stu);//修改通讯录成员
void clearContacts(struct Addressbooks* stu);//清空通讯录
int isExit(struct Addressbooks* abs, string name);//判断联系人是否存在
struct contractMember
{
	string name;
	//性别 1男 2女
	int sex;
	int age;
	string phoneNumber;
	string residentialAddress;
};
struct Addressbooks
{
	struct contractMember personArray[MAX];
	int m_Size;
};
#endif