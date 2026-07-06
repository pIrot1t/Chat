#include "Chat.h"


string Chat::getName()
{
	return name;
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