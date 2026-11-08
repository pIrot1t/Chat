#include "Client.h"

using namespace std;

bool Client::StartClient()
{
    if (!StartNetwork())
    {
        cout << "Error: network initialization failed!" << endl;
        return false;
    }

    if (!ConnectToServer("192.168.198.128", PORT, socket_file_descriptor))
    {
        cout << "Connection with server failed!" << endl;
        StopNetwork();
        return false;
    }

    return true;
}

void Client::StopClient()
{
    CloseConnection(socket_file_descriptor);
    StopNetwork();
}

string Client::GetMessage()
{
    ReceiveMessageFromServer(socket_file_descriptor, message);

    return message;
}

void Client::SendMessage(const string& message)
{
    //bzero(message, sizeof(message));
    //strncpy(message, _message, MESSAGE_LENGTH - 1);

    SendMessageToServer(socket_file_descriptor, message);
}
