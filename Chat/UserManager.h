#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "sha1.h"

#define DATALENGTH 32

typedef char Data[DATALENGTH];
typedef unsigned int uint;

using namespace std;

class UserManager
{
private:
	struct User
	{
		Data _name;
		uint _password;
		vector<int> _chatsID;

		User() : _name(""), _password(-1) {};
		User(Data name, Data password)
		{
			strcpy_s(_name, name);
			_password = *sha1(password, sizeof(password) - 1);
		};

		~User() = default;

		bool operator ==(const User& other)
		{
			if (!strcmp(_name, other._name) && _password == other._password)
			{
				return true;
			}
			return false;
		}

		void addChat(int id)
		{
			_chatsID.push_back(id);
		}

		void delChat(int id)
		{
			for (vector<int>::iterator it = _chatsID.begin(); it != _chatsID.end();)
			{
				if (*it == id)
				{
					_chatsID.erase(it);
					return;
				}
				else
				{
					++it;
				}
			}
		}

	};

	vector<User> users;

public:

	UserManager() = default;

	~UserManager()
	{
		users.clear();
	}

	void Register()
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
		return;
	}

	void DeleteAccount(Data name, Data password)
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

	bool SignIn()
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
			if (!strcmp(user._name, name) && user._password == *sha1(password, sizeof(password) - 1))
			{
				cout << "Success" << endl;
				return true;
			}
		}
		cout << "NULL" << endl;
		return false;
	}
};