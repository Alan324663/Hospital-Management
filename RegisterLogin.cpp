#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "User.cpp"
using namespace std;
class RegisterLogin : public User
{
private:
    string username;
    string password;

public:
    bool userLogin()
    {
        inputUser();
        bool userFound = false;
        string fileUsername, filePassword;
        ifstream fin("User.dat", ios::in);

        if (!fin.is_open())
        {
            cerr << "Cannot open file" << endl;
            return false;
        }

        while (fin >> fileUsername >> filePassword)
        {
            if (fileUsername == username && filePassword == password)
            {
                cout << "Welcome to patient management"
                     << " " << username << endl;
                userFound = true;
                break;
            }
        }

        fin.close();

        if (!userFound)
        {
            cout << "User not found" << endl;
        }

        return userFound;
    }

    void userRegister()
    {
        inputUser();

        ofstream fout("User.dat", ios::out | ios::app);

        if (!fout.is_open())
        {
            cerr << "Cannot open file" << endl;
            return;
        }

        fout << username << " " << password << endl;
        fout.close();

        cout << "User created" << endl;
    }
};
