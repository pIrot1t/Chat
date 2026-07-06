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
	Chat(string name, vector<string> senders) : name(name), senders(senders) {};

	~Chat() 
	{
		senders.clear();
		messages.clear();
	}

	string getName();

	void ListSenders();

	void Send(string mes, string sender);
	
	void ViewMessages();
};