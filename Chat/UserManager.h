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

	};

	vector<User> users;
	int i = 0;

public:

	UserManager() = default;

	~UserManager()
	{
		users.clear();
	}

	void Register();

	void DeleteAccount(Data name, Data password);

	string SignIn();
};