#pragma once
#include <iostream>
#include <filesystem>
#include <string>
#include <map>
#include "Chat.h"

using namespace std;

class ChatManager
{
private:
	fstream chats_data;

	vector<Chat> chats;
	int i = 0;

public:

	friend ostream& operator <<(ostream& os, const Chat& chat);

	ChatManager();

	~ChatManager();

	void SaveChats();

	void LoadChats();

	void ListChats(string name);

	void CreateChat(string u_name, string c_name);

	void DeleteChat(int id);

	Chat* getChat(int id);

	void Control(string u_name);
};