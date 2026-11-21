#include <iostream>
#include <string>
#include <vector>

class ChatManager
{
public:

    std::vector<std::string> ChatsMenu(std::vector<std::string> chats);

    std::vector<std::string> UseChat(int chatID, std::string chatName, std::vector<std::string> users, std::vector<std::string> messages);
};
