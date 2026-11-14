#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include "Network.h"

#define MESSAGE_LENGTH 1024
#define PORT 51111
#define DEFAULT_SERVER_IP "192.168.198.128"

class Client
{
private:
    int socket_file_descriptor, connection;
    std::string message;
    std::string buffer;

public:
    bool StartClient(const std::string& ip);

    void StopClient();

    std::string GetMessage();

    void SendMessage(const std::string& message);
};
