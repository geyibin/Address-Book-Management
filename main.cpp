
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
	"1.�����ϵ��",
	"2.��ʾ��ϵ��",
	"3.ɾ����ϵ��",
	"4.������ϵ��",
	"5.�޸���ϵ��",
	"6.�����ϵ��",
	"0.�˳�ͨѶ¼"
};
//�˵���װ����
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
	* 0:�˳�
	* 1 �����ϵ��
	* 2 ��ʾ��ϵ
	* 3 ɾ����ϵ��
	* 4 ������ϵ��
	* 5 �޸���ϵ��
	* 6 �����ϵ��
	*/
	switch (choice)
	{
	case 0:exitcontacts();
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		break;
	case 1:addmember(&abs);break;//���õ�ַ���ݿ������β�����ʵ��
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


	//����˵�ѡ���
	int selection;
	while (1)
	{
		//��ʾ�˵�����
		for (int i = 0;i < 15;i++)
		{
			cout << "**";
		}//��30������
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
		cout << "��ѡ��ͨѶ¼����" << endl;
		cin >> selection;
		if (selection < 8 && selection >= 0)
		{
			menuSettoFunction(selection);
		}
		else
		{
			cout << "����ָ����Ч������������" << endl;
			continue;
		}


	}


	system("pause");
	return 0;
}
