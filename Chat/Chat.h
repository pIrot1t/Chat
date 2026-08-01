#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <list>

using namespace std;

namespace fs = filesystem;

class Chat
{
private:
	struct Message
	{
		string _message;
		string _sender;

		Message() : _message(""), _sender("") {};
		Message(string message, string sender) : _message(message), _sender(sender) {};

		~Message() = default;
	};

	vector<string> senders;
	vector<Message> messages;
	string _name;
	int _id;

public:

	friend fstream& operator >>(fstream& is, Message& mess);

	friend ostream& operator <<(ostream& os, const Message& mess);

	Chat() : _id(-1), _name("") {};
	Chat(int id, string name);
	Chat(int id, string name, vector<string> senders) : _id(id), _name(name), senders(senders) {};

	~Chat();


	void SaveChat();

	void LoadChat();

	int getID() const;

	string getName() const;

	vector<string> getSenders() const;

	void addSender(string name);

	void ListSenders();

	void Send(string mes, string sender);
	
	void ViewMessages();

	int UseChat(string user_name);
};