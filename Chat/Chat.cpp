#include "Chat.h"

int Chat::getID()
{
	return id;
}

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

int Chat::UseChat(string u_name)
{
	int com;
	string mess;
	while (true)
	{
		cout << "\033[2J\033[1;1H";
		cout.flush();
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
			cout << "\033[2J\033[1;1H";
			cout.flush();
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
			cout << "\033[2J\033[1;1H";
			cout.flush();
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
				cout << "\033[2J\033[1;1H";
				cout.flush();
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
