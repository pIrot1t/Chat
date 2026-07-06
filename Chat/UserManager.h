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
		Data _user_name;
		uint _password;

		User() : _user_name(""), _password(-1) {};
		User(Data name, Data password)
		{
			strcpy_s(_user_name, name);
			_password = *sha1(password, sizeof(password) - 1);
		};

		~User() = default;

	};

	vector<User> users;

public:
	void Register(Data name, Data password)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (!strcmp(users[i]._user_name, name))
			{
				cout << "ERROR" << endl;
				return;
			}
		}
		users.push_back({ name, password });
		cout << "Success" << endl;
	}

	void DeleteAccount(Data name, Data password)
	{
		for (int i = 0; i < users.size(); i++)
		{
			cout << users[i]._user_name << " " << users[i]._password << endl;
		}
	}

	bool SignIn(Data name, Data password)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (!strcmp(users[i]._user_name, name) && users[i]._password == *sha1(password, sizeof(password) - 1))
			{
				cout << "Success" << endl;
				return true;
			}
		}
		cout << "NULL" << endl;
		return false;
	}
};