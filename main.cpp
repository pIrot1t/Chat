#include <iostream>
#include <string>
#include "Client.h"
#include "MessageManager.h"
#include "UserManager.h"
#include "ChatManager.h"


using namespace std;

int main(int argc, char* argv[])
{
    Client client;

    UserManager userManager;

    ChatManager chatManager;

    int com;
    vector<string> result;
    bool status = false;

    string serverIP = argc > 1 ? argv[1] : DEFAULT_SERVER_IP;

    if (!client.StartClient(serverIP))
    {
        return 1;
    }

    while(true)
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cout << "==================================================" << endl << endl;
        if (!status)
        {
            cout << "                1 > Registration" << endl;
            cout << "                2 > Authorization" << endl;
            cout << "                0 > Exit" << endl << endl;
            cout << "==================================================" << endl << endl;
            if (result.size() >= 2)
            {
                cout << result[0] << ": " << result[1] << endl << endl;
            }
            result.clear();
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
                    if (result.size() >= 3 && result[0] == "SUCCESS")
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
            if (result.size() >= 2)
            {
                cout << result[0] << ": " << result[1] << endl << endl;
            }
            result.clear();
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
                            chatManager.clearChats();
                            while (true)
                            {
                                result = mprec(client.GetMessage());
                                if (result.empty() || result[0] == "ENDLIST" || result[0] == "ERROR")
                                {
                                    result.clear();
                                    break;
                                }
                                if (result.size() >= 2)
                                {
                                    try
                                    {
                                        chatManager.addChat(stoi(result[0]), result[1]);
                                    }
                                    catch (const exception&)
                                    {
                                    }
                                }
                            }
                            vector<string> command = chatManager.ChatsMenu();
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
                                if (command.size() < 2)
                                {
                                    cout << "Error: invalid OPENCHAT command" << endl;
                                    continue;
                                }

                                int chatID = 0;

                                try
                                {
                                    chatID = stoi(command[1]);
                                }
                                catch (const exception&)
                                {
                                    cout << "Error: invalid chat ID" << endl;
                                    continue;
                                }

                                string chatStatus;

                                while (true)
                                {
                                    vector<string> messages;
                                    vector<string> users;
                                    //string chatname = "unknown";

                                    //client.SendMessage(mpsen({ "GETCHATNAME", to_string(chatID) }).c_str());

                                    //result = mprec(client.GetMessage());

                                    //string response = client.GetMessage();

                                    //cout << "DEBUG GETCHATNAME response: [" << response << "]" << endl;

                                    //result = mprec(response);

                                    //cout << "DEBUG parts: " << result.size() << endl;

                                    //if (result.size() > 1)
                                    //
                                    //    chatname = result[1];
                                    //}
                                    //else
                                    //{
                                    //    cout << "Error: failed to get chat name" << endl;
                                    //}

                                    client.SendMessage(mpsen({ "GETMSGS", to_string(chatID) }).c_str());

                                    while (true)
                                    {
                                        result = mprec(client.GetMessage());

                                        if (result.empty())
                                        {
                                            break;
                                        }

                                        if (result[0] == "ENDMSGS")
                                        {
                                            result.clear();
                                            break;
                                        }

                                        messages.push_back(result[0]);
                                    }

                                    client.SendMessage(mpsen({ "GETUSERSCHAT", to_string(chatID) }).c_str());

                                    while (true)
                                    {
                                        result = mprec(client.GetMessage());

                                        if (result.empty())
                                        {
                                            break;
                                        }

                                        if (result[0] == "ENDLIST")
                                        {
                                            result.clear();
                                            break;
                                        }

                                        users.push_back(result[0]);
                                    }

                                    vector<string> chatCommand = chatManager.UseChat(chatID, users, messages, chatStatus);

                                    chatStatus.clear();

                                    if (chatCommand.empty())
                                    {
                                        continue;
                                    }

                                    if (chatCommand[0] == "RETURN")
                                    {
                                        break;
                                    }
                                    else if (chatCommand[0] == "SENDMSG")
                                    {
                                        if (chatCommand.size() > 1)
                                        {
                                            client.SendMessage(mpsen({ chatCommand[0], to_string(chatID), to_string(userManager.getID()), chatCommand[1] }).c_str());

                                            result = mprec(client.GetMessage());

                                            if (result.size() > 1 && result[0] == "ERROR")
                                            {
                                                chatStatus = "ERROR: " + result[1];
                                            }

                                            result.clear();
                                        }
                                    }
                                    else if (chatCommand[0] == "ADDUSERCHAT")
                                    {
                                        if (chatCommand.size() > 1)
                                        {
                                            client.SendMessage(mpsen({ chatCommand[0], to_string(chatID), chatCommand[1] }).c_str());

                                            result = mprec(client.GetMessage());

                                            if (result.size() > 1)
                                            {
                                                chatStatus = result[0] + ": " + result[1];
                                            }

                                            result.clear();
                                        }
                                    }
                                }
                            }
                        }
                    }
                break;
                case 2:
                    while (true)
                    {
#ifdef _WIN32
                        system("cls");
#else
                        system("clear");
#endif
                        cout << "==================================================" << endl << endl;
                        cout << "          ID:       " << userManager.getID() << endl;
                        cout << "          Name:     " << userManager.getName() << endl;
                        cout << "          Password: " << userManager.getPassword() << endl << endl;
                        cout << "==================================================" << endl;
                        cout << "0 > return" << endl;
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
