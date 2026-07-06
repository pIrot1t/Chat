#include "Chat.h"


string Chat::getName()
{
	return name;
}

vector<string> Chat::getSenders()
{
	return senders;
}

void Chat::addSender(string name)
{
	senders.push_back(name);
}

void Chat::ListSenders()
{
	for (string& sender : senders)
	{
		cout << sender << endl;
	}
}

void Chat::Send(string mes, string sender)
{
	messages.push_back(Message(mes, sender));
}

void Chat::ViewMessages()
{
	for (Chat::Message& message : messages)
	{
		cout << message._sender << " > " << message._message << endl;
	}
}

void Chat::UseChat(string user_name)
{
	system("cls");
	cout << getName() << endl << endl;
	cout << " ======================================================================================================================" << endl << endl;
	ViewMessages();
	cout << endl;
	cout << "			0 - exit | 1 - send message | 2 - list users | 3 - leave chat" << endl;
	cout << " ======================================================================================================================" << endl << endl;
	cout << "Enter: ";
}