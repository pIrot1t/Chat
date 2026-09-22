#include <iostream>
#include <string>
#include "Client.h"
#include "MessageManager.h"
#include "UserManager.h"
#include "ChatManager.h"


using namespace std;

int main()
{
    Client client;

    UserManager userManager;

    ChatManager chatManager;

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
                {
                    vector<string> temp = userManager.EnterData("AUTHORIZE");
                    client.SendMessage(mpsen(temp).c_str());
                    result = mprec(client.GetMessage());
                    if (result[0] == "SUCCESS")
                    {
                        userManager.setID(stoi(result[2]));
                        userManager.setName(temp[1]);
                        userManager.setPassword(temp[2]);
                        status = true;
                    }
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
                    {
                        while (true)
                        {
                            client.SendMessage(mpsen({"GETCHATS", to_string(userManager.getID())}).c_str());
                            vector<string> chats;
                            while (true)
                            {
                                result = mprec(client.GetMessage());
                                if (result[0] == "ENDLIST")
                                {
                                    result.clear();
                                    break;
                                }
                                if (result.size() >= 2)
                                {
                                    chats.push_back(result[0] + "    " + result[1]);
                                }
                                else
                                {
                                    chats.push_back(result[0] + "    (unnamed)");
                                }
                            }
                            vector<string> command = chatManager.ChatsMenu(chats);
                            if (command[0] == "RETURN")
                            {
                                break;
                            }
                            else if (command[0] == "CREATECHAT")
                            {
                                client.SendMessage(mpsen({command[0], command[1], to_string(userManager.getID())}).c_str());
                                result = mprec(client.GetMessage());
                            }
                            else if (command[0] == "OPENCHAT")
                            {
                                while (true)
                                {
                                    vector<string> messages;
                                    int chatID = stoi(command[1]);

                                    client.SendMessage(mpsen({"GETMSGS", command[1]}).c_str());
                                    while (true)
                                    {
                                        result = mprec(client.GetMessage());
                                        if (result[0] == "ENDMSGS")
                                        {
                                            result.clear();
                                            break;
                                        }
                                        messages.push_back(result[0]);
                                    }

                                    vector<string> command = chatManager.UseChat(chatID, "Chat", messages);
                                    if (command[0] == "RETURN")
                                    {
                                        break;
                                    }
                                    else if (command[0] == "SENDMSG")
                                    {
                                        client.SendMessage(mpsen({command[0], to_string(chatID), to_string(userManager.getID()), command[1]}).c_str());
                                    }
                                }
                            }
                        }
                    }
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
