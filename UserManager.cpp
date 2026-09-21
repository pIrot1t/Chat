#include "UserManager.h"
#include <filesystem>

using namespace std;

namespace fs = filesystem;

UserManager::UserManager()
{
    if (fs::exists("UserData"))
    {
        fstream file;
        file.open("UserData/id.txt", ios::in);
        file >> user.id;
        file.close();

        file.open("UserData/name.txt", ios::in);
        file >> user.name;
        file.close();

        file.open("UserData/password.txt", ios::in);
        file >> user.password;
        file.close();

        file.open("UserData/contacts.txt", ios::in);
        string contact;
        while (getline(file, contact))
        {
            user.contacts.push_back(contact);
            contact.clear();
        }
        file.close();
    }
}

UserManager::~UserManager()
{
    if (user.id >= 0 && !user.name.empty() && !user.password.empty())
    {
        if (!fs::exists("UserData"))
        {
            fs::create_directory("UserData");
        }

        fstream file;
        file.open("UserData/id.txt", ios::out | ios::trunc);
        file << user.id;
        file.close();

        file.open("UserData/name.txt", ios::out | ios::trunc);
        file << user.name;
        file.close();

        file.open("UserData/password.txt", ios::out | ios::trunc);
        file << user.password;
        file.close();

        file.open("UserData/contacts.txt", ios::out | ios::trunc);
        for (string contact : user.contacts)
        {
            file << contact << endl;
        }
        file.close();
    }
}

void UserManager::clearData()
{
    fs::remove_all("UserData");
    user.clear();
}

int UserManager::getID()
{
    return user.id;
}

string UserManager::getName()
{
    return user.name;
}

string UserManager::getPassword()
{
    return user.password;
}

void UserManager::setID(int id)
{
    user.id = id;
}

void UserManager::setName(string name)
{
    user.name = name;
}

void UserManager::setPassword(string password)
{
    user.password = password;
}

void UserManager::addContact(string contact)
{
    user.contacts.push_back(contact);
}

void UserManager::delContact(string contact)
{
    for (vector<string>::iterator it = user.contacts.begin(); it < user.contacts.end();)
    {
        if (*it == contact)
        {
            it = user.contacts.erase(it);
        }
        else
        {
            it++;
        }
    }
}

vector<string> UserManager::EnterData(string type)
{
    cout << "==================================================" << endl << endl;
    if (type == "REGISTER")
    {
        cout << "                   Registration" << endl << endl;
    }
    else if (type == "AUTHORIZ")
    {
        cout << "                   Authorization" << endl << endl;
    }
    else if (type == "DELETEAC")
    {
        cout << "                   Delete account" << endl << endl;
    }
    cout << "==================================================" << endl << endl;
    string name;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    string password;
    cout << "Enter password: ";
    cin >> password;
    return {type, name, password};
}
