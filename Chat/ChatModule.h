#pragma once
#include <iostream>
#include <string>

using namespace std;

class ChatModule
{
private:
	string messages[255][3];
public:
	ChatModule() = default;
	~ChatModule() = default;
	void SendMessage(string sender, string recipient, string message);
	void ViewMessages(string sender, string recipient);
};