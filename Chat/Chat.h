#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Chat
{
private:
	struct Message
	{
		string _message;
		string _sender;

		Message(string message, string sender) : _message(message), _sender(sender) {};

		~Message() 
		{
			_message.clear();
		};
	};

	vector<string> senders;
	list<Message> messages;
	string name;

public:
	Chat() : name("") {};
	Chat(string name) : name(name) {};
	Chat(string name, vector<string> senders) : name(name), senders(senders) {};

	~Chat() 
	{
		senders.clear();
		messages.clear();
	}

	string getName();

	vector<string> getSenders();

	void addSender(string name);

	void ListSenders();

	void Send(string mes, string sender);
	
	void ViewMessages();

	void UseChat(string user_name);
};