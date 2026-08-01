#include "UserManager.h"

fstream& operator >>(fstream& is, UserManager::User& usr)
{
	is >> usr._name;
	is >> usr._password;
	return is;
}

ostream& operator <<(ostream& os, const UserManager::User& usr)
{
	os << usr._name << " " << usr._password << endl;
	return os;
}

UserManager::UserManager()
{
	LoadUsers();
}

UserManager::~UserManager()
{
	SaveUsers();
}

void UserManager::SaveUsers()
{
	users_data.open("users_data.txt", ios::out | ios::trunc);
	for (User& usr : users)
	{
		users_data << usr;
	}
	users_data.close();
}

void UserManager::LoadUsers()
{
	users_data.open("users_data.txt", ios::in);
	if (users_data)
	{
		User usr;
		while (users_data >> usr)
		{
			users.push_back(usr);
		}
	}
	users_data.close();
}

void UserManager::Register()
{
	string name;
	Data password;
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#else
	system("clear");
#endif
	cout << endl << "						   <<GigaWord>>" << endl;
	cout << " ======================================================================================================================" << endl << endl;
	cout << "						  --sign up account--" << endl << endl;
	cout << " ======================================================================================================================" << endl << endl;
	cout << "						Enter name: ";
	cin >> name;
	cout << "						Enter password: ";
	cin >> password;
	for (User& usr : users)
	{
		if (usr._name == name)
		{
			return;
		}
	}
	users.push_back(User(name, password));
}

void UserManager::DeleteAccount()
{
	string name;
	Data password;
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#else
	system("clear");
#endif
	cout << endl << "						   <<GigaWord>>" << endl;
	cout << " ======================================================================================================================" << endl << endl;
	cout << "						--delete account--" << endl << endl;
	cout << " ======================================================================================================================" << endl << endl;
	cout << "						Enter name: ";
	cin >> name;
	cout << "						Enter password: ";
	cin >> password;
	for (vector<User>::iterator it = users.begin(); it != users.end();)
	{
		if (*it == User(name, password))
		{
			it = users.erase(it);
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
	system("cls");
#else
	system("clear");
#endif
	cout << endl << "						   <<GigaWord>>" << endl;
	cout << " ======================================================================================================================" << endl << endl;
	cout << "						  --sign in account--" << endl << endl;
	cout << " ======================================================================================================================" << endl << endl;
	cout << "						Enter name: ";
	cin >> name;
	cout << "						Enter password: ";
	cin >> password;
	for (User& usr : users)
	{
		if (usr == User(name, password))
		{
			_name = name;
			return ;
		}
	}
}
