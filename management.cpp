#include "management.h"
/*
* ��ӳ�Ա����Ϣ������
* ����
* �ֻ���
* �Ա�
* ����
* ��ס��ַ
*/
void addmember(struct Addressbooks* stu)
{

	cout << "�����ϵ��" << endl;
	//���ж�ͨѶ¼�ǲ�������
	if (stu->m_Size == MAX)
	{
		cout << "��ǰͨѶ¼�Ѿ�����" << endl;
		return;
	}
	else//�����ϵ��
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		stu->personArray[stu->m_Size].name = name;

		string phenoNumber;
		cout << "�������ֻ��ţ�" << endl;
		cin >> phenoNumber;
		stu->personArray[stu->m_Size].phoneNumber = phenoNumber;

		int sex;//�����Ա�1Ϊ��2ΪŮ
		cout << "�������Ա�1Ϊ���ԣ�2ΪŮ��" << endl;
		cin >> sex;
		while (sex != 1 && sex != 2)
		{
			cout << "�Ƿ����룬���������룺" << endl;
			cin >> sex;
		}
		stu->personArray[stu->m_Size].sex = sex;

		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		stu->personArray[stu->m_Size].age = age;

		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		stu->personArray[stu->m_Size].residentialAddress = address;
	}
	cout << "��ӳ�Ա�ɹ�" << endl;
	stu->m_Size += 1;
	cout << stu->m_Size;


}
void exitcontacts()//�˳�ͨѶ¼
{
	cout << "�˳�ͨѶ¼" << endl;
}
/*
* չʾͨѶ¼��Ա����Ϣ������
* ����
* �ֻ���
* �Ա�
* ����
* ��ס��ַ
*/
void displayMember(struct Addressbooks* stu)
{
	cout << "չʾ��ϵ��" << endl;
	for (int i = 0;i < stu->m_Size;i++)
	{
		cout << "��ϵ��: " << i << '\t' << ':' << endl;
		cout << "����: " << stu->personArray[i].name << '\t' << endl;
		cout << "����: " << stu->personArray[i].age << '\t' << endl;
		cout << "�Ա�: " << stu->personArray[i].sex << '\t' << endl;
		cout << "�ֻ���: " << stu->personArray[i].phoneNumber << '\t' << endl;
		cout << "��ͥסַ: " << stu->personArray[i].residentialAddress << '\t' << endl;

	}
}
//1. �����ϵ���Ƿ����
/*
* ����1 ͨѶ¼
* ����2 �Ա�����
* ������ڼ���˷��ؼ���˱�ţ����򷵻�ֵΪ-1
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
* ɾ��ָ����ϵ��
*/
void delateMember(struct Addressbooks* stu)
{
	string name;
	cout << "������Ҫɾ������ϵ��" << endl;
	cin >> name;
	int flag = isExit(stu, name);
	if (isExit(stu, name) != -1)
	{
		for (int i = flag;i < stu->m_Size;i++)
		{
			stu->personArray[i] = stu->personArray[i + 1];
		}
		stu->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else cout << "δ�ҵ�����ϵ��" << endl;
}
/*
* �޸���ϵ��
*/
void modifyMember(Addressbooks* stu)
{
	cout << "�޸���ϵ��" << endl;
	string name;
	cout << "������Ҫ�޸ĵ���ϵ������:" << endl;
	cin >> name;
	int exsitFlag = 1;
	int flag = isExit(stu, name);
	while (exsitFlag)
	{
		if (flag != -1)
		{
			int changeNumber;
			cout << "��ѡ��Ҫ�޸ĵ���Ϣ���" << endl;
			cout << "1.���� 2.�ֻ��� 3.�Ա�  4.�ֻ���" << endl;
			cin >> changeNumber;
			switch (changeNumber)
			{
			case 1:
			{
				string changeName;
				cout << "�������޸ĺ��������" << endl;
				cin >> changeName;
				stu->personArray[flag].name = changeName;
				break;
			};
			case 2:
			{
				string changePhenoNumber;
				cout << "�������޸ĺ���ֻ�����" << endl;
				cin >> changePhenoNumber;
				stu->personArray[flag].name = changePhenoNumber;
				break;
			}
			case 3:
			{
				int sex;
				while (1)
				{
					cout << "�������޸ĺ���Ա�(1Ϊ�У�2ΪŮ����" << endl;
					cin >> sex;
					if (sex != 1 && sex != 2)
					{
						cout << "�Ƿ����룬�����������Ա�" << endl;
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
				cout << "�������޸ĺ���ֻ���" << endl;
				cin >> changePhenoNumber;
				stu->personArray[flag].phoneNumber = changePhenoNumber;
				break;
			}
			default:break;
			}
			cout << "�Ƿ�����޸ģ�" << "����1�����޸ģ�����������˳�" << endl;
			cin >> exsitFlag;
		}
		else
		{
			cout << "��ϵ�˲����ڣ���ȷ����ϵ���Ƿ�������ȷ" << endl;
			break;
		}
	}

}
/*
* ������ϵ�ˣ�����ϵ��������Ϊ����
*/
void searchMember(struct Addressbooks* stu)
{
	string name;
	cout << "����������������ϵ��" << endl;
	cin >> name;
	int flag;
	int i;
	flag = isExit(stu, name);
	while (1)
	{
		int found = -1;  // ���ڱ���Ƿ��ҵ�����ϵ��
		for (i = 0; i < stu->m_Size; i++)
		{
			if (name == stu->personArray[i].name)
			{
				found = i;
				cout << "�ҵ���ϵ�ˣ�" << stu->personArray[i].name << endl;
				cout << "������" << '\t' << stu->personArray[i].name << endl;
				cout << "�ֻ��ţ�" << '\t' << stu->personArray[i].phoneNumber << endl;
				cout << "�Ա�" << '\t' << stu->personArray[i].sex << endl;
				cout << "���䣺" << '\t' << stu->personArray[i].age << endl;
				cout << "��ס��ַ��" << '\t' << stu->personArray[i].residentialAddress << endl;
				break;
			}
		}

		if (found == -1)
		{
			string sympal;
			cout << "�����ҵ���ϵ�˲����ڣ���ȷ��������" << endl;
			cout << "�Ƿ������ѯ������ 1 ��������������������˳���";
			cin >> sympal;
			if (sympal == "1")
			{
				cout << "��������ϵ��������";
				cin >> name; // ��������Ҫ��ѯ������
				continue; // ���� while ѭ����ͷ
			}
			else
			{
				break; // �˳�ѭ��
			}
		}
		else
		{
			break; // �ҵ�����ϵ�ˣ��˳�ѭ��
		}
	}


}
void clearContacts(struct Addressbooks* stu)
{
	cout << "�����ϵ��" << endl;
	stu->m_Size = 0;
	cout << "�Ѿ������ϵ��" << endl;
}