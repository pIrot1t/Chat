#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Chat.h"

using namespace std;

class ChatManager
{
private:
	vector<Chat> chats;
	int i = 0;

public:

	ChatManager() = default;

	~ChatManager()
	{
		chats.clear();
	}

	void ListChats(string name);

	void CreateChat(string u_name, string c_name);

	void DeleteChat(int id);

	Chat* getChat(int id);

	void Control(string u_name);
};