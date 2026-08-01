#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include "sha1.h"

#define DATALENGTH 32

typedef char Data[DATALENGTH];
typedef unsigned int uint;

using namespace std;

namespace fs = filesystem;

class UserManager
{
private:
	struct User
	{
		string _name;
		uint _password;

		User() : _name(""), _password(-1) {};
		User(string name, Data password) : _name(name)
		{
			_password = *sha1(password, sizeof(password) - 1);
		};

		~User() = default;

		bool operator ==(const User& other)
		{
			if (_name == other._name && _password == other._password)
			{
				return true;
			}
			return false;
		}

	};

	fstream users_data;

	vector<User> users;
	int i = 0;

public:

	friend fstream& operator >>(fstream& is, User& usr);

	friend ostream& operator <<(ostream& os, const User& usr);

	UserManager();

	~UserManager();

	void SaveUsers();

	void LoadUsers();

	void Register();

	void DeleteAccount();

	void SignIn(string& name);
};
