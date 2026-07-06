#include <iostream>
#include "UserManager.h"
#include "ChatManager.h"

using namespace std;

int main()
{
	UserManager* userM = new UserManager;
	ChatManager* chatM = new ChatManager;
	bool* active  = new bool(false);
	int* com = new int;
	while (true)
	{
		system("cls");
		cout << endl << "						   <<GigaWord>>" << endl;
		cout << " ======================================================================================================================" << endl << endl;
		cout << "						0 - leave chat" << endl;
		if (!active)
		{
			cout << "						1 - account data" << endl;
			cout << "						2 - create chat" << endl;
			cout << "						3 - sign in chat" << endl;
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
			delete active;
			delete com;
			return 0;
			break;
		case 1:
			if (!active)
			{

			}
			else
			{
				userM->Register();
			}
			break;
		default:
			break;
		}
	}
}
