#pragma once
#include <iostream>
#include <string>

using namespace std;

class UserModule
{
private:
	string userData[8][3];
public:
	//UserModule();
	~UserModule() = default;
	void AddUser(string name, string login, string password);
	void DeleteUser(string name, string password);
	bool SignIn(string login, string password);
	string GetNameByID(int id);
	string GetLoginByID(int id);
	int GetID(string str);
};

