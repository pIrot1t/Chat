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

	void ListChats(string name);

	void CreateChat(string name, string user_name);

	void DeleteChat(int id);

	Chat getChat(int id);

	void Control(string name);
};