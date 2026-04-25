#include "ChatModule.h"

void ChatModule::SendMessage(string sender, string recipient, string message)
{
	for (int i = 0; i < sizeof(messages) / sizeof(messages[0]); ++i)
	{
		if (messages[i]->empty())
		{
			messages[i][0] = sender;
			messages[i][1] = recipient;
			messages[i][2] = message;
			return;
		}
	}
}

void ChatModule::ViewMessages(string sender, string recipient) const
{
	for (int i = 0; i < sizeof(messages) / sizeof(messages[0]); ++i)
	{
		// проверки для корректного отображения сообщений
		if ((messages[i][0] == sender || messages[i][0] == recipient) && (messages[i][1] == sender || messages[i][1] == recipient))
		{
			cout << messages[i][0] << ": " << messages[i][2] << endl;
		}
		else if (recipient == "shared" && messages[i][1] == "shared")
		{
			cout << messages[i][0] << ": " << messages[i][2] << endl;
		}
	}
}