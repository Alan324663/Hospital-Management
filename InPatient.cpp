#pragma once
#include <iostream>
#include <iomanip>
#include "Patient.cpp"
#include "DataInputValidation.cpp"

using namespace std;

class InPatient : public Patient
{
private:
    string condition;

public:
    InPatient() : Patient()
    {
        this->condition = "Unknown";
    }

    InPatient(int id, const string name, const string sex, const string condition) : Patient(id, name, sex)
    {
        setCondition(this->condition);
    }

    void setCondition(const string &condition)
    {
        if (!condition.empty())
        {
            this->condition = condition;
        }
        else
        {
            throw BadInputException();
        }
    }

    string getCondition() const
    {
        return condition;
    }

    void Display() override
    {
        cout << "In Patient: " << endl;
        cout << "-------------------------------------------------------------------\n";
        cout << "ID      Name        Sex           Condition \n";
        cout << "-------------------------------------------------------------------\n";
        // Implement the display logic for OutPatient
        Patient::Display(); // Optionally call the base class Display function
        cout << setw(20) << getCondition() << endl;
    }

    void Input() override
    {
        Patient::Input();
        string condition;
        cout << "Please enter the condition: ";
        cin >> condition;
        setCondition(condition);
    }
};
