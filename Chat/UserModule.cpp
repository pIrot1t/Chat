#include "UserModule.h"

void UserModule::AddUser(string name, string login, string password)
{
	
	for(int i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
	{
		if (names[i].empty() && logins[i].empty() && passwords[i].empty())
		{
			names[i] = name;
			logins[i] = login;
			passwords[i] = password;
			cout << "Registration succes" << endl;
			return;
		}
		else if (i == sizeof(names) / sizeof(names[0])-1)
		{
			cout << "Count of users is max" << endl;
			return;
		}
	}
}

void UserModule::DeleteUser(string name, string password)
{
	
	for(int i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
	{
		if (names[i] == name && passwords[i] == password)
		{
			names[i].clear();
			logins[i].clear();
			passwords[i].clear();
			cout << "Account deleted" << endl;
			return;
		}
		else if (i == sizeof(names) / sizeof(names[0]) - 1)
		{
			cout << "Wrong name or password" << endl;
		}
	}
}

bool UserModule::SignIn(string login, string password)
{
	for (int i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
	{
		if (logins[i] == login && passwords[i] == password)
		{
			cout << "You sign in account" << endl;
			return true;
		}
		else
		{
			cout << "Wrong login or password" << endl;
			return false;
		}
	}
}

string UserModule::GetNameByID(int id)
{
	return names[id];
}
string UserModule::GetLoginByID(int id)
{
	return logins[id];
}
int UserModule::GetID(string str)
{
	for (int i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
	{
		if (names[i] == str || logins[i] == str)
		{
			return i;
		}
		else
		{
			return NULL;
		}
	}
}