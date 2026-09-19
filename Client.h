#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MESSAGE_LENGTH 1024
#define PORT 51111

class Client
{
private:
    int socket_file_descriptor, connection;
    struct sockaddr_in serveraddress, client;
    char message[MESSAGE_LENGTH];

public:
    bool StartClient();

    void StopClient();

    std::string GetMessage();

    void SendMessage(char *message);
};
