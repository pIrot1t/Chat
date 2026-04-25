#include <iostream>
#include "UserModule.h"
#include "ChatModule.h"

using namespace std;

int main()
{
	UserModule* UserM = new UserModule;
	ChatModule* ChatM = new ChatModule;
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
			cout << "/login - sign in account" << endl;
			cout << "/logout - left the account" << endl;
			cout << "/del - delete account" << endl;
			cout << "/chat - sign in chat" << endl;

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
			cout << "Enter email: ";
			cin >> temp[1];
			cout << "Enter password: ";
			cin >> temp[2];
			try
			{
				UserM->AddUser(temp[0], temp[1], temp[2]);
			}
			catch (const char* exeption)
			{
				cout << exeption << endl;
			}
			cout << endl;
			delete[] temp;
		}
		else if (*com == "/login")
		{
			string* temp = new string[2];
			cout << "Enter email: ";
			cin >> temp[0];
			cout << "Enter password: ";
			cin >> temp[1];
			*signIn = UserM->Login(temp[0], temp[1]);
			*name = UserM->GetNameByID(UserM->GetID(temp[0]));
			cout << endl;
			delete[] temp;
		}
		else if (*com == "/logout")
		{
			cout << "You left the account" << endl << endl;
			*signIn = false;
		}
		else if (*com == "/del")
		{
			string* temp = new string[3];
			cout << "Enter name: ";
			cin >> temp[0];
			cout << "Enter email: ";
			cin >> temp[1];
			cout << "Enter password: ";
			cin >> temp[2];
			UserM->DeleteUser(temp[0], temp[1], temp[2]);
			name->clear();
			*signIn = false;
			cout << endl;
			delete[] temp;
		}
		else if (*com == "/chat")
		{
			if (!*signIn)
			{
				cout << "First, login account" << endl << endl;
			}
			else
			{
				cout << "Enter which chat to open [shared/<UserName>]: ";
				cin >> *com;
				string* message = new string;
				if (*com == "shared")
				{
					while (true)
					{
						system("cls");
						cout << "Welcome to shared chat!" << endl << endl;
						cout << "Enter /q - left the chat" << endl << endl;
						ChatM->ViewMessages(*name, "shared");
						cout << *name << ": ";
						cin >> *message;
						if (*message == "/q")
						{
							system("cls");
							break;
						}
						ChatM->SendMessage(*name, "shared", *message);
					}
				}
				else
				{
					if (UserM->GetID(*com) != NULL)
					{
						while (true)
						{
							system("cls");
							cout << "Welcome to " << *com << " chat!" << endl << endl;
							cout << "Enter /q - left the chat" << endl << endl;
							ChatM->ViewMessages(*name, *com);
							cout << *name << ": ";
							cin >> *message;
							if (*message == "/q")
							{
								system("cls");
								break;
							}
							ChatM->SendMessage(*name, *com, *message);
						}
					}
					else
					{
						cout << "User not found" << endl << endl;
					}
				}
				delete message;
			}
		}
		else
		{
			cout << "Wrong command" << endl << endl;
		}
	}

	delete UserM;
	delete ChatM;
	delete com;
	delete name;
	delete signIn;

	return 0;
}
