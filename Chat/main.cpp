#include <iostream>
#include "UserManager.h"
#include "ChatManager.h"

using namespace std;

int main()
{
	UserManager* userM = new UserManager;
	ChatManager* chatM = new ChatManager;
	string* name = new string("");
	int* com = new int;
	while (true)
	{
		system("cls");
		cout << endl << "						   <<GigaWord>>" << endl;
		cout << " ======================================================================================================================" << endl << endl;
		cout << "						0 - leave GigaWord" << endl;
		if (*name != "")
		{
			cout << "						1 - create chat" << endl;
			cout << "						2 - sign in chat" << endl;
			cout << "						3 - leave account" << endl;
			cout << endl << "		{ " << *name << " }" << endl;
		}
		else
		{
			cout << "						1 - sign up account" << endl;
			cout << "						2 - sign in account" << endl;
		}
		cout << endl << " ======================================================================================================================" << endl << endl;
		cout << "						Enter: ";

		cin >> *com;

		switch (*com)
		{
		case 0:
			delete userM;
			delete chatM;
			delete name;
			delete com;
			return 0;
			break;
		case 1:
			if (*name != "")
			{

			}
			else
			{
				userM->Register();
			}
			break;
		case 2:
			if (*name != "")
			{

			}
			else
			{
				*name = (string)userM->SignIn();
			}
			break;
		default:
			break;
		}
	}
}
