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
	void AddUser(string name, string email, string password);
	void DeleteUser(string name, string email, string password);
	bool Login(string email, string password) const;
	string GetNameByID(int id);
	string GetEmailByID(int id);
	int GetID(string str) const;
};

