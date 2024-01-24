#pragma once
#include <iostream>
using namespace std;

class User
{
private:
    string userName;
    string password;

public:
    // constructors
    User()
    {
        userName = "Unknown";
        password = "Unkonow";
    }
    User(string userName, string password, string role)
    {
        this->userName = userName;
        this->password = password;
    }
    // setter and getter methods
    string getUsername() const
    {
        return userName;
    }
    void setUsername(string userName)
    {
        this->userName = userName;
    }
    string getPassword() const
    {
        return password;
    }
    void setPassword(string password)
    {
        this->password = password;
    }

    // methods
    void display()
    {
        cout << "Username: " << userName << " Password:" << password << endl;
    }

    void inputUser()
    {
        cout << "Enter userName:";
        cin >> userName;
        cout << "Enter password:";
        cin >> password;
    }
};