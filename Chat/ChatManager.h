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

	void ListChats();

	void CreateChat(string name, vector<string> senders);

	void DeleteChat(int id);

	Chat getChat(int id);

	void Interface(Chat& chat);

	void Control(int id, string name);
};