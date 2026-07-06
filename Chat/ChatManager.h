#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Chat.h"

using namespace std;

class ChatManager
{
private:
	map<int,Chat> chats;
	int i = 0;

public:

	ChatManager() = default;

	~ChatManager()
	{
		chats.clear();
	}

	void ListChats()
	{
		for (map<int, Chat>::iterator it = chats.begin(); it != chats.end(); ++it)
		{
			cout << it->first << " : " << it->second.getName() << endl;
		}
	}

	void CreateChat(string name, vector<string> senders)
	{
		chats.insert({ i++, Chat(name, senders)});
	}

	void DeleteChat(int id)
	{
		map<int, Chat>::iterator it = chats.find(id);
		chats.erase(it);
	}

	Chat getChat(int id)
	{
		return chats.at(id);
	}

	void Interface(Chat& chat)
	{
		system("cls");
		cout << chat.getName() << endl << endl;
		cout << "===================================================================" << endl << endl;
		chat.ViewMessages();
		cout << endl;
		cout << "0 - exit | 1 - send message | 2 - list users" << endl;
		cout << "===================================================================" << endl << endl;
		cout << "Enter: ";
	}

	void Control(int id, string name)
	{
		int* com = new int;
		Chat* chat = new Chat(getChat(id));
		while (true)
		{
			string* mes = new string;
			Interface(*chat);
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
				Interface(*chat);
				getline(cin, *mes);
				if (*mes == "0")
					break;
				chat->Send(*mes, name);
				delete mes;
				break;
			case 2:
				chat->ListSenders();
				break;
			default:
				break;
			}
		}
	}
};