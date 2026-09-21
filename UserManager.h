#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>

class UserManager
{
private:
    struct User
    {
        int id;
        std::string name;
        std::string password;
        std::vector<std::string> contacts;

        void clear()
        {
            id = -1;
            name.clear();
            password.clear();
            contacts.clear();
        }
    };

    User user;

public:

    UserManager();

    ~UserManager();

    int getID();

    std::string getName();

    std::string getPassword();

    void setID(int id);

    void setName(std::string name);

    void setPassword(std::string password);

    void addContact(std::string contact);

    void delContact(std::string contact);

    std::vector<std::string> EnterData(std::string type);

};
