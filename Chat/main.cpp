#include <iostream>
#include "UserManager.h"
#include "ChatManager.h"

using namespace std;

int main()
{
	UserManager* userM = new UserManager;
	ChatManager* chatM = new ChatManager;
	string name = "";
	int com;
	while (true)
	{
		cout << "\033[2J\033[1;1H";
		cout.flush();
		cout << endl << "						   <<GigaWord>>" << endl;
		cout << " ======================================================================================================================" << endl << endl;
		cout << "						0 - leave GigaWord" << endl;
		if (name != "")
		{
			cout << "						1 - chats" << endl;
			cout << "						2 - leave account" << endl << endl;
			cout << "						{ " << name << " }";
		}
		else
		{
			cout << "						1 - sign up account" << endl;
			cout << "						2 - sign in account" << endl;
		}
		cout << endl;
		cout << " ======================================================================================================================" << endl << endl;
		cout << "						Enter: ";

		cin >> com;
		cout << "\033[2J\033[1;1H";
		cout.flush();

		switch (com)
		{
		case 0:
			delete userM;
			delete chatM;
			return 0;
			break;
		case 1:
			if (name != "")
			{
				chatM->Control(name);
			}
			else
			{
				userM->Register();
			}
			break;
		case 2:
			if (name != "")
			{
				name = "";
			}
			else
			{
				userM->SignIn(name);
			}
			break;
		default:
			break;
		}
	}
}
