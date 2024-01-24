#pragma once
#include <iostream>
#include <iostream>
#include <limits>

using namespace std;

class DataInputValidation
{
private:
    bool validate_id(int id)
    {
        if (cin.fail() || id <= 0 || id > 1000)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        return true;
    }

    bool validate_name(const string &name)
    {
        if (name.length() > 10)
        {
            return false;
        }

        for (char c : name)
        {
            if (!isalpha(c))
            {
                return false;
            }
        }
        return true;
    }

    bool validate_sex(const string &sex)
    {
        if (sex.length() != 1 || (sex[0] != 'M' && sex[0] != 'F' && sex[0] != 'm' && sex[0] != 'f'))
        {
            return false;
        }
        return true;
    }

    bool validate_diag(const string &diag)
    {
        if (diag.length() > 100)
        {
            return false;
        }

        for (char c : diag)
        {
            if (!isalpha(c))
            {
                return false;
            }
        }
        return true;
    }

public:
    int input_PatientID()
    {
        int id;
        while (true)
        {
            cout << "Enter Patient ID: ";
            cin >> id;
            if (!validate_id(id))
            {
                cout << "Error: Invalid Input" << endl;
            }
            else
            {
                return id;
            }
        }
    }

    string input_name()
    {
        string name;
        while (true)
        {
            cout << "Enter name: ";
            cin >> name;
            if (!validate_name(name))
            {
                cout << "Error: Invalid/max letter reached" << endl;
            }
            else
            {
                return name;
            }
        }
    }

    string input_sex()
    {
        string sex;
        while (true)
        {
            cout << "Enter Sex (M/F): ";
            cin >> sex;
            if (!validate_sex(sex))
            {
                cout << "Error: Invalid input. Please enter 'M' for Male or 'F' for Female." << endl;
            }
            else
            {
                return sex;
            }
        }
    }

    string input_reason()
    {
        string reason;
        while (true)
        {
            cout << "Enter reason: ";
            cin >> reason;
            if (!validate_diag(reason))
            {
                cout << "Error: Invalid/max letter reached" << endl;
            }
            else
            {
                return reason;
            }
        }
    }

    string input_condition()
    {
        string condition;
        while (true)
        {
            cout << "Enter condition: ";
            cin >> condition;
            if (!validate_diag(condition))
            {
                cout << "Error: Invalid/max letter reached" << endl;
            }
            else
            {
                return condition;
            }
        }
    }
};