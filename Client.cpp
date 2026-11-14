#include "Client.h"

using namespace std;

bool Client::StartClient(const string& ip)
{
    if (!StartNetwork())
    {
        cout << "Error: network initialization failed!" << endl;
        return false;
    }

    if (!ConnectToServer(ip, PORT, socket_file_descriptor))
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
    size_t end;

    while ((end = buffer.find('\n')) == string::npos)
    {
        string chunk;

        if (!ReceiveMessageFromServer(socket_file_descriptor, chunk))
        {
            buffer.clear();
            message.clear();
            return message;
        }

        for (char c : chunk)
        {
            if (c != '\0')
            {
                buffer += c;
            }
        }
    }

    message = buffer.substr(0, end + 1);
    buffer.erase(0, end + 1);

    return message;
}

void Client::SendMessage(const string& message)
{
    SendMessageToServer(socket_file_descriptor, message);
}
