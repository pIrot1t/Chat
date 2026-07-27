#include "ChatManager.h"


void ChatManager::ListChats(string name)
{
	for (vector<Chat>::iterator it = chats.begin(); it != chats.end(); ++it)
	{
		vector<string> senders = it->getSenders();
		for (string& sender : senders)
		{
			if (sender == name)
			{
				cout << it->getID() << " : " << it->getName() << endl;
			}
		}
	}
}

void ChatManager::CreateChat(string u_name, string c_name)
{
	Chat chat(i++, c_name);
	chat.addSender(u_name);
	chats.push_back(chat);
}

void ChatManager::DeleteChat(int id)
{
	for (vector<Chat>::iterator it = chats.begin(); it != chats.end();)
	{
		if (it->getID() == id)
		{
			it = chats.erase(it);
		}
		else
		{
			it++;
		}
	}
}

Chat* ChatManager::getChat(int id)
{
	for (Chat& chat : chats)
	{
		if (chat.getID() == id)
		{
			return &chat;
		}
	}
	return nullptr;
}

void ChatManager::Control(string u_name)
{
	int com;
	Chat* chat = nullptr;
	string c_name;
	while (true)
	{
		system("cls");
		cout << endl << "						   <<GigaWord>>" << endl;
		cout << " ======================================================================================================================" << endl << endl;
		ListChats(u_name);
		cout << "		0 - return to main page | 1 - enter chat | 2 - create chat" << endl;
		cout << " ======================================================================================================================" << endl << endl;
		cout << "						Enter: ";
		cin >> com;
		switch (com)
		{
		case 0:
			return;
			break;
		case 1:
			system("cls");
			cout << endl << "						   <<GigaWord>>" << endl;
			cout << " ======================================================================================================================" << endl << endl;
			ListChats(u_name);
			cout << "					--enter chat ID--" << endl;
			cout << " ======================================================================================================================" << endl << endl;
			cout << "						Enter: ";
			cin >> com;
			chat = getChat(com);
			if (chat != nullptr)
			{
				if (chat->UseChat(u_name) == 1)
				{
					DeleteChat(chat->getID());
				}
			}
			break;
		case 2:
			system("cls");
			cout << endl << "						   <<GigaWord>>" << endl;
			cout << " ======================================================================================================================" << endl << endl;
			ListChats(u_name);
			cout << "					--enter chat name--" << endl;
			cout << " ======================================================================================================================" << endl << endl;
			cout << "						Enter: ";
			cin.ignore();
			getline(cin, c_name);
			CreateChat(u_name, c_name);
			break;
		default:
			break;
		}
	}
}