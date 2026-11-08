#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include "Network.h"

#define MESSAGE_LENGTH 1024
#define PORT 51111

class Client
{
private:
    int socket_file_descriptor, connection;
    std::string message;

public:
    bool StartClient();

    void StopClient();

    std::string GetMessage();

    void SendMessage(const std::string& message);
};
