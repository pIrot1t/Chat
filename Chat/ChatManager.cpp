#include "ChatManager.h"


void ChatManager::ListChats(string name)
{
	for (map<int, Chat>::iterator it = chats.begin(); it != chats.end(); ++it)
	{
		vector<string> senders = it->second.getSenders();
		for (string& sender : senders)
		{
			if (sender == name)
			{
				cout << it->first << " : " << it->second.getName() << endl;
			}
		}
	}
}

void ChatManager::CreateChat(string name, string user_name)
{
	chats.insert({ i++, Chat(name) });
}

void ChatManager::DeleteChat(int id)
{
	map<int, Chat>::iterator it = chats.find(id);
	chats.erase(it);
}

Chat ChatManager::getChat(int id)
{
	return chats.at(id);
}

void ChatManager::Control(string name)
{
	int* com = new int;
	Chat* chat = new Chat(getChat(id));
	while (true)
	{
		string* mes = new string;
		system("cls");
		cout << endl << "						   <<GigaWord>>" << endl;
		cout << " ======================================================================================================================" << endl << endl;
		ListChats(name);
		cout << "		0 - return to main page | 1 - enter chat | 2 - create chat" << endl;
		cout << " ======================================================================================================================" << endl << endl;
		cout << "						Enter: ";
		cin >> *com;
		switch (*com)
		{
		case 0:
			delete com;
			delete chat;
			delete mes;
			return;
			break;
		case 1:

			break;
		case 2:

			break;
		default:
			break;
		}
	}
}