#include "Chat.h"

fstream& operator >>(fstream& is, Chat::Message& mess)
{
	is >> mess._sender;
	getline(is, mess._message);
	return is;
}

ostream& operator <<(ostream& os, const Chat::Message& mess)
{
	os << mess._sender << " " << mess._message << endl;
	return os;
}

Chat::Chat(int id, string name) : _id(id), _name(name)
{
	LoadChat();
}

Chat::~Chat()
{
	SaveChat();
}

void Chat::SaveChat()
{
	if (fs::exists(_name + to_string(_id) + "/"))
	{
		fstream chat_data;
		chat_data.open(_name + to_string(_id) + "/chat_senders.txt", ios::out | ios::trunc);
		for (string& sender : senders)
		{
			chat_data << sender << endl;
		}
		chat_data.close();
		chat_data.open(_name + to_string(_id) + "/chat_messages.txt", ios::out | ios::trunc);
		for (Message& mess : messages)
		{
			chat_data << mess;
		}
		chat_data.close();
	}
	else
	{
		fs::create_directory(_name + to_string(_id));
		SaveChat();
	}
}

void Chat::LoadChat()
{
	if (fs::exists(_name + to_string(_id) + "/"))
	{
		fstream chat_data;
		chat_data.open(_name + to_string(_id) + "/chat_senders.txt", ios::in);
		string sender;
		while (chat_data >> sender)
		{
			senders.push_back(sender);
		}
		chat_data.close();
		chat_data.open(_name + to_string(_id) + "/chat_messages.txt", ios::in);
		Message mess;
		while (chat_data >> mess)
		{
			messages.push_back(mess);
		}
		chat_data.close();
	}
}

int Chat::getID() const
{
	return _id;
}

string Chat::getName() const
{
	return _name;
}

vector<string> Chat::getSenders() const
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

int Chat::UseChat(string u_name)
{
	int com;
	string mess;
	while (true)
	{
#if defined(_WIN32) || defined(_WIN64)
		system("cls");
#else
		system("clear");
#endif
		cout << endl << "						   " << getName() << endl;
		cout << " ======================================================================================================================" << endl << endl;
		ViewMessages();
		cout << endl;
		cout << "		0 - return back | 1 - send message | 2 - menu" << endl;
		cout << " ======================================================================================================================" << endl << endl;
		cout << "	Enter: ";
		cin >> com;
		switch (com)
		{
		case 0:
			return 0;
			break;
		case 1:
#if defined(_WIN32) || defined(_WIN64)
			system("cls");
#else
			system("clear");
#endif
			cout << "						   " << getName() << endl << endl;
			cout << " ======================================================================================================================" << endl << endl;
			ViewMessages();
			cout << endl;
			cout << "							--send message--" << endl;
			cout << " ======================================================================================================================" << endl << endl;
			cout << "	Enter: ";
			cin.ignore();
			getline(cin, mess);
			Send(mess, u_name);
			break;
		case 2:
#if defined(_WIN32) || defined(_WIN64)
			system("cls");
#else
			system("clear");
#endif
			cout << "						   " << getName() << endl << endl;
			cout << " ======================================================================================================================" << endl << endl;
			ListSenders();
			cout << endl;
			cout << "		0 - return back | 1 - add user | 2 - leave chat | 3 - delete chat" << endl;
			cout << " ======================================================================================================================" << endl << endl;
			cout << "	Enter: ";
			cin >> com;
			switch (com)
			{
			case 0:
				break;
			case 1:
#if defined(_WIN32) || defined(_WIN64)
				system("cls");
#else
				system("clear");
#endif
				cout << "						   " << getName() << endl << endl;
				cout << " ======================================================================================================================" << endl << endl;
				ListSenders();
				cout << endl;
				cout << "							--add user--" << endl;
				cout << " ======================================================================================================================" << endl << endl;
				cout << "	Enter: ";
				cin >> mess;
				addSender(mess);
				cin.ignore();
				break;
			case 2:
				for (vector<string>::iterator it = senders.begin(); it != senders.end();)
				{
					if (*it == u_name)
					{
						it = senders.erase(it);
					}
					else
					{
						it++;
					}
				}
				return 0;
				break;
			case 3:
				return 1;
				break;
			}
			break;
		}
	}
}
