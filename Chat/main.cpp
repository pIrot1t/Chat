#include <iostream>
#include "UserModule.h"

using namespace std;

int main()
{
	UserModule* UserM = new UserModule;
	string* com = new string;
	string* name = new string;
	bool* signIn = new bool(false);
	cout << "Welcome to My Program Chat" << endl << endl;
	cout << "Enter /help - view commands" << endl;
	cout << "      /exit - quit on desktop" << endl << endl;

	while (true)
	{
		if (*signIn == true) cout << *name << " ";
		cout << "Enter: ";
		cin >> *com;
		cout << endl;
		if (*com == "/help")
		{
			cout << "/help - view commands" << endl;
			cout << "/exit - quit on desktop" << endl;
			cout << "/reg - create account" << endl;
			cout << "/signin - sign in account" << endl;
			cout << "/quitacc - left the account" << endl;
			cout << "/del - delete account" << endl;

			cout << endl;
		}
		else if (*com == "/exit")
		{
			cout << "Goodbye!!!" << endl;
			time((long long *)2000);
			break;
		}
		else if (*com == "/reg")
		{
			string* temp = new string[3];
			cout << "Enter name: ";
			cin >> temp[0];
			cout << "Enter login: ";
			cin >> temp[1];
			cout << "Enter passowrd: ";
			cin >> temp[2];
			UserM->AddUser(temp[0], temp[1], temp[2]);
			cout << endl;
			delete[] temp;
		}
		else if (*com == "/signin")
		{
			string* temp = new string[2];
			cout << "Enter login: ";
			cin >> temp[0];
			cout << "Enter password: ";
			cin >> temp[1];
			*signIn = UserM->SignIn(temp[0], temp[1]);
			*name = UserM->GetNameByID(UserM->GetID(temp[0]));
			cout << endl;
			delete[] temp;
		}
		else if (*com == "/quitacc")
		{
			cout << "You lef the account" << endl;
			*signIn = false;
		}
		else if (*com == "/del")
		{
			string* temp = new string[2];
			cout << "Enter name: ";
			cin >> temp[0];
			cout << "Enter password: ";
			cin >> temp[1];
			UserM->DeleteUser(temp[0], temp[1]);
			name->clear();
			*signIn = false;
			cout << endl;
			delete[] temp;
		}
		else
		{
			cout << "Wrong command" << endl << endl;
		}
	}

	delete UserM;
	delete com;
	delete signIn;
}
