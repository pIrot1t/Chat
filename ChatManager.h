#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <map>

class ChatManager
{
private:

    std::map<int, std::string> chats;

public:

    void addChat(int chatID, std::string chatName);

    void clearChats();

    std::vector<std::string> ChatsMenu();

    std::vector<std::string> UseChat(int chatID, std::vector<std::string> users, std::vector<std::string> messages, std::string status = "");
};
