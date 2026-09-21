#include <iostream>
#include <string>
#include "Client.h"
#include "MessageManager.h"
#include "UserManager.h"


using namespace std;

int main()
{
    Client client;

    UserManager userManager;

    int com;
    vector<string> result;
    bool status;

    if (!client.StartClient())
    {
        return 1;
    }

    while(true)
    {
        cout << "==================================================" << endl << endl;
        if (!status)
        {
            cout << "                1 > Registration" << endl;
            cout << "                2 > Authorization" << endl;
            cout << "                0 > Exit" << endl << endl;
            cout << "==================================================" << endl << endl;
            if (!result.empty())
            {
                cout << result[0] << ": " << result[1] << endl << endl;
                result.clear();
            }
            cout << "Enter num(0-2): ";
            cin >> com;
            switch (com)
            {
                case 0:
                    client.SendMessage(mpsen({"END"}).c_str());
                    client.StopClient();
                    return 0;
                break;
                case 1:
                    client.SendMessage(mpsen(userManager.EnterData("REGISTER")).c_str());
                    result = mprec(client.GetMessage());
                break;
                case 2:
                    client.SendMessage(mpsen(userManager.EnterData("AUTHORIZ")).c_str());
                break;
                default:
                    result.emplace_back("ERROR","Unknown command");
                break;
            }
        }
    }
}
