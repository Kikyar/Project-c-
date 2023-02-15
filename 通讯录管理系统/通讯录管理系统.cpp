#include <iostream>
#define Max 1000
using namespace std;

struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
struct Addressbooks
{
	struct Person personArray[Max];
	int m_Size;
};
void ShowMenu()
{
	cout << "***************************" << endl;
	cout << "****** 1�������ϵ�� ******" << endl;
	cout << "****** 2����ʾ��ϵ�� ******" << endl;
	cout << "****** 3��ɾ����ϵ�� ******" << endl;
	cout << "****** 4��������ϵ�� ******" << endl;
	cout << "****** 5���޸���ϵ�� ******" << endl;
	cout << "****** 6�������ϵ�� ******" << endl;
	cout << "***************************" << endl;
}

void addPerson(Addressbooks *abs)
{
	if (abs->m_Size == Max)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		int sex;
		cout << "������������" <<endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		
		cout << "�������Ա�" << endl;
		cout << "1-------��" << endl;
		cout << "2-------Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�����������������룡" << endl;
			}
		}
		
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		
		cout << "������绰���룺" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "������סַ��" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		abs->m_Size++;
		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}
}
//��ʾ������ϵ��
void showPerson(Addressbooks* abs)
{// �ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ�գ������Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size==0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex ==1 ? "��":"Ů" )<< "\t";
			cout << "���䣺"<<abs->personArray[i].m_Age<< "\t";
			cout << "�绰���룺" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//�ж���ϵ���Ƿ����
int isExit(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;//�ҵ��ˣ������±���
		}
	}
	return -1;
}
//ɾ��ָ����ϵ��
//��װɾ����ϵ�˺����������û��������ϵ���жϸ�ͨѶ¼���Ƿ��д��ˣ����ҵ�����ɾ��������ʾɾ���ɹ����鲻����ʾ���޴���
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴��ˣ�ɾ��ʧ��" << endl;
	}
	system("pause");
	system("cls");
}
//����ָ����ϵ����Ϣ
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret=isExit(abs, name);
	if (ret != -1)
	{
		cout << "����" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex==1?"��":"Ů") << "\t";
		cout << "����" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰����" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ" << abs->personArray[ret].m_Addr << endl;
	}
	system("pause");
	system("cls");
}
//�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1-----��" << endl;
		cout << "2-----Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�����������������룡" << endl;
			}
		}
		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		cout << "�������ͥסַ��" << endl;
		string adress;
		cin >> adress;
		abs->personArray[ret].m_Addr = adress;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ�� ���裺1����װ�����ϵ�˺���   2�����������ϵ��
void clearPerson(Addressbooks* abs)
{
	cout << "�Ƿ�ȷ����գ�" << endl;
	cout << "1----yes" << endl;
	cout << "2----no" << endl;
	int number;
	cin >> number;
	if (number == 1) {
		abs->m_Size = 0;
		cout << "ͨѶ¼�����" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("pause");
		system("cls");
	}
}
int main()
{
	Addressbooks abs;
	abs.m_Size = 0;
	int select;
	while (true)
	{
		ShowMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
		/*{
			cout << "������Ҫɾ�����˵�����" << endl;
			string name;
			cin >> name;
			if (isExit(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ�����" << endl;
			}
		}*/
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			clearPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
}