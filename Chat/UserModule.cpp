#include "UserModule.h"

void UserModule::AddUser(string name, string login, string password)
{
	
	for(int i = 0; i < sizeof(userData) / sizeof(userData[0]); ++i)
	{
		if (userData[i]->empty())
		{
			for (int j = 0; j < sizeof(userData) / sizeof(userData[0]); ++j)
			{
				if (userData[j][0] == name)
				{
					cout << "This name is already used" << endl;
					return;
				}
				else if (userData[j][1] == login)
				{
					cout << "This email is already used" << endl;
					return;
				}
			}
			userData[i][0] = name;
			userData[i][1] = login;
			userData[i][2] = password;
			cout << "Registration succes" << endl;
			return;
		}
		else if (i == sizeof(userData) / sizeof(userData[0]) - 1)
		{
			cout << "Count of users is max" << endl;
			return;
		}
	}
}

void UserModule::DeleteUser(string name, string password)
{
	
	for(int i = 0; i < sizeof(userData) / sizeof(userData[0]); ++i)
	{
		if (userData[i][0] == name && userData[i][2] == password)
		{
			userData[i][0].clear();
			userData[i][1].clear();
			userData[i][2].clear();
			cout << "Account deleted" << endl;
			return;
		}
		else if (i == sizeof(userData) / sizeof(userData[0]) - 1)
		{
			cout << "Wrong name or password" << endl;
		}
	}
}

bool UserModule::SignIn(string login, string password)
{
	for (int i = 0; i < sizeof(userData) / sizeof(userData[0]); ++i)
	{
		if (userData[i][1] == login && userData[i][2] == password)
		{
			cout << "You sign in account" << endl;
			return true;
		}
	}
	cout << "Wrong login or password" << endl;
	return false;
}

string UserModule::GetNameByID(int id)
{
	return userData[id][0];
}

string UserModule::GetLoginByID(int id)
{
	return userData[id][1];
}

int UserModule::GetID(string str)
{
	for (int i = 0; i < sizeof(userData) / sizeof(userData[0]); ++i)
	{
		if (userData[i][0] == str || userData[i][1] == str)
		{
			return i;
		}
	}
	cout << "User not found" << endl;
	return NULL;
}