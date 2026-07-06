#include "UserManager.h"


void UserManager::Register()
{
	Data name;
	Data password;
	system("cls");
	cout << endl << "						   <<GigaWord>>" << endl;
	cout << " ======================================================================================================================" << endl << endl;
	cout << "						  sign up account" << endl << endl;
	cout << " ======================================================================================================================" << endl << endl;
	cout << "						Enter name: ";
	cin >> name;
	cout << "						Enter password: ";
	cin >> password;
	for (User& user : users)
	{
		if (!strcmp(user._name, name))
		{
			return;
		}
	}
	users.emplace_back(User(name, password));
}

void UserManager::DeleteAccount(Data name, Data password)
{
	for (vector<User>::iterator it = users.begin(); it != users.end();)
	{
		if (*it == User(name, password))
		{
			users.erase(it);
			return;
		}
		else
		{
			++it;
		}
	}
}

string UserManager::SignIn()
{
	Data name;
	Data password;
	system("cls");
	cout << endl << "						   <<GigaWord>>" << endl;
	cout << " ======================================================================================================================" << endl << endl;
	cout << "	Enter name: ";
	cin >> name;
	cout << "	Enter password: ";
	cin >> password;
	for (User& user : users)
	{
		if (user == User(name, password))
		{
			cout << "Success" << endl;
			return user._name;
		}
	}
	cout << "NULL" << endl;
	return "";
}