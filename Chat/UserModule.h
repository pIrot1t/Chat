#pragma once
#include <iostream>
#include <string>

using namespace std;

class UserModule
{
private:
	string userData[8][3];
public:
	UserModule() = default;
	~UserModule() = default;
	void AddUser(string name, string email, string password); // создает аккаунт
	void DeleteUser(string name, string email, string password); // удаляет аакаунт
	bool Login(string email, string password) const; // вход в аккаунт
	string GetNameByID(int id);
	string GetEmailByID(int id);
	int GetID(string str) const;
};

