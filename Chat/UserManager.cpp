#include "UserManager.h"


void UserManager::Register()
{
	string name;
	Data password;
#if defined(_WIN32) || defined(_WIN64)
	std::system("cls");
#else
	std::system("clear");
#endif
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
		if (user._name == name)
		{
			return;
		}
	}
	users.emplace_back(User(name, password));
}

void UserManager::DeleteAccount(string name, Data password)
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

void UserManager::SignIn(string& _name)
{
	string name;
	Data password;
#if defined(_WIN32) || defined(_WIN64)
	std::system("cls");
#else
	std::system("clear");
#endif
	cout << endl << "						   <<GigaWord>>" << endl;
	cout << " ======================================================================================================================" << endl << endl;
	cout << "						  sign in account" << endl << endl;
	cout << " ======================================================================================================================" << endl << endl;
	cout << "						Enter name: ";
	cin >> name;
	cout << "						Enter password: ";
	cin >> password;
	for (User& user : users)
	{
		if (user == User(name, password))
		{
			_name = name;
			return ;
		}
	}
}
