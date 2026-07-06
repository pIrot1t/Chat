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
	int id;

public:
	Chat() : id(-1), name("") {};
	Chat(int id, string name) : id(id), name(name) {};
	Chat(int id, string name, vector<string> senders) : id(id), name(name), senders(senders) {};

	~Chat() 
	{
		senders.clear();
		messages.clear();
	}

	int getID();

	string getName();

	vector<string> getSenders();

	void addSender(string name);

	void ListSenders();

	void Send(string mes, string sender);
	
	void ViewMessages();

	int UseChat(string user_name);
};