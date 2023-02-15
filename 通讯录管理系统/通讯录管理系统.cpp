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
	cout << "****** 1、添加联系人 ******" << endl;
	cout << "****** 2、显示联系人 ******" << endl;
	cout << "****** 3、删除联系人 ******" << endl;
	cout << "****** 4、查找联系人 ******" << endl;
	cout << "****** 5、修改联系人 ******" << endl;
	cout << "****** 6、清空联系人 ******" << endl;
	cout << "***************************" << endl;
}

void addPerson(Addressbooks *abs)
{
	if (abs->m_Size == Max)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		int sex;
		cout << "请输入姓名：" <<endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		
		cout << "请输入性别：" << endl;
		cout << "1-------男" << endl;
		cout << "2-------女" << endl;
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
				cout << "输入有误，请重新输入！" << endl;
			}
		}
		
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		
		cout << "请输入电话号码：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入住址：" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		abs->m_Size++;
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}
}
//显示所有联系人
void showPerson(Addressbooks* abs)
{// 判断通讯录中人数是否为0，如果为0，提示记录为空，如果不为0，显示记录的联系人信息
	if (abs->m_Size==0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex ==1 ? "男":"女" )<< "\t";
			cout << "年龄："<<abs->personArray[i].m_Age<< "\t";
			cout << "电话号码：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//判断联系人是否存在
int isExit(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;//找到了，返回下标编号
		}
	}
	return -1;
}
//删除指定联系人
//封装删除联系人函数，根据用户输入的联系人判断该通讯录中是否有此人，查找到进行删除，并提示删除成功，查不到提示查无此人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人，删除失败" << endl;
	}
	system("pause");
	system("cls");
}
//查找指定联系人信息
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret=isExit(abs, name);
	if (ret != -1)
	{
		cout << "姓名" << abs->personArray[ret].m_Name << "\t";
		cout << "性别" << (abs->personArray[ret].m_Sex==1?"男":"女") << "\t";
		cout << "年龄" << abs->personArray[ret].m_Age << "\t";
		cout << "电话号码" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址" << abs->personArray[ret].m_Addr << endl;
	}
	system("pause");
	system("cls");
}
//修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1-----男" << endl;
		cout << "2-----女" << endl;
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
				cout << "输入有误，请重新输入！" << endl;
			}
		}
		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		cout << "请输入家庭住址：" << endl;
		string adress;
		cin >> adress;
		abs->personArray[ret].m_Addr = adress;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//清空联系人 步骤：1、封装清空联系人函数   2、测试情况联系人
void clearPerson(Addressbooks* abs)
{
	cout << "是否确定清空？" << endl;
	cout << "1----yes" << endl;
	cout << "2----no" << endl;
	int number;
	cin >> number;
	if (number == 1) {
		abs->m_Size = 0;
		cout << "通讯录已请空" << endl;
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
			cout << "请输入要删除的人的姓名" << endl;
			string name;
			cin >> name;
			if (isExit(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到此人" << endl;
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
			cout << "欢迎下次使用！" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
}