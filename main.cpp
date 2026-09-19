#include <iostream>
#include <string>
#include "Client.h"


using namespace std;

int main()
{
    Client client;

    string mess;

    while(client.StartClient())
    {
        cin >> mess;

        client.SendMessage((char*)&mess);

        if (strncmp((char*)&mess, "end", 3))
        {
            client.StopClient();
            break;
        }

        client.GetMessage();
    }

    return 0;
}
