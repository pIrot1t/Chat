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
    bool status = false;

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
                    vector<string> temp = userManager.EnterData("AUTHORIZ");
                    client.SendMessage(mpsen(temp).c_str());
                    result = mprec(client.GetMessage());
                    if (result[0] == "SUCCESS")
                    {
                        userManager.setID(stoi(result[1]));
                        userManager.setName(temp[1]);
                        userManager.setPassword(temp[2]);
                        status = true;
                    }
                break;
                default:
                    result = {"ERROR", "Unknown command"};
                break;
            }
        }
        else
        {
            cout << "                1 > Chats" << endl;
            cout << "                2 > Account data" << endl;
            cout << "                3 > Leave account" << endl;
            cout << "                0 > Exit" << endl << endl;
            cout << "==================================================" << endl << endl;
            if (!result.empty())
            {
                cout << result[0] << ": " << result[1] << endl << endl;
                result.clear();
            }
            cout << "Enter num(0-3): ";
            cin >> com;
            switch (com)
            {
                case 0:
                    client.SendMessage(mpsen({"END"}).c_str());
                    client.StopClient();
                    return 0;
                break;
                case 1:
                    
                break;
                case 2:
                    while (true)
                    {
                        cout << "==================================================" << endl << endl;
                        cout << "          ID:       " << userManager.getID() << endl;
                        cout << "          Name:     " << userManager.getName() << endl;
                        cout << "          Password: " << userManager.getPassword() << endl << endl;
                        cout << "==================================================" << endl;
                        cout << "0 > return | 1 > change name | 2 > change password" << endl;
                        cout << "==================================================" << endl << endl;
                        cin >> com;
                        if (com == 0)
                        {
                            break;
                        }
                    }
                break;
                case 3:
                    userManager.clearData();
                    status = false;
                break;
            }
        }
    }
}
