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

        client.SendMessage(mess.c_str());

        if (!strncmp(mess.c_str(), "end", 3))
        {
            break;
        }

        cout << client.GetMessage() << endl;
    }

    client.StopClient();

    return 0;
}
