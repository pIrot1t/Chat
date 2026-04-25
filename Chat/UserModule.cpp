#include "UserModule.h"

void UserModule::AddUser(string name, string email, string password)
{
	if (password.length() < 8) // ограничение на минимальное кол-во символов пароля
	{
		throw "Password less then eight characters";
	}
	for(int i = 0; i < sizeof(userData) / sizeof(userData[0]); ++i)
	{
		if (userData[i]->empty())
		{
			for (int j = 0; j < sizeof(userData) / sizeof(userData[0]); ++j)
			{
				if (userData[j][0] == name) // исключение для неповторяемости имен
				{
					throw "This name is already used"; 
				}
				else if (userData[j][1] == email) // исключение для неповторяемости логинов
				{
					throw "This email is already used";
				}
			}
			userData[i][0] = name;
			userData[i][1] = email;
			userData[i][2] = password;
			cout << "Registration success" << endl;
			return;
		}
		else if (i == sizeof(userData) / sizeof(userData[0]) - 1)
		{
			throw "Count of users is max"; // исключение на достижение максимального кол-ва пользователей
		}
	}
}

void UserModule::DeleteUser(string name, string email, string password)
{
	for(int i = 0; i < sizeof(userData) / sizeof(userData[0]); ++i)
	{
		if (userData[i][0] == name && userData[i][1] == email && userData[i][2] == password)
		{
			userData[i][0].clear();
			userData[i][1].clear();
			userData[i][2].clear();
			cout << "Account deleted" << endl;
			return;
		}
		else if (i == sizeof(userData) / sizeof(userData[0]) - 1)
		{
			cout << "Wrong name, email or password" << endl;
		}
	}
}

bool UserModule::Login(string email, string password) const
{
	for (int i = 0; i < sizeof(userData) / sizeof(userData[0]); ++i)
	{
		if (userData[i][1] == email && userData[i][2] == password)
		{
			cout << "You sign in account" << endl;
			return true;
		}
	}
	cout << "Wrong email or password" << endl;
	return false;
}

string UserModule::GetNameByID(int id)
{
	return userData[id][0];
}

string UserModule::GetEmailByID(int id)
{
	return userData[id][1];
}

int UserModule::GetID(string str) const
{
	for (int i = 0; i < sizeof(userData) / sizeof(userData[0]); ++i)
	{
		if (userData[i][0] == str || userData[i][1] == str)
		{
			return i;
		}
	}
	return NULL;
}