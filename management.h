

#ifndef MANAGEMENT_H   // ���û�ж��� MANAGEMENT_H
#define MANAGEMENT_H   // �ǾͶ�����
#include <iostream>
using namespace std;
#define MAX 1000
void addmember(struct Addressbooks* stu);//��ӳ�Ա
void exitcontacts();//�˳�ͨѶ¼
void displayMember(struct Addressbooks* stu);//��ʾͨѶ¼��Ա
void delateMember(struct Addressbooks* stu);//ɾ����Ա
void searchMember(struct Addressbooks* stu);//����ͨѶ¼��Ա
void modifyMember(struct Addressbooks* stu);//�޸�ͨѶ¼��Ա
void clearContacts(struct Addressbooks* stu);//���ͨѶ¼
int isExit(struct Addressbooks* abs, string name);//�ж���ϵ���Ƿ����
struct contractMember
{
	string name;
	//�Ա� 1�� 2Ů
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