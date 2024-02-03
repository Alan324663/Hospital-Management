#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include "User.cpp"
using namespace std;
class AdminAccount
{
private:
    string adminName;
    string password;

public:
    bool adminLogin() // login user to file
    {
        cout << "Enter admin name:";
        cin >> adminName;
        cout << "Enter password:";
        cin >> password;
        bool adminFound = false;
        string fileAdminName, filePassword;
        ifstream fin("Admin.dat", ios::in);

        if (!fin.is_open())
        {
            cerr << "Cannot open file" << endl;
            return false;
        }

        while (fin >> fileAdminName >> filePassword)
        {
            if (fileAdminName == adminName && filePassword == password)
            {
                cout << "Welcome to patient management"
                     << " " << adminName << endl;
                adminFound = true;
                break;
            }
        }

        fin.close();

        if (!adminFound)
        {
            cout << "Admin not found" << endl;
        }

        return adminFound;
    }

    void adminRegister() // create new user to file
    {
        cout << "Enter admin name:";
        cin >> adminName;
        cout << "Enter password:";
        cin >> password;

        ofstream fout("Admin.dat", ios::out | ios::app);

        if (!fout.is_open())
        {
            cerr << "Cannot open file" << endl;
            return;
        }

        fout << adminName << " " << password << endl;
        fout.close();

        cout << "Admin created" << endl;
    }
};
