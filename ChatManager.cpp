#include "ChatManager.h"

using namespace std;

void ChatManager::addChat(int chatID, string chatName)
{
    chats.insert({ chatID, chatName });
}

vector<string> ChatManager::ChatsMenu()
{
    while (true)
    {
#ifdef _WIN32
        system("cls");
#elif
        system("clear");
#endif
        int com;
        cout << "===================================================" << endl << endl;
        for (map<int, string>::iterator it = chats.begin(); it != chats.end(); it++)
        {
            cout << it->first << " : " << it->second << endl;
        }
        cout << endl << "======================================================" << endl;
        cout << "    0 > return | 1 > create chat | 2 > open chat" << endl;
        cout << "===================================================" << endl << endl;
        cout << "Enter num(0-2): ";
        cin >> com;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (com)
        {
            case 0:
                return {"RETURN"};
            break;
            case 1:
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter chat name: ";
                    string chat_name;
                    cin.ignore();
                    getline(cin, chat_name);
                    return {"CREATECHAT", chat_name};
                }
            break;
            case 2:
                cout << "Enter chat ID: ";
                cin >> com;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                return {"OPENCHAT", to_string(com)};
            break;
        }
    }
}

vector<string> ChatManager::UseChat(int chatID, vector<string> users, vector<string> messages)
{
    while (true)
    {
#ifdef _WIN32
        system("cls");
#elif
        system("clear");
#endif
        int com;
        string message;
        cout << "===================================================" << endl;
        cout << "    " << chatID << "        " << chats[chatID] << endl;
        cout << "===================================================" << endl << endl;
        for (string _message : messages)
        {
            cout << _message << endl;
        }
        cout << endl << "====================================================" << endl;
        cout << "0 > return | 1 > update messages | 2 > send message | 3 > chat menu" << endl;
        cout << "===================================================" << endl << endl;
        cout << "Enter num(0-3): ";
        cin >> com;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (com)
        {
            case 0:
                return {"RETURN"};
            break;
            case 1:
                return {"GETMSGS"};
            break;
            case 2:
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter message: ";
                getline(cin, message);
                return {"SENDMSG", message};
            break;
            case 3:
                while (true)
                {
#ifdef _WIN32
                    system("cls");
#elif
                    system("clear");
#endif
                    cout << "===================================================" << endl;
                    cout << "    " << chatID << "        " << chats[chatID] << endl;
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

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }

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
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
