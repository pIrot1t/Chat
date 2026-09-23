#include "ChatManager.h"
#include <string>

using namespace std;

vector<string> ChatManager::ChatsMenu(vector<string> chats)
{
    while (true)
    {
        system("clear");
        int com;
        cout << "===================================================" << endl << endl;
        for (string chat : chats)
        {
            cout << chat << endl;
        }
        cout << endl << "======================================================" << endl;
        cout << "    0 > return | 1 > create chat | 2 > open chat" << endl;
        cout << "===================================================" << endl << endl;
        cout << "Enter num(0-2): ";
        cin >> com;
        switch (com)
        {
            case 0:
                return {"RETURN"};
            break;
            case 1:
                {
                    cout << "Enter chat name: ";
                    string chatname;
                    cin.ignore();
                    getline(cin, chatname);
                    return {"CREATECHAT", chatname};
                }
            break;
            case 2:
                cout << "Enter chat ID: ";
                cin >> com;
                return {"OPENCHAT", to_string(com)};
            break;
        }
    }
}

vector<string> ChatManager::UseChat(int chatID, string chatName, vector<string> users, vector<string> messages)
{
    while (true)
    {
        system("clear");
        int com;
        string message;
        cout << "===================================================" << endl;
        cout << "    " << chatID << "        " << chatName << endl;
        cout << "===================================================" << endl << endl;
        for (string _message : messages)
        {
            cout << _message << endl;
        }
        cout << endl << "======================================================" << endl;
        cout << "0 > return | 1 > update messages | 2 > send message | 3 > chat menu" << endl;
        cout << "===================================================" << endl << endl;
        cout << "Enter num(0-3): ";
        cin >> com;
        switch (com)
        {
            case 0:
                return {"RETURN"};
            break;
            case 1:
                return {"GETMSGS"};
            break;
            case 2:
                cin.ignore();
                getline(cin, message);
                return {"SENDMSG", message};
            break;
            case 3:
                while (true)
                {
                    system("clear");
                    cout << "===================================================" << endl;
                    cout << "    " << chatID << "        " << chatName << endl;
                    cout << "===================================================" << endl << endl;
                    for (string user : users)
                    {
                        cout << user << endl;
                    }
                    cout << endl << "===================================================" << endl;
                    cout << "    0 > return | 1 > add user" << endl;
                    cout << "===================================================" << endl << endl;
                    cout << "Enter num(0,1): ";
                    cin >> com;
                    if (com == 0)
                    {
                        break;
                    }
                    switch (com)
                    {
                        /*case 1:
                            return {"LEAVECHAT"};
                        break;*/
                        case 1:
                            cout << "Enter user ID: ";
                            cin.ignore();
                            getline(cin, message);
                            return {"ADDUSERCHAT", message};
                        break;
                    }
                }
            break;
        }
    }
}
